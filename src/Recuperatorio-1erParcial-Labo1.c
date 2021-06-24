/*
 ============================================================================
 Name        : Recuperatorio-1erParcial-Labo1.c
 Author      : Brutto, Ezequiel Andrés
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Sistema de gestión de bicicletería. Recuperatorio 1° parcial Labo 1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "menu.h"

#define TRABAJOS 1000
#define SERVICIOS 4

int main(void)
{
	setbuf(stdout, NULL);

	Trabajo dataTrabajos[TRABAJOS];
	Servicio dataServicios[SERVICIOS];
	int idTrabajo = 1;
	int validacionMenu = 1;
	int opcionMenu;

	inicializarArrayTrabajos(dataTrabajos,TRABAJOS);
	inicializarArrayServicios(dataServicios,SERVICIOS);

	do
	{
		menuPrincipal();
		utn_getNumero(&opcionMenu,"\n*Selecione opción: ","\nERROR. La opción no es válida.",1,7,100);
		fflush(stdin);
		{
			switch(opcionMenu)
			{
				case 1:
					darAltaTrabajo(dataTrabajos,TRABAJOS,&idTrabajo,dataServicios,SERVICIOS);
			    break;
				case 2:
					modificarTrabajo(dataTrabajos,TRABAJOS,dataServicios,SERVICIOS);
				break;
				case 3:
					darBajaTrabajo(dataTrabajos,TRABAJOS,dataServicios,SERVICIOS);
				break;
				case 4:
					listarTrabajosOrdenados(dataTrabajos,TRABAJOS,dataServicios,SERVICIOS);
				break;
				case 5:
					if(listarServicios(dataServicios,SERVICIOS) == 0)
					{
						pausa();
					}
				break;
				case 6:
					sumarPreciosTrabajos(dataTrabajos,TRABAJOS,dataServicios,SERVICIOS);
				break;
				case 7:
					cerrarPrograma(&validacionMenu);
				break;
				case 8:
					cerrarPrograma(&validacionMenu);
				break;
			}
		}

	}while(validacionMenu);

	return EXIT_SUCCESS;
}
