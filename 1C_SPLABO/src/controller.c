/*
 * controller.c
 *
 *  Created on: 26 nov. 2021
 *      Author: giova
 */

#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayList, int fileType)
{
	FILE* auxFile;
	int state;

	state = -1;

	auxFile = fopen(path,"r");

	if(auxFile != NULL)
	{
		if(fileType == 1)
		{
			parser_BooksFromText(auxFile, pArrayList);
				state = 0;
		}
		else
		{
			parser_EditorialsFromText(auxFile, pArrayList);
			printf("ENTRE al parser editoriales");
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

int controller_sortBookAuthors(LinkedList* pArrayListBooks)
{
	int state;
	int menuOption;

	state = -1;

	if(pArrayListBooks != NULL)
	{
		menuOption = getValidInt("\n\nComo le gustaria ordenar los autores de los libros?\n\t\t "
				"1 -> (Autores [Mayor] Ascendentes) || 2 -> (Sueldos [Mayor]  Descendentes) \n\t\t",
				"\n\nERROR - (Ingrese una opcion correcta) - ERROR", 1, 2);

		switch (menuOption) {
			case 1:
				ll_sort(pArrayListBooks, BOOK_compareByAuthors, 1);
				printf("Se han ordenado los empleados satisfactoriamente");

			break;

			default:
				ll_sort(pArrayListBooks, BOOK_compareByAuthors, 0);
				printf("Se han ordenado los empleados satisfactoriamente");
			break;
		}

	}

	return state;
}

