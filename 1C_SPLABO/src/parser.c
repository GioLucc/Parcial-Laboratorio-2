/*
 * parser.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Book.h"
#include "Editorial.h"
#include "parser.h"

/// @fn int parser_BooksFromText(FILE*, LinkedList*)
/// @brief Lee el archivo hasta el final guardando todos los datos en variables que despues el BOOK_newCharge las castee y las guarde dentro de la LinkedList
///
/// @param pFile
/// @param pArrayListBooks
/// @return -1 si no se pudo realizar o 0 si se pudo.
int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks)
{
	Book* booksCharger;
	int state;
	char idAux[MAX_CHAR];
	char titleAux[MAX_CHAR];
	char authorAux[MAX_CHAR];
	char priceAux[MAX_CHAR];
	char editorialId[MAX_CHAR];
	int readCounter;

	state = -1;

	readCounter = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idAux,titleAux,authorAux,priceAux);

	while(!feof(pFile))
	{
		readCounter = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]",idAux,titleAux,authorAux,priceAux,editorialId);

		if(readCounter == 5)
		{
			booksCharger = BOOK_newCharge(idAux, titleAux, authorAux, priceAux,editorialId);
			if(booksCharger != NULL)
			{
				ll_add(pArrayListBooks, booksCharger);
				state = 0;
			}
		}
	}

	return state;
}
/// @fn int parser_EditorialsFromText(FILE*, LinkedList*)
/// @brief Lee el archivo hasta el final guardando todos los datos en variables que despues el EDI_newCharge las castee y las guarde dentro de la LinkedList
///
/// @param pFile
/// @param pArrayListBooks
/// @return -1 si no se pudo realizar o 0 si se pudo.
int parser_EditorialsFromText(FILE* pFile , LinkedList* pArrayListEditorials)
{
	Editorial* editorialCharger;
	int state;
	char idAux[MAX_CHAR];
	char editorialAux[MAX_CHAR];
	int readCounter;

	state = -1;

	readCounter = fscanf(pFile,"%[^,],%[^\n]",idAux,editorialAux);

	while(!feof(pFile))
	{
		readCounter = fscanf(pFile,"%[^,],%[^\n]",idAux,editorialAux);


		if(readCounter == 2)
		{
			editorialCharger = EDI_newCharge(idAux,editorialAux);
			if(editorialCharger != NULL)
			{
				ll_add(pArrayListEditorials, editorialCharger);
				state = 0;
			}
		}
	}

	return state;
}

/// @fn int parser_ToSaveAsText(FILE*, LinkedList*, LinkedList*)
/// @brief Escribe el archivo Minotauro books por tantos elementos haya en la LinkedList del mismo
///
/// @param pFile
/// @param pArrayListMinotauroBooks
/// @param pArrayListEditorials
/// @return -1 si no se pudo realizar o 0 si se pudo.
int parser_ToSaveAsText(FILE* pFile , LinkedList* pArrayListMinotauroBooks,LinkedList* pArrayListEditorials)
{
	Book* auxMinotauroBooks;
	Editorial* editorialBookstring;
	int state;
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	float price;
	int editorialId;
	char editorialName[CHAR_MAX];

	state = -1;

	if(pFile != NULL && pArrayListMinotauroBooks != NULL)
	{
		fprintf(pFile,"Id,Title,Author,Price,EditorialName\n");
		for(int i = 0; i < ll_len(pArrayListMinotauroBooks); i++)
		{
			state = 0;
			auxMinotauroBooks = ll_get(pArrayListMinotauroBooks, i);
			BOOK_getId(auxMinotauroBooks, &id);
			BOOK_getTitle(auxMinotauroBooks, title);
			BOOK_getAuthor(auxMinotauroBooks, author);
			BOOK_getPrice(auxMinotauroBooks, &price);
			BOOK_getEditorialId(auxMinotauroBooks, &editorialId);
			editorialBookstring = bringEditorials(pArrayListEditorials, editorialId);
			EDI_getEditorialName(editorialBookstring, editorialName);

			fprintf(pFile,"%d,%s,%s,%.2f,%s\n",id,title,author,price,editorialName);
		}
	}

	return state;
}

/// @fn int parser_ToSaveAsTextMapper(FILE*, LinkedList*, LinkedList*)
/// @brief Escribe el archivo Mappeado por tantos elementos haya en la LinkedList de pArrayListBooks.
///
/// @param pFile
/// @param pArrayListBooks
/// @param pArrayListEditorials
/// @return -1 si no se pudo realizar o 0 si se pudo.
int parser_ToSaveAsTextMapper(FILE* pFile , LinkedList* pArrayListBooks,LinkedList* pArrayListEditorials)
{
		Book* auxBooks;
		Editorial* editorialBookstring;
		int state;
		int id;
		char title [MAX_CHAR];
		char author [MAX_CHAR];
		float price;
		int editorialId;
		char editorialName[CHAR_MAX];

		state = -1;

		if(pFile != NULL && pArrayListBooks != NULL)
		{
			fprintf(pFile,"Id,Title,Author,Price,EditorialName\n");

			for(int i = 0; i < ll_len(pArrayListBooks); i++)
			{
				state = 0;

				auxBooks = ll_get(pArrayListBooks, i);
				BOOK_getId(auxBooks, &id);
				BOOK_getTitle(auxBooks, title);
				BOOK_getAuthor(auxBooks, author);
				BOOK_getPrice(auxBooks, &price);
				BOOK_getEditorialId(auxBooks, &editorialId);
				editorialBookstring = bringEditorials(pArrayListEditorials, editorialId);
				EDI_getEditorialName(editorialBookstring, editorialName);

				fprintf(pFile,"%d,%s,%s,%.2f,%s\n",id,title,author,price,editorialName);
			}
		}

		return state;
}
