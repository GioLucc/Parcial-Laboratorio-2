/*
 ============================================================================
 Name        : 1C_SPLABO.c
 Author      : Giovanni Lucchetta
 Version     :
 Copyright   : Tano?

Parte 1

Desarrollar en ANSI C:
Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guard?ndolos en un linkedList de entidades
eLibro.
ACLARACI?N: El nombre del archivo se debe pasar como par?metro por l?nea de
comandos.
2. Leer un archivo con los datos de editoriales, guard?ndolos en un linkedList de entidades
eEditorial.
ACLARACI?N: El nombre del archivo se debe pasar como par?metro por l?nea de
comandos.
3. Ordenar la lista generada en el ?tem anterior, con la funci?n ll_sort, seg?n el criterio de
ordenamiento ?Autor? de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACI?N: Se deber? imprimir la descripci?n de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber? utilizar la
funci?n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
Detalle de la funci?n ?ll_filter()?
Prototipo de la funci?n:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La funci?n ?ll_filter? recibir? una lista y una funci?n criterio ?fn?. Se deber? iterar todos los elementos
de la lista y pasarlos a la funci?n ?fn?. La funci?n ?fn? devolver? 1 si ese ?tem se debe agregar a la
lista resultado o 0 si no debe agregarse. La funci?n ?ll_filter? generar? la nueva lista resultado,
agregar? a la misma los ?tems correspondientes y la devolver?.

Datos:
eLibro:
? id
? titulo
? autor
? precio
? idEditorial
eEditorial:
? idEditorial
? nombre
Las editoriales con las que trabajaremos son las siguientes. Deber?n generar un archivo csv con
estos datos.
1 - PLANETA
2 - SIGLO XXI EDITORES
3 - PEARSON
4 - MINOTAURO
5 - SALAMANDRA
6 - PENGUIN BOOKS
Los datos de los libros los generar?n ustedes. deber?n ser los suficientes como para probar las
distintas opciones del men?.
NOTAS:
Nota 0: El c?digo deber? tener comentarios con la documentaci?n de cada una de las funciones y respetar las
reglas de estilo de la c?tedra.
Nota 1: Se deber? realizar el men? de opciones y las validaciones a trav?s de funciones.
Nota 2: Se deber?n utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deber?n estar en listas separadas, realizando las relaciones
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
	int state;
	int menuOption;
	char nombredeArchivo[MAX_CHAR];


	do
       {

       	printMenu();
       	menuOption = getValidInt("\n\n\t\t\t\t\t\t   Ingrese una opcion del menu para realizar del 1 al 10: ",
       	"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 7);

           switch(menuOption)
           {
           	   case 1:
           		   if(ll_isEmpty(booksList) == 1)
           		   {
           			   getString("\n\n\t\t\t\t\tIngrese el nombre del archivo que quiere abrir (Disponibles {Libros.csv } o :", nombredeArchivo);
           			   state = controller_loadFromText(nombredeArchivo,booksList);

					 if(state == 0)
					 {
						 printf("\n\t\t\t\t\t\t\tSe ha cargado la lista satisfactoriamente");
					 }
					 else
					 {
						 if(state == -1)
						 {
							 printf("\n\t\t\t\t\t\t\tNo se puede cargar porque no existe!\n"
							 "\t\t\t\t\t\t\t   Intente ingresando el nombre de los disponibles nuevamente!");
						 }
						 else
						 {
							 printf("El archivo contiene datos incompatibles");
						 }

					 }
				 }
           		 else
				 {
					 printf("\n\t\t\t\t\t\t\tNo se puede cargar el archivo mas de una vez!\n"
						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
				 }
               break;
           	   case 2:
           		   if(ll_isEmpty(editorialsList) == 1)
           		   {
           			   getString("\n\n\t\t\t\t\tIngrese el nombre del archivo que quiere abrir (Disponibles {Editoriales.csv } o :", nombredeArchivo);
           			   state =  controller_loadFromTextEditorials(nombredeArchivo, editorialsList);

           			   if(state == 0)
           			   {
           				   printf("\n\t\t\t\t\t\t\tSe ha cargado la lista satisfactoriamente");
           			   }
           			   else
           			   {
           				   if(state == -1)
           				   {
           					   printf("\n\t\t\t\t\t\t\tNo se puede cargar porque no existe!\n"
           							   "\t\t\t\t\t\t\t   Intente ingresando el nombre de los disponibles nuevamente!");
           				   }
           				   else
           				   {
           					   printf("El archivo contiene datos incompatibles");
           				   }

           			   }
				  }
           		  else
				  {
           			  printf("\n\t\t\t\t\t\t\tNo se puede cargar el archivo mas de una vez!\n"
						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
				  }
               break;
           	   case 3:
           		   controller_sortBookAuthors(booksList);
               break;
           	   case 4:
                   if(ll_isEmpty(editorialsList) == 0 && ll_isEmpty(booksList) == 0)
    			   {
                	   controller_displayBooksAndEditorialsLists(booksList, editorialsList);
     			   }
				   else
				   {
					   printf("\n\t\t\t\t\t\t\tNo se pueden mostrar los archivos ya que no ha cargado los Libros o Editoriales!\n"
						   "\t\t\t\t\t\t\t   Esto ocasionaria un error en el programa");
				   }
               break;
           	   case 5:
           		   controller_MinotauroFilter(booksList, editorialsList);
           	   break;
           	   case 6:
           		   controller_callMappeado(booksList, editorialsList);
           	   break;
          }
       }while(menuOption != 7);



	return EXIT_SUCCESS;
}
