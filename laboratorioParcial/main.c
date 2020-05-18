#include <stdio.h>
#include <stdlib.h>
#include "clientes-mascotas.h"
#define SIZE_CLIENTES 10
#define SIZE_MASCOTAS 20


int main()
{
    eClientes listaClientes[SIZE_CLIENTES];
    eMascotas listaMascotas[SIZE_MASCOTAS];

    char confirma;
    char salir='s';


    inicializarClientes(listaClientes,SIZE_CLIENTES);
    harcodeoClientes(listaClientes);
    inicioMascotas(listaMascotas,SIZE_MASCOTAS);
    harcodeoMascotas(listaMascotas);


    do
        {
            switch(menuPrincipal())
            {
                case 1:
                        altaMascota(listaMascotas,SIZE_MASCOTAS,listaClientes,SIZE_CLIENTES);
                        system("pause");
                        break;
                case 2:
                        bajaMascota(listaMascotas,SIZE_MASCOTAS);
                        system("pause");
                        break;
                case 3:
                        modificarMascota(listaMascotas,SIZE_MASCOTAS);
                        system("pause");
                        break;
                case 4:
                        altaClientes(listaClientes,SIZE_CLIENTES);
                        system("pause");
                        break;
                case 5:
                        bajaCliente(listaClientes,SIZE_CLIENTES,listaMascotas,SIZE_MASCOTAS);
                        system("pause");
                        break;
                case 6:
                        modificarCliente(listaClientes,SIZE_CLIENTES);
                        system("pause");
                        break;
                case 7:
                        switch(menuOrdenar())
                        {
                            case 1:
                                    ordenarMascotaPorTipo(listaMascotas,SIZE_MASCOTAS,listaClientes,SIZE_CLIENTES);
                                    system("pause");
                                    break;
                            case 2:
                                    ordernarClientesPorCantidad(listaClientes,SIZE_CLIENTES,listaMascotas,SIZE_MASCOTAS);
                                    system("pause");
                                    break;
                            case 3:
                                    ordenarClientePorCantidadYnombre(listaClientes,SIZE_CLIENTES,listaMascotas,SIZE_MASCOTAS);
                                    system("pause");
                                    break;
                            case 4:
                                    printf("Volviendo al menu principal\n");
                                    system("pause");
                                    break;
                            default:
                                    printf("Opcion invalida\n:");
                                    system("pause");
                                    break;

                        }
                    break;

                case 8:
                        switch(menuListados())
                        {

                            case 1:
                                    listarClientes(listaClientes,SIZE_CLIENTES);
                                    system("pause");
                                    break;

                            case 2:
                                listarMascotas(listaMascotas,SIZE_MASCOTAS);
                                    //listarMascotasConClientes(listaMascotas,SIZE_MASCOTAS,listaClientes,SIZE_CLIENTES);
                                    system("pause");
                                    break;

                            case 3:
                                    listarClientesConMascotas(listaClientes,SIZE_CLIENTES,listaMascotas,SIZE_MASCOTAS);
                                    system("pause");
                                    break;
                            case 4:
                                    listarClienteConVariasMascotas(listaClientes,SIZE_CLIENTES,listaMascotas,SIZE_MASCOTAS);
                                    system("pause");
                                    break;
                            case 5:
                                    listarMascotasMayoreDeTres(listaMascotas,SIZE_MASCOTAS,listaClientes,SIZE_CLIENTES);
                                    system("pause");
                                    break;
                            case 6:
                                    listarMasctotaPorTipo(listaMascotas,SIZE_MASCOTAS);
                                    system("pause");
                                    break;
                            case 7:
                                    printf("Volviendo al menu principal\n");
                                    system("pause");
                                    break;
                            default:
                                    printf("Comando desconosido\n");
                                    break;

                            }
                            break;
                case 9:
                        promedioEdadMascotas(listaMascotas,SIZE_MASCOTAS);
                        system("pause");
                        break;

                case 10:

                        promedioPorTipoMascota(listaMascotas,SIZE_MASCOTAS);
                        system("pause");
                        break;
                case 11:
                        promedioDeClientes(listaClientes,SIZE_CLIENTES);
                        system("pause");
                        break;
                case 12:
                        listarClientesConMascotasDelMismoSexo(listaClientes,SIZE_CLIENTES,listaMascotas,SIZE_MASCOTAS);
                        system("pause");
                        break;
                case 13:
                        getOptionChar(&confirma,"Desea salir[S/N]","Error, letras invalidas\n",'s','n');

                        if(confirma=='S')
                            {
                                salir='n';
                            }
                        break;
                default:
                        printf("Comando desconocido\n");
                        system("pause");
                        break;


            }
            system("cls");
            system("pause");

            fflush(stdin);
        }while(salir == 's');
        printf("Hasta luego!\n");

    return 0;
}
