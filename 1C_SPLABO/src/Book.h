/*
 * eLibro.h
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#ifndef BOOK_H_
#define BOOK_H_
#define MAX_CHAR 100
#include "BasicFunctions.h"
#include "LinkedList.h"

struct
{
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	float price;
	int editorialId;

}typedef Book;

Book* BOOK_new();
Book* BOOK_newCharge(char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editorialStr);
void BOOK_delete(Book* this);
int BOOK_setId(Book* this, int id);
int BOOK_setTitle(Book* this, char* title);
int BOOK_setAuthor(Book* this, char* author);
int BOOK_setPrice(Book* this, float price);
int BOOK_setEditorialId(Book* this, int editorialId);
int BOOK_getId(Book* this, int *id);
int BOOK_getTitle(Book* this, char *title);
int BOOK_getAuthor(Book* this, char *author);
int BOOK_getPrice(Book* this, float *price);
int BOOK_getEditorialId(Book* this, int *editorialId);
int BOOK_showOneBook(Book* this, LinkedList* pArrayListEditorials);
int BOOK_showListOfBooks(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials);
int BOOK_compareByAuthors(void* element1, void* element2);
int BOOK_showOneMinotauroBook(Book* this,LinkedList* pArrayListEditorials);
int BOOK_showListOfMinotaurosBook(LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials);

















#endif /* BOOK_H_ */
