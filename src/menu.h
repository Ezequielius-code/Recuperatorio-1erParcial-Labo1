/*
 * utn.h
 *
 *  Biblioteca Menu.
 *      Author: Brutto, Ezequiel Andr�s
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * \brief Despliega el men� ppal. del programa.
 */
void menuPrincipal();

/**
 * \brief Hace una pausa en la operaci�n del programa, y solicita el pulsado
 * de una tecla para continuar ejecutando.
 */
void pausa();

/**
 * \brief Despliega el encabezado de la lista de Trabajos.
 */
void encabezadoListaTrabajos();

/**
 * \brief Despliega el cierre de la lista de Trabajos.
 */
void pieListaTrabajos();

/**
 * \brief Despliega el men� de modificaci�n de trabajos.
 */
void menuModificacion();

/**
 * \brief Despliega el men� para seleccionar la forma de ordenar los trabajos.
 */
void menuOrdenar();

/**
 * \brief Pregunta si se quiere cerrar el programa y cambia, o no, el valor de validaci�n para hacerlo.
 * \param validacion Recibe por puntero el valor de validaci�n.
 */
void cerrarPrograma(int *validacion);

#endif /* MENU_H_ */
