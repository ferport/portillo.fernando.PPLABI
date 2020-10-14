#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"
#include "tipo.h"
#include "color.h"


void mostrarTipos(eTipo tipos[], int tam){
    if(tipos != NULL && tam > 0){

            printf("  *** LISTADO DE TIPOS ***  \n\n");
            printf("<------------------------------------------------>\n");
            printf("     ID         DESCRIPCION\n");
            printf("<------------------------------------------------>\n");
        for(int i = 0; i < tam; i++){
                mostrarTipo(tipos[i]);
        }
        printf("\n\n");
    }
}

void mostrarTipo(eTipo tipos){
    printf("   %4d%15s\n",tipos.id,tipos.descripcion);
}

int validarTipo(eTipo tipos[], int tam, int id){
    int esValido = 0;
    for(int i =  0; i < tam; i++){
        if(tipos[i].id == id){
            esValido = 1;
            break;
        }
    }
    return esValido;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]){
    int error = 1;
    if(tipos != NULL && tam > 0 && id > 0 && descripcion != NULL){
        for(int i = 0; i < tam; i++){
            if(tipos[i].id == id){
                strcpy(descripcion, tipos[i].descripcion);
                error = 0;
            break;
            }
        }
    }
    return error;
}
