/*
 * cliente.c
 *
 *  Created on: 15 may. 2020
 *      Author: Agus
 */
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "prestamo.h"

int devolverCuil(eCliente list[],int len, int id, char cuil[])
{
	int ret = 0;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].idCliente == id)
			{
				strcpy(cuil,list[i].cuil);
				break;
				ret = 1;
			}
		}
	}
	return ret;
}

int inicializarClientes(eCliente list[],int len)
{
	int ret = -1;
	if(list != NULL && len > 0)
	{
		ret = 0;
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return ret;
}

int imprimirClientes(eCliente list[], int length)
{
	int flag = 0;
	system("cls");
	printf("***Clientes lista***\n");

	printf("Nombre       Apellido       cuil                ID           isEmpty\n");
	for(int i = 0; i<length;i++)
		{
			if(list[i].isEmpty == 0)
			{
				imprimirCliente(list[i]);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			system("cls");
			printf("\n---No hay clientes para mostrar---\n");
			system("pause");
		}
	printf("\n\n");
	return 0;
}

void imprimirCliente(eCliente list)
{
	printf("%s     %s      %s          %d                  %d\n", list.nombre,list.apellido,list.cuil, list.idCliente,list.isEmpty);
}

int altaCliente(eCliente array[], int tam, int* idCliente) {
	int retorno = 0;

	if (tam > 0 && array != NULL) {
		int indice;

		system("cls");
		printf("***Alta cliente****\n\n");

		indice = buscarClienteLibre(array, tam);

		if (indice == -1) {
			printf("\nNo hay espacios para dar de alta.\n");
		} else {
			(*idCliente)++;
			array[indice].idCliente=*idCliente;
			array[indice].isEmpty=0;
			fflush(stdin);
			utn_getName("Ingrese el nombre: \n", "ERROR: NOMBRE INCORRECTO\n",
					1, 51, 2, array[indice].nombre);
			fflush(stdin);
			utn_getName("Ingrese el apellido: \n",
					"ERROR: APELLIDO INCORRECTO\n", 1, 51, 2, array[indice].apellido);
			fflush(stdin);
			utn_getTexto("Ingrese el cuil: \n", "Error, cuil invalido.\n", 11, 14,
					2, array[indice].cuil);

			retorno = 1;
		}
	}

	return retorno;
}

int buscarClienteLibre(eCliente array[], int tam)
{
	int index;
	for (int i = 0; i < tam; i++)
	{
		if (array[i].isEmpty == 1)
		{
			index = i;
			break;
		}
	}
	return index;
}


int modificarCliente(eCliente array[], int tam)
{
	int retorno = -1;
	int idAModificar;
	int indice;
	int opcion;
	char nombre[30];
	char apellido[30];
	char cuil[13];
	if(array != NULL && tam > 0)
	{
		system("cls");
		printf("***Modificar Cliente***\n");

		imprimirClientes(array, tam);

		utn_getNumero(&idAModificar, "Ingrese el id del cliente a modificar\n",
					"ERROR:ID ERRONEO", 0, 10000, 2);

		indice = buscarCliente(array, tam, idAModificar);
		if (indice == -1)
		{
			printf("\nNo tenemos a un cliente registrado con ese ID.\n");
			system("pause");
		}else
		{
			printf("Modificar\n\n");
			printf("1-Nombre\n");
			printf("2-Apellido\n");
			printf("3-Cuil\n");

			utn_getNumero(&opcion, "Que opcion desea modificar?\n", "Error: opcion erronea", 1,3,2);

			if(opcion == 1)
			{
				utn_getName("Ingrese el nombre: \n", "ERROR: NOMBRE INCORRECTO\n",0, 30, 2, nombre);
				strcpy(array[indice].nombre, nombre);
				printf("\nSe actualizo el nombre del cliente.\n");
				retorno = 1;
			}
			else if(opcion == 2)
			{
				utn_getName("Ingrese el apellido: \n", "ERROR: APELLIDO INCORRECTO\n",0, 30, 2, apellido);
				strcpy(array[indice].apellido, apellido);
				printf("\nSe actualizo el apellido del cliente.\n");
				retorno = 1;
			}else if(opcion == 3)
			{
				utn_getTexto("Ingrese el cuil: \n","ERROR: INGRESE UN CUIL VALIDO\n", 11, 14, 2, cuil);
				strcpy(array[indice].cuil, cuil);
				printf("Se actualizo el cuil del cliente.\n");
				retorno = 1;
			}
			else
			{
				printf("Opcion invalida.\n");
			}
			system("pause");
		}
	}
	return retorno;
}

int buscarCliente(eCliente array[], int tam, int id) {
	int indice = -1;
	int i;
	if (array != NULL && tam > 0 && id >= 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].isEmpty == 0 && array[i].idCliente == id) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int clienteCargado(eCliente list[],int len)
{
	int ret = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				ret = 0;
			}
		}
	}
	return ret;
}

