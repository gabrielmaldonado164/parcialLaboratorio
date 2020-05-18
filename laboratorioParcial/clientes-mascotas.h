#include <stdio.h>
#include <string.h>
#include "mascotas.h"
#include "clientes.h"
#include "input.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idCliente;
    int idMasctoa;
    int contador;
}eAux;
/** \brief Menu principal, que se encarga de mostrar los datos para seleccionar las opciones
 *
 * \param void
 * \return int returna el valor ingresado
 *
 */
int menuPrincipal(void);
/** \brief Menu de los listados, que se encarga de mostrar los datos para listar
 *
 * \param void
 * \return int retorna el valor ingresado
 *
 */
int menuListados(void);
/** \brief Menu para mostrar los datos ordenados
 *
 * \param void
 * \return int retornar el valor ingresado
 *
 */
int menuOrdenar(void);
/** \brief Se encarga de mostrar los datos del los  cliente con sus respectivas  mascotas
 *
 * \param listaClientes[] eClientes el primer array con el cual se trabaja
 * \param sizeCliente int longitud del primer array
 * \param listaMascotas[] eMascotas el segundo array con el cual se trabaja
 * \param sizeMascota int longitud del segundo array
 * \return void
 *
 */
void listarClientesConMascotas(eClientes listaClientes[], int sizeCliente, eMascotas listaMascotas[], int sizeMascota);
/** \brief Se encarga de listar los clientes que tienen mas de 1 mascota
 *
 * \param listaClientes[] eClientes el primer array con el cual se trabaja
 * \param sizeClientes int longitud del primer array
 * \param listaMascotas[] eMascotas el segundo array con el cual se trabaja
 * \param sizeMascotas int longitud del segundo array
 * \return void
 *
 */
void listarClienteConVariasMascotas(eClientes listaClientes[], int sizeClientes, eMascotas listaMascotas[], int sizeMascotas);
/** \brief Se encarga de mostrar las mascotas mayores a 3 años con sus clientes
 *
 * \param listaMascotas[] eMascotas  el primer array con el cual se trabaja
 * \param sizeMascotas int longitud del primer array
 * \param listaClientes[] eClientes el segundo array con el cual se trabaja
 * \param sizeClientes int longitud del segundo array
 * \return void
 *
 */
void listarMascotasMayoreDeTres(eMascotas listaMascotas[], int sizeMascotas, eClientes listaClientes[], int sizeClientes);
/** \brief Se encarga de mostrar las mascotas con los clientes correspondiente
 *
 * \param listaMascotas[] eMascotas el primer array con el cual se trabaja
 * \param sizeMascotas int longitud del primer array
 * \param listaClientes[] eClientes el segundo array con el cual se trabaja
 * \param sizeClientes int longitud del segundo array
 * \return void
 *
 */
void listarMascotasConClientes(eMascotas listaMascotas[], int sizeMascotas, eClientes listaClientes[], int sizeClientes);
/** \brief Se encarga de ordenar a los clientes por cantidad de mascotas que tengan y los muestra
 *
 * \param listaClientes[] eClientes  el primer array con el cual se trabaja
 * \param sizeClientes int  longitud del primer array
 * \param listaMascotas[] eMascotas el segundo array con el cual se trabaja
 * \param sizeMascotas int  longitud del segundo array
 * \return void
 *
 */
void ordernarClientesPorCantidad(eClientes listaClientes[],int sizeClientes, eMascotas listaMascotas[],int sizeMascotas);
/** \brief Se encarga de ordenar a los clientes por cantidad de mascotas y alfabeticamente por nombre
 *
 * \param listaClientes[] eClientes el primer array con el cual se trabaja
 * \param sizeClientes int  longitud del primer array
 * \param listaMascotas[] eMascotas el segundo array con el cual se trabaja
 * \param sizeMascotas int longitud del segundo array
 * \return void
 *
 */
void ordenarClientePorCantidadYnombre(eClientes listaClientes[],int sizeClientes, eMascotas listaMascotas[],int sizeMascotas);
