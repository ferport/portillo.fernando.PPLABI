#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "trabajo.h"
#include "dataStoreTrabajo.h"
#include "validaciones.h"

int altaTrabajo(eTrabajo trabajos[], int tam, eMascota mascotas[], int tamM, eServcio servicios[], int tamS, int id, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int indice;
    int idMascota;
    int idServicio;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tam > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0 && clientes != NULL && tamCl > 0){

        system("cls");
        printf("  *** ALTA DE TRABAJO ***\n\n");

        indice = buscarLibreTrabajo(trabajos, tam);
        if(indice == -1){
            printf("Sistema Completo.\n");
        }else{
            nuevoTrabajo.id = id;
            nuevoTrabajo.isEmpty = 0;

            mostrarMascotas(mascotas, tamM, tipos, tamT, colores, tamC, clientes, tamCl);
            printf("Ingrese id de la mascota: ");
            scanf("%d", &idMascota);
            while(validarMascota(mascotas, tamM, idMascota)){
                printf("Id invalido. Reingrese id de la mascota: ");
                scanf("%d", &idMascota);
            }
            nuevoTrabajo.idMascota = idMascota;

            mostrarServicios(servicios, tamS);
            printf("Ingrese id del servicio: ");
            scanf("%d", &idServicio);
            while(validarServicio(servicios, tamS, idServicio) == 0){
                printf("Id invalido. Reingrese id del servicio: ");
                scanf("%d", &idServicio);
            }
            nuevoTrabajo.idServicio = idServicio;

            printf("Ingrese fecha del trabajo dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            while(validarFecha(nuevoTrabajo.fecha) == 1){
                printf("Fecha invalida. Reingrese fecha del trabajo dd/mm/aaaa(año no menor a 2020 o mayor a 2021): ");
                scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            }

            trabajos[indice] = nuevoTrabajo;

            error = 0;
        }

    }
    return error;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam){
    int indice = -1;
    for(int i = 0; i < tam; i++){
        if(trabajos[i].isEmpty){
            indice = i;
            break;
        }
    }
    return indice;
}

int mostrarTrabajos(eTrabajo trabajos[],int tam, eServcio servicios[], int tamS){

    //system("cls");
    int flag = 0;
    int error = 1;

    if(trabajos != NULL && tam > 0 && servicios != NULL && tamS > 0){

            printf("  *** LISTADO DE TRABAJOS ***  \n\n");
            printf("    ID     ID MASCOTA        SERVICIO          FECHA   \n");
            printf("<-------------------------------------------------------->\n");
        for(int i = 0; i < tam; i++){
            if(!trabajos[i].isEmpty){
                mostrarTrabajo(trabajos[i], servicios, tamS);
                flag = 1;
            }
        }
        if(!flag){
            printf("        No hay trabajos en la lista\n");
        }
        error = 0;
    }
    return error;
}

void mostrarTrabajo(eTrabajo trabajo, eServcio servicios[], int tamS){
    char descServcio[20];
    if(!cargarDescripcionServicio(servicios, tamS, trabajo.idServicio, descServcio)){
        printf("  %4d      %5d       %15s      %02d/%02d/%04d     \n", trabajo.id, trabajo.idMascota, descServcio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
    }else{
        printf("Problema para recuperar la descripcion\n");
    }
}

int inicializarTrabajo(eTrabajo trabajos[], int tam){
    int error = 1;

    if(trabajos != NULL && tam > 0){
        for(int i=0; i<tam; i++){
            trabajos[i].isEmpty = 1;
    }
        error = 0;
    }
    return error;
}

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant){
    int retorno = -1;
    if(trabajos != NULL && tam > 0 && cant <= tam){
        retorno = 0;
        for(int i = 0; i < cant; i++){
            trabajos[i].id = idUno[i];
            trabajos[i].idMascota = idMascotas[i];
            trabajos[i].idServicio = idServicios[i];
            trabajos[i].fecha = fechasVeinte[i];
            trabajos[i].isEmpty = 0;
            retorno ++;
        }
    }

    return retorno;
}

