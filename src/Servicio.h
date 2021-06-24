/*
 * Servicio.h
 *
 *  Biblioteca servicio.
 *      Author: Brutto, Ezequiel Andr�s
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
 * \param pArrayServicios Puntero al espacio de memoria donde se copiar� la cadena obtenida.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si se obtiene una cadena y -1 (ERROR) si no.
 */
int inicializarArrayServicios(Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Muestra en lista los datos de la estructura Servicio.
 * \param pArrayServicios Puntero al espacio de memoria del cual mostrar los datos.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si se muestran los datos y -1 (ERROR) si no.
 *
 */
int listarServicios(Servicio *pArrayServicios,int lengthServicios);

/**
 * \brief Obtiene una cadena a trav�s de un entero.
 * \param idServicio N�mero de Id con el cual buscar� la descripci�n del servicio.
 * \param descripcion Cadena auxiliar donde copiar� la descripci�n del servicio.
 * \param pArrayServicios Puntero al espacio de memoria donde buscar� el Id.
 * \param lengthServicios Define el tama�o de la cadena.
 * \return Retorna 0 (�XITO) si encuentra el Id y copia la cadena y -1 (ERROR) si no.
 */
int obtenerDescripcionId(int idServicio,char *descripcion,Servicio *pArrayServicios,int lengthServicios);


#endif /* SERVICIO_H_ */
