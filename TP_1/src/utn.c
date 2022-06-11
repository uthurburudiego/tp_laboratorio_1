/*
 * utn.c
 *
 *  Created on: 24 abr. 2022
 *      Author: diego
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int esNumerica(char *cadena, int limite);
static int getInt(int *pResultado);
static int esFlotante(char *cadena, int limite);
static int getNombre(char* pResultado, int longitud);
static int getFloat(float *pResultado);
static int getNombre(char* pResultado, int longitud);
static int getString(char *cadena, int longitud);
static int esNombre(char *cadena, int limite);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param *cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
int myGets(char *cadena, int longitud)
{

	int retorno=-1;
	char bufferString[256];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}

			if(strnlen(bufferString,sizeof(bufferString))<= longitud )
			{
				strncpy(cadena, bufferString,longitud);
				retorno=0;
			}
		}
	}


	return retorno;
}


/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int *pResultado)
{
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer,sizeof(buffer)))
	{

			*pResultado = atoi(buffer);
			retorno = 0;
	}

	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esNumerica(char *cadena, int limite)
{
	int i;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		for (i=0;i<limite && cadena[i] != '\0';i++)
		{
			if (i==0 && (cadena[i]=='+' || cadena[i]=='-' ))
			{
				continue;
			}
			if(cadena[i]>'9'|| cadena[i]<'0')
			{
				retorno=0;
				break;
			}

		}
	}
	return retorno;
}


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0
			&& bufferInt >= minimo
			&& bufferInt <= maximo)
		{
			*pResultado = bufferInt;
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

// ESTA FUNCION SE ENCARGA DE PEDIR UN CARACTER
int utn_getCaracter(char *resultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char bufferCaracter;

	if (resultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);

			scanf("%c", &bufferCaracter);

			if (bufferCaracter >= minimo && bufferCaracter <= maximo) {
				*resultado = bufferCaracter;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

// IMPRIMIR UN ARRAY

void utn_imprimirArray(int arrayInt[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf(" %d \n", arrayInt[i]);
	}

}
/**
 *\ brief Descripcion de lo que hace la funcion
 * \ param nombre de la variable+ que contiene
 * \ return que devuelve la funcion
 */
// CALCULAR UN PROMEDIO
int utn_promedio(int *resultado, int arrayInt[], int size) {
	int retorno = -1;
	int acumulador = 0;

	if (arrayInt != NULL && resultado != NULL && size > 0) {
		for (int i = 0; i < size; i++) {
			acumulador = arrayInt[i] + acumulador;

		}

		*resultado = ((float) acumulador) / size;

		retorno = 0;
	}

	return retorno;

}

// FUNCION DE ORDENAMIENTO DE BURBUJEO

int utn_ordenarArray(int *array, int limite) {
	int nuevoLimite;
	int retorno = -1;
	int flagSwap;
	int contador = 0;
	int buffer;
	if (array != NULL && limite >= 0) {
		nuevoLimite = limite - 1;
		do {
			flagSwap = 0;
			for (int i = 0; i < nuevoLimite; i++) {
				contador++;

				if (array[i] < array[i + 1]) {
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i + 1];
					array[i + 1] = buffer;
				}
			}

			nuevoLimite--;

		} while (flagSwap);

		retorno = contador;
	}

	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
 int utn_getNumeroConDecimales(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos) {
		float bufferFloat;
		int retorno = -1;
		while (reintentos > 0) {
			reintentos--;
			printf("%s", mensaje);
			if (getFloat(&bufferFloat) == 0
				&& bufferFloat >= minimo
				&& bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
		}
		return retorno;

 }
 /**
  * \brief Verifica si la cadena ingresada es numerica decimal
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
  *
  */
 static int getFloat(float *pResultado)
 {
 	int retorno = -1;
 	char buffer[64];
 	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer,sizeof(buffer)))
 		{
 			*pResultado = atof(buffer);
 			retorno = 0;
 		}

 	return retorno;
 }

 //INICIALIZAR ARRAY FLOAT
 float inicializalArrayFloat(float* arrayFloat,int tam,float inicializar)
 {

	 float retorno=-1;
	 if(arrayFloat != NULL && tam > 0)
	 {
		 for (int i = 0; i < tam; i++)
		 		{
		 			arrayFloat[i]=inicializar;

		 		}
	 }




	 return retorno;
 }

 static int esFlotante(char *cadena, int limite)
 {
	int i;
	int retorno = 1;
	int contadorPuntos=0;

		for (i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(cadena[i]<'0'|| cadena[i]>'9')
			{
				if(cadena[i]=='.')
				{
					contadorPuntos++;
					if(contadorPuntos> 1)
					{
						retorno=0;
						break;
					}
				}
				else
				{
					if (i==0 && (cadena[i]!='+' && cadena[i]!='-' ))
					{
						retorno=0;
						break;
					}
				}
			}
		}
	 	return retorno;
 }

 /**
  * \brief Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param longitud Es el tamaño del array
  * \param reintentos Es la cantidad maxima de reintentos que puede tener el usuario
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  */
 int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,int longitud, int reintentos)
 {
	 int retorno=-1;
	 char bufferString[4096];



		 while(reintentos >= 0)
		 {
			 reintentos--;
			 printf("%s",mensaje);
			 if(getNombre(bufferString,sizeof(bufferString))== 0)
			 {

				 strncpy(pResultado,bufferString,longitud);
				 retorno=0;
				 break;
			 }
			 printf("%s",mensajeError);
		 }

	 return retorno;
 }
static int getNombre(char* pResultado, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(pResultado != NULL)
	{
		if(getString(bufferString,sizeof(bufferString))== 0 &&
			esNombre(bufferString,sizeof(bufferString)) &&
			strnlen(bufferString,sizeof(bufferString))< longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno=0;
		}
	}

	return retorno;
}

static int getString(char *cadena, int longitud)
{

	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)
				)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}

			if(strnlen(bufferString,sizeof(bufferString))<= longitud )
			{
				strncpy(cadena, bufferString,longitud);
				retorno=0;
			}
		}
	}


	return retorno;
}



static int esNombre(char *cadena, int limite)
{
	int i;
	int retorno = 1;
	if (cadena != NULL && limite > 0)
	{
		for (i=0;i<limite && cadena[i] != '\0';i++)
		{

			if((cadena[i]<'a'|| cadena[i]>'z') && (cadena [i]<'A' || cadena[i]>'Z') && cadena[i] != ' ')
			{
				retorno=0;
				break;
			}

		}
	}
	return retorno;
}
