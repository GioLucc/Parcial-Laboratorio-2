/*
 * controller.h
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "BasicFunctions.h"
#include "Book.h"
#include "Editorial.h"
#include "LinkedList.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayList, int fileType);
int controller_firstObligatoryLoad(int* verification);
int controller_sortBookAuthors(LinkedList* pArrayListBooks);
int controller_saveAsText(char* path , LinkedList* pArrayListMinotauroBooks, LinkedList* pArrayListEditorialsList);



#endif /* CONTROLLER_H_ */
