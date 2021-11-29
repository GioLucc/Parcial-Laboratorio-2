/*
 * eLibro.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#include "Book.h"
#include "Controller.h"

/// @fn Book BOOK_new*()
/// @brief Crea espacio en memoria dinamica para el nuevo libro.
///
/// @return El espacio de memoria asignado para poder empezar a trabajar.
Book* BOOK_new()
{
	Book* newBook;

	newBook = (Book*) calloc(1,sizeof(Book)); // Consigue espacio mediante memoria dinamica para la estructura empleado

	return newBook;
}

/// @fn Book BOOK_newCharge*(char*, char*, char*, char*, char*)
/// @brief Recibe todos los datos en tipo string que contiene el archivo para meterlos dentro de la LinkedList.
///
/// @param idStr
/// @param titleStr
/// @param authorStr
/// @param priceStr
/// @param editorialStr
/// @return un puntero a book ya cargado para usarlo o agregarlo a la LinkedList.
Book* BOOK_newCharge(char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editorialStr)
{
	Book* newBook;

	newBook = BOOK_new();

	int id;
	char title[MAX_CHAR];
	char author[MAX_CHAR];
	float price;
	int editorialId;

	id = atoi(idStr);
	strcpy(title,titleStr);
	strcpy(author,authorStr);
	price = atoi(priceStr);
	editorialId = atoi(editorialStr);

	BOOK_setId(newBook, id);
	BOOK_setTitle(newBook, title);
	BOOK_setAuthor(newBook, author);
	BOOK_setPrice(newBook, price);
	BOOK_setEditorialId(newBook,editorialId);

	return newBook;
}

/// @fn void BOOK_delete(Book*)
/// @brief Libera el espacio de memoria del dato pasado por parametros.
///
/// @param this
void BOOK_delete(Book* this)
{
	free(this);
}

/// @fn int BOOK_setId(Book*, int)
/// @brief Toma el dato que le llega por parametros y se lo asigna a this.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_setId(Book* this, int id)
{
	int state;

	state = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		state = 0;
	}

	return state;
}

/// @fn int BOOK_setId(Book*, char*)
/// @brief Toma el dato que le llega por parametros y se lo asigna a this.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_setTitle(Book* this, char* title)
{
	int state;

	state = -1;

	if(this != NULL && title != NULL)
	{
		strcpy(this->title, title);
		state = 0;
	}

	return state;
}

/// @fn int BOOK_setAuthor(Book*, char*)
/// @brief Toma el dato que le llega por parametros y se lo asigna a this.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_setAuthor(Book* this, char* author)
{
	int state;

	state = -1;

	if(this != NULL && author != NULL)
	{
		strcpy(this->author, author);
		state = 0;
	}

	return state;
}

/// @fn int BOOK_setPrice(Book*, float)
/// @brief Toma el dato que le llega por parametros y se lo asigna a this.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_setPrice(Book* this, float price)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		this->price = price;
		state = 0;
	}

	return state;
}

/// @fn int BOOK_setEditorialId(Book*, int)
/// @brief Toma el dato que le llega por parametros y se lo asigna a this.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_setEditorialId(Book* this, int editorialId)
{
	int state;

	state = -1;

	if(this != NULL && editorialId > 0)
	{
		this->editorialId = editorialId;
		state = 0;
	}

	return state;
}

/// @fn int BOOK_getId(Book*, int*)
/// @brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_getId(Book* this, int *id)
{
	int state;

	state = -1;

	if(this != NULL && id != NULL)
	{
		*id = this-> id;
	}

	return state;
}

/// @fn int BOOK_getTitle(Book*, char*)
/// @brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_getTitle(Book* this, char *title)
{
	int state;

	state = -1;

	if(this != NULL && title != NULL)
	{
		strcpy(title, this->title);
		state = 0;
	}

	return state;
}

/// @fn int BOOK_getAuthor(Book*, char*)
/// @brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_getAuthor(Book* this, char *author)
{
	int state;

	state = -1;

	if(this != NULL && author != NULL)
	{
		strcpy(author, this->author);
	}

	return state;
}

/// @fn int BOOK_getPrice(Book*, int*)
/// @brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_getPrice(Book* this, float *price)
{
	int state;

	state = -1;

	if(this != NULL && price != NULL)
	{
		*price = this->price;
	}

	return state;
}

/// @fn int BOOK_getEditorialId(Book*, int*)
/// @brief Guarda lo que tenga el this dentro del tipo de dato, pasado por parametros.
///
/// @param this
/// @param id
/// @return -1 si se no pudo hacer correctamente, 0 si pudo asignarse correctamente.
int BOOK_getEditorialId(Book* this, int *editorialId)
{
	int state;

	state = -1;

	if(this != NULL && editorialId != NULL)
	{
		*editorialId = this->editorialId;
	}

	return state;
}

/// @fn int BOOK_showOneBook(Book*, LinkedList*)
/// @brief Obtiene cada uno de los campos de this mediante los geters en esa posición para poder printearlos.
///
/// @param this
/// @param pArrayListEditorials
/// @return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int BOOK_showOneBook(Book* this, LinkedList* pArrayListEditorials)
{
	int state;
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	float price;
	int editorialId;
	char editorial[MAX_CHAR];
	Editorial* editorialName;

	state = -1;

	if(this != NULL)
	{
		BOOK_getId(this, &id);
		BOOK_getTitle(this, title);
		BOOK_getAuthor(this, author);
		BOOK_getPrice(this, &price);
		BOOK_getEditorialId(this, &editorialId);
		editorialName = bringEditorials(pArrayListEditorials, editorialId);
		EDI_getEditorialName(editorialName, editorial);

		printf("\t\t\t|%4d  |%30s   | %22s         |   %9.2f  |    %18s   |\n",id,title,author,price,editorial);
		state = 0;
	}

	return state;
}

/// @fn int BOOK_showListOfBooks(LinkedList*, LinkedList*)
/// @brief Recorre la cantidad de elementos que hayan sido cargados en pArrayListBooks y llama a showOneBook para printear cada uno.
///
/// @param pArrayListBooks
/// @param pArrayListEditorials
/// @return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int BOOK_showListOfBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials)
{
	Book* aux;
	int state;
	int booksQty;

	state = -1;

	if(pArrayListBooks != NULL)
	{
		booksQty = ll_len(pArrayListBooks);

		printf("\n\n\t\t\t|  ID  |              Title              |             Author             |    Price     |         Editorial       |\n");
		printf("\t\t\t|______|_________________________________|________________________________|______________|_________________________|\n");

		for(int i = 0; i < booksQty; i++)
		{
			aux = ll_get(pArrayListBooks, i);

			BOOK_showOneBook(aux,pArrayListEditorials);
		}
		state = 0;
	}

	return state;
}

/// @fn int BOOK_compareByAuthors(void*, void*)
/// @brief Criterio de ordenamiento para los autores segun lo que devuelva el strcmpi.
///
/// @param element1
/// @param element2
/// @return El criterio que debe ser llevado a cabo 0, 1.
int BOOK_compareByAuthors(void* element1, void* element2)
{
	Book* bookOne;
	Book* bookTwo;
	int criterio;
	char author1[MAX_CHAR];
	char author2[MAX_CHAR];

	if(element1 != NULL && element2 != NULL)
	{
		bookOne = (Book*) element1;
		bookTwo = (Book*) element2;

		BOOK_getAuthor(bookOne, author1);

		BOOK_getAuthor(bookTwo, author2);

		criterio = strcmpi(author1,author2);
	}

	return criterio;
}

/// @fn int BOOK_showOneMinotauroBook(Book*, LinkedList*)
/// @brief Obtiene cada uno de los campos de this mediante los geters en esa posición para poder printearlos.
///
/// @param this
/// @param pArrayListEditorials
/// @return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int BOOK_showOneMinotauroBook(Book* this,LinkedList* pArrayListEditorials)
{
	Editorial* editorialName;
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	float price;
	int editorialId;
	char editorial[MAX_CHAR];
	int state;

	state = -1;

	BOOK_getId(this, &id);
	BOOK_getTitle(this, title);
	BOOK_getAuthor(this, author);
	BOOK_getPrice(this, &price);
	BOOK_getEditorialId(this, &editorialId);
	editorialName = bringEditorials(pArrayListEditorials, editorialId);
	EDI_getEditorialName(editorialName, editorial);

	printf("\t\t\t|%4d  |%30s   | %22s         |   %9.2f  |    %18s   |\n",id,title,author,price,editorial);

	state = -1;

	return state;
}

/// @fn int BOOK_showListOfBooks(LinkedList*, LinkedList*)
/// @brief Recorre la cantidad de elementos que hayan sido cargados en pArrayListBooks y llama a showOneMinotauroBook para printear cada uno.
///
/// @param pArrayListBooks
/// @param pArrayListEditorials
/// @return -1 si se no pudo hacer correctamente, 0 si pudo correctamente.
int BOOK_showListOfMinotaurosBook(LinkedList* minotaurosBooks, LinkedList* pArrayListEditorials)
{
	Book* aux;
	int state;
	int booksQty;

	state = -1;

	if(minotaurosBooks != NULL)
	{
		booksQty = ll_len(minotaurosBooks);

		printf("\n\n\t\t\t|  ID  |              Title              |             Author             |    Price     |         Editorial       |\n");
		printf("\t\t\t|______|_________________________________|________________________________|______________|_________________________|\n");

		for(int i = 0; i < booksQty; i++)
		{
			aux = ll_get(minotaurosBooks, i);

			BOOK_showOneMinotauroBook(aux,pArrayListEditorials);
		}
		state = 0;
	}

	return state;
}
