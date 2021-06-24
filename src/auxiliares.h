/*
 * auxiliares.h
 *
 *  Biblioteca auxiliares.
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef AUXILIARES_H_
#define AUXILIARES_H_

/**
 * \brief Recibe una fecha en formato string y convierte el año en un entero.
 * \param cadenaFecha Dirección de memoria donde guardará el entero.
 * \return Retorna 0 si no puede convertir nada, de lo contrario retorna el año como entero.
 *
 */
int convertirAnioChar(char *cadenaFecha);

/**
 * \brief Recibe dos datos de tipo Trabajo y hace el swap en el ordenamiento.
 * \param trabajo1 Primer dato a intercambiar.
 * \param trabajo2 Segundo dato a intercambiar.
 *
 */
void intercambiarValores(Trabajo *trabajo1,Trabajo *trabajo2);

#endif /* AUXILIARES_H_ */
