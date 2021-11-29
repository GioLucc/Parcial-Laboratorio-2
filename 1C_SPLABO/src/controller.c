/*
 * controller.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#include "Controller.h"

/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief Abre un archivo que le llega por parametros y procede a parsearlo llamando a parser_BooksFromText y despues cerrarlo.
///
/// @param path
/// @param pArrayList
/// @return -1 si no se pudo abrir el archivo en cuestion o 0 si se pudo.
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	FILE* auxFile;
	int state;

	state = -1;

	auxFile = fopen(path,"r");

	if(auxFile != NULL)
	{
		parser_BooksFromText(auxFile, pArrayList);
		state = 0;

		fclose(auxFile);
	}

	return state;
}

/// @fn int controller_loadFromTextEditorials(char*, LinkedList*)
/// @brief Abre un archivo que le llega por parametros y procede a parsearlo llamando a parser_EditorialsFromText y despues cerrarlo.
///
/// @param path
/// @param pArrayList
/// @return -1 si no se pudo abrir el archivo en cuestion o 0 si se pudo.
int controller_loadFromTextEditorials(char* path, LinkedList* pArrayList)
{
	int state;
	FILE* auxFile;

	state = -1;

	auxFile = fopen(path,"r");

	if(auxFile != NULL)
	{
		parser_EditorialsFromText(auxFile, pArrayList);
		state = 0;
	}

	fclose(auxFile);

	return state;
}

/// @fn int controller_sortBookAuthors(LinkedList*)
/// @brief presenta las posibilidades de ordenamiento de los vectores ya sea autores de mayor a menor o viceversa.
///
/// @param pArrayListBooks
/// @return -1 si no se pudo ordenar, y 0 si se pudo ordenar satisfactoriamente.
int controller_sortBookAuthors(LinkedList* pArrayListBooks)
{
	int state;
	int menuOption;

	state = -1;

	if(pArrayListBooks != NULL)
	{
		menuOption = getValidInt("\n\nComo le gustaria ordenar los autores de los libros?\n\t\t "
				"1 -> (Autores [Mayor] Ascendentes) || 2 -> (Autores [Mayor]  Descendentes) \n\t\t",
				"\n\nERROR - (Ingrese una opcion correcta) - ERROR", 1, 2);

		switch (menuOption) {
			case 1:
				ll_sort(pArrayListBooks, BOOK_compareByAuthors, 1);
				printf("Se han ordenado los empleados satisfactoriamente");

			break;

			default:
				ll_sort(pArrayListBooks, BOOK_compareByAuthors, 0);
				printf("Se han ordenado los empleados satisfactoriamente");
			break;
		}
		state = 0;
	}

	return state;
}

/// @fn int controller_saveAsText(char*, LinkedList*, LinkedList*)
/// @brief Abre el path en metodo de escritura se lo asigna a un puntero a File para despues poder, llama al parser y escribe lo que haya dentro de pArrayListMinotauroBooks
///
/// @param path
/// @param pArrayListMinotauroBooks
/// @param pArrayListEditorialsList
/// @return -1 si no se pudo escribir el archivo en cuestion o 0 si se pudo hacer.
int controller_saveAsText(char* path , LinkedList* pArrayListMinotauroBooks, LinkedList* pArrayListEditorialsList)
{
	int state;
	FILE* pFile;

	state = -1;

	if(path != NULL && pArrayListMinotauroBooks != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_ToSaveAsText(pFile, pArrayListMinotauroBooks,pArrayListEditorialsList);
			state = 0;
		}
			fclose(pFile);
	}

	return state;
}

/// @fn int controller_displayBooksAndEditorialsLists(LinkedList*, LinkedList*)
/// @brief Muestra ambas listas con sus datos hata el momento.
///
/// @param booksList
/// @param editorialsList
/// @return -1 si no se pudieron mostrar, 0 si se pudieron mostrar.
int controller_displayBooksAndEditorialsLists(LinkedList* booksList, LinkedList* editorialsList)
{
	int state;
	state = -1;

	if(booksList != NULL && editorialsList != NULL)
	{
 	   BOOK_showListOfBooks(booksList,editorialsList);
 	   EDI_showListOfEditorials(editorialsList);
 	   state = 0;
	}

	return state;
}

/// @fn int controller_MinotauroFilter(LinkedList*, LinkedList*, LinkedList*)
/// @brief Llama a el filtro, le pasa la funcion criterio y devuelve la nueva LinkedList con dichos elementos, y luego llama a parser para guardarlos y copiarlos en el archivo.
///
/// @param minotaurosBookList
/// @param booksList
/// @param editorialsList
/// @return
int controller_MinotauroFilter (LinkedList* booksList, LinkedList* editorialsList)
{
	int state;
	LinkedList* minotaurosBookList;

	state = -1;

	if(booksList != NULL && editorialsList != NULL)
	{
	  minotaurosBookList = ll_filter(booksList,EDI_criterio);
	  if(minotaurosBookList != NULL)
	  {
		  BOOK_showListOfMinotaurosBook(minotaurosBookList, editorialsList);
		  controller_saveAsText("LibrosEditorialMinotauro.csv", minotaurosBookList, editorialsList);
	  }
	  state = 0;
	}

	return state;
}

/// @fn int controller_saveAsTextMappeo(char*, LinkedList*, LinkedList*)
/// @brief Abre el path en metodo de escritura se lo asigna a un puntero a File para despues poder, llama al parser y escribe lo que haya dentro de pArrayListBooks
///
/// @param path
/// @param pArrayListMinotauroBooks
/// @param pArrayListEditorialsList
/// @return -1 si no se pudo escribir el archivo en cuestion o 0 si se pudo hacer.
int controller_saveAsTextMappeo(char* path , LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList)
{
	int state;
	FILE* pFile;

	state = -1;

	if(path != NULL && pArrayListBooks != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_ToSaveAsTextMapper(pFile, pArrayListBooks,pArrayListEditorialsList);
			state = 0;
		}
			fclose(pFile);
	}

	return state;
}
/// @fn int controller_callMappeado(LinkedList*, LinkedList*)
/// @brief
///
/// @param pArrayListBooks
/// @param pArrayListEditorialsList
/// @return
int controller_callMappeado(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorialsList)
{
	int state;

	state = -1;

	if(pArrayListBooks != NULL && pArrayListEditorialsList != NULL)
	{
		 ll_map(pArrayListBooks, EDIBOOKPRICE_criterio);
		 controller_saveAsTextMappeo("mapeado.csv", pArrayListBooks, pArrayListEditorialsList);
		 state = 0;
	}

	return state;
}



