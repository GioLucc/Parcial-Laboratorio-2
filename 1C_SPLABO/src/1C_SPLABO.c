/*
 ============================================================================
 Name        : 1C_SPLABO.c
 Author      : Giovanni Lucchetta
 Version     :
 Copyright   : Tano™

Parte 1

Desarrollar en ANSI C:
Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
Detalle de la función “ll_filter()”
Prototipo de la función:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
agregará a la misma los ítems correspondientes y la devolverá.

Datos:
eLibro:
• id
• titulo
• autor
• precio
• idEditorial
eEditorial:
• idEditorial
• nombre
Las editoriales con las que trabajaremos son las siguientes. Deberán generar un archivo csv con
estos datos.
1 - PLANETA
2 - SIGLO XXI EDITORES
3 - PEARSON
4 - MINOTAURO
5 - SALAMANDRA
6 - PENGUIN BOOKS
Los datos de los libros los generarán ustedes. deberán ser los suficientes como para probar las
distintas opciones del menú.
NOTAS:
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.
Nota 1: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Nota 2: Se deberán utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deberán estar en listas separadas, realizando las relaciones
correspondientes entre las entidades.
Nota 4: Utilizar MVC (modelo vista controlador)
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"

int main(void)
{
	setbuf(stdout,NULL);
	LinkedList* booksList = ll_newLinkedList();
	LinkedList* editorialsList = ll_newLinkedList();
	int firstLoadFlag;
	int booksQty;
	int maxTimesCharge;
	int menuOption;
	char fileToChose[MAX_CHAR];
//	char availableFiles[MAX_CHAR]={"Libros.csv"};


    firstLoadFlag = 0;
    maxTimesCharge = 0;

      do
       {
    	booksQty = ll_len(booksList);

       	printMenu();
       	menuOption = getValidInt("\n\n\t\t\t\t\t\t   Ingrese una opcion del menu para realizar del 1 al 10: ",
       	"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 10);

           switch(menuOption)
           {
           	   case 1:
//                 if(firstLoadFlag == 0
//                 && maxTimesCharge == 0)
//   			     {
//                	 getString("\n\n\t\t\t\t\tIngrese el nombre del archivo que quiere abrir (Disponibles {Libros.csv } o :", fileToChose);
//                	 if(strcmp(fileToChose,availableFiles)== 0)
//                	 {
//                		 controller_firstObligatoryLoad(&firstLoadFlag);
						 controller_loadFromText("Libros.csv",booksList,1);
//						 printf("\n\t\t\t\t\t\t\tSe ha cargado la lista satisfactoriamente");
//	   	                 firstLoadFlag = 1;
//	   	                 maxTimesCharge = 1;
//                	 }
//                	 else
//                	 {
//    					 printf("\n\t\t\t\t\t\t\tNo se puede cargar porque no existe!\n"
//    						   "\t\t\t\t\t\t\t   Intente ingresando el nombre de los disponibles nuevamente!");
//                	 }
//				 }
//				 else
//				 {
//					 printf("\n\t\t\t\t\t\t\tNo se puede cargar el archivo mas de una vez!\n"
//						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
//				 }
               break;
           	   case 2:
					 controller_loadFromText("Editoriales.csv",editorialsList,0);
               break;
           	   case 3:
           		   controller_sortBookAuthors(booksList);
               break;
           	   case 4:
//                   if(firstLoadFlag == 1
//                   && maxTimesCharge == 1)
//     			   {
                	   BOOK_showListOfBooks(booksList,editorialsList);
                	   EDI_showListOfEditorials(editorialsList);
//     			   }
//				   else
//				   {
//					   printf("\n\t\t\t\t\t\t\tNo se puede cargar el archivo mas de una vez!\n"
//						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
//				   }
               break;
          }
       }while(menuOption != 6);



	return EXIT_SUCCESS;
}
