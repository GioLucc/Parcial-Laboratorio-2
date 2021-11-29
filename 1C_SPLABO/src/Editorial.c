/*
 * eEditorial.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#include "Editorial.h"
#include "Book.h"

/// @fn Editorial EDI_new*()
/// @brief Crea espacio en memoria dinamica para el nuevo libro.
///
/// @return El espacio de memoria asignado para poder empezar a trabajar.
Editorial* EDI_new()
{
	Editorial* newEditorial;

	newEditorial = (Editorial*) calloc(1,sizeof(Editorial));

	return newEditorial;
}

/// @fn Editorial EDI_newCharge*(char*, char*)
/// @brief Recibe todos los datos en tipo string que contiene el archivo para meterlos dentro de la LinkedList.
///
/// @param idStr
/// @param editorialStr
/// @return un puntero a editorial ya cargado para usarlo o agregarlo a la LinkedList.
Editorial* EDI_newCharge(char* idStr,char* editorialStr)
{
	Editorial* newEditorial;
	int idAux;
	char editorialName[MAX_CHAR];

	newEditorial = EDI_new();

	idAux = atoi(idStr);
	strcpy(editorialName, editorialStr);

	EDI_setEditorialName(newEditorial, editorialName);
	EDI_setId(newEditorial, idAux);

	return newEditorial;
}

/// @fn int EDI_getId(Book*, int)
/// @brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int EDI_getId(Editorial* this, int* editorialId)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		*editorialId = this->idEditorial;
		state = 0;
	}

	return state;
}

/// @fn int EDI_getEditorialName(Book*, char*)
/// @brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int EDI_getEditorialName(Editorial* this, char* editorialName)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		strcpy(editorialName, this->nombre);
		state = 0;
	}

	return state;
}

/// @fn int EDI_setId(Book*, char*)
/// @brief Toma el dato que le llega por parametros y se lo asigna a this.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int EDI_setId(Editorial* this, int editorialId)
{
	int state;

	state = -1;

	if(this != NULL && editorialId > 0)
	{
		this->idEditorial = editorialId;
		state = 0;
	}

	return state;
}

/// @fn int EDI_setEditorialName(Book*, char*)
/// @brief Toma el dato que le llega por parametros y se lo asigna a this.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int EDI_setEditorialName(Editorial* this, char* editorialName)
{
	int state;

	state = -1;

	if(this != NULL && editorialName != NULL)
	{
		strcpy(this->nombre, editorialName);
		state = 0;
	}

	return state;
}

/// @fn int EDI_showOneEditorials(Book*, LinkedList*)
/// @brief Obtiene cada uno de los campos de this mediante los geters en esa posición para poder printearlos.
///
/// @param this
/// @param pArrayListEditorials
/// @return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int EDI_showOneEditorials(Editorial* this)
{
	int state;
	char editorialName [MAX_CHAR];
	int editorialId;

	state = -1;

	if(this != NULL)
	{
		EDI_getEditorialName(this, editorialName);
		EDI_getId(this, &editorialId);

		printf("\t\t\t\t\t\t\t\t|%4d  |%20s   |\n",editorialId,editorialName);
		state = 0;
	}

	return state;
}
/// @fn int EDI_showListOfEditorials(LinkedList*, LinkedList*)
/// @brief Recorre la cantidad de elementos que hayan sido cargados en pArrayListBooks y llama a showOneBook para printear cada uno.
///
/// @param pArrayListBooks
/// @param pArrayListEditorials
/// @return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int EDI_showListOfEditorials(LinkedList* pArrayListEditorials)
{
	Editorial* aux;
	int state;
	int editorialsQty;

	state = -1;

	if(pArrayListEditorials != NULL)
	{
		editorialsQty = ll_len(pArrayListEditorials);

		printf("\n\n\n\n\t\t\t\t\t\t\t\t|  ID  |    Editorial name     |\n");
		printf("\t\t\t\t\t\t\t\t|______|_______________________|\n");

		for(int i = 0; i < editorialsQty; i++)
		{
			aux = ll_get(pArrayListEditorials, i);

			EDI_showOneEditorials(aux);
		}
		state = 0;
	}

	return state;
}

/// @fn Editorial bringEditorials*(LinkedList*, int)
/// @brief Devuelve un puntero auxiliar de la estructura editorials con todos los datos con los que haya matcheado la id pasada por parametros.
///
/// @param pArrayListEditorials
/// @param bookEditorialId
/// @return NULL, o el puntero a estructura con todos los campos correspondientes del id matcheado.
Editorial* bringEditorials (LinkedList* pArrayListEditorials, int bookEditorialId)
{
	Editorial* bookStringEditorial;
	int editorialId;

	bookStringEditorial = NULL;

	if(pArrayListEditorials != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEditorials); i++)
		{
			bookStringEditorial = ll_get(pArrayListEditorials, i);

			EDI_getId(bookStringEditorial, &editorialId);
			if(editorialId == bookEditorialId)
			{
				break;
			}
		}
	}
	return bookStringEditorial;
}

/// @fn int EDI_criterio(void*)
/// @brief criterio usado a la hora de filtrar con el ll_filter, este evalua si void* element es igual a la id minotauro.
///
/// @param element
/// @return 0 si se pudo realizar correctamente, -1 si no hubo match de filter.
int EDI_criterio (void* element)
{
	int state;
	Book* auxBook;
	int minotauroEditorialId;
	int elementEditorialId;

	minotauroEditorialId = 4;
	state = 0;

	if(element != NULL)
	{
		auxBook = (Book*)element;
		BOOK_getEditorialId(auxBook, &elementEditorialId);

		if(minotauroEditorialId == elementEditorialId)
		{
			state = 1;
		}
	}

	return state;
}

int EDIBOOKPRICE_criterio(void *element)
{
	int state;
	Book* auxBook;
	int elementEditorialId;
	float elementPrice;
	int idPlaneta;
	int idSiglo;
	float precioFinal;

	auxBook = NULL;
	idPlaneta = 1;
	idSiglo = 2;
	state = -1;
	precioFinal = 0;

	auxBook = (Book*)element;
	BOOK_getEditorialId(auxBook, &elementEditorialId);
	BOOK_getPrice(auxBook, &elementPrice);

	if(elementEditorialId == idPlaneta && elementPrice > 299)
	{
		precioFinal = elementPrice - (elementPrice * 0.2);
		BOOK_setPrice(auxBook, precioFinal);
		state = 0;
	}
	else
	{
		if(elementEditorialId == idSiglo && elementPrice < 201)
		{
			precioFinal = elementPrice - (elementPrice * 0.1);
			BOOK_setPrice(auxBook, precioFinal);
			state = 0;
		}
	}

	return state;
}



