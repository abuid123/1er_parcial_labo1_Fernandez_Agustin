/*
 * cliente.h
 *
 *  Created on: 15 may. 2020
 *      Author: Agus
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "prestamo.h"
typedef struct
{
	char nombre[51];
	char apellido[51];
	char cuil[13];
	int idCliente;
	int isEmpty;
}eCliente;


/**
 * \brief Inicializa el array de clientes poniendo el isEmpty en 1
 * \param eCliente aCliente puntero al array de clientes
 * \param int len limite del array de clientes
 * \return -1 si hay error 0 si all ok
 */
int inicializarClientes(eCliente list[],int len);


/**
 * \brief imprime el array de clientes con sus datos
 * \param eCliente aCliente puntero al array de clientes
 * \param int lenghth limite del array de clientes
 * \return 0 si all ok
 */
int imprimirClientes(eCliente list[], int length);


/**
 * \brief Imprime una posicion del array de clientes
 * \param eCliente list posicion del array
 * \return void
 */
void imprimirCliente(eCliente list);


/**
 * \brief Busca clientes con la posicion en isEmpty en 1
 * \param eCliente aCliente puntero al array de clientes
 * \param int tam limite del array de clientes
 * \return int tetorna el indice del cliente libre
 */
int buscarClienteLibre(eCliente array[], int tam);


/**
 * \brief da de alta un cliente
 * \param eCliente aCliente puntero al array de clientes
 * \param int tam limite del array de clientes
 * \param int* idCliente puntero al idCliente
 * \return  0 si hay error 1 si no
 */
int altaCliente(eCliente array[], int tam, int* idCliente);


/**
 * \brief modifica un cliente
 * \param eCliente aCliente puntero al array de clientes
 * \param int tam limite del array de clientes
 * \return -1 si hay error 1 si no
 */
int modificarCliente(eCliente array[], int tam);


/**
 * \brief devuelve el indice del cliente con el id que le paso por parametro
 * \param eCliente aCliente puntero al array de clientes
 * \param int tam limite del array de clientes
 * \param int id Id para buscar la posicion
 * \return int indice, retorna el indice del cliente
 */
int buscarCliente(eCliente array[], int tam, int id);


/**
 * \brief sirve para saber si ya ha cargado algun cliente
 * \param eCliente aCliente puntero al array de clientes
 * \param int len limite del array de clientes
 * \return -1 si hay error y 0 si no
 */
int clienteCargado(eCliente list[],int len);


/**
 * \brief devuelve el cuil en la ultima variable
 * \parame Cliente aCliente puntero al array de clientes
 * \param int len limite del array de clientes
 * \param int id el id del cliente a buscar
 * \param char cuil paraetro al array cuil
 * \return 0 si hay error 1 si no
 */
int devolverCuil(eCliente list[],int len, int id, char cuil[]);
#endif /* CLIENTE_H_ */
