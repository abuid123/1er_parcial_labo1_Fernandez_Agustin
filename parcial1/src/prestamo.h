/*
 * prestamo.h
 *
 *  Created on: 16 may. 2020
 *      Author: Agus
 */

#ifndef PRESTAMO_H_
#define PRESTAMO_H_

typedef struct
{
	int idCliente;
	float importe;
	int cantidadCuotas;
	int idPrestamo;
	int isEmpty;
}ePrestamo;

int devuelveCantidadPrestamosGeneral(ePrestamo list[],int len, int id, int* cantidad);

/**
 * \brief inicializa el array de prestamos isEmpty en 1
 * \param ePrestamo list[] puntero al array de prestamos
 * \param int len limite de el array de prestamos
 * \return -1 si hay error 0 si no
 */
int inicializarPrestamo(ePrestamo list[], int len);


/**
 * \brief busca una posicion en prestamo con el isEmpty en 1
 * \param ePrestamo list[] puntero al array de prestamos
 * \param int len limite de el array de prestamos
 * \return retorna el indice el primer lugar libre
 */
int buscarPrestamoLibre(ePrestamo array[], int tam);


/**
 * \brief devuelve la cantidad de prestamos saldados
 * \param ePrestamo list[] punteo al array de prestamos
 * \param int len limite de el array de prestamos
 * \param int id es el ID del cliente
 * \param int* cantidad puntero a la variable cantidad
 * \return 0 si hay error 1 si no
 */
int devuelveCantidadPrestamosSaldados(ePrestamo list[],int len, int id, int* cantidad);


/**
 * \brief devuelve la cantidad de prestamos activos
 * \param ePrestamo list[] punteo al array de prestamos
 * \param int len limite de el array de prestamos
 * \param int id es el ID del cliente
 * \param int* cantidad puntero a la variable cantidad
 * \return 0 si hay error 1 si no
 */
int devuelveCantidadPrestamos(ePrestamo list[],int len, int id, int* cantidad);
#endif /* PRESTAMO_H_ */
