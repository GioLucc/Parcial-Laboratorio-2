/*
 * controller.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBooks)
{
	FILE* auxFile;
	int state;

	state = -1;

	auxFile = fopen(path,"r");

	if(auxFile != NULL)
	{
		if(!parser_BooksFromText(auxFile, pArrayListBooks))
		{
			state = 0;
		}

		fclose(auxFile);
	}

	return state;
}

int controller_firstObligatoryLoad(int* verification)
{
	if(*verification == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



