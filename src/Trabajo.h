/*
 * Trabajo.h
 *
 *  Biblioteca trabajo.
 *      Author: Brutto, Ezequiel Andr�s
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "Servicio.h"

/**
 * \brief Estructura que origina el tipo de dato "Trabajo".
 */
typedef struct
{
	int idTrabajo;
	char marcaBici[20];
	int rodadoBici;
	int idServicio;
	char fecha[11];
	int isEmpty;
}Trabajo;

/**
 * \brief Inicializo el array de Trabajos.
 * \param pArrayTrabajos Puntero al espacio de memoria donde se copiar� la cadena obtenida.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
int inicializarArrayTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Busca una posici�n libre dentro del array de datos de tipo "Trabajo".
 * \param pArrayTrabajos Puntero al spacio de memoria donde se buscar� la posici�n libre.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \return Retorna el n�mero de posici�n en caso de encontrar una posici�n libre,
 * -1 (LLENO) si la lista se encuentra llena y -2 (ERROR) si se produce alg�n error.
 *
 */
int buscarPosLibre(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Si hay un espacio libre, obtiene los datos a cargar en un dato de tipo "Trabajo".
 * \param pArrayTrabajos Puntero al espacio de memoria donde se buscar� la posici�n libre y se guardar� el trabajo.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \param idTrabajo Recibe como puntero el idTrabajo.
 * \param pArrayServicios Puntero al espacio de memoria del cual obtiene los servicios.
 * \param lengthServicios  Define el tama�o de la cadena de la estructura Servicio.
 * \return Retorna 0 (�XITO) si puede guardar el trabajo y -1 (ERROR) si no.
 *
 */
int darAltaTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,int *idTrabajo,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Usa los datos obtenidos por darAltaTrabajo() y los guarda en una posici�n libre del array.
 * \param pArrayTrabajos Puntero al espacio de memoria donde se guardar� el trabajo.
 * \param posLibre Obtiene el �ndice de la posici�n libre encontrada en donde guardar� los datos.
 * \param idTrabajo N�mero de id a guardar en la posici�n encontrada.
 * \param marcaBici Marca de bicicleta a guardar en la posici�n encontrada.
 * \param rodadoBici Rodado de bicicleta a guardar en la posici�n encontrada.
 * \param servicio ID de servicio a guardar en la posici�n encontrada.
 * \param fecha Fecha a ser registrada en la posici�n libre.
 * \return Retorna 0 (�XITO) si puede guardar el trabajo y -1 (ERROR) si no.
 *
 */
int cargarTrabajo(Trabajo *pArrayTrabajos,int posLibre,int *idTrabajo,char *marcaBici,int rodadoBici,int servicio,char *fecha);

/**
 * \brief Busca las posiciones ocupadas dentro del array de la estructura Trabajo.
 * \param pArrayTrabajos Puntero al espacio de memoria donde se buscar�n las posiciones ocupadas.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \return Retorna la cantidad de posiciones ocupadas, si ninguna lo est� retorna 0.
 *
 */
int buscarPosOcupadas(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Muestra en lista los datos de la estructura Trabajo.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendr� los datos a mostrar.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendr� la descripci�n de los Servicios.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si se muestran los datos y -1 (ERROR) si no.
 */
int listarTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Modifica campos en un trabajo previamente cargado.
 * \param pArrayTrabajos Puntero al espacio de memoria donde se modificaran los campos.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria para mostrar el array en un sub men�.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si se muestran los datos y -1 (ERROR) si no.
 *
 */
int modificarTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Busca una trabajo dentro del array por el numero de Id ingresado.
 * \param pArrayTrabajos Puntero al espacio de memoria donde buscar� el Id.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \param idTrabajoBuscar Id ingresado con el cual buscar� un equivalente dentro del array.
 * \return Retorna 0 en caso de que el Id no se encuentre dentro del array, de lo contrario
 * 		   retorna el numero de la posici�n donde se encuentra el Id equivalente.
 *
 */
int buscarTrabajoPorId(Trabajo *pArrayTrabajos,int lengthTrabajos,int idTrabajoBuscar);

/**
 * \brief Recibe el array de Trabajos, y a trav�s del numero de Id da de baja el solicitado.
 * \param pArrayTrabajos Puntero al espacio de memoria donde borrar� el registro.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendr� la descripci�n de los Servicios.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si no ocurren errores y -1 (ERROR) si los hay.
 *
 */
int darBajaTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Suma el precio de todos los trabajos cargados.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendr� los trabajos realizados.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendr� el precio de cada trabajo.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si puede realizar la suma y -1 (ERROR) si no.
 *
 */
int sumarPreciosTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Ordena la lista de Trabajos seg�n el criterio solicitado e imprime la lista ordenada.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendr� los datos a ordenar y mostrar.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendr� la descripci�n de los Servicios.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si puede realizar operaci�n y -1 (ERROR) si no.
 *
 */
int listarTrabajosOrdenados(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Ordena el array recibido de manera ascendente teniendo en cuenta el a�o.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendr� los datos a ordenar.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si puede realizar operaci�n y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosAnioAsc(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Ordena el array recibido de manera descendente teniendo en cuenta el a�o.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendr� los datos a ordenar.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si puede realizar operaci�n y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosAnioDesc(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Ordena el array recibido de manera ascendente teniendo en cuenta la marca.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendr� los datos a ordenar.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si puede realizar operaci�n y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosMarcaAsc(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Ordena el array recibido de manera descendente teniendo en cuenta la marca.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendr� los datos a ordenar.
 * \param lengthTrabajos Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si puede realizar operaci�n y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosMarcaDesc(Trabajo *pArrayTrabajos,int lengthTrabajos);

int listarMayorCantServicios(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

int contarServicios(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios,int *totalLimp,int *totalPar,int *totalCad,int *totalCen);

#endif /* TRABAJO_H_ */
