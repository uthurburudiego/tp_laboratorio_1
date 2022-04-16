/*
 * utn.c
 *
 *  Created on: 10 abr. 2022
 *      Author: diego
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//************ESTA FUNCION SE ENCARGA DE GUARDAR UN NUMERO ENTERO ENTRE 1 Y 6
int pedirEntero(int numero)
{



	scanf("%d",&numero);

	if(!(numero>0 && numero< 7))
	{
		fflush(stdin);
		numero=7;
	}

	return numero;
}

//***********ESTA FUNCION SE ENCARGA DE GUARDAR UN NUMERO CON DECIMAL MAYOR QUE 0 ********
float pedirNumeroDecimal(float numero)

{


	scanf("%f",&numero);

	if(numero<0 )
		{


			numero=0;
		}

	return numero;
}
//****************  ESTA FUNCION REALIZA UN DESCUENTO DEL 10%   **************
float precioConDebito(float numero)

{
	float precio;
	precio= numero*0.9;

	return precio;
}
//****************  ESTA FUNCION REALIZA UN AUMENTO DE DEL 25% *******************
float precioConCredito(float numero)
{
	float precio;
	precio= numero*1.25;

	return precio;
}

//****************  ESTA FUNCION SE ENCARGA DE CALCULAR EL PRECIO CON BITCOIN **********


float precioConBitcoin(float numero)
{
	float precio;
	precio=numero*0.00000021708;

return precio;
}

//********** ESTA FUNCION SE ENCARGA DE CALCULAR EL PRECIO POR KILOMETRO ********

float precioPorKilometro(float precio, float kilometros)
{
	float resultado;

	resultado= precio / kilometros;

	return resultado;
}

//******* ESTA FUNCION SE ENCARGA DE CALCULAR LA DIFERENCIA QUE TIENEN DOS VALORES ****

float diferenciaEntreDos(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno-numeroDos;

	return resultado;
}
