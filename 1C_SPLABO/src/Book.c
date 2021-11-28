/*
 * eLibro.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#include "Book.h"
#include "Controller.h"

Book* BOOK_new()
{
	Book* newBook;

	newBook = (Book*) calloc(1,sizeof(Book)); // Consigue espacio mediante memoria dinamica para la estructura empleado

	return newBook;
}

Book* BOOK_newCharge(char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editorialStr)
{
	Book* newBook;

	newBook = BOOK_new();

	int id;
	char title[MAX_CHAR];
	char author[MAX_CHAR];
	char price[MAX_CHAR];
	int editorialId;

	id = atoi(idStr);
	strcpy(title,titleStr);
	strcpy(author,authorStr);
	strcpy(price,priceStr);
	editorialId = atoi(editorialStr);

	BOOK_setId(newBook, id);
	BOOK_setTitle(newBook, title);
	BOOK_setAuthor(newBook, author);
	BOOK_setPrice(newBook, price);
	BOOK_setEditorialId(newBook,editorialId);

	return newBook;
}

void BOOK_delete(Book* this)
{
	free(this);
}

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

int BOOK_setPrice(Book* this, char* price)
{
	int state;

	state = -1;

	if(this != NULL)
	{
		strcpy(this->price, price);
		state = 0;
	}

	return state;
}

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

int BOOK_getPrice(Book* this, char *price)
{
	int state;

	state = -1;

	if(this != NULL && price != NULL)
	{
		strcpy(price, this->price);
	}

	return state;
}

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

int BOOK_showOneBook(Book* this, LinkedList* pArrayListEditorials)
{
	int state;
	int id;
	char title [MAX_CHAR];
	char author [MAX_CHAR];
	char price[MAX_CHAR];
	int editorialId;
	char editorial[MAX_CHAR];
	Editorial* editorialName;

	state = -1;

	if(this != NULL)
	{
		BOOK_getId(this, &id);
		BOOK_getTitle(this, title);
		BOOK_getAuthor(this, author);
		BOOK_getPrice(this, price);
		BOOK_getEditorialId(this, &editorialId);
		editorialName = bringEditorials(pArrayListEditorials, editorialId);
		EDI_getEditorialName(editorialName, editorial);

		printf("\t\t\t|%4d  |%30s   | %22s         |   %9s  |    %18s   |\n",id,title,author,price,editorial);
		state = 0;
	}

	return state;
}

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



