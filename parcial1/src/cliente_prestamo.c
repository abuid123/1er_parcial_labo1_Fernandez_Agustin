/*
 * cliente_prestamo.c
 *
 *  Created on: 16 may. 2020
 *      Author: Agus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "prestamo.h"
#include "cliente_prestamo.h"

int bajaDeCliente(eCliente aCliente[], int tamC, ePrestamo aPrestamo[],
		int tamP) {
	int ret = -1;
	int idCliente;
	int indiceCliente;
	char confirmarcion;
	if (aCliente != NULL && tamC > 0 && aPrestamo != NULL && tamP > 0)
	{
		imprimirClientes(aCliente, tamC);
		utn_getNumero(&idCliente, "Ingrese el id que desea eliminar: \n",
				"Error, id invalido", 1, tamC, 3);

		indiceCliente = buscarCliente(aCliente, tamC, idCliente);

		if (indiceCliente == -1) {
			printf("No tenemos un cliente registrado con ese id.\n");
		} else {
			for (int i = 0; i < tamP; i++) {
				if (aPrestamo[i].idCliente == idCliente) {
					printf("Id cliente: %d\n"
							"Id prestamo: %d\n"
							"Importe: %.2f\n"
							"Cantidad Cuotas: %d\n", aPrestamo[i].idCliente,
							aPrestamo[i].idPrestamo, aPrestamo[i].importe,
							aPrestamo[i].cantidadCuotas);
				}
			}

			utn_getCaracter(&confirmarcion,
					"Esta seguro, que queres eliminar el cliente? (s o n)\n",
					"Error,caracter invalido.\n", 'n', 's', 2);
			if (confirmarcion == 's') {
				for (int i = 0; i < tamC; i++) {
					if (aCliente[i].isEmpty== 0 && aCliente[i].idCliente == idCliente) {
						aCliente[i].isEmpty = 1;
					}
				}

				for (int j = 0; j < tamP; j++) {
					if (aPrestamo[j].isEmpty == 0 && aPrestamo[j].idCliente == idCliente) {
						aPrestamo[j].isEmpty = 1;
					}
				}
				ret = 0;
			}else
			{
				printf("Se ha cancelado la eliminacion.\n");
			}

		}
	}
	return ret;
}

int realizarPrestamo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP, int* idPrestamo)
{
	int ret = -1;
	int indicePrestamo;
	int indiceCliente;
	int idCliente;
	if(aCliente != NULL && tamC > 0 && aPrestamo != NULL && tamP > 0 && idPrestamo != NULL)
	{
		indicePrestamo = buscarPrestamoLibre(aPrestamo,tamP);
		if(indicePrestamo == -1)
		{
			printf("No tenemos lugar para mas prestamos.\n");
		}else
		{
			imprimirClientes(aCliente, tamC);
			utn_getNumero(&idCliente, "Ingrese el id del cliente al cual desea agregarle un prestamo: \n",
							"Error, id invalido", 1, tamC, 3);

			indiceCliente = buscarCliente(aCliente, tamC,idCliente);
			if(indiceCliente == -1)
			{
				printf("No tenemos un cliente con ese id.\n");
			}else
			{
				(*idPrestamo)++;
				aPrestamo[indicePrestamo].isEmpty = 0;
				aPrestamo[indicePrestamo].idPrestamo = *idPrestamo;
				aPrestamo[indicePrestamo].idCliente = idCliente;
				utn_getFloat("Ingrese el importe: \n","Error importe invalido.\n",1, 400000, 1, 400000, 2,&aPrestamo[indicePrestamo].importe);
				utn_getNumero(&aPrestamo[indicePrestamo].cantidadCuotas,"Ingrese la cantidad de cuotas: (1 a 12)\n", "Error, cuotas invalidas.\n",1,12,3);

				printf("Importe: %.2f\n"
						"Cantidad cuotas: %d\n"
						"Id prestamo: %d\n"
						"Id cliente: %d\n",aPrestamo[indicePrestamo].importe,aPrestamo[indicePrestamo].cantidadCuotas,aPrestamo[indicePrestamo].idPrestamo,aPrestamo[indicePrestamo].idCliente);


				ret = 0;
			}
		}
	}
	return ret;
}

int saldarPrestamo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int idPrestamo;
	int indicePrestamo;
	int opcion;
	int indiceCliente;
	if(aCliente != NULL &&tamC> 0 && aPrestamo != NULL && tamP > 0)
	{
		mostrarPrestamos(aPrestamo,tamP,aCliente,tamC,0);
		utn_getNumero(&idPrestamo,"\nIngrese el id del prestamo: \n","Error, id incorrecto.\n",1,tamP,3);
		indicePrestamo = buscarPrestamo(aPrestamo,tamP,idPrestamo,0);

		if(indicePrestamo == -1)
		{
			printf("No tenemos un prestamo con ese id.\n");
		}else
		{
			indiceCliente = buscarCliente(aCliente, tamC, aPrestamo[indicePrestamo].idCliente);
			imprimirCliente(aCliente[indiceCliente]);
		}
			utn_getNumero(&opcion, "\nQuiere saldar su prestamo?.\n"
					"1) SI.\n"
					"2) NO.\n", "Error: opcion invalida.\n",1,2,3);

			switch(opcion)
			{
			case 1:
				aPrestamo[indicePrestamo].isEmpty = -1;
				ret = 0;
				break;
			case 2:
				break;
			}
	}
	return ret;
}

int reanudarPrestamo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int idPrestamo;
	int indicePrestamo;
	int opcion;
	int indiceCliente;
	if(aCliente != NULL &&tamC> 0 && aPrestamo != NULL && tamP > 0)
	{
		mostrarPrestamos(aPrestamo,tamP,aCliente,tamC,-1);
		utn_getNumero(&idPrestamo,"Ingrese el id del prestamo: \n","Error, id incorrecto.\n",1,tamP,3);
		indicePrestamo = buscarPrestamo(aPrestamo,tamP,idPrestamo,-1);

		if(indicePrestamo == -1)
		{
			printf("No tenemos un prestamo con ese id.\n");
		}else
		{
			indiceCliente = buscarCliente(aCliente, tamC, aPrestamo[indicePrestamo].idCliente);
			imprimirCliente(aCliente[indiceCliente]);

			utn_getNumero(&opcion, "Quiere reanudar su prestamo?.\n"
					"1) SI.\n"
					"2) NO.\n", "Error: opcion invalida.\n",1,2,3);

			switch(opcion)
			{
			case 1:
				aPrestamo[indicePrestamo].isEmpty = 0;
				ret = 0;
				break;
			case 2:
				break;
			}
		}
	}
	return ret;
}

void mostrarPrestamos(ePrestamo aPrestamo[],int tamP ,eCliente aCliente[], int tamC,int opcion)
{
	int flag = 0;
	system("cls");
	printf("Prestamos lista\n");
	if(aPrestamo != NULL && tamP > 0 && aCliente != NULL && tamC > 0)
	{
		printf("Cuil\tId Cliente\t\tImporte\t\tId Prestamo\t\tCantidad Cuotas\t isEmpty\n");
		for(int i = 0; i < tamP; i++)
		{
			if(aPrestamo[i].isEmpty == opcion)
			{
				mostrarPrestamo(aPrestamo[i],aCliente,tamC);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			system("cls");
			printf("\n---No hay prestamos para mostrar---\n");
			system("pause");
		}
	}
}

void mostrarPrestamo(ePrestamo array,eCliente aCliente[], int tamC)
{
	char cuil[13];
	devolverCuil(aCliente,tamC,array.idCliente,cuil);
	printf("%s\t%d\t\t%.2f\t\t%d\t\t%d\t%d\n",cuil,array.idCliente,array.importe,array.idPrestamo,array.cantidadCuotas,array.isEmpty);
}



int imprimirClientesPrestamoActivo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int i;
	int contador;
	if(aCliente != NULL && tamC > 0 && aPrestamo != NULL && tamP > 0)
	{
		for(i = 0; i< tamC; i ++)
		{
			if(aCliente[i].isEmpty == 0)
			{
				devuelveCantidadPrestamos(aPrestamo,tamP, aCliente[i].idCliente, &contador);

				printf("Id Cliente: %d\n"
						"Nombre: %s\n"
						"Apellido: %s\n"
						"cuil: %s\n"
						"Cantidad de prestamos activos: %d\n", aCliente[i].idCliente,aCliente[i].nombre,aCliente[i].apellido,aCliente[i].cuil,contador);
			}
		}
	}
	return ret;
}


int clienteMasPrestamosActivos(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int contador;
	int maximo;
	int flag = 0;
	int posicion;
	if(aCliente != NULL && tamC > 0 && aPrestamo != NULL && tamP > 0)
	{
		for(int i = 0; i<tamC; i++)
		{
			if(aCliente[i].isEmpty == 0)
			{
				devuelveCantidadPrestamos(aPrestamo,tamP, aCliente[i].idCliente, &contador);

				if(flag == 0 || contador > maximo)
				{
					maximo = contador;
					posicion = i;
					flag = 1;
				}
			}
		}

		printf("El cliente con mas prestamos activos es: \n"
				"Nombre: %s\n"
				"Apellido: %s\n"
				"cuil: %s\n"
				"Cantidad de prestamos: %d\n",aCliente[posicion].nombre,aCliente[posicion].apellido,aCliente[posicion].cuil,maximo);

		ret = 0;
	}
	return ret;
}


int clienteMasPrestamosSaldados(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int contador;
	int maximo;
	int flag = 0;
	int posicion;
	if(aCliente != NULL && tamC > 0 && aPrestamo != NULL && tamP > 0)
	{
		for(int i = 0; i<tamC; i++)
		{
			if(aCliente[i].isEmpty == 0)
			{
				devuelveCantidadPrestamosSaldados(aPrestamo,tamP, aCliente[i].idCliente, &contador);

				if(flag == 0 || contador > maximo)
				{
					maximo = contador;
					posicion = i;
					flag = 1;
				}
			}
		}

		printf("El cliente con mas prestamos saldados es: \n"
				"Nombre: %s\n"
				"Apellido: %s\n"
				"cuil: %s\n"
				"Cantidad de prestamos saldados: %d\n",aCliente[posicion].nombre,aCliente[posicion].apellido,aCliente[posicion].cuil,maximo);

		ret = 0;
	}
	return ret;
}


int informePrestamos(ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int auxImporte;
	int contador = 0;
	if(aPrestamo != NULL && tamP > 0)
	{
		if(utn_getNumero(&auxImporte,"Ingrese un importe mayor a 1000: \n","Error ese importe es muy bajo.\n",1000,400000,2)== 0)
		{
			for(int i = 0; i < tamP; i++)
			{
				if(aPrestamo[i].isEmpty == 0 && aPrestamo[i].importe == auxImporte)
				{
					contador++;
				}
			}
			printf("Se encontraron %d prestamos con ese importe.\n",contador);
			ret = 0;
		}
	}
	return ret;
}

int clienteMasPrestamos(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int contador;
	int maximo;
	int flag = 0;
	int posicion;
	if(aCliente != NULL && tamC > 0 && aPrestamo != NULL && tamP > 0)
	{
		for(int i = 0; i<tamC; i++)
		{
			if(aCliente[i].isEmpty == 0)
			{
				devuelveCantidadPrestamosGeneral(aPrestamo,tamP, aCliente[i].idCliente, &contador);

				if(flag == 0 || contador > maximo)
				{
					maximo = contador;
					posicion = i;
					flag = 1;
				}
			}
		}

		printf("El cliente con mas prestamos es: \n"
				"Nombre: %s\n"
				"Apellido: %s\n"
				"cuil: %s\n"
				"Cantidad de prestamos: %d\n",aCliente[posicion].nombre,aCliente[posicion].apellido,aCliente[posicion].cuil,maximo);

		ret = 0;
	}
	return ret;
}

int prestamosCuotas(ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int contador = 0;
	if(aPrestamo != NULL && tamP > 0)
	{
		for(int i = 0; i < tamP; i++)
		{
			if(aPrestamo[i].isEmpty == -1 && aPrestamo[i].cantidadCuotas == 12)
			{
				contador++;
			}
		}

		printf("La cantidad de prestamos saldados de 12 cuotas es de: %d\n", contador);
		ret = 0;
	}
	return ret;
}

int prestamosActivosCuotas(ePrestamo aPrestamo[], int tamP)
{
	int ret = -1;
	int contador = 0;
	int auxNumero;
	if(aPrestamo != NULL && tamP > 0)
	{
		if(utn_getNumero(&auxNumero,"Ingrese la cantidad de cuotas: (1 a 12)\n","Error cuotas incorrectas.\n",1,12,3) == 0)
		{
			for(int i = 0; i < tamP; i++)
			{
				if(aPrestamo[i].isEmpty == 0 && aPrestamo[i].cantidadCuotas == auxNumero)
				{
					contador++;
				}
			}
			printf("La cantidad de prestamos activos de %d cuotas es de: %d\n",auxNumero ,contador);
			ret = 0;
		}
	}
	return ret;
}
