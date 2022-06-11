/*
 ============================================================================
 Name        : TP_1.c
 Author      : Diego Uthurburu
 Version     :
 Copyright   : Your copyright notice
 Description : Este es un programa en C, realiza calculos para determinar los costos de viajes,
 segun distintos parametros
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "utn.h"
#define  REINTENTOS 3
#define PRECIO_MAX 2000000
#define DESCUENTO 10
#define INTERES 25
#define BTN 4606954.55

int main(void)
{
	setbuf(stdout, NULL);

	// Declaramos las variables

 float kilometros;
 float precioAerolineas;
 float precioLatam;
 float precioDebitoA;
 float precioCreditoA;
 float precioBitcoinA;
 float precioUnitarioA;

 float precioDebitoL;
 float precioCreditoL;
 float precioBitcoinL;
 float precioUnitarioL;
 float diferencia;
 int selectorMenu;
 int flagKilometros=0;
 int flagPrecio=0;
 int flagCalculos=0;
 int retorno;


do{


	 //********ENTRADAS AL MENU*******


	if(utn_getNumero(&selectorMenu, "(1) Ingresar cantidad de Kilometros \n"
									"(2) Ingresar Precio de Vuelos \n"
									"(3) Realizar Calculos \n"
									"(4) Informar Resultados \n"
									"(5) Carga forzada de datos \n"
									"(6) Salida \n \n", "ERROR, ingrese nuevamente :", 1, 6, REINTENTOS)==0)
	{

//************ SEGUN LA OPCION ELEGIDA ENTRA EN UNA PARTE DEL MENU *********

		switch (selectorMenu)
		 {
		// ************* SE INGRESA LA CANTIDAD DE KILOMETROS ***********
			case 1:
					if(utn_getNumeroConDecimales(&kilometros, "\nIngrese la cantidad de kilometros: \n"
															, "\nERROR, vuelva a ingresar: \n", 1, 9999999, REINTENTOS)==0)

					{
						printf("\n*** La cantidad de kilometros se cargo con exito.***\n");
						flagKilometros=1;
					}
					else
					{
						printf("\n Ingreso demasiadas veces mal la cantidad de kilometros \n");
					}
			break;
			// ************* SE INGRESAN LOS PRECIOS DE VUELO  ***********
			case 2:

				if(utn_getNumeroConDecimales(&precioAerolineas, "\nIngrese el precio de Aerolineas :\n",
																"\n ERROR, reingrese el precio:\n", 1, PRECIO_MAX, 2)==0)
				{
					if(utn_getNumeroConDecimales(&precioLatam,"\nIngrese el precio de Latam:\n",
															  "\n ERROR, reingrese el precio:\n", 1,PRECIO_MAX, 2)==0)
					{
						flagPrecio=1;
						printf("\nLos precios se cargaron con exito.\n");
					}
				}

				break;
				// ************* REALIZAR CALCULOS   ***********
			case 3:
				if( flagKilometros==1 && flagPrecio==1)
				{
					calcularDebito(&precioDebitoA, precioAerolineas, DESCUENTO);
					calcularDebito(&precioDebitoL, precioLatam, DESCUENTO);

					calcularCredito(&precioCreditoL, precioLatam, INTERES);
					calcularCredito(&precioCreditoA, precioAerolineas, INTERES);

					calcularConversion(&precioBitcoinL, precioLatam, BTN);
					calcularConversion(&precioBitcoinA, precioAerolineas, BTN);

					calcularPrecioPorKilometro(&precioUnitarioL, precioLatam, kilometros);
					calcularPrecioPorKilometro(&precioUnitarioA, precioAerolineas, kilometros);

					retorno=calcularDiferencia(&diferencia, precioAerolineas, precioLatam);

					printf("\n*** Retorno: %d ***\n",retorno);

					printf("\n*** Los calculos se realizaron  con exito.***\n");
					flagCalculos=1;
				}
				else
				{
					printf("ERRORPara poder calcular primero tiene que ingresar los kilometros y el precio\n\n");
				}



				break;

				// ************* INFORMAR RESULTADOS ***********
			case 4:

				if(flagCalculos ==1)
				{
					printf("\n ***** LATAM *****\n"
							"\n Precio con tarjeta de debito: %.2f \n"
							" Precio con tarjeta de credito: %.2f \n"
							" Precio pagando con Bitcion: %f \n"
							" Precio unitario: %.2f \n"
							"\n ***** AEROLINEAS ****** \n"
							"\n Precio con tarjeta de debito: %.2f \n"
							" Precio con tarjeta de credito: %.2f \n"
							" Precio pagando con Bitcion: %f \n"
							" Precio unitario: %.2f \n"
							,precioDebitoL,precioCreditoL,precioBitcoinL,precioUnitarioL,precioDebitoA,precioCreditoA,precioBitcoinA,precioUnitarioA);


					if(retorno == 1 )
					{
						printf("No hay diferencia de precio\n");

					}
					else
					{
						if(retorno == 2)
						{
							printf("El precio de Latam es mayor por $ %.2f \n",diferencia);
						}
						else
						{
							printf("El precio de Aerolineas es mayor por $ %.2f \n\n",diferencia);
						}
					}
				}
				else
				{
					printf("\n ERROR, Para poder ver resultado primero tiene que realizar calculos\n");
				}
				break;
				// ************* CARGA FORZADA DE DATOS ***********
			case 5:
				// Datos hardcodeados
				kilometros = 7090;
				precioLatam = 1350000.76;
				precioAerolineas= 1335000.66;

				// calculos

				calcularDebito(&precioDebitoA, precioAerolineas, DESCUENTO);
				calcularDebito(&precioDebitoL, precioLatam, DESCUENTO);

				calcularCredito(&precioCreditoL, precioLatam, INTERES);
				calcularCredito(&precioCreditoA, precioAerolineas, INTERES);

				calcularConversion(&precioBitcoinL, precioLatam, BTN);
				calcularConversion(&precioBitcoinA, precioAerolineas, BTN);

				calcularPrecioPorKilometro(&precioUnitarioL, precioLatam, kilometros);
				calcularPrecioPorKilometro(&precioUnitarioA, precioAerolineas, kilometros);

				retorno=calcularDiferencia(&diferencia, precioAerolineas, precioLatam);

				// mostrar resultados

				printf("\n ***** LATAM *****\n"
						"\n Precio con tarjeta de debito: %.2f \n"
						" Precio con tarjeta de credito: %.2f \n"
						" Precio pagando con Bitcion: %f \n"
						" Precio unitario: %.2f \n"
						"\n ***** AEROLINEAS ****** \n"
						"\n Precio con tarjeta de debito: %.2f \n"
						" Precio con tarjeta de credito: %.2f \n"
						" Precio pagando con Bitcion: %f \n"
						" Precio unitario: %.2f \n\n"
						,precioDebitoL,precioCreditoL,precioBitcoinL,precioUnitarioL,precioDebitoA,precioCreditoA,precioBitcoinA,precioUnitarioA);


				if(retorno == 1 )
				{
					printf("No hay diferencia de precio\n\n");

				}
				else
				{
					if(retorno == 2)
					{
						printf("El precio de Latam es mayor por $ %.2f \n\n",diferencia);
					}
					else
					{
						printf("El precio de Aerolineas es mayor por $ %.2f \n\n",diferencia);
					}
				}


 		}
	}







} while (selectorMenu != 6);



printf("Gracias por utilizar nuestro software");












	return EXIT_SUCCESS;
}


