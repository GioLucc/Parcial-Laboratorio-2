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

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_firstObligatoryLoad(int* verification);

#endif /* CONTROLLER_H_ */
