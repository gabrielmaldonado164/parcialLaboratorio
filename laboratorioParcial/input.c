#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int getInt(int* puntero, char texto[],char error[] , int min , int max, int intentos)
{
    int allOk=-1;
    int valor;


        do{
                printf("%s",texto);

                if(getNumero(&valor)==1 && valor>=min && valor<=max)
                    {
                       *puntero=valor;
                       allOk=0;
                       break;

                    }
                else
                    {
                        printf("%s",error);
                        intentos--;
                    }

            }while(intentos >0);

       return allOk;
}

int getFloat(float* puntero,char texto[], char error[],float min, float max,int intentos)
{
    int allOk = -1;
    float valor;


        do{
                printf("%s",texto);


                if((getNumeroFlotante(&valor)==1) && (valor>min && valor<max))
                    {
                       *puntero=valor;
                       allOk=0;
                       break;

                    }
                else
                    {
                        printf("%s",error);
                        intentos--;
                    }

            }while(intentos >0);

       return allOk;
}


int getOptionChar(char* input,char mensaje[],char error[], char caracterUno, char caracterDos)
{
    char caracter;
    int validar = -1;

    printf("%s ", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);

    while( toupper(caracter) != toupper(caracterUno) && toupper(caracter) != toupper(caracterDos))
    {
        printf("///%s///\n", error);
        printf("\n%s ", mensaje);
        fflush(stdin);
        scanf("%c", &caracter);
    }

    *input = toupper(caracter);
    validar = 0;

    return validar;
}


char getCharString(char* puntero,char texto[],char error[], int min, int max,int intentos)
{
    int allOk = -1;
    char palabra[50];


        do{
                printf("%s",texto);

                if(getTexto(&palabra)==1 && (strlen(palabra)>min && strlen(palabra)<max))
                    {
                       strcpy(puntero,palabra);
                       allOk=0;
                       break;

                    }
                else
                    {
                        printf("%s",error);
                        intentos--;
                    }

            }while(intentos >0);

       return allOk;
}

char getCharStringNumeros(char* puntero,char texto[],char error[], int min, int max,int intentos)
{
    int allOk = -1;
    char palabra[50];


        do{
                printf("%s",texto);

                if(getStringNumero(&palabra)==1 && (strlen(palabra)>min && strlen(palabra)<max))
                    {
                       strcpy(puntero,palabra);
                       allOk=0;
                       break;

                    }
                else
                    {
                        printf("%s",error);
                        intentos--;
                    }

            }while(intentos >0);

       return allOk;
}

int esNumerico(char* cadena)//busco la falla con el while
{
   int i=0;
   int retorno=1;
   while(cadena[i]!= '\0')//interactua hasta el barra 0
    {
        if((cadena[i] < '0' || cadena[i] > '9')&&(cadena[i]!='.') &&(cadena[i]!=' ') )
            {
                retorno= 0;
            }
       i++;
    }

   return retorno;
}

int esLetra(char* cadena)//busco la falla con el while
{
   int i=0;
   int retorno=1;
   while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ') &&(cadena[i] < 'a' || cadena[i] > 'z') &&(cadena[i] < 'A' || cadena[i] > 'Z'))
            {
                retorno= 0;
            }
       i++;
    }

    return retorno;
}


int guardoDatos(char* cadena, int longitud)// esto es para que no usar scanf que se desborda
{
    fflush(stdin);
    fgets(cadena,longitud,stdin);
    cadena[strlen(cadena)-1]='\0';

    return 0;
}

int getNumero(int* puntero)
{
    char valor[5000];
    int retorno=0;

    if(guardoDatos(valor,sizeof(valor))==0 && esNumerico(valor)==1)
        {
            *puntero = atoi(valor);
            retorno =1;
        }

    return retorno;
}


int getStringNumero(char* puntero)
{
    char valor[5000];
    int retorno=0;

    if(guardoDatos(valor,sizeof(valor))==0 && esNumerico(valor)==1)
        {
            strcpy(puntero,valor);
            retorno =1;
        }

    return retorno;
}


int getTexto(char* puntero)
{
    char palabra[50];
    int retorno=0;

    if(guardoDatos(palabra,sizeof(palabra))==0 && esLetra(palabra)==1)
    {
        strcpy(puntero,palabra);
        retorno=1;
    }
    return retorno;
}

int getNumeroFlotante(float* puntero)
{
    char valor[5000];
    int retorno=0;

    if(guardoDatos(valor,sizeof(valor))==0 && esNumerico(valor)==1)
        {
            *puntero = atof(valor);
            retorno =1;
        }

    return retorno;
}


