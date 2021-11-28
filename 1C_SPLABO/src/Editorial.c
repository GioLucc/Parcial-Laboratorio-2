/*
 * eEditorial.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#include "Editorial.h"

Editorial* EDI_new()
{
	Editorial* newEditorial;

	newEditorial = (Editorial*) calloc(1,sizeof(Editorial));

	return newEditorial;
}

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




