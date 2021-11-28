/*
 * eEditorial.h
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#define MAX_CHAR 100

#include "BasicFunctions.h"
#include "LinkedList.h"

struct
{
	int idEditorial;
	char nombre[MAX_CHAR];

}typedef Editorial;

Editorial* EDI_new();
Editorial* EDI_newCharge(char* idStr,char* editorialStr);
int EDI_getId(Editorial* this, int* editorialId);
int EDI_getEditorialName(Editorial* this, char* editorialName);
int EDI_setId(Editorial* this, int editorialId);
int EDI_setEditorialName(Editorial* this, char* editorialName);
int EDI_showOneEditorials(Editorial* this);
int EDI_showListOfEditorials(LinkedList* pArrayListEditorials);
int EDI_showOneEditorials(Editorial* this);
int EDI_showListOfEditorials(LinkedList* pArrayListEditorials);
Editorial* bringEditorials (LinkedList* pArrayListEditorials, int bookEditorialId);





#endif /* EDITORIAL_H_ */
