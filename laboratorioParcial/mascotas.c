#include "clientes-mascotas.h"

void harcodeoMascotas(eMascotas listaMascotas[])
{
    eMascotas mascotas[]={

        {1,1,"Lupe",1,"Bengala","Canada",5,10.5,'h',1},
        {2,1,"Poni",1,"Persa","Francia",2,15,'h',1},
        {3,2,"Toni",2,"Labrador","Aleman",2,15.5,'m',1},
        {4,3,"Benito",2,"Galgo","Italiano",10,22.2,'m',1},
        {5,3,"Rocky",2,"Galgo","Italiano",3,16,'m',1},
        {6,3,"Tobi",1,"Persa","Francia",3,10,'m',1},
        {7,4,"Rufu",2,"Pitbull","Argentino",5,15.3,'m',1},
        {8,4,"Lopi",3,"Iguana","Africano",1,2,'m',1},
        {9,5,"Sizi",1,"Bengala","Canada",10,15,'m',1},
        {10,5,"Feli",1,"Siames","Mexicano",2,10.9,'m',1},
        {11,5,"Toribio",2,"Bulldog","Frances",8,20.9,'m',1}

    };

    for(int i=0;i<11;i++)
        {
            listaMascotas[i]=mascotas[i];

        }
}
//////////////////MENU MODIFICACIONES /////////////////////////////////////

int menuModificacion(void)
{
    int opcion;

            system("cls");
            printf("Menu de opciones \n");
            printf("1.Modificar ID\n");
            printf("2.Modificar nombre\n");
            printf("3.Modificar tipo\n");
            printf("4.Modificar raza\n");
            printf("5.Modificar edad\n");
            printf("6.Modificar peso\n");
            printf("7.Modificar sexo\n");
            printf("8.Modificar sexo\n");

            printf("9.Salir\n");

            printf("\nElija una opcion:");
            fflush(stdin);
            scanf("%d",&opcion);

    return opcion;

}
///////////////////////FIN MENU///////////////////////////////////////



void inicioMascotas(eMascotas listaMascotas[],int sizeMascotas)
{
    for(int i=0;i<sizeMascotas;i++)
        {
            listaMascotas[i].isEmpty=LIBRE;
        }
}



int contadorMascotas(eMascotas listaMascotas[],int sizeMascotas)
{
    int i;
    int contador=0;

    for(i=0;i<sizeMascotas;i++)
        {
            if(listaMascotas[i].isEmpty == OCUPADO)
                {
                    contador++;
                }
        }

    return contador;

}

//////////////////////////////LISTAR/////////////////////////////////////////

char* TipoRaza(int tipo)
{
    char* raza;

    switch(tipo)
    {
        case 1:
            raza="Gato";
            break;

        case 2:
            raza="Perro";
            break;

        case 3:
            raza="Raro";
            break;

        default:
            raza="No es ningun tipo de animal";
            break;
    }

    return raza;
}

void listarTipoAnimal()
{
    for(int i=1;i<=3;i++)
    {
        printf("%d - %s\n",i ,TipoRaza(i));
    }
}

void mostrarMascota(eMascotas listarMascotas[],int i)
{
    printf("%2d | %7s \t%10s \t%10s \t%15s\t%15d \t%5.2f \t%5c\n",listarMascotas[i].idMascota,listarMascotas[i].nombre,TipoRaza(listarMascotas[i].tipo),listarMascotas[i].raza.nombre, listarMascotas[i].raza.pais,listarMascotas[i].edad,listarMascotas[i].peso,listarMascotas[i].sexo);
}



void listarMascotas(eMascotas listaMascotas[], int sizeMascota)
{
    int i;
    int hayMascotas;

    hayMascotas = contadorMascotas(listaMascotas,sizeMascota);

    if(hayMascotas>=1)
        {
            printf(" ID \tNOMBRE        TIPO      RAZA                      PAIS             EDAD        PESO       SEXO   \n");
            printf("------------------------------------------------------------------------------------\n");
            for(i=0;i<sizeMascota;i++)
                {
                    if(listaMascotas[i].isEmpty == OCUPADO)
                        {
                            mostrarMascota(listaMascotas,i);
                        }
                }
        }
    else
        {
            printf("No hay mascotas en el sistema\n");
        }
}

void listarMasctotaPorTipo(eMascotas listaMascota[], int sizeMasctota)
{
    int i;
    int tipo;

    listarTipoAnimal();
    getInt(&tipo,"Seleccione el tipo de animal para visualizar su lista:","Error, no es un una saleccion valida\n",1,3,10);
     printf(" ID \tNOMBRE        TIPO      RAZA                      PAIS             EDAD        PESO       SEXO   \n");

    for(i=0;i<sizeMasctota;i++)
        {
            if(listaMascota[i].isEmpty == OCUPADO && listaMascota[i].tipo == tipo)
                {
                    //printf("%s:",TipoRaza(listaMascota[i].tipo));
                    mostrarMascota(listaMascota,i);
                }
        }


}

/////////////////////////FIN LISTAR//////////////////////////////////////

int idMascotas(eMascotas listaMascotas[],int sizeMascotas)
{
    int id=1;

    for(int i=0; i<sizeMascotas;i++)
    {
        if(listaMascotas[i].isEmpty == LIBRE)
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

int buscarIndexLibre(eMascotas listaMascotas[],int sizeMascotas)
{
    int indice=-1;

    for(int i=0;i<sizeMascotas;i++)
    {
        if(listaMascotas[i].isEmpty == LIBRE)
        {
            indice=i;
            listaMascotas[i].idMascota= idMascotas(listaMascotas,sizeMascotas);
            break;
        }
    }

    return indice;
}

int buscarIdMascota(eMascotas listaMascota[], int sizeMascota)
{
    int id;
    int indice=-1;

    getInt(&id,"Ingrese ID de la mascota:","Error, no se encontro un ID para esa mascota\n",1,500,10);

    for(int i=0;i<sizeMascota;i++)
    {
        if(listaMascota[i].isEmpty == OCUPADO && listaMascota[i].idMascota==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void ordenarMascotaPorTipo(eMascotas listaMascotas[], int sizeMascotas, eClientes listaClientes[], int sizeClientes)
{
    int i;
    int k;

    eMascotas auxSwap;
    eClientes auxSwapCliente;

    for(i=0;i<sizeMascotas-1;i++)
        {
            for(k=i+1;k<sizeMascotas;k++)
                {
                    if(listaMascotas[i].tipo>listaMascotas[k].tipo)
                        {
                            auxSwap=listaMascotas[i];
                            listaMascotas[i]=listaMascotas[k];
                            listaMascotas[k]=auxSwap;

                            auxSwapCliente=listaClientes[i];
                            listaClientes[i]=listaClientes[k];
                            listaClientes[k]=auxSwapCliente;

                        }
                }
        }



        for(i=0;i<sizeMascotas;i++)
            {
                if(listaMascotas[i].isEmpty == OCUPADO)
                    {

                        printf("%s\n",TipoRaza(listaMascotas[i].tipo));
                    }
            }
}

int altaMascota(eMascotas listaMascota[],int sizeMascota, eClientes listaClientes[], int sizeClientes)
{
    int altaExitosa=-1;
    int indiceEncontrado=buscarIndexLibre(listaMascota,sizeMascota);
    int clientesCargados;
    clientesCargados = contadorClientes(listaClientes,sizeClientes);

    if(indiceEncontrado == -1)
        {
            printf("No hay mas espacio en el sistema\n");
        }
    else
        {
            if(clientesCargados>=1)
                {

                    getCharString(&listaMascota[indiceEncontrado].nombre,"Ingrese nombre de la mascota:","Error, no es un nombre valido\n",1,50,10);
                    listarTipoAnimal();
                    getInt(&listaMascota[indiceEncontrado].tipo,"Ingrese el tipo de animas, selecione una opcion [1-2-3]:","Error, no es una opcion valida\n",1,3,10);
                    switch(listaMascota[indiceEncontrado].tipo)
                    {
                    case 1:
                            getCharString(&listaMascota[indiceEncontrado].raza.nombre,"Ingrese nombre de la raza:","Error, debe ser letras\n",1,50,10);
                            getCharString(&listaMascota[indiceEncontrado].raza.pais,"Ingrese pais ","Error, debe se letras\n",1,50,10);
                            break;
                    case 2:
                            getCharString(&listaMascota[indiceEncontrado].raza.nombre,"Ingrese nombre de la raza:","Error, debe ser letras\n",1,50,10);
                            getCharString(&listaMascota[indiceEncontrado].raza.pais,"Ingrese pais :","Error, debe se letras\n",1,50,10);
                            break;
                    case 3:
                            getCharString(&listaMascota[indiceEncontrado].raza.nombre,"Ingrese nombre de la raza:","Error, debe ser letras\n",1,50,10);
                            getCharString(&listaMascota[indiceEncontrado].raza.pais,"Ingrese pais","Error, debe se letras\n",1,50,10);
                            break;

                    }
                    getInt(&listaMascota[indiceEncontrado].edad,"Ingrese edad de la mascota:","Error, no es un numero\n",1,100,10);
                    getFloat(&listaMascota[indiceEncontrado].peso,"Ingrese el peso de la mascota:","Error, debe ser en numeros",1,150,10);
                    getOptionChar(&listaMascota[indiceEncontrado].sexo,"Ingrese el sexo de la mascota[M/H][Macho/Hembra]:","Error, no es una letra valida\n",'m','h');

                    listarClientes(listaClientes,sizeClientes);

                    getInt(&listaMascota[indiceEncontrado].idCliente,"Ingrese el ID del duenio de la mascota:","Error, no es un ID valido\n",1,25,10);

                    listaMascota[indiceEncontrado].isEmpty=OCUPADO;

                    system("pause");
                    system("cls");
                    printf("Mascota Cargada correctamente\n\n");
                      printf(" ID \tNOMBRE        TIPO      RAZA                      PAIS             EDAD        PESO       SEXO   \n");
                    mostrarMascota(listaMascota,indiceEncontrado);
                    printf("\n");

                    altaExitosa=1;
                }
                else
                    {
                        printf("Primero debe cargar un cliente, ya que no se puede cambiar el cliente\n");
                    }

        }

    return altaExitosa;


}

int  bajaMascota(eMascotas listaMascota[], int sizeMascotas)
{

    int indiceEncontado;
    int mascotasCargadas;
    int bajaExitosa=-1;
    char seguir;

    mascotasCargadas=contadorMascotas(listaMascota,sizeMascotas);

    if(mascotasCargadas>=1)
        {

            listarMascotas(listaMascota,sizeMascotas);
            indiceEncontado=buscarIdMascota(listaMascota,sizeMascotas);

            if(listaMascota[indiceEncontado].isEmpty == OCUPADO)
                {
                    printf("La siguiente mascosta se dara de baja:\n");
                    mostrarMascota(listaMascota,indiceEncontado);

                   getOptionChar(&seguir,"Desea continuar S/N","Error",'s','n');

                    if(seguir=='S')
                        {
                            listaMascota[indiceEncontado].isEmpty = LIBRE;
                            printf("Se elimino correctamente\n");
                            bajaExitosa=1;

                        }else
                        {

                            printf("Volviendo al menu\n");
                        }

                }else
                {
                    printf("No  hay mascota con ese ID\n");
                }


        }else
        {
            printf("No hay mascotas en el sistema\n");
        }

    return bajaExitosa;


}

void modificarMascota(eMascotas listaMascotas[],int sizeMascota,eClientes listaClientes[], int sizeClientes)
{

    int mascotaCargadas;
    int indiceEncontrado;
    char seguir;
    char salida;
    char continuar;

    mascotaCargadas=contadorMascotas(listaMascotas,sizeMascota);//tengo que ver si hay empledados cargados pq si no ni entro al if

    if(mascotaCargadas>=1)
        {
            listarMascotas(listaMascotas,sizeMascota);
            indiceEncontrado=buscarIdMascota(listaMascotas,sizeMascota);

            if(listaMascotas[indiceEncontrado].isEmpty == OCUPADO)
                {
                    printf("La siguiente mascota  sera modificada:");
                    mostrarMascota(listaMascotas,indiceEncontrado);

                    getOptionChar(&seguir,"Desea seguir con la modificacion [S/N]","Error, no es una letra valida\n",'s','n');

                    if(seguir == 'S')
                        {

                            do{
                                switch(menuModificacion())
                                {
                                    case 1:
                                           getInt(&listaMascotas[indiceEncontrado].idMascota,"Ingrese ID de la mascota","Error, no es un numero\n",1,500,10);
                                           system("pause");
                                            break;
                                    case 2:
                                            getCharString(&listaMascotas[indiceEncontrado].nombre,"Ingrese el nombre de la mascota:","Error, no son letras validas\n",1,50,10);
                                            system("pause");
                                            break;
                                    case 3:
                                            listarTipoAnimal();
                                            getInt(&listaMascotas[indiceEncontrado].tipo,"Selecciona una opcion [1-2-3]:","Error, no es una opcion validad\n",1,3,10);
                                            system("pause");
                                            break;

                                    case 4:
                                            getCharString(&listaMascotas[indiceEncontrado].raza,"Ingrese raza de la mascota:","Error, deben ser letras\n",1,50,10);
                                            system("pause");
                                            break;
                                    case 5:
                                            getInt(&listaMascotas[indiceEncontrado].edad,"Ingrese edad de la mascota:","Error, es un numero valido\n",1,60,10);
                                            system("pause");
                                            break;
                                    case 6:
                                            getFloat(&listaMascotas[indiceEncontrado].peso,"Ingrese peso de la mascota:","Error, no es un numero valido\n",1,150,10);
                                            system("pause");
                                            break;
                                    case 7:
                                            getOptionChar(&listaMascotas[indiceEncontrado].sexo,"Ingrese sexo de la mascota [M/H]:","Error, no es una letra valida\n",'m','h');
                                            system("pause");
                                            break;
                                    case 8:
                                            listarClientes(sizeClientes,indiceEncontrado);
                                            getInt(&listaMascotas[indiceEncontrado].idCliente,"Ingrese ID del cliente:","Error, no es un ID correspondiente\n",1,1000,10);
                                            system("pause");
                                            break;

                                    case 9:

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
                                printf("Mascota modificada correctamente\n\n");
                                mostrarMascota(listaMascotas,indiceEncontrado);

                                fflush(stdin);

                            }while(continuar == 's');

                            }else
                            {
                                printf("Volviendo al menu principal\n");
                            }

                }else
                {
                    printf("\nNo se ha encontrado una mascota en el sistema con el ID ingresado.\n\n");
                }
        }else
        {
            printf("No hay mascotas cargados\n");
        }

}

int promedioEdadMascotas(eMascotas listaMasctotas[], int sizeMascotas)
{
    int i;
    int suma=0;
    float promedio=0;
    int hayMascotas;

    hayMascotas=contadorMascotas(listaMasctotas,sizeMascotas);

    if(hayMascotas>=1)
        {
            for(i=0;i<sizeMascotas;i++)
                {
                    if(listaMasctotas[i].isEmpty == OCUPADO)
                        {
                            suma=suma+listaMasctotas[i].edad;
                        }
                }
            promedio=(float)suma/contadorMascotas(listaMasctotas,sizeMascotas);

            printf("Hay %d mascotas en el sistema\n\n",contadorMascotas(listaMasctotas,sizeMascotas));
            printf("El promedio de edad de las mascota es de: %.2f anios\n",promedio);
        }
        else
            {
                printf("No hay mascotas cargadas para realizar promedios\n");
            }

    return promedio;
}

void promedioPorTipoMascota(eMascotas listaMascota[], int sizeMasctota)
{
    int i;
    int sumaGato=0;
    int sumaPerro=0;
    int sumaRaro=0;
    float promedioGato=0;
    float promedioPerro=0;
    float promedioRaro=0;
    int contadorPerro=0;
    int contadorGato=0;
    int contadorRaro=0;
    int hayMascota=contadorMascotas(listaMascota,sizeMasctota);

    if(hayMascota>=1)
        {
            for(i=0;i<sizeMasctota;i++)
                {
                    if(listaMascota[i].isEmpty == OCUPADO && listaMascota[i].tipo == 1)
                        {
                            contadorGato++;
                            sumaGato = sumaGato+listaMascota[i].edad;
                            promedioGato=(float)sumaGato/contadorGato;;
                        }
                   if(listaMascota[i].isEmpty == OCUPADO && listaMascota[i].tipo == 2)
                        {
                            contadorPerro++;
                            sumaPerro=sumaPerro+listaMascota[i].edad;
                            promedioPerro=(float)sumaPerro/contadorPerro;

                        }
                    if(listaMascota[i].isEmpty == OCUPADO && listaMascota[i].tipo == 3)
                        {
                            contadorRaro++;
                            sumaRaro=sumaRaro+listaMascota[i].edad;
                            promedioRaro=(float)sumaRaro/contadorRaro;

                        }
                }
             printf("Hay %d de gatos, el promedio de edad de los gatos es de: %.2f\n",contadorGato,promedioGato);
             printf("Hay %d de perros, el promedio de edad de los perro es de: %.2f\n",contadorPerro,promedioPerro);
             printf("Hay %d de mascotas raros, el promedio de edad de las mascotas raras es de: %.2f\n",contadorRaro,promedioRaro);
        }
        else
            {
                printf("No hay mascotas en el sistemas cargadas\n");
            }

}
