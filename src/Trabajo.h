/*
 * Trabajo.h
 *
 *  Biblioteca trabajo.
 *      Author: Brutto, Ezequiel Andrés
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
 * \param pArrayTrabajos Puntero al espacio de memoria donde se copiará la cadena obtenida.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
int inicializarArrayTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Busca una posición libre dentro del array de datos de tipo "Trabajo".
 * \param pArrayTrabajos Puntero al spacio de memoria donde se buscará la posición libre.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \return Retorna el número de posición en caso de encontrar una posición libre,
 * -1 (LLENO) si la lista se encuentra llena y -2 (ERROR) si se produce algún error.
 *
 */
int buscarPosLibre(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Si hay un espacio libre, obtiene los datos a cargar en un dato de tipo "Trabajo".
 * \param pArrayTrabajos Puntero al espacio de memoria donde se buscará la posición libre y se guardará el trabajo.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \param idTrabajo Recibe como puntero el idTrabajo.
 * \param pArrayServicios Puntero al espacio de memoria del cual obtiene los servicios.
 * \param lengthServicios  Define el tamaño de la cadena de la estructura Servicio.
 * \return Retorna 0 (ÉXITO) si puede guardar el trabajo y -1 (ERROR) si no.
 *
 */
int darAltaTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,int *idTrabajo,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Usa los datos obtenidos por darAltaTrabajo() y los guarda en una posición libre del array.
 * \param pArrayTrabajos Puntero al espacio de memoria donde se guardará el trabajo.
 * \param posLibre Obtiene el índice de la posición libre encontrada en donde guardará los datos.
 * \param idTrabajo Número de id a guardar en la posición encontrada.
 * \param marcaBici Marca de bicicleta a guardar en la posición encontrada.
 * \param rodadoBici Rodado de bicicleta a guardar en la posición encontrada.
 * \param servicio ID de servicio a guardar en la posición encontrada.
 * \param fecha Fecha a ser registrada en la posición libre.
 * \return Retorna 0 (ÉXITO) si puede guardar el trabajo y -1 (ERROR) si no.
 *
 */
int cargarTrabajo(Trabajo *pArrayTrabajos,int posLibre,int *idTrabajo,char *marcaBici,int rodadoBici,int servicio,char *fecha);

/**
 * \brief Busca las posiciones ocupadas dentro del array de la estructura Trabajo.
 * \param pArrayTrabajos Puntero al espacio de memoria donde se buscarán las posiciones ocupadas.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \return Retorna la cantidad de posiciones ocupadas, si ninguna lo está retorna 0.
 *
 */
int buscarPosOcupadas(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Muestra en lista los datos de la estructura Trabajo.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendrá los datos a mostrar.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendrá la descripción de los Servicios.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si se muestran los datos y -1 (ERROR) si no.
 */
int listarTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Modifica campos en un trabajo previamente cargado.
 * \param pArrayTrabajos Puntero al espacio de memoria donde se modificaran los campos.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria para mostrar el array en un sub menú.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si se muestran los datos y -1 (ERROR) si no.
 *
 */
int modificarTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Busca una trabajo dentro del array por el numero de Id ingresado.
 * \param pArrayTrabajos Puntero al espacio de memoria donde buscará el Id.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \param idTrabajoBuscar Id ingresado con el cual buscará un equivalente dentro del array.
 * \return Retorna 0 en caso de que el Id no se encuentre dentro del array, de lo contrario
 * 		   retorna el numero de la posición donde se encuentra el Id equivalente.
 *
 */
int buscarTrabajoPorId(Trabajo *pArrayTrabajos,int lengthTrabajos,int idTrabajoBuscar);

/**
 * \brief Recibe el array de Trabajos, y a través del numero de Id da de baja el solicitado.
 * \param pArrayTrabajos Puntero al espacio de memoria donde borrará el registro.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendrá la descripción de los Servicios.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si no ocurren errores y -1 (ERROR) si los hay.
 *
 */
int darBajaTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Suma el precio de todos los trabajos cargados.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendrá los trabajos realizados.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendrá el precio de cada trabajo.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si puede realizar la suma y -1 (ERROR) si no.
 *
 */
int sumarPreciosTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Ordena la lista de Trabajos según el criterio solicitado e imprime la lista ordenada.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendrá los datos a ordenar y mostrar.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \param pArrayServicios Puntero al espacio de memoria desde donde obtendrá la descripción de los Servicios.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si puede realizar operación y -1 (ERROR) si no.
 *
 */
int listarTrabajosOrdenados(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Ordena el array recibido de manera ascendente teniendo en cuenta el año.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendrá los datos a ordenar.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si puede realizar operación y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosAnioAsc(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Ordena el array recibido de manera descendente teniendo en cuenta el año.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendrá los datos a ordenar.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si puede realizar operación y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosAnioDesc(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Ordena el array recibido de manera ascendente teniendo en cuenta la marca.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendrá los datos a ordenar.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si puede realizar operación y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosMarcaAsc(Trabajo *pArrayTrabajos,int lengthTrabajos);

/**
 * \brief Ordena el array recibido de manera descendente teniendo en cuenta la marca.
 * \param pArrayTrabajos Puntero al espacio de memoria desde donde obtendrá los datos a ordenar.
 * \param lengthTrabajos Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si puede realizar operación y -1 (ERROR) si no.
 *
 */
int ordenarTrabajosMarcaDesc(Trabajo *pArrayTrabajos,int lengthTrabajos);

int listarMayorCantServicios(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios);

int contarServicios(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios,int *totalLimp,int *totalPar,int *totalCad,int *totalCen);

#endif /* TRABAJO_H_ */
