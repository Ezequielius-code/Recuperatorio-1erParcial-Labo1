#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "menu.h"
#include "Servicio.h"
#include "Trabajo.h"

int inicializarArrayServicios(Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;

	if(pArrayServicios != NULL && lengthServicios > 0)
	{
		pArrayServicios[0].idServicio = 20000;
		strcpy(pArrayServicios[0].descripcion,"Limpieza.");
		pArrayServicios[0].precio = 250;
		pArrayServicios[0].isEmpty = 0;

		pArrayServicios[1].idServicio = 20001;
		strcpy(pArrayServicios[1].descripcion,"Parche.  ");
		pArrayServicios[1].precio = 300;
		pArrayServicios[1].isEmpty = 0;

		pArrayServicios[2].idServicio = 20002;
		strcpy(pArrayServicios[2].descripcion,"Cadena.  ");
		pArrayServicios[2].precio = 350;
		pArrayServicios[2].isEmpty = 0;

		pArrayServicios[3].idServicio = 20003;
		strcpy(pArrayServicios[3].descripcion,"Centrado.");
		pArrayServicios[3].precio = 400;
		pArrayServicios[3].isEmpty = 0;

		retorno = 0;
	}

	return retorno;
}

int listarServicios(Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;
	int i;

	if(pArrayServicios != NULL && lengthServicios > 0)
	{
		printf("\n========SERVICIOS========");
		for(i = 0; i < lengthServicios; i ++)
		{
			printf("\n%d %9s $%3.2f.-",pArrayServicios[i].idServicio,pArrayServicios[i].descripcion,pArrayServicios[i].precio);
		}

		retorno = 0;
	}

	return retorno;
}

int obtenerDescripcionId(int idServicio,char *descripcion,Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;
	int i;

	if(descripcion != NULL && pArrayServicios != NULL && lengthServicios > 0)
	{
		for(i = 0;i < lengthServicios;i ++)
		{
			if(pArrayServicios[i].idServicio == idServicio)
			{
				strncpy(descripcion,pArrayServicios[i].descripcion,25);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
