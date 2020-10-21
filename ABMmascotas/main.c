#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "fecha.h"
#include "informes.h"

#define TAM 50
#define TAM_T 5
#define TAM_C 5
#define TAM_S 3
#define TAM_TR 50
#define TAM_CL 10



char menuInformes();

char menu();


int main()
{
    int flag = 0;
    char seguir = 's';
    char confirma;
    int proximoId = 100;
    int proximoIdTrabajo = 1;
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

    eServcio servicios[TAM_S] = {
        {20000, "Corte", 250},
        {20001, "Desparacitado", 300},
        {20002, "Castrado", 400}
    };

    eTrabajo listaTrabajos[TAM_TR];
    eCliente listaClientes[TAM_CL] = {
        {100, "Pablo", 'm'},
        {101, "Liliana", 'f'},
        {102, "Betina", 'f'},
        {103, "Paulo", 'm'},
        {104, "Roberto", 'm'},
        {105, "Juan", 'm'},
        {106, "Romina", 'f'},
        {107, "Jazmin", 'f'},
        {108, "Julio", 'm'},
        {109, "Silvia", 'f'}
    };

    if(!inicializarMascotas(lista,TAM)){
        printf("Inicializacion exitoza!\n");
    }else{
        printf("Fallo al inicializar");
    }

    if(!inicializarTrabajo(listaTrabajos,TAM_TR)){
        printf("Inicializacion exitoza!\n");
    }else{
        printf("Fallo al inicializar");
    }

    proximoId += hardcodearMascotas(lista, TAM, 20);

    proximoIdTrabajo += hardcodearTrabajos(listaTrabajos, TAM_TR, 30);


do
    {
        switch(menu())
        {
        case 'a':
            if(!altaMascota(lista, TAM, tipos, TAM_T, colores, TAM_T, listaClientes, TAM_CL, proximoId)){
                proximoId++;
                printf("Alta exitosa.\n");
                flag = 1;
            }else{
                printf("No se pudo realizar el alta.\n\n");
            }
            break;
        case 'b':
            if(flag == 1){
                rta = modificarMascota(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes, TAM_CL);

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
                rta = bajaMascota(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes, TAM_CL);

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
                mostrarMascotasXTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes, TAM_CL);
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
            system("cls");
            mostrarServicios(servicios, TAM_S);
            break;
        case 'h':
            if(!altaTrabajo(listaTrabajos, TAM_TR, lista, TAM, servicios, TAM_S, proximoIdTrabajo, tipos, TAM_T,colores, TAM_C, listaClientes, TAM_CL )){
                proximoIdTrabajo++;
                printf("Alta exitosa.\n");
                flag = 1;
            }else{
                printf("No se pudo realizar el alta.\n\n");
            }
            break;
        case 'i':
            system("cls");
            mostrarTrabajos(listaTrabajos, TAM_TR, servicios, TAM_S);
            break;
        case 'j':
            switch(menuInformes()){
            case 'a':
                system("cls");
                mostrarXColorElegido(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes,TAM_CL);
                break;
            case 'b':
                system("cls");
                mostrarXTipoElegido(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes,TAM_CL);
                break;
            case 'c':
                system("cls");
                mascotaMasJoven(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes,TAM_CL);
                break;
            case 'd':
                system("cls");
                mostrarMascotasXTipo(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes,TAM_CL);
                break;
            case 'e':
                system("cls");
                contarXTipoYColor(lista, TAM, tipos, TAM_T, colores, TAM_C, listaClientes,TAM_CL);
                break;
            case 'f':
                system("cls");
                colorMayorCantidad(lista, TAM, colores, TAM_C);
                break;
            case 'g':
                system("cls");
                trabajoXMascota(listaTrabajos, TAM_TR, lista, TAM, servicios, TAM_S, proximoIdTrabajo, tipos, TAM_T,colores, TAM_C, listaClientes, TAM_CL);
                break;
            case 'h':
                system("cls");
                importesXMascota(listaTrabajos, TAM_TR, lista, TAM, servicios, TAM_S, proximoIdTrabajo, tipos, TAM_T,colores, TAM_C, listaClientes, TAM_CL);
                break;
            case 'i':
                system("cls");
                serviciosXMascota(listaTrabajos, TAM_TR, lista, TAM, servicios, TAM_S, proximoIdTrabajo, tipos, TAM_T,colores, TAM_C, listaClientes, TAM_CL);
                break;
            case 'j':
                system("cls");
                serviciosXfecha(listaTrabajos, TAM_TR, lista, TAM, servicios, TAM_S, proximoIdTrabajo, tipos, TAM_T,colores, TAM_C, listaClientes, TAM_CL);
                break;
            default:
                printf("Opcion invalida!!!\n");

            }
            break;
        case 'k':
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
    printf("J INFORMES\n");
    printf("K SALIR\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;

}


char menuInformes()
{
    char opcion;
    system("cls");

    printf("*** INFORMES ***\n\n");
    printf("A MASCOTAS POR COLOR ELEGIDO\n");
    printf("B MASCOTAS POR TIPO ELEGIDO\n");
    printf("C MASCOTA MAS JOVEN\n");
    printf("D MASCOTA POR TIPO\n");
    printf("E CONTADOR POR COLOR Y TIPO\n");
    printf("F COLOR DE MAYOR CANTIDAD\n");
    printf("G TRABAJOS POR MASCOTA\n");
    printf("H IMPORTES POR MASCOTA\n");
    printf("I MASCOTAS POR SERVICIO\n");
    printf("J SERVICIOS POR FECHA\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;

}


