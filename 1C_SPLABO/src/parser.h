/*
 * parser.h
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Book.h"

int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks);
int parser_EditorialsFromText(FILE* pFile , LinkedList* pArrayListEditorials);
int parser_ToSaveAsText(FILE* pFile , LinkedList* pArrayListMinotauroBooks,LinkedList* pArrayListEditorials);
int parser_ToSaveAsTextMapper(FILE* pFile , LinkedList* pArrayListBooks, LinkedList* pArrayListEditorials);





#endif /* PARSER_H_ */

