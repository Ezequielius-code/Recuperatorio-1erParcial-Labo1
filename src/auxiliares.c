#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Trabajo.h"
#include "auxiliares.h"

int convertirAnioChar(char *cadenaFecha)
{
	int retorno = 0;
	int posInicial = 6;
	int i = 0;
	int posFinal = 9;
	char aux[4];

	if(cadenaFecha != NULL)
	{
		while(i < posFinal)
		{
			aux[i] = cadenaFecha[posInicial + i];
			i ++;
		}
		retorno = atoi(aux);
	}
	return retorno;
}

void intercambiarValores(Trabajo *trabajo1,Trabajo *trabajo2)
{
	Trabajo aux;

	aux = *trabajo1;
	*trabajo1 = *trabajo2;
	*trabajo2 = aux;
}
