#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"
#include "tipo.h"
#include "color.h"

#define TAM 10
#define TAM_T 5
#define TAM_C 5

char menu();

int main()
{
    int flag = 0;
    char seguir = 's';
    char confirma;
    int proximoId = 1;
    int rta;
    eTipo tipos[TAM_T] = {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Gato"},
        {1003, "Roedor"},
        {1004, "Pez"}
    };
    eColor colores[TAM_C] = {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eMascota lista[TAM];

    if(!inicializarMascotas(lista,TAM)){
        printf("Inicializacion exitoza!\n");
    }else{
        printf("Fallo al inicializar");
    }



do
    {
        switch(menu())
        {

        case 'a':
            if(!altaMascota(lista, TAM, tipos, TAM_T, colores, TAM_C, proximoId)){
                proximoId++;
                printf("Alta exitosa.\n");
                flag = 1;
            }else{
                printf("No se pudo realizar el alta.\n\n");
            }
            break;
        case 'b':
            if(flag == 1){
                rta = modificarMascota(lista, TAM, tipos, TAM_T, colores, TAM_C);

                if(!rta){
                    printf("Se ha modificado con exito.\n\n");
                }else if(rta == 2){
                    printf("Modificacion cancelada por el usuario. \n\n");
                }else{
                    printf("Hubo un problema al intentar realizar la modificacion. \n\n");
                }
            }else{
                printf("Primero debe realizar un alta. \n");
            }
            break;
        case 'c':
            if(flag == 1){
                rta = bajaMascota(lista, TAM, tipos, TAM_T, colores, TAM_C);

                if(!rta){
                    printf("Ha realizado la baja con exito.\n\n");
                }else if(rta == 2){
                    printf("Baja cancelada por el usuario. \n\n");
                }else{
                    printf("Hubo un problema al intentar realizar la baja. \n\n");
                }
            }else{
                printf("Primero debe realizar un alta. \n");
            }
            break;
        case 'd':
            if(flag == 1){
                system("cls");
                mostrarMascotasXTipo(lista, TAM, tipos, TAM_T, colores, TAM_C);
            }else{
                printf("Primero debe realizar un alta. \n");
            }
            break;
        case 'e':
            system("cls");
            mostrarTipos(tipos, TAM_T);
            break;
        case 'f':
            system("cls");
            mostrarColores(colores, TAM_C);
            break;
        case 'g':
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');

    return 0;
}

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM VETERINARIA ***\n\n");
    printf("A ALTA MASCOTA\n");
    printf("B MODIFICAR MASCOTA\n");
    printf("C BAJA MASCOTA\n");
    printf("D LISTAR MASCOTAS\n");
    printf("E LISTAR TIPOS\n");
    printf("F LISTAR COLORES\n");
    printf("G LISTAR SERVICIOS\n");
    printf("H ALTA TRABAJO\n");
    printf("I LISTAR TRABAJOS\n");
    printf("J SALIR\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}
