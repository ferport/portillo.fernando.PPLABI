#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"
#include "tipo.h"
#include "color.h"

int altaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, int id){
    int error = 1;
    int indice;
    int idTipo;
    int idColor;
    eMascota nuevaMascota;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 ){

        system("cls");
        printf("  *** ALTA DE MASCOTA ***\n\n");

        indice = buscarLibre(mascotas, tam);
        if(indice == -1){
            printf("Sistema Completo.\n");
        }else{
            nuevaMascota.id = id;
            nuevaMascota.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevaMascota.nombre);

            mostrarTipos(tipos, tamT);
            printf("Ingrese id del tipo: ");
            scanf("%d", &idTipo);
            while(validarTipo(tipos, tamT, idTipo) == 0){
                printf("Id invalido. Reingrese id del tipo: ");
                scanf("%d", &idTipo);
            }
            nuevaMascota.idTipo = idTipo;

            mostrarColores(colores, tamC);
            printf("Ingrese id del color: ");
            scanf("%d", &idColor);
            while(validarColor(colores, tamC, idColor) == 0){
                printf("Id invalido. Reingrese id del color: ");
                scanf("%d", &idColor);
            }
            nuevaMascota.idColor = idColor;

            printf("Ingrese edad: ");
            scanf("%d", &nuevaMascota.edad);


            mascotas[indice] = nuevaMascota;

            error = 0;
        }

    }
    return error;
}

int buscarLibre(eMascota mascotas[], int tam){
    int indice = -1;
    for(int i = 0; i < tam; i++){
        if(mascotas[i].isEmpty){
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int id;
    int indice;
    int error = 1;
    int opcion;
    char confirmacion;
    eMascota auxMascota;
    int flagSalir = 0;
    int flagDef = 0;
    int idTipo;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 ){

        system("cls");
        printf("        *** MODIFICAR MASCOTA ***\n\n");

        mostrarMascotas(mascotas, tam, tipos, tamT, colores, tamC);
        printf("-------------------------------------------------------\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMascotas(mascotas, tam, id);
        auxMascota = mascotas[indice];

        if(indice == -1){
            printf("No hay ninguna mascota con ese ID\n");
        }else{
            system("cls");

            printf("*** MODIFICAR MASCOTAS ***\n\n");
            mostrarMascota(mascotas[indice], tipos, tamT, colores, tamC);
            printf("1) MODIFICAR TIPO.\n");
            printf("2) MODIFICAR EDAD.\n");
            printf("3) MENU ANTERIOR.\n");
            printf("Seleccione un opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            switch(opcion){
            case 1:
                mostrarTipos(tipos, tamT);
                printf("Ingrese id del nuevo tipo: ");
                scanf("%d", &idTipo);
                while(validarTipo(tipos, tamT, idTipo) == 0){
                    printf("Id invalido. Reingrese id del tipo: ");
                    scanf("%d", &idTipo);
                }
                auxMascota.idTipo = idTipo;
                break;
            case 2:
                printf("Ingrese nueva edad: ");
                scanf("%d", &auxMascota.edad);
                break;
            case 3:
                flagSalir = 1;
                error = 2;
                break;
            default:
                flagDef = 1;
                printf("Opcion no valida\n");
                break;
            }
            if(!flagSalir && !flagDef){
                printf("Confirma la modificacion(s/n)? ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if(confirmacion == 's'){
                    mascotas[indice] = auxMascota;
                    error = 0;
                }else{
                    error = 2;
                }
            }
        }


    }
    return error;
}

int mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){

    //system("cls");
    int flag = 0;
    int error = 1;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 ){

            printf("  *** LISTADO DE MASCOTAS ***  \n\n");
            printf("    ID       NOMBRE         TIPO          COLOR      EDAD   \n");
            printf("<-------------------------------------------------------->\n");
        for(int i = 0; i < tam; i++){
            if(!mascotas[i].isEmpty){
                mostrarMascota(mascotas[i], tipos, tamT, colores, tamC);
                flag = 1;
            }
        }
        if(!flag){
            printf("        No hay mascotas en la lista\n");
        }
        error = 0;
    }
    return error;
}

void mostrarMascota(eMascota unaMascota, eTipo tipos[], int tamT, eColor colores[], int tamC){
    char descTipo[20];
    char nombreColor[20];
    if(!cargarDescripcionTipo(tipos, tamT, unaMascota.idTipo, descTipo) && !cargarNombreColor(colores, tamC, unaMascota.idColor, nombreColor)){
        printf("  %4d   %10s     %10s      %10s    %02d     \n",unaMascota.id,unaMascota.nombre,descTipo, nombreColor, unaMascota.edad);
    }else{
        printf("Problema para recuperar la descripcion\n");
    }
}

int buscarMascotas(eMascota mascotas[], int tam, int id){
    int indice = -1;
    for(int i = 0; i < tam; i++){
        if(mascotas[i].id == id && !mascotas[i].isEmpty){
            indice = i;
            break;
        }
    }
    return indice;
}

int bajaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int id;
    int indice;
    int error = 1;
    char confirma;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 ){

        system("cls");
        printf("  *** BAJA DE MASCOTA ***\n\n");

        mostrarMascotas(mascotas, tam, tipos, tamT, colores, tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMascotas(mascotas, tam, id);

        if(indice == -1){
            printf("No hay ninguna mascota con ese ID\n");
        }else{
            mostrarMascota(mascotas[indice], tipos, tamT, colores, tamC);
            printf("Confirma baja? ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's'){
                mascotas[indice].isEmpty = 1;
                error = 0;
            }else{
                error = 2;
            }
        }


    }
    return error;
}

int mostrarMascotasXTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int error = 1;
    int flag;
    char tipo[20];

    if(mascotas != NULL && tipos != NULL && tam > 0 && tamT > 0){
        system("cls");
        printf("       ***Informe de mascotas *** \n\n");
        printf("    ID       NOMBRE         TIPO          COLOR      EDAD   \n");
        printf("<-------------------------------------------------------->\n");
        for(int i = 0; i < tamT; i++){
            flag = 0;
            cargarDescripcionTipo(tipos, tamT, tipos[i].id, tipo);
            printf("\nTipo: %s\n\n",tipo);

            for(int j = 0; j < tam; j++){
                if(mascotas[j].isEmpty == 0 && mascotas[j].idTipo == tipos[i].id){
                    mostrarMascota(mascotas[j] , tipos, tamT, colores, tamC);
                    flag = 1;
                }
            }
            if(flag == 0){
                printf("Ninguna mascota con este color\n");
            }
        }
        error = 0;
    }

    return error;
}

int inicializarMascotas(eMascota mascotas[], int tam){
    int error = 1;

    if(mascotas != NULL && tam > 0){
        for(int i=0; i<tam; i++){
            mascotas[i].isEmpty = 1;
    }
        error = 0;
    }
    return error;
}

