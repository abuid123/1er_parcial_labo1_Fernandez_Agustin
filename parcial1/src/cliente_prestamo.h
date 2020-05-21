/*
 * cliente_prestamo.h
 *
 *  Created on: 16 may. 2020
 *      Author: Agus
 */

#ifndef CLIENTE_PRESTAMO_H_
#define CLIENTE_PRESTAMO_H_

int clienteMasPrestamos(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP);
int prestamosCuotas(ePrestamo aPrestamo[], int tamP);
int prestamosActivosCuotas(ePrestamo aPrestamo[], int tamP);

/**
 * \brief Da de baja un cliente poniendo su isEmpty en 1
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \return int ret [-1] error [0] all ok
 */
int bajaDeCliente(eCliente aCliente[], int tamC, ePrestamo aPrestamo[],
		int tamP);


/**
 * \brief da de alta un prestamo
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \param int* idPrestamo puntero al idPrestamo
 * \return int ret [-1] error [0] all ok
 */
int realizarPrestamo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP, int* idPrestamo);


/**
 * \brief Salda un prestamo poniendolo en -1.    -1 = saldado    0 = activo   1 = vacio = escribible
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \return int ret [-1] error [0] all ok
 */
int saldarPrestamo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP);


/**
 * \brief Reanuda el prestamo pasando de -1 a 0
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \return int ret [-1] error [0] all ok
 */
int reanudarPrestamo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP);


/**
 * \brief Imprime los clientes con prestamos activos
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \return int ret [-1] error [0] all ok
 */
int imprimirClientesPrestamoActivo(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP);


/**
 * \brief Informe de los prestamos, busca prestamos con el importe que pasa el usuario
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \return int ret [-1] error [0] all ok
 */
int informePrestamos(ePrestamo aPrestamo[], int tamP);


/**
 * \brief Imprime los prestamos con el cuil de cada cliente
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \param int opcion Elijo la opcion para que muestre los prestamos activos [0] o [-1] para saldado
 * \return int ret [-1] error [0] all ok
 */
void mostrarPrestamos(ePrestamo aPrestamo[],int tamP ,eCliente aCliente[], int tamC,int opcion);


/**
 * \brief busca el prestamo con el id de cliente
 * \param ePrestamo array Puntero array de prestamos
 * \param int tam Tamaño del array de prestamo
 * \param int id Id del cliente
 * \param int opcion Elijo la opcion para buscar los prestamos activos [0] o [-1] para saldado
 * \return int ret [-1] error [0] all ok
 */
int buscarPrestamo(ePrestamo array[], int tam, int id,int opcion);


/**
 * \brief muestra un prestamo solo con el cuil del cliente
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo posicion del array
 * \return int ret [-1] error [0] all ok
 */
void mostrarPrestamo(ePrestamo array,eCliente aCliente[], int tamC);


/**
 * \brief Busca el cliente con mas prestamos activos
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \return int ret [-1] error [0] all ok
 */
int clienteMasPrestamosActivos(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP);


/**
 * \brief Busca el cliente con mas prestamos saldados
 * \param eCliente aCliente puntero al array de clientes
 * \param int tamC Tamaño del array cliente
 * \param ePrestamo aPrestamo puntero al array de prestamo
 * \param int tamP tamaño del array prestamo
 * \return int ret [-1] error [0] all ok
 */
int clienteMasPrestamosSaldados(eCliente aCliente[], int tamC, ePrestamo aPrestamo[], int tamP);
#endif /* CLIENTE_PRESTAMO_H_ */
