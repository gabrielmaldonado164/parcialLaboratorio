#include "clientes-mascotas.h"
void harcodeoClientes(eClientes listaClientes[])
{
    eClientes clientes[]={
        {1,"Gabriela","Bautista","Barracas","1560292029",30,'m',1},
        {2,"Kevin","Ahumada","La Boca","1589203192",10,'v',1},
        {3,"Ulises","Tomas","San telmo","1563209726",60,'v',1},
        {4,"Maria","Gonzales","Avellaneda","1530862715",15,'m',1},
        {5,"Pepe","Toledo","Belgrano","1598062853",55,'v',1}
    };

    for(int i=0;i<5;i++)
        {
            listaClientes[i]=clientes[i];
        }
}

//////////////////MENU MODIFICACIONES /////////////////////////////////////

int menuModificaciones(void)
{
    int opcion;

            system("cls");
            printf("Menu de opciones \n");
            printf("1.Modificar ID\n");
            printf("2.Modificar nombre\n");
            printf("3.Modificar apellido\n");
            printf("4.Modificar localidad\n");
            printf("5.Modificar telefono\n");
            printf("6.Modificar edad\n");
            printf("7.Modificar sexo\n");
            printf("8.Salir\n");

            printf("\nElija una opcion:");
            fflush(stdin);
            scanf("%d",&opcion);

    return opcion;

}
/////////////////////////////////////////////////////////////

void inicializarClientes(eClientes listarClientes[], int sizeClientes)
{
    for(int i=0;i<sizeClientes;i++)
        {
            listarClientes[i].isEmpty=LIBRE;
        }
}

int contadorClientes(eClientes listaClientes[], int sizeClientes)
{
    int i;
    int contador=0;

    for(i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO)
                {
                    contador++;
                }
        }

    return contador;
}

void mostrarCliente(eClientes listarClientes[],int i)
{
    printf("%2d | %4s \t%14s \t%14s  \t%-12s | \t%d \t%c \n",listarClientes[i].idCliente,listarClientes[i].nombre,listarClientes[i].apellido,listarClientes[i].localidad,listarClientes[i].telefono,listarClientes[i].edad,listarClientes[i].sexo);

}

void listarClientes(eClientes listarClientes[],int sizeClientes)
{
    int i;
    int hayClientes;

    hayClientes=contadorClientes(listarClientes,sizeClientes);

    if(hayClientes>=1)
        {   printf(" ID \tNOMBRE        APELLIDO        LOCALIDAD         TELEFONO       EDAD    SEXO\n");
            printf("------------------------------------------------------------------------------------\n");

            for(i=0;i<sizeClientes;i++)
                {
                    if(listarClientes[i].isEmpty == OCUPADO)
                        {
                            mostrarCliente(listarClientes,i);
                        }
                }
        }
    else
        {
            printf("No hay clientes en el sistema\n");
        }
}

int idClientes(eClientes listaClientes[], int sizeClientes)
{
    int id=1;

    for(int i=0; i<sizeClientes;i++)
    {
        if(listaClientes[i].isEmpty == LIBRE)
        {
            break;
        }
        else
        {
            id++;
        }
    }
    return id;
}

int buscarIndexCliente(eClientes listaClientes[], int sizeClientes)
{
    int indice=-1;

    for(int i=0;i<sizeClientes;i++)
    {
        if(listaClientes[i].isEmpty == LIBRE)
        {
            indice=i;
            listaClientes[i].idCliente= idClientes(listaClientes,sizeClientes);
            break;
        }
    }

    return indice;
}

int buscarIdCliente(eClientes listaClientes[], int sizeClientes)
{
    int id;
    int indice=-1;

    getInt(&id,"Ingrese ID del cliente:","Error, no se encontro un ID para esa mascota\n",1,500,10);

    for(int i=0;i<sizeClientes;i++)
    {
        if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].idCliente==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int altaClientes(eClientes listaClientes[],int sizeClientes)
{
    int altaExitosa=-1;
    int indiceEncontrado=buscarIndexCliente(listaClientes,sizeClientes);
    int clientesCargados=contadorClientes(listaClientes,sizeClientes);

    if(indiceEncontrado == -1)
        {
            printf("No hay mas espacio en el sistema\n");
        }
    else
        {
            getCharString(&listaClientes[indiceEncontrado].nombre,"Ingrese nombre del cliente:","Error, no son letras validas\n",1,50,10);
            getCharString(&listaClientes[indiceEncontrado].apellido,"Ingrese apellido del cliente:","Error,  no son letras validas\n",1,50,10);
            getCharString(&listaClientes[indiceEncontrado].localidad,"Ingrese localidad del cliente:","Error, localidad no valida\n",1,50,10);
            getCharStringNumeros(&listaClientes[indiceEncontrado].telefono,"Ingrese telefono:","Error, deben ser numeros\n",1,50,10);
            getInt(&listaClientes[indiceEncontrado].edad,"Ingrese la edad del cliente:","Error, debe ser en numeros\n",1,100,10);
            getOptionChar(&listaClientes[indiceEncontrado].sexo,"Ingrese sexo del cliente[M/H][Mujer/Hombre]:","Error, no es un letra valida",'m','h');

            listaClientes[indiceEncontrado].isEmpty = OCUPADO;


            system("pause");
            system("cls");
            printf("Cliente cargado correctamente\n\n");
            printf(" ID \tNOMBRE        APELLIDO        LOCALIDAD         TELEFONO       EDAD    SEXO\n");
            mostrarCliente(listaClientes,indiceEncontrado);
            printf("\n");

            altaExitosa=1;

        }

    return altaExitosa;
}

int  bajaCliente(eClientes listaClientes[], int sizeClientes, eMascotas listaMascotas[], int sizeMascotas)
{

    int indiceEncontado;
    int clientesCargados;
    int bajaExitosa=-1;
    char seguir;

    clientesCargados=contadorClientes(listaClientes,sizeClientes);

    if(clientesCargados>=1)
        {

           listarClientes(listaClientes,sizeClientes);
           indiceEncontado=buscarIdCliente(listaClientes,sizeClientes);

            if(listaClientes[indiceEncontado].isEmpty == OCUPADO)
                {
                    printf("El siguiente cliente se eliminara\n");
                    mostrarCliente(listaClientes,indiceEncontado);

                   getOptionChar(&seguir,"Desea continuar S/N","Error, no son letras validas\n",'s','n');

                    if(seguir=='S')
                        {
                            listaClientes[indiceEncontado].isEmpty = LIBRE;
                            listaMascotas[indiceEncontado].isEmpty = LIBRE;
                            printf("Se elimino correctamente\n");
                            bajaExitosa=1;

                        }else
                        {

                            printf("Volviendo al menu\n");
                        }

                }else
                {
                    printf("No  hay cliente con ese ID\n");
                }


        }else
        {
            printf("No hay cliente en  el sistema\n");
        }

    return bajaExitosa;


}

void modificarCliente(eClientes listaClientes[],int sizeCliente)
{

    int clienteCargados;
    int indiceEncontrado;
    char seguir;
    char salida;
    char continuar;

    clienteCargados=contadorClientes(listaClientes,sizeCliente);//tengo que ver si hay empledados cargados pq si no ni entro al if

    if(clienteCargados>=1)
        {
            listarClientes(listaClientes,sizeCliente);
            indiceEncontrado=buscarIdCliente(listaClientes,sizeCliente);

            if(listaClientes[indiceEncontrado].isEmpty == OCUPADO)
                {
                    printf("El siguien cliente  sera modificado\n");
                    mostrarCliente(listaClientes,indiceEncontrado);

                    getOptionChar(&seguir,"Desea seguir con la modificacion [S/N]","Error, no es una letra valida\n",'s','n');

                    if(seguir == 'S')
                        {

                            do{
                                switch(menuModificaciones())
                                {
                                    case 1:
                                           getInt(&listaClientes[indiceEncontrado].idCliente,"Ingrese ID del cliente","Error, no es un numero\n",1,500,10);
                                            break;
                                    case 2:
                                            getCharString(&listaClientes[indiceEncontrado].nombre,"Ingrese el nombre del cliente:","Error, no son letras validas\n",1,50,10);
                                            break;
                                    case 3:
                                            getCharString(&listaClientes[indiceEncontrado].apellido,"Ingrese el apellido del cliente:","Error, no son letras validasd\n",1,50,10);
                                            break;

                                    case 4:
                                            getCharString(&listaClientes[indiceEncontrado].localidad,"Ingrese localidad del cliente:","Error, deben ser letras\n",1,50,10);
                                            break;
                                    case 5:
                                            getCharString(&listaClientes[indiceEncontrado].telefono,"Ingrese telefono contacto:","Error, no es un numero correcto\n",1,50,10);
                                            break;
                                    case 6:
                                            getInt(&listaClientes[indiceEncontrado].edad,"Ingrese la edad del cliente:","Error, debe ser en numeros\n",1,100,10);
                                            break;
                                    case 7:
                                            getOptionChar(&listaClientes[indiceEncontrado].sexo,"Ingrese sexo del cliente[M/H]:","Error, no es un letra valida",'m','h');
                                            break;
                                    case 8:

                                        getOptionChar(&salida,"Desea salir [S/N]:","Error, no es una letra valida\n",'s','n');

                                        if(salida == 'S')
                                            {
                                                continuar='n';
                                            }
                                        break;

                                    default :
                                            printf("Opcion invalida\n\n");
                                            break;
                                }

                                system("pause");
                                system("cls");
                                printf("Cliente modificado correctamente\n\n");

                                mostrarCliente(listaClientes,indiceEncontrado);

                                fflush(stdin);

                            }while(continuar == 's');

                            }else
                            {
                                printf("Volviendo al menu principal");
                            }

                }else
                {
                    printf("\nNo se ha encontrado clientes  en el sistema con el ID ingresado.\n\n");
                }
        }else
        {
            printf("No hay clientes cargados");
        }

}

int contadorVarones(eClientes listaClientes[],int sizeClientes)
{
    int contador=0;
    for(int i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].sexo == 'v')
                {
                    contador++;
                }
        }
    return contador;

}

int contadorMujeres(eClientes listaClientes[], int sizeClientes)
{
    int contador=0;
    for(int i=0;i<sizeClientes;i++)
        {
            if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].sexo == 'M')
                {
                    contador++;
                }
        }
    return contador;
}

void promedioDeClientes(eClientes listaClientes[], int sizeClientes)
{

        float promedioMujeres=0;

        promedioMujeres=contadorClientes(listaClientes,sizeClientes)*100/contadorMujeres(listaClientes,sizeClientes);

        printf("El porcetaje es de de mujeres es de:%2.2f\n",promedioMujeres);

}
