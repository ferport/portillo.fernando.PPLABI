#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "servicio.h"
#include "trabajo.h"


void mostrarServicios(eServcio servicios[], int tam){
    if(servicios != NULL && tam > 0){

            printf("    *** LISTADO DE SERVICIOS ***  \n\n");
            printf("<------------------------------------------->\n");
            printf("     ID         DESCRIPCION       PRECIO\n");
            printf("<------------------------------------------->\n");
        for(int i = 0; i < tam; i++){
                mostrarServicio(servicios[i]);
        }
        printf("\n\n");
    }
}

void mostrarServicio(eServcio servicio){
    printf("   %4d    %15s        $%3d\n",servicio.id,servicio.descripcion,servicio.precio);
}

int validarServicio(eServcio servicios[], int tam, int id){
    int esValido = 0;
    for(int i =  0; i < tam; i++){
        if(servicios[i].id == id){
            esValido = 1;
            break;
        }
    }
    return esValido;
}

int cargarDescripcionServicio(eServcio servicios[], int tam, int id, char descripcion[]){
    int error = 1;
    if(servicios != NULL && tam > 0 && id > 0 && descripcion != NULL){
        for(int i = 0; i < tam; i++){
            if(servicios[i].id == id){
                strcpy(descripcion, servicios[i].descripcion);
                error = 0;
            break;
            }
        }
    }
    return error;
}
