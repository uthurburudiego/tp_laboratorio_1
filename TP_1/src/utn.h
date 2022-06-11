/*
 * utn.h
 *
 *  Created on: 24 abr. 2022
 *      Author: diego
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroConDecimales(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);
int utn_getCaracter(char* resultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
void utn_imprimirArray(int arrayInt[],int tam);
int utn_promedio(int* resultado,int arrayInt[], int size);
int utn_ordenarArray(int* array, int limite);
int myGets(char *cadena, int longitud);
void utn_imprimirArrayFloat(float arrayFloat[], int tam);
void utn_imprimirArray(int arrayInt[], int tam);
int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,int longitud, int reintentos);



#endif /* UTN_H_ */
