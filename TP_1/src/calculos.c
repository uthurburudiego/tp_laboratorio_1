
/*
 * calculos.c
 *
 *  Created on: 2 jun. 2022
 *      Author: diego
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"


int calcularDebito(float* pResultado, float precio, float descuento)
{
	int retorno=-1;


	if(pResultado!=NULL && precio!=0 && descuento > 0)
	{
		*pResultado= precio - (precio*descuento/100);
		retorno=0;

	}

	return retorno;
}

int calcularCredito(float* pResultado, float precio, float interes )
{
	int retorno=-1;


		if(pResultado!=NULL && precio!=0 && interes > 0)
		{
			*pResultado= precio + (precio * interes/100);
			retorno=0;

		}

		return retorno;
}

int calcularConversion(float* pResultado, float precio, float valorDelBitcoin)
{
	int retorno=-1;


		if(pResultado!=NULL && precio!=0 && valorDelBitcoin > 0)
		{
			*pResultado= precio / valorDelBitcoin;
			retorno=0;

		}

		return retorno;
}

int calcularPrecioPorKilometro(float* pResultado, float precio, float kilometros)
{
	int retorno=-1;


		if(pResultado!=NULL && precio!=0 && kilometros > 0)
		{
			*pResultado= precio / kilometros;
			retorno=0;

		}

		return retorno;
}

int calcularDiferencia(float* pResultado, float precioUno, float precioDos)
{
	int retorno=-1;
	int buffer;


		if(pResultado!=NULL && precioUno!=0 && precioDos!= 0)
		{
			buffer= precioUno - precioDos;
			if(buffer == 0)
			{
				*pResultado=buffer;
				retorno=1;
			}
			else
			{
				if(buffer < 0 )
				{
					*pResultado= buffer * -1;
					retorno=2;
				}
				else
				{
					*pResultado=buffer;
					retorno=0;

				}
			}



		}

		return retorno;
}




