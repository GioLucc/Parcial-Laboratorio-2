/*
 * BasicFunctions.c
 *
 *  Created on: 19 oct. 2021
 *      Author: giova
 */

#include "BasicFunctions.h"

void printMenu(void)
{

	printf("\n\n\n\t\t\t================================================================================================\n");
	printf("\t\t\t\t\t\t\t\tWelcome to the Data Base\n");
	printf("\t\t\t\t\t\t\t\t\tDalaran\n");
	printf("\t\t\t================================================================================================\n\t\t\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t               ( V ) Menu de Opciones ( V )\t\t\t\t  \n\n");
	printf("\t\t\t> 1 - Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro. - 1 <\n\n");
	printf("\t\t   > 2 - Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial. - 2 <\n\n");
	printf("\t> 3 - Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente. - 3 <\n\n");
	printf("\t\t\t\t\t    > 4 - Imprimir por pantalla todos los datos de los libros. - 4 <\n\n");
	printf("\t    > 5 - Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList. - 5 <\n\n");
	printf("\t\t\t\t    > 6 - Generar el archivo de salida “mapeado.csv” luego de aplicar la función map. - 6 <\n\n");
	printf("\t\t\t\t\t\t\t               > 7 - Salir - 7 <\n");
}

int getValidInt(char mensaje [], char error [], int min, int max)
{
	char integrer[MAX];
	int validIntegrer;

	validIntegrer = OnlyIntegrersValidation(integrer,error,mensaje, min, max);

	return validIntegrer;

}

int OnlyIntegrersValidation(char integrer [],char error [], char mensaje[], int min, int max)
{
	int resultado = 0;
	int valido;
	do
	{
		valido = 1;
		printf ("%s",mensaje);
		scanf ("%s", integrer);

	/*	for(char* ptr = integrer; *ptr != 0; ptr++)
		{
			if (!isdigit(*ptr))
			{

			}
		}
*/
		while(valido == 0)
		{
			char *ptr;

			ptr = integrer;

			if(!isdigit(*ptr))
			printf("\n\n\t\t\t\t\t    ERROR - (Has ingresado %s y solo se aceptan numeros) - ERROR\n", integrer);
			valido = 0;
		}


		if (valido == 1)
		{
			resultado = atof(integrer);
			if (resultado < min || resultado > max)
			{
				valido = 0;
			}

			if(valido == 0)
			{
				printf("%s", error);
			}
		}
	} while (!valido);

	return resultado;
}

int getString(char mensaje[],char str[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]s", str);

    return 1;
}

int OnlyCharacterValidation(char str[])
{
   int i=0;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int askForAdress (char message[], char str[])
{
    printf("%s",message);
    fflush(stdin);
    scanf("%[^\n]s",str);

    return 1;
}

int getStringVerificado(char mensaje[], char mensajeError[], char *input)
{
    int retorno = -1;
    char aux[256];

    getString(mensaje, aux);

    while (retorno == -1)
    {
        if (OnlyCharacterValidation(aux) == 0)
        {
            getString(mensajeError, aux);
        }
        else
        {
            retorno = 0;
            strcpy(input, aux);
        }
    }
    return retorno;
}
