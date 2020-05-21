/*
 * prestamo.c
 *
 *  Created on: 16 may. 2020
 *      Author: Agus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "prestamo.h"
#include "cliente.h"

int devuelveCantidadPrestamos(ePrestamo list[],int len, int id, int* cantidad)
{
	int ret = 0;
	int acumulador = 0;
	if(list != NULL && len > 0 && cantidad != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].idCliente == id)
			{
				acumulador++;
			}
		}
		*cantidad = acumulador;
		ret = 1;
	}
	return ret;
}

int devuelveCantidadPrestamosSaldados(ePrestamo list[],int len, int id, int* cantidad)
{
	int ret = 0;
	int acumulador = 0;
	if(list != NULL && len > 0 && cantidad != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == -1 && list[i].idCliente == id)
			{
				acumulador++;
			}
		}
		*cantidad = acumulador;
		ret = 1;
	}
	return ret;
}

int inicializarPrestamo(ePrestamo list[], int len)
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

int buscarPrestamoLibre(ePrestamo array[], int tam)
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

int buscarPrestamo(ePrestamo array[], int tam, int id, int opcion) {
	int indice = -1;
	int i;
	if (array != NULL && tam >= 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].isEmpty == opcion && array[i].idPrestamo == id) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}


int devuelveCantidadPrestamosGeneral(ePrestamo list[],int len, int id, int* cantidad)
{
	int ret = 0;
	int acumulador = 0;
	if(list != NULL && len > 0 && cantidad != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].isEmpty == -1 &&list[i].idCliente == id)
			{
				acumulador++;
			}
		}
		*cantidad = acumulador;
		ret = 1;
	}
	return ret;
}

