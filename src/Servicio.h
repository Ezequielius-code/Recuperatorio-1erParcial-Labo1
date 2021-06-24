/*
 * Servicio.h
 *
 *  Biblioteca servicio.
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

/**
 * \brief Estructura que origina el tipo de dato "Servicio".
 */
typedef struct
{
	int idServicio;
	char descripcion[25];
	float precio;
	int isEmpty;
}Servicio;

/**
 * \brief Inicializo el array de Servicios.
 * \param pArrayServicios Puntero al espacio de memoria donde se copiará la cadena obtenida.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si se obtiene una cadena y -1 (ERROR) si no.
 */
int inicializarArrayServicios(Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Muestra en lista los datos de la estructura Servicio.
 * \param pArrayServicios Puntero al espacio de memoria del cual mostrar los datos.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si se muestran los datos y -1 (ERROR) si no.
 *
 */
int listarServicios(Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Obtiene una cadena a través de un entero.
 * \param idServicio Número de Id con el cual buscará la descripción del servicio.
 * \param descripcion Cadena auxiliar donde copiará la descripción del servicio.
 * \param pArrayServicios Puntero al espacio de memoria donde buscará el Id.
 * \param lengthServicios Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si encuentra el Id y copia la cadena y -1 (ERROR) si no.
 */
int obtenerDescripcionId(int idServicio,char *descripcion,Servicio *pArrayServicios,int lengthServicios);


#endif /* SERVICIO_H_ */
