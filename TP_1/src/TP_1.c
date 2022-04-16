/*
 ============================================================================
 Name        : TP_1.c
 Author      : Diego Uthurburu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);

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
 int salida;
 int selectorMenu;
 int flag=0;


do{


	 //********ENTRADAS AL MENU*******

	 printf("\n    ***** MENU PRINCIPAL *****  \n \n ");

	 printf("(1) Ingresar cantidad de Kilometros \n \n");

	 printf("(2) Ingresar Precio de Vuelos \n \n");

	 printf("(3) Realizar Calculos \n \n");

	 printf("(4) Informar Resultados \n \n");

	 printf("(5) Carga forzada de datos \n \n");

	 printf("(6) Salida \n \n");

	   selectorMenu=pedirEntero(selectorMenu);




	switch (selectorMenu)
	 {
		case 1:

			printf("(1) **** Ingrese cantidad de Kilometros ****\n \n");

			printf(" Ingrese cantidad de Kilometros: ");

			 kilometros=pedirNumeroDecimal(kilometros);

			 while (kilometros==0)
			 {
				printf("\n *****ERROR, iNGRESO UN VALOR NO VALIDO ***** \n");

				printf("\n Ingrese cantidad de Kilometros: \n");
				kilometros=pedirNumeroDecimal(kilometros);
			 }

			break;

		case 2:
			 printf("(2) **** Ingresar Precio de Vuelos  ****\n \n");

			 printf("Precio vuelo Aerolíneas: \n") ;
			 precioAerolineas=pedirNumeroDecimal(precioAerolineas);

			 while (precioAerolineas==0)
						 {
							printf("\n *****ERROR, iNGRESO UN VALOR NO VALIDO ***** \n");

							printf("\n Ingrese precio de Aerolineas: \n");
							precioAerolineas=pedirNumeroDecimal(precioAerolineas);
						 }

			 printf("Precio vuelo Latam: \n");
			 precioLatam=pedirNumeroDecimal(precioLatam);

			 while (precioAerolineas==0)
			 {
				printf("\n *****ERROR, iNGRESO UN VALOR NO VALIDO ***** \n");

				printf("\n Ingrese precio de Latam: \n");
				precioLatam=pedirNumeroDecimal(precioLatam);
			 }
			break;

		case 3:
			if(kilometros !=0 && precioLatam!=0 && precioAerolineas!=0)
			{
					printf("(3) **** Realizar calculos  ****\n \n");


					precioDebitoL= precioConDebito(precioLatam);
					precioDebitoA=precioConDebito(precioAerolineas);

					precioCreditoL=precioConCredito(precioLatam);
					precioCreditoA=precioConCredito(precioAerolineas);

					precioBitcoinL=precioConBitcoin(precioLatam);
					precioBitcoinA=precioConBitcoin(precioAerolineas);

					precioUnitarioL= precioPorKilometro(precioLatam,kilometros );
					precioUnitarioA= precioPorKilometro(precioAerolineas,kilometros );

					diferencia=diferenciaEntreDos(precioAerolineas,precioLatam);
					flag =1;

					printf("\n LOS CALCULOS FUERON REALIZADOS CON EXITO!! \n");
			}
			else
			{
				printf("ERROR, SE NECESITAN DATOS 'CANTIDAD DE KILOMETROS' Y 'PRECIOS DE VUELOS' ");
			}
					break;

		case 4:
			if(flag==1)
			{

							printf("4. Informar Resultados");

				printf("***Aerolineas** \n \n");

				printf("a) Precio con tarjeta de débito: $ %.2f \n",precioDebitoA);
				printf("b) Precio con tarjeta de crédito: $ %.2f \n",precioCreditoA);
				printf("c) Precio pagando con bitcoin : $ %.4f \n",precioBitcoinA);
				printf("d) Precio unitario: $ %.2f \n",precioUnitarioA);

				printf("***Latam** \n \n");

				printf("a) Precio con tarjeta de débito: $ %.2f \n",precioDebitoL);
				printf("b) Precio con tarjeta de crédito: $ %.2f \n",precioCreditoL);
				printf("c) Precio pagando con bitcoin : $ %.4f \n",precioBitcoinL);
				printf("d) Precio unitario: $ %.2f \n",precioUnitarioL);



				printf("La diferencia de precio es :  $ %.2f \n",diferencia);
			}
			else
			{
				printf("\n ERROR, SE NECECITA CALCULAR DATOS PRIMERO \n");
			}

			break;

		case 5:
			printf("\n\n 5) Carga forzada de datos \n\n  ");

			// harcodeamos los valires
					kilometros = 7090;
					precioAerolineas = 162965;
					precioLatam = 159339;

				// realizamos los calculos

					precioDebitoL= precioConDebito(precioLatam);
					precioDebitoA=precioConDebito(precioAerolineas);

					precioCreditoL=precioConCredito(precioLatam);
					precioCreditoA=precioConCredito(precioAerolineas);

					precioBitcoinL=precioConBitcoin(precioLatam);
					precioBitcoinA=precioConBitcoin(precioAerolineas);

					precioUnitarioL= precioPorKilometro(precioLatam,kilometros );
					precioUnitarioA= precioPorKilometro(precioAerolineas,kilometros );

					diferencia=diferenciaEntreDos(precioAerolineas,precioLatam);

					//imprimimos por consola los resultados


					printf("***Aerolineas** \n \n");

					printf("a) Precio con tarjeta de débito: $ %.2f \n",precioDebitoA);
					printf("b) Precio con tarjeta de crédito: $ %.2f \n",precioCreditoA);
					printf("c) Precio pagando con bitcoin : $ %.4f \n",precioBitcoinA);
					printf("d) Precio unitario: $ %.2f \n",precioUnitarioA);

					printf("\n\n***Latam** \n \n");

					printf("a) Precio con tarjeta de débito: $ %.2f \n",precioDebitoL);
					printf("b) Precio con tarjeta de crédito: $ %.2f \n",precioCreditoL);
					printf("c) Precio pagando con bitcoin : $ %.4f \n",precioBitcoinL);
					printf("d) Precio unitario: $ %.2f \n",precioUnitarioL);



					printf("La diferencia de precio es :  $ %.2f \n",diferencia);





					break;



		case 6:

			salida=0;


			break;

		default:
			printf("Error, tiene que elegir una de las opciones: \n");
			break;
	}








} while (salida != 0);



printf("Gracias por utilizar nuestro software");












	return EXIT_SUCCESS;
}


