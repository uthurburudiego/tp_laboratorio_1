/*
 * calculos.h
 *
 *  Created on: 2 jun. 2022
 *      Author: diego
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * @brief Esta funcion se encarga de calcular un descuento
 * @param pResultado Puntero que devuelve el resultado con el  descuento
 * @param precio Parametro que recibe la funcion indica el valor que va a recibir una disminucion
 * @param descuento Parametro que recibe la funcion que indica el descuento a realizar
 * @return retorna -1(ERROR), 0 (EXITO)
 */
int calcularDebito(float* pResultado, float precio, float descuento);

/**
 * @brief Esta funcion se encarga de calcular un interes
 * @param pResultado Puntero que devuelve el resultado con el interes
 * @param precio Parametro que recibe la funcion indica el valor que va a recibir un incremento
 * @param interes Parametro que recibe la funcion que indica el interes a realizar
 * @return retorna -1(ERROR), 0 (EXITO)
 */
int calcularCredito(float* pResultado, float precio, float interes );

/**
 * @brief Esta funcion se encarga de convertir el valor de una moneda a otra
 * @param pResultado Puntero que devuelve el resultado de la conversion
 * @param precio Parametro que recibe la funcion indica el valor que va a recibir la conversion
 * @param valorDelBitcoin Parametro que recibe la funcion que indica el valor de la moneda
 * @return retorna -1(ERROR), 0 (EXITO)
 */
int calcularConversion(float* pResultado, float precio, float valorDelBitcoin);

/**
 * @brief Esta funcion se encarga de calcular el precio por kilometro
 * @param pResultado Puntero que devuelve el resultado de la division
 * @param precio Parametro que recibe la funcion indica el valor por el total de kilometros
 * @param kilometros Parametro que recibe la funcion que indica el total de kilometros que tiene el vuelo
 * @return retorna -1(ERROR), 0 (EXITO)
 */
int calcularPrecioPorKilometro(float* pResultado, float precio, float kilometros);

/**
 * @brief  Esta funcion se encarga de calcular que diferencia tenemos entre dos valores
 * @param pResultado Puntero que devuelve el resultado
 * @param precioUno  Parametro que recibe la funcion indica el valor
 * @param precioDos Parametro que recibe la funcion indica el valor
 * @return retorna -1 (ERROR), 1 (LOS VALORES SON IGUALES), 2(SI EL SEGUNDO VALOR ES MAYOR), 0(SI EL PRIMER VALOR ES MAYOR)
 */
int calcularDiferencia(float* pResultado, float precioUno, float precioDos);


#endif /* CALCULOS_H_ */
