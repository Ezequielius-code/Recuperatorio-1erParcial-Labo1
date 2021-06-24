#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "utn.h"

void menuPrincipal()
{
	printf("\n|°°°°°°°°°<MENÚ>°°°°°°°°°|"
		   "\n|     1.Alta trabajo     |"
		   "\n|   2.Modificar trabajo  |"
		   "\n|     3.Baja trabajo     |"
		   "\n|    4.Listar trabajos   |"
		   "\n|   5.Listar servicios   |"
		   "\n|        6.TOTAL         |"
		   "\n|        7.SALIR         |"
		   "\n°°°°°°°°°°°°°°°°°°°°°°°°°°");
}

void pausa()
{
	printf("\n\nPulse una tecla para continuar...\n");
	fflush(stdin);
	getchar();
}

void encabezadoListaTrabajos()
{
	printf("\n===============================================================================");
	printf("\n|%12s | %14s | %14s | %12s | %12s |","Id Trabajo","  Marca","Rodado","Servicio","  Fecha");
	printf("\n===============================================================================");
}

void pieListaTrabajos()
{
	printf("\n===============================================================================");
}

void menuModificacion()
{
	printf("\nSeleccione la opcion a modificar:\n1.Marca bicicleta.\n2.Id Servicio.\n3.Volver al menu");
}

void menuOrdenar()
{
	printf("\nSelecione forma de ordenar: \n1.Año ascendente\n2.Año descendiente\n3.Marca ascendente\n4.Marca descendiente\n5.Volver al menu");
}

void cerrarPrograma(int *validacion)
{
	char respuesta;

	utn_getCaracter(&respuesta,"\n¿Esta seguro que desea cerrar el programa?\n"
			        "           (s)i - (n)o        Repuesta: ","\nERROR. Respuesta no valida.",'s','n',100);
	pausa();
	if(respuesta == 's')
	{
		printf("\n\n\t EL PROGRAMA SE HA CERRADO EXITOSAMENTE.");
		*validacion = 0;
	}
	else
	{
		*validacion = 1;
	}
}
