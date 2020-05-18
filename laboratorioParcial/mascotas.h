#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
typedef struct
{

    char nombre[50];
    char pais[50];

}eRaza;

typedef struct
{
    int idMascota;
    int idCliente;
    char nombre[50];
    int tipo;
    //char raza[50];
    eRaza raza;
    int edad;
    float peso;
    char sexo;
    int isEmpty;

}eMascotas;


/** \brief Precarga datos en el array
 *
 * \param listaMascotas[] eMascotas el array con el cual se esta trabajando
 * \return void
 *
 */
void harcodeoMascotas(eMascotas listaMascotas[]);
/** \brief Menu  de modificaciones, que muestra las opciones
 *
 * \param void
 * \return int retorna el valor que se ingreso
 *
 */
int menuModificacion(void);
/** \brief Inicializa todo los datos de la estructura en valor LIBRE u OCUPADO
 *
 * \param listaMascotas[] eMascotas  el array con el cual se esta trabajando
 * \param sizeMascotas int longitud del array
 * \return void
 *
 */
void inicioMascotas(eMascotas listaMascotas[],int sizeMascotas);
/** \brief Cuenta cuantas mascotas hay dentro del array cargadas correctamente
 *
 * \param listaMascotas[] eMascotas  el array con el cual se esta trabajando
 * \param sizeMascotas int longitud del array
 * \return int returnar el valor acumulado del contador
 *
 */
int contadorMascotas(eMascotas listaMascotas[],int sizeMascotas);
/** \brief Muestra los tipos de raza que hay cargados dentro del array
 *
 * \param tipo int recibe el valor elegido de las opciones mostradas
 * \return char* muestra los tipos de raza
 *
 */
char* TipoRaza(int tipo);
/** \brief Muestra una masctota de una posicion del array
 *
 * \param listarMascotas[] eMascotas  el array con el cual se esta trabajando
 * \param i int  indicen del array
 * \return void
 *
 */
void mostrarMascota(eMascotas listarMascotas[],int i);
/** \brief Muestra todas las mascotas del array
 *
 * \param listaMascotas[] eMascotas  l array con el cual se esta trabajando
 * \param sizeMascota int
 * \return void
 *
 */
void listarMascotas(eMascotas listaMascotas[], int sizeMascota);

