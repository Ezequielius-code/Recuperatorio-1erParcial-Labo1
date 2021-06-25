#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "menu.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "auxiliares.h"

#define VACIO 1
#define LLENO 0

int inicializarArrayTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos)
{
	int retorno = -1;
	int i;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		for(i = 0;i < lengthTrabajos;i ++)
		{
			pArrayTrabajos[i].isEmpty = VACIO;
		}

		retorno = 0;
	}

	return retorno;
}

int buscarPosLibre(Trabajo *pArrayTrabajos,int lengthTrabajos)
{
	int i;
	int retorno = -2;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		for (i = 0; i < lengthTrabajos; i ++)
		{
			if(pArrayTrabajos[i].isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
			else
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int darAltaTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,int *idTrabajo,Servicio *pArrayServicios,int lengthServicios)
{
	char marcaBici[20];
	int rodadoBici;
	char fecha[11];
	int servicio;
	int posLibre;
	int retorno = -1;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0 &&
	   idTrabajo > 0 && pArrayServicios != NULL && lengthServicios > 0)
	{
		posLibre = buscarPosLibre(pArrayTrabajos,lengthTrabajos);

		if(posLibre >= 0)
		{
			utn_getNombre(marcaBici,20,"\nIngrese marca de la bicicleta: ","\nERROR. Ha ingresado una marca no valida.",100);
			utn_getNumero(&rodadoBici,"\nIngrese el número de rodado: ","\nERROR. El número de rodado no existe. ",12,28,100);
			utn_getFecha(fecha,11,"\nIngrese fecha en formato (dd/mm/aaaa): ","\nERROR. La fecha ingresada no es valida.",100);
			listarServicios(pArrayServicios,lengthServicios);
			utn_getNumero(&servicio,"\nIngrese el numero de servicio a realizar: ","\nERROR. El servicio no existe.",20000,20003,100);
			if(cargarTrabajo(pArrayTrabajos,posLibre,idTrabajo,marcaBici,rodadoBici,servicio,fecha) == 0)
			{
				(*idTrabajo) ++;

				printf("\nSe ha ingresado un trabajo exitosamente.");
				pausa();

				retorno = 0;
			}
			else
			{
				printf("\nHa ocurrido un error al cargar los datos.");
				retorno = -1;
			}
		}
		else
		{
			if(posLibre == -1)
			{
				printf("\nNo hay lugar disponible para cargar nuevos trabajos.");
				retorno = -1;
			}
			else
			{
				if(posLibre == -2)
				{
					printf("\nHa ocurrido un error para encontrar posiciones libres.");
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

int cargarTrabajo(Trabajo *pArrayTrabajos,int posLibre,int *idTrabajo,char *marcaBici,int rodadoBici,int servicio,char *fecha)
{
	int retorno = -1;

	if(pArrayTrabajos != NULL && posLibre >= 0 && idTrabajo != NULL &&
	   marcaBici != NULL && rodadoBici > 0 && servicio > 0 && fecha != NULL)
	{
		pArrayTrabajos[posLibre].idTrabajo = *idTrabajo;
		strncpy(pArrayTrabajos[posLibre].marcaBici,marcaBici,sizeof(pArrayTrabajos[posLibre].marcaBici));
		pArrayTrabajos[posLibre].rodadoBici = rodadoBici;
		pArrayTrabajos[posLibre].idServicio = servicio;
		strncpy(pArrayTrabajos[posLibre].fecha,fecha,sizeof(pArrayTrabajos[posLibre].fecha));
		pArrayTrabajos[posLibre].isEmpty = LLENO;

		retorno = 0;
	}

	return retorno;
}

int buscarPosOcupadas(Trabajo *pArrayTrabajos,int lengthTrabajos)
{
	int retorno = 0;
	int i;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		for (i = 0; i < lengthTrabajos; i ++)
		{
			if(pArrayTrabajos[i].isEmpty == LLENO)
			{
				retorno ++;
			}
		}
	}

	return retorno;
}

int listarTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;
	int i;
	char auxDetalleServicio[25];

	if(pArrayTrabajos != NULL && lengthTrabajos > 0 &&
	   buscarPosOcupadas(pArrayTrabajos,lengthTrabajos) != 0)
	{
		encabezadoListaTrabajos();
		for (i = 0; i < lengthTrabajos; i ++)
		{
			if(pArrayTrabajos[i].isEmpty == LLENO)
			{
				obtenerDescripcionId(pArrayTrabajos[i].idServicio,auxDetalleServicio,pArrayServicios,lengthServicios);
				printf("\n|%12d | %14s | %14d | %12s | %12s |",pArrayTrabajos[i].idTrabajo,pArrayTrabajos[i].marcaBici,
						pArrayTrabajos[i].rodadoBici,auxDetalleServicio,pArrayTrabajos[i].fecha);
			}
		}
		pieListaTrabajos();

		retorno = 0;
	}

	return retorno;
}

int modificarTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;
	int idTrabajoMod;
	int auxPos;
	char auxIdServicio[25];
	int opcMenuMod;
	char marcaMod[20];
	int servicioMod;
	char respuesta;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0 &&
	   pArrayServicios != NULL && lengthServicios > 0)
	{
		if(buscarPosOcupadas(pArrayTrabajos,lengthTrabajos) == 0)
		{
			printf("\nPrimero debe ingresar un trabajo.");
			pausa();
			retorno = 0;
		}
		else
		{
			do
			{
				listarTrabajos(pArrayTrabajos,lengthTrabajos,pArrayServicios,lengthServicios);

				utn_getNumero(&idTrabajoMod,"\nSi ha ingresado por error, ingrese 0 (cero)\npara volver al menu principal.\nIngrese el numero de Id del trabajo a modificar: ","\nERROR. El Id ingresado no existe.",0,1000,100);
				if(idTrabajoMod == 0)
				{
					break;
				}
				auxPos = buscarTrabajoPorId(pArrayTrabajos,lengthTrabajos,idTrabajoMod);

				if(auxPos >= 0)
				{
					obtenerDescripcionId(pArrayTrabajos[auxPos].idServicio,auxIdServicio,pArrayServicios,lengthServicios);
					printf("\nSe modificara el siguiente trabajo:");
					encabezadoListaTrabajos();
					printf("\n|%12d | %14s | %14d | %12s | %12s |",pArrayTrabajos[auxPos].idTrabajo,pArrayTrabajos[auxPos].marcaBici,
							pArrayTrabajos[auxPos].rodadoBici,auxIdServicio,pArrayTrabajos[auxPos].fecha);
					pieListaTrabajos();

					menuModificacion();
					utn_getNumero(&opcMenuMod,"\n\n*Seleccione opcion: ","\nERROR. La opcion ingresada no es valida.",1,3,100);
					switch(opcMenuMod)
					{
						case 1:
							utn_getNombre(marcaMod,20,"\nIngrese nueva marca de bicicleta: ","\nERROR. Ha ingresado una marca no valida.",100);
							strncpy(pArrayTrabajos[auxPos].marcaBici,marcaMod,sizeof(pArrayTrabajos[auxPos].marcaBici));
						break;
						case 2:
							listarServicios(pArrayServicios,lengthServicios);
							utn_getNumero(&servicioMod,"\nIngrese el numero del nuevo servicio a realizar: ","\nERROR. El servicio no existe.",20000,20003,100);
							pArrayTrabajos[auxPos].idServicio = servicioMod;
						break;
						case 3:
							respuesta = 's';
						break;
					}

						pausa();
						retorno = 0;
				}

				printf("¿Desea seguir modificando trabajos? (s)i - (n)o : ");
				fflush(stdin);
				scanf("%c",&respuesta);
			}while(respuesta == 's');
		}
	}

	return retorno;
}

int buscarTrabajoPorId(Trabajo *pArrayTrabajos,int lengthTrabajos,int idTrabajoBuscar)
{
	int i;
	int retorno = -1;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0 && idTrabajoBuscar > 0)
	{
		for(i = 0; i < lengthTrabajos; i ++)
		{
			if(pArrayTrabajos[i].idTrabajo == idTrabajoBuscar && pArrayTrabajos[i].isEmpty == LLENO)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

int darBajaTrabajo(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;
	int idTrabajoBorrar;
	int auxPos;
	char respuesta;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		do
		{
			if(buscarPosOcupadas(pArrayTrabajos,lengthTrabajos) == 0)
			{
				printf("\nPrimero debe ingresar un trabajo.");
				pausa();
				retorno = 0;
			}
			else
			{
				listarTrabajos(pArrayTrabajos,lengthTrabajos,pArrayServicios,lengthServicios);

				utn_getNumero(&idTrabajoBorrar,"\nSi ha ingresado por error, ingrese 0 (cero)\npara volver al menu principal.\nIngrese el numero de Id del trabajo a eliminar: ","\nERROR. El Id ingresado no existe.",0,1000,100);
				if(idTrabajoBorrar == 0)
				{
					break;
				}
				auxPos = buscarTrabajoPorId(pArrayTrabajos,lengthTrabajos,idTrabajoBorrar);

				if(auxPos >= 0 && pArrayTrabajos[auxPos].isEmpty == LLENO)
				{
					pArrayTrabajos[auxPos].isEmpty = VACIO;

					printf("\nEl trabajo ha sido borrado exitosamente.");
					pausa();
					retorno = 0;
				}
			}
			printf("¿Desea seguir eliminando trabajos? (s)i - (n)o : ");
			fflush(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's');
	}

	return retorno;
}

int sumarPreciosTrabajos(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;
	int i;
	int j;
	float acumuladorPrecios = 0;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0 &&
	   pArrayServicios != NULL && lengthServicios > 0)
	{
		if(buscarPosOcupadas(pArrayTrabajos,lengthTrabajos) == 0)
		{
			printf("\nPrimero debe ingresar un trabajo.");
			pausa();
			retorno = 0;
		}
		else
		{
			for(i = 0;i < lengthTrabajos;i ++)
			{
				if(pArrayTrabajos[i].isEmpty == LLENO)
				{
					for(j = 0;j < lengthServicios;j ++)
					{
						if(pArrayTrabajos[i].idServicio == pArrayServicios[j].idServicio)
						{
							acumuladorPrecios = acumuladorPrecios + pArrayServicios[j].precio;
						}
					}
				}
			}

			printf("El total en pesos por los trabajos realizados es de: $ %.2f.-",acumuladorPrecios);
			pausa();
			retorno = 0;
		}
	}

	return retorno;
}

int listarTrabajosOrdenados(Trabajo *pArrayTrabajos,int lengthTrabajos,Servicio *pArrayServicios,int lengthServicios)
{
	int retorno = -1;
	int opcOrden;

	if(buscarPosOcupadas(pArrayTrabajos,lengthTrabajos) == 0)
	{
		printf("\nPrimero debe ingresar un trabajo.");
		pausa();
		retorno = 0;
	}
	else
	{
		menuOrdenar();
		utn_getNumero(&opcOrden,"\n*Seleccione opcion:","\nERROR. Opcion no valida.",1,5,100);

		switch(opcOrden)
		{
			case 1:
				ordenarTrabajosAnioAsc(pArrayTrabajos,lengthTrabajos);
			break;
			case 2:
				ordenarTrabajosAnioDesc(pArrayTrabajos,lengthTrabajos);
			break;
			case 3:
				ordenarTrabajosMarcaAsc(pArrayTrabajos,lengthTrabajos);
			break;
			case 4:
				ordenarTrabajosMarcaDesc(pArrayTrabajos,lengthTrabajos);
			break;
			case 5:
			break;
		}

		if(opcOrden != 5)
		{
			listarTrabajos(pArrayTrabajos,lengthTrabajos,pArrayServicios,lengthServicios);
		}
		retorno = 0;
	}

	return retorno;
}

int ordenarTrabajosAnioAsc(Trabajo *pArrayTrabajos,int lengthTrabajos)
{
	int retorno = -1;
	int i;
	int j;
	int auxAnio1;
	int auxAnio2;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		for(i = 0;i < lengthTrabajos -1;i ++)
		{
			for(j = i+1;j < lengthTrabajos;j ++)
			{
				if(pArrayTrabajos[i].isEmpty == LLENO &&
				   pArrayTrabajos[j].isEmpty == LLENO)
				{
					auxAnio1 = convertirAnioChar(pArrayTrabajos[i].fecha);
					auxAnio2 = convertirAnioChar(pArrayTrabajos[j].fecha);
					if(auxAnio1 > auxAnio2)
					{
						intercambiarValores(&pArrayTrabajos[i],&pArrayTrabajos[j]);
					}
					if(auxAnio1 == auxAnio2 &&
					   strcmp(pArrayTrabajos[i].marcaBici,pArrayTrabajos[j].marcaBici) > 0)
					{
						intercambiarValores(&pArrayTrabajos[i],&pArrayTrabajos[j]);
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

int ordenarTrabajosAnioDesc(Trabajo *pArrayTrabajos,int lengthTrabajos)
{
	int retorno = -1;
	int i;
	int j;
	int auxAnio1;
	int auxAnio2;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		for(i = 0;i < lengthTrabajos -1;i ++)
		{
			for(j = i+1;j < lengthTrabajos;j ++)
			{
				if(pArrayTrabajos[i].isEmpty == LLENO &&
				   pArrayTrabajos[j].isEmpty == LLENO)
				{
					auxAnio1 = convertirAnioChar(pArrayTrabajos[i].fecha);
					auxAnio2 = convertirAnioChar(pArrayTrabajos[j].fecha);
					if(auxAnio1 < auxAnio2)
					{
						intercambiarValores(&pArrayTrabajos[i],&pArrayTrabajos[j]);
					}
					if(auxAnio1 == auxAnio2 &&
					   strcmp(pArrayTrabajos[i].marcaBici,pArrayTrabajos[j].marcaBici) < 0)
					{
						intercambiarValores(&pArrayTrabajos[i],&pArrayTrabajos[j]);
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

int ordenarTrabajosMarcaAsc(Trabajo *pArrayTrabajos,int lengthTrabajos)
{
	int retorno = -1;
	int i;
	int j;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		for(i = 0;i < lengthTrabajos -1;i ++)
		{
			for(j = i+1;j < lengthTrabajos;j ++)
			{
				if(pArrayTrabajos[i].isEmpty == LLENO &&
				   pArrayTrabajos[j].isEmpty == LLENO &&
				   strcmp(pArrayTrabajos[i].marcaBici,pArrayTrabajos[j].marcaBici) > 0)
				{
					intercambiarValores(&pArrayTrabajos[i],&pArrayTrabajos[j]);
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

int ordenarTrabajosMarcaDesc(Trabajo *pArrayTrabajos,int lengthTrabajos)
{
	int retorno = -1;
	int i;
	int j;

	if(pArrayTrabajos != NULL && lengthTrabajos > 0)
	{
		for(i = 0;i < lengthTrabajos -1;i ++)
		{
			for(j = i+1;j < lengthTrabajos;j ++)
			{
				if(pArrayTrabajos[i].isEmpty == LLENO &&
				   pArrayTrabajos[j].isEmpty == LLENO &&
				   strcmp(pArrayTrabajos[i].marcaBici,pArrayTrabajos[j].marcaBici) < 0)
				{
					intercambiarValores(&pArrayTrabajos[i],&pArrayTrabajos[j]);
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}


int listarMayorCantServicios(Trabajo *pArrayTrabajos, int lengthTrabajos,Servicio *pArrayServicios, int lengthServicios)
{
	int retorno = -1;
	int totalLimpieza = 0;
	int totalParche = 0;
	int totalCadena = 0;
	int totalCentrado = 0;
	int idServicio = 0;
	int mayorServicio = 0;
	char descripcion[25];
	if (pArrayTrabajos != NULL && lengthTrabajos > 0 &&
		pArrayServicios != NULL && lengthServicios > 0)
	{
		if (buscarPosOcupadas(pArrayTrabajos,lengthTrabajos) == 0)
		{
			printf("\nPrimero debe ingresar un trabajo.");
			pausa();
			retorno = 0;
		}
		else
		{
			for (int i = 0; i < lengthTrabajos; i ++)
			{
				idServicio = pArrayTrabajos[i].idServicio;

				switch(idServicio)
				{
					case 20000:
						totalLimpieza ++;
						if(totalLimpieza > mayorServicio)
						{
							mayorServicio = totalLimpieza;
							obtenerDescripcionId(idServicio,descripcion,pArrayServicios,lengthServicios);
						}
					break;
					case 20001:
						totalParche ++;
						if(totalParche > mayorServicio)
						{
							mayorServicio = totalParche;
							obtenerDescripcionId(idServicio,descripcion,pArrayServicios,lengthServicios);
						}
					break;
					case 20002:
						totalCadena ++;
						if(totalCadena > mayorServicio)
						{
							mayorServicio = totalCadena;
							obtenerDescripcionId(idServicio,descripcion,pArrayServicios,lengthServicios);
						}
					break;
					case 20003:
						totalCentrado ++;
						if(totalCentrado > mayorServicio)
						{
							mayorServicio = totalCentrado;
							obtenerDescripcionId(idServicio,descripcion,pArrayServicios,lengthServicios);
						}
					break;
				}
			}

		}
		printf("Servicio con mayor recaudacion: %s con %d",descripcion,mayorServicio);
		retorno = 0;
	}

	return retorno;
}
