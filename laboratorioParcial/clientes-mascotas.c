#include "clientes-mascotas.h"

/////////////////////MENU PARA INGRESAR AL SWITCH EN EL MAIN//////////////////////////////
int menuPrincipal(void)
{
    int opcion;

            system("cls");
            printf("Menu de opciones\n");
            printf("1.Alta Mascota\n");
            printf("2.Baja Mascota\n");
            printf("3.Modificar Mascota\n");
            printf("4.Alta Duenio\n");
            printf("5.Baja Duenio\n");
            printf("6.Modificar Duenio\n");
            printf("7.Ordenar\n");
            printf("8.Listar\n");
            printf("9.Promedio de edad de las mascotas\n");
            printf("10.Promedio de edad de las mascotas por tipo\n");
            printf("11.Porcentaje mujeres\n");
            printf("12.Listar clientes con mascotas del mismo sexo\n");
            printf("13.Salir\n");



            printf("\nElija una opcion:");
            fflush(stdin);
            scanf("%d",&opcion);

    return opcion;

}

int menuListados(void)
{
    int opcion;

            system("cls");
            printf("Menu de opciones\n");
            printf("1.Listado de Clientes\n");
            printf("2.Listado de Mascota\n");
            printf("3.Listado de clientes con mascotas\n");
            printf("4.Listar los clientes con mas de una mascotas\n");
            printf("5.Listar mascotas mayores de 3 años, con duenio\n");
            printf("6.Listar las mascota por tipo\n");
            printf("7.Salir\n");

            printf("\nElija una opcion:");
            fflush(stdin);
            scanf("%d",&opcion);

    return opcion;

}

int menuOrdenar(void)
{
    int opcion;

            system("cls");
            printf("Menu de opciones\n");
            printf("1.Ordenar las mascotas por tipo\n");
            printf("2.Ordenar a los dueios por cantidades de mascotas y mostrarlos\n");
            printf("3.ordenar a los dueios por cantidades de mascotas y por orden alfabetico de los nombres y mostrarlos\n");
            printf("4.Salir\n");

            printf("\nElija una opcion:");
            fflush(stdin);
            scanf("%d",&opcion);

    return opcion;

}
//////////////////////////////FIN MENU////////////////////////////////////////////////


/////////////////////////////LISTADOS////////////////////////////////////////////////
void listarClientesConMascotas(eClientes listaClientes[], int sizeCliente, eMascotas listaMascotas[], int sizeMascota)
{
    char flagTieneMascota;


    for(int i=0;i<sizeCliente;i++)
    {
        if(listaClientes[i].isEmpty==OCUPADO)
        {
            printf("\n------------------------------------cliente %i------------------------------------------------\n\n",i+1);
            printf(" ID \tNOMBRE        APELLIDO        LOCALIDAD         TELEFONO       EDAD    SEXO\n");
            mostrarCliente(listaClientes,i);
            printf("\n\tMascota:\n\n");
            flagTieneMascota='n';


           printf(" ID \tNOMBRE        TIPO      RAZA                      PAIS             EDAD        PESO       SEXO   \n");


            for(int j=0;j<sizeMascota;j++)
            {
                if(listaMascotas[j].isEmpty==OCUPADO && (listaMascotas[j].idCliente == listaClientes[i].idCliente))
                {

                    mostrarMascota(listaMascotas,j);
                    flagTieneMascota='s';
                }
            }
            if(flagTieneMascota=='n')
            {
                printf("No tiene mascotas\n");
            }
            printf("\n");
        }
    }
    return 0;
}

void listarClientesConMascotasDelMismoSexo(eClientes listaClientes[], int sizeCliente, eMascotas listaMascotas[], int sizeMascota)
{
    char flagTieneMascota;


    for(int i=0;i<sizeCliente;i++)
    {
        if(listaClientes[i].isEmpty==OCUPADO)
        {
            printf("\n------------------------------------cliente %i------------------------------------------------\n\n",i+1);
            printf(" ID \tNOMBRE        APELLIDO        LOCALIDAD         TELEFONO       EDAD    SEXO\n");
            mostrarCliente(listaClientes,i);
            printf("\n\tMascota:\n\n");


            printf(" ID \tNOMBRE        TIPO      RAZA                      PAIS             EDAD        PESO       SEXO   \n");


            for(int j=0;j<sizeMascota;j++)
            {
                if(listaMascotas[j].isEmpty==OCUPADO && (listaMascotas[j].idCliente == listaClientes[i].idCliente)&& listaMascotas[j].sexo == 'H')
                {

                    mostrarMascota(listaMascotas,j);

                }
            }

        }
    }
    return 0;
}

void listarClienteConVariasMascotas(eClientes listaClientes[], int sizeClientes, eMascotas listaMascotas[], int sizeMascotas)
{
    int i;//clientes
    int j;//mascota
    eAux aux[sizeClientes];

    for(i=0;i<sizeClientes;i++)
        {
            aux[i].idCliente=listaMascotas[i].idCliente;
            aux[i].contador=0;

            for(j=0;j<sizeMascotas;j++)
                {
                    if(listaMascotas[j].isEmpty == OCUPADO &&(listaClientes[i].idCliente == listaMascotas[j].idCliente))
                        {
                            aux[i].contador++;
                        }
                }
        }
    printf("\     NOMBRE\t\tCANTIDAD\n");
    for(i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO && aux[i].contador>1)
                {

                    printf("%10s \t\t%2d\n",listaClientes[i].nombre,aux[i].contador);
                }

        }


}

void listarMascotasMayoreDeTres(eMascotas listaMascotas[], int sizeMascotas, eClientes listaClientes[], int sizeClientes)
{
    int i;//mascota
    int j;//cliente

    for(i=0;i<sizeMascotas;i++)
        {
            if(listaMascotas[i].isEmpty == OCUPADO && listaMascotas[i].edad>3)
                {
                    printf("\n------------------------------------MASCOTA %i------------------------------------------------\n\n",i+1);
                     printf(" ID \tNOMBRE        TIPO      RAZA                      PAIS             EDAD        PESO       SEXO   \n");
                    mostrarMascota(listaMascotas,i);
                    printf("\n\Cliente:\n\n");


                    printf(" ID \tNOMBRE        APELLIDO        LOCALIDAD         TELEFONO       EDAD    SEXO\n");


                    for(j=0;j<sizeClientes;j++)
                        {
                            if(listaClientes[j].isEmpty == OCUPADO &&(listaClientes[j].idCliente == listaMascotas[i].idCliente))
                            {

                                mostrarCliente(listaClientes,j);
                            }
                        }
                }
        }
}


void listarMascotasConClientes(eMascotas listaMascotas[], int sizeMascotas, eClientes listaClientes[], int sizeClientes)
{
    int i;//mascota
    int j;//cliente

    for(i=0;i<sizeMascotas;i++)
        {
            if(listaMascotas[i].isEmpty == OCUPADO)
                {
                    printf("\n------------------------------------MASCOTA %i------------------------------------------------\n\n",i+1);
                     printf(" ID \tNOMBRE        TIPO      RAZA                      PAIS             EDAD        PESO       SEXO   \n");
                    mostrarMascota(listaMascotas,i);
                    printf("\n\Cliente:\n\n");


                    printf(" ID \tNOMBRE        APELLIDO        LOCALIDAD         TELEFONO       EDAD    SEXO\n");


                    for(j=0;j<sizeClientes;j++)
                        {
                            if(listaClientes[j].isEmpty == OCUPADO &&(listaClientes[j].idCliente == listaMascotas[i].idCliente))
                            {

                                mostrarCliente(listaClientes,j);
                            }
                        }
                }
        }
}

////////////////////////////////FIN LISTADOS////////////////////////////////////////////////////


////////////////////////////////ORDENADO///////////////////////////////////////////////////////
void ordernarClientesPorCantidad(eClientes listaClientes[],int sizeClientes, eMascotas listaMascotas[],int sizeMascotas)
{
    int i;
    int j;
    int k;

    eAux aux[sizeClientes];
    eAux auxSwap;
    eClientes auxSwapCliente;



    for(i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO)
                {
                aux[i].idCliente=listaMascotas[i].idCliente;
                aux[i].contador=0;

                    for(j=0;j<sizeMascotas;j++)
                        {
                            if(listaMascotas[j].isEmpty == OCUPADO &&(listaClientes[i].idCliente == listaMascotas[j].idCliente))
                                {
                                    aux[i].contador++;
                                }
                        }
                }
        }

    for(i=0;i<sizeClientes-1;i++)
        {
            for(k=i+1;k<sizeClientes;k++)
                {
                    if(aux[i].contador >aux[k].contador )
                        {
                            auxSwap=aux[i];
                            aux[i]=aux[k];
                            aux[k]=auxSwap;

                            auxSwapCliente=listaClientes[i];
                            listaClientes[i]=listaClientes[k];
                            listaClientes[k]=auxSwapCliente;

                        }
                }
        }

    printf("\     NOMBRE\t\tCANTIDAD\n");
    for(i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO)
                {

                    printf("%10s \t\t%2d\n",listaClientes[i].nombre,aux[i].contador);
                }
        }
}


void ordenarClientePorCantidadYnombre(eClientes listaClientes[],int sizeClientes, eMascotas listaMascotas[],int sizeMascotas)
{
    int i;
    int j;
    int k;

    eAux aux[sizeClientes];
    eAux auxSwap;
    eClientes auxSwapCliente;



    for(i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO)
                {
                aux[i].idCliente=listaMascotas[i].idCliente;
                aux[i].contador=0;

                    for(j=0;j<sizeMascotas;j++)
                        {
                            if(listaMascotas[j].isEmpty == OCUPADO &&(listaClientes[i].idCliente == listaMascotas[j].idCliente))
                                {
                                    aux[i].contador++;
                                }
                        }
                }
        }

    for(i=0;i<sizeClientes-1;i++)
        {
            for(k=i+1;k<sizeClientes;k++)
                {
                    if(aux[i].contador >aux[k].contador )
                        {
                            auxSwap=aux[i];
                            aux[i]=aux[k];
                            aux[k]=auxSwap;

                            auxSwapCliente=listaClientes[i];
                            listaClientes[i]=listaClientes[k];
                            listaClientes[k]=auxSwapCliente;

                        }
                    else
                        {
                            if(aux[i].contador == aux[k].contador)
                                {
                                    if(strcmp(listaClientes[i].nombre,listaClientes[k].nombre)>0)
                                        {
                                            auxSwap=aux[i];
                                            aux[i]=aux[k];
                                            aux[k]=auxSwap;

                                            auxSwapCliente=listaClientes[i];
                                            listaClientes[i]=listaClientes[k];
                                            listaClientes[k]=auxSwapCliente;
                                        }
                                }
                        }
                }
        }

       printf("\     NOMBRE\t\tCANTIDAD\n");
    for(i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO)
                {
                    printf("%10s \t\t%2d\n",listaClientes[i].nombre,aux[i].contador);
                }
        }
}
////////////////////////////////////////FIN ORDENADO//////////////////////////////////////////
