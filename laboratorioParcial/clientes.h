#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idCliente;
    char nombre[50];
    char apellido[50];
    char localidad[50];
    char telefono[50];
    int edad;
    char sexo;
    int isEmpty;


}eClientes;

/** \brief Precarga datos en el array
 * \param listaClientes[] eClientes la estructura en la cual estamos trabajando
 * \return void muestra los datos
 *
 */
void harcodeoClientes(eClientes listaClientes[]);
/** \brief  Inicializa todo el array de datos con un estado de libre u ocupado
 *
 * \param listarClientes[] eClientes el array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int la longitud que tiene el array
 * \return void
 *
 */
void inicializarClientes(eClientes listarClientes[], int sizeClientes);
/** \brief muestra un cliente cargado
 *
 * \param listarClientes[] eClientes el array de la estrucutura en la cual estamos trabajando
 * \param i int entero que recorre el array
 * \return void
 *
 */
void mostrarCliente(eClientes listarClientes[],int i);

/** \brief  muestra la lista completa de los cliente cargados
 *
 * \param listarClientes[] eClientes el array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int la longitud que tiene el array
 * \return void
 *
 */
void listarClientes(eClientes listarClientes[],int sizeClientes);
/** \brief  Se encarga de generar un ID incremental
 *
 * \param listaClientes[] eClientes  el array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int int la longitud que tiene el array
 * \return int retorna el ID
 *
 */

int idClientes(eClientes listaClientes[], int sizeClientes);
/** \brief Se encarca de buscar un indice libre dentro del array para poder cargar datos
 *
 * \param listaClientes[] eClientes  el array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int  la longitud que tiene el array
 * \return int retorna el indice libre
 *
 */
int buscarIndexCliente(eClientes listaClientes[], int sizeClientes);
/** \brief Se encargar de buscar un ID en el array ya existente
 *
 * \param listaClientes[] eClientes  el array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int la longitud que tiene el array
 * \return int retorna el indice donde se encontro el ID
 *
 */
int buscarIdCliente(eClientes listaClientes[], int sizeClientes);
/** \brief Se encargar de dar de alta datos de una posicion  dentro del array
 *
 * \param listaClientes[] eClientes el array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int la longitud que tiene el array
 * \return int retorna 1 si salio bien, -1 si salio mal
 *
 */
int altaClientes(eClientes listaClientes[],int sizeClientes);
/** \brief Se encarga de dara una baja logica  datos cargado dentro de una posicion del array
 *
 * \param listaClientes[] eClientes  array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int la longitud que tiene el array
 * \param listaMascotas[] eMascotas  segundo array de la estrucutura en la cual estamos trabajando
 * \param sizeMascotas int la longitud que tiene el segundo array
 * \return int retorna 1 si la baja salio bien, -1 si la baja salio mal
 *
 */
int  bajaCliente(eClientes listaClientes[], int sizeClientes, eMascotas listaMascotas[], int sizeMascotas);

/** \brief Se encarga de modificar datos dentro de una posicion del array
 *
 * \param listaClientes[] eClientes  array de la estrucutura en la cual estamos trabajando
 * \param sizeCliente int la longitud que tiene el array
 * \return void
 *
 */
void modificarCliente(eClientes listaClientes[],int sizeCliente);
/** \brief Se encarga de contar cuantos clientes varones hay dentro del array
 *
 * \param listaClientes[] eClientes  array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int la longitud que tiene el array
 * \return int retorna el el valor acumulado del contador
 *
 */
int contadorVarones(eClientes listaClientes[],int sizeClientes);
/** \brief Se encarga de contar cuantos clientes mujeres hay dentro del array
 *
 * \param listaClientes[] eClientes array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int la longitud que tiene el array
 * \return int retorna el el valor acumulado del contador
 *
 */
int contadorMujeres(eClientes listaClientes[], int sizeClientes);
/** \brief Se encarga de calcular el promedio de los clientes en el sistema y mostrarlos
 *
 * \param listaClientes[] eClientes  array de la estrucutura en la cual estamos trabajando
 * \param sizeClientes int  la longitud que tiene el array
 * \return void
 *
 */
void promedioDeClientes(eClientes listaClientes[], int sizeClientes);

