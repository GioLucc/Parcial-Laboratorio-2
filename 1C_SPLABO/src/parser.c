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
#include "parser.h"


int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks)
{
	Book* booksCharger;
	int state;
	char idAux[MAX_CHAR];
	char titleAux[MAX_CHAR];
	char authorAux[MAX_CHAR];
	char priceAux[MAX_CHAR];
	int readCounter;

	state = -1;

	readCounter = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idAux,titleAux,authorAux,priceAux);

	while(!feof(pFile))
	{
		readCounter = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idAux,titleAux,authorAux,priceAux);

		if(readCounter == 4)
		{
			booksCharger = BOOK_newCharge(idAux, titleAux, authorAux, priceAux);
			if(booksCharger != NULL)
			{
				ll_add(pArrayListBooks, booksCharger);
				state = 0;
			}
		}
	}

	return state;
}
