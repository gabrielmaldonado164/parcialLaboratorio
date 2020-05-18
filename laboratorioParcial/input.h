#include <stdio.h>
#include <string.h>
#include <ctype.h>
/** \brief Solicita un numero y lo valida si es entero
 *
 * \param puntero int* Se carga el numero
 * \param texto[] char  El mensaje el cual se muestra
 * \param error[] char El mensaje de error en caso de que haya error
 * \param min int   Limite inferior a validar
 * \param max int   Limite superior a validad
 * \param intentos int  Intentos que tiene para pedir datos
 * \return int  retorna un numero entero, 0 si se pudo realizar -1 si no se pudo realizar
 *
 */
int getInt(int* puntero, char texto[],char error[] , int min , int max, int intentos);

/** \brief Se encarga de validad si el contenido que tiene guardao es de numeros enteros
 *
 * \param cadena char* recibe el string con el contenido
 * \return int Retora 0 si salio bien, 1 si salio mal
 *
 */
int esNumerico(char* cadena);
/** \brief  Se encarga de guardar un string de texto
 *
 * \param cadena char* Recibe una cadena de texto y lo guarda
 * \param longitud int  recibe el temaño que tiene el string
 * \return int retorna un 1 si esta todo bien,si esta mal retorna 0
 *
 */
int guardoDatos(char* cadena, int longitud);
/** \brief recibe una cadena de texto y valida si son numeros
 *
 * \param puntero int* recibe el string con contenido
 * \return int retorna  1 si esta bien, retorna 0 si salio mal
 *
 */
int getNumero(int* puntero);

/** \brief Solicita un numero y valida si es decimal
 *
 * \param puntero float* se carga el numero
 * \param texto[] char el mensaje que se muestra
 * \param error[] char  el mensaje que se muestra en caso de error
 * \param min float Limite inferior a validar
 * \param max float  Limite superior a validar
 * \param intentos int  Numeros de intento que tiene para pedir datos
 * \return int retorna 0 si salio bien, si salio mal retorna -1
 *
 */
int getFloat(float* puntero,char texto[], char error[],float min, float max,int intentos);
/** \brief Recibe numeros mediante un string para validarlos
 *
 * \param puntero float* guarda el dato cargado
 * \return int  retorna 1 si salio bie, retorna 0 si salio mal
 *
 */
int getNumeroFlotante(float* puntero);

/** \brief Solicita un caracter y lo valida
 *
 * \param input char*  se carga el caracter ingresado
 * \param mensaje[] char    se muestra el mensaje
 * \param error[] char      se muestra el mensaje en caso de error
 * \param caracterUno char  opcion uno de tipo char
 * \param caracterDos char  opcion dos de tipo char
 * \return int Si salio bien retorna 0, si salio mal retorna -1
 *
 */
int getOptionChar(char* input,char mensaje[],char error[], char caracterUno, char caracterDos);


/** \brief  Solicita una cadena de caracteres y los valida
 *
 * \param puntero char*  Se carga la cadena de caracteres ingresados
 * \param texto[] char   Se muestra el mensaje
 * \param error[] char   Se muestra el mensaje en caso de error
 * \param min int        Longitud minima de la cadena de caracteres
 * \param max int        Longitud minima de la cadena de caracteres
 * \param intentos int   Numeros de intento para pedir datos
 * \return char Retorna 0 si salio bien, si salio mal retorna -1
 *
 */
char getCharString(char* puntero,char texto[],char error[], int min, int max,int intentos);
/** \brief Se encarga de validad si el contenido guardado son letras
 *
 * \param cadena char* Se carga la cadena de caracteres
 * \return int  Retorna 1 si salio bien, si salio mal retorna 0
 *
 */
int esLetra(char* cadena);
/** \brief Recibe un cadena de caracteres que
 *
 * \param puntero char*
 * \return int
 *
 */
int getTexto(char* puntero);
/** \brief Se encarga si la cadena de caracteres que se le paso son numeros
 *
 * \param puntero char* se carga la cadena de caracteres ingresados
 * \param texto[] char Se muestra el mensaje
 * \param error[] char Se muestra el mensaje en caso de error
 * \param min int Longitud minima de la cadena de caracteres
 * \param max int Longitud minima de la cadena de caracteres
 * \param intentos int Numeros de intento para pedir datos
 * \return char Retorna 0 si salio bien, si salio mal retorna -1
 *
 */
char getCharStringNumeros(char* puntero,char texto[],char error[], int min, int max,int intentos);
/** \brief recibe una cadena de texto y valida si son numeros
 *
 * \param puntero char* Recibe una cadena de texto y lo guarda
 * \return int Retorna 1 si salio bien, 0 si salio mal
 *
 */
int getStringNumero(char* puntero);



