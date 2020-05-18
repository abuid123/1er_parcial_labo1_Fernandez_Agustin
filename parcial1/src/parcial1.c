/*
 ============================================================================
 Name        : parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "prestamo.h"
#include "utn.h"
#include "cliente_prestamo.h"

#define QTY_CLIENTES 50
#define QTY_PRESTAMOS 50

int main(void) {
	setbuf(stdout, NULL);
	int idCliente = 0;
	int idPrestamo = 0;
	int opcion = 0;
	int opcion3 = 0;
	int opcion2 = 0;


	eCliente cliente[QTY_CLIENTES];
	inicializarClientes(cliente,QTY_CLIENTES);

	ePrestamo prestamo[QTY_PRESTAMOS];
	inicializarPrestamo(prestamo,QTY_PRESTAMOS);

	while(opcion != 11)
	{
		utn_getNumero(&opcion,"****Menu****\n"
				"1) Alta de cliente.\n"
				"2) Modificar datos de cliente.\n"
				"3) Baja de cliente.\n"
				"4) Prestamo.\n"
				"5) Saldar prestamo.\n"
				"6) Reanudar prestamo.\n"
				"7) Imprimir clientes.\n"
				"8) Imprimir prestamos.\n"
				"9) Informar clientes.\n"
				"10) Informar prestamos.\n"
				"11) Salir.\n", "Error, opcion invalida.\n",1,11,3);
		switch(opcion)
		{
		case 1:

			altaCliente(cliente,QTY_CLIENTES,&idCliente);
			printf("\nCliente cargado satisfactoriamente!\n\n");

			break;
		case 2:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				modificarCliente(cliente,QTY_CLIENTES);
			}else
				printf("Primero debes cargar un cliente.\n");

			break;
		case 3:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				if(bajaDeCliente(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS)==0)
				{
					printf("\nCliente bajado satisfactoriamente!\n\n");
				}
			}else
				printf("Primero debes cargar un cliente.\n");

			break;
		case 4:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				realizarPrestamo(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS, &idPrestamo);
				printf("\nPrestamo realizado satisfactoriamente!\n\n");
			}else
				printf("Primero debes cargar un cliente.\n");

			break;
		case 5:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				saldarPrestamo(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS);
			}else
				printf("Primero debes cargar un cliente.\n");

			break;
		case 6:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				reanudarPrestamo(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS);
			}else
				printf("Primero debes cargar un cliente.\n");

			break;
		case 7:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				imprimirClientesPrestamoActivo(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS);
				system("pause");
			}else
				printf("Primero debes cargar un cliente.\n");

			break;
		case 8:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				mostrarPrestamos(prestamo,QTY_PRESTAMOS,cliente, QTY_CLIENTES,0);
			}else
				printf("Primero debes cargar un cliente.\n");

			break;
		case 9:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				do
				{
					system("cls");
					printf("Informes\n");
					utn_getNumero(&opcion2,"Que desea hacer?\n"
							"1) Cliente con más préstamos activos.\n"
							"2) Cliente con más préstamos saldados. \n"
							"3) Salir.\n","ERROR:OPCION INVALIDA",1,3,2);

					switch(opcion2)
					{
					case 1:
						clienteMasPrestamosActivos(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS);
						break;
					case 2:
						clienteMasPrestamosSaldados(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS);
						break;
					case 3:
						break;
					}
				}
				while(opcion2 != 3);
			}else
			{
				printf("Primero debes cargar un cliente.\n");
			}

			break;
		case 10:

			if(clienteCargado(cliente,QTY_CLIENTES)==0)
			{
				do
				{
					system("cls");
					printf("Informes prestamos\n");
					utn_getNumero(&opcion3,"Que desea hacer?\n"
							"1) Cantidad de préstamos de importe mayor a 1000.\n"
							"2) Salir.\n","ERROR:OPCION INVALIDA",1,2,2);

					switch(opcion3)
					{
					case 1:
						if(informePrestamos(cliente, QTY_CLIENTES, prestamo, QTY_PRESTAMOS)== -1)
						{
							printf("Error, no se reconocio el ingreso.\n");
						}
						break;
					case 2:
						break;
					}
				}
				while(opcion3 != 2);
			}else
			{
				printf("Primero debes cargar un cliente.\n");
			}

			break;
		case 11:

			printf("Gracias! vuelva pronto.\n");

			break;
		}
	}
	return EXIT_SUCCESS;
}
