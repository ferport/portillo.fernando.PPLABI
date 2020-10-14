#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"
#include "tipo.h"
#include "color.h"

void mostrarColores(eColor colores[], int tam){
    if(colores != NULL && tam > 0){

            printf("  *** LISTADO DE COLORES ***  \n\n");
            printf("<------------------------------------------------>\n");
            printf("     ID          NOMBRE\n");
            printf("<------------------------------------------------>\n");
        for(int i = 0; i < tam; i++){
                mostrarColor(colores[i]);
        }
        printf("\n\n");
    }
}

void mostrarColor(eColor colores){
    printf("   %4d%15s\n",colores.id,colores.nombreColor);
}

int validarColor(eColor colores[], int tam, int id){
    int esValido = 0;
    for(int i =  0; i < tam; i++){
        if(colores[i].id == id){
            esValido = 1;
            break;
        }
    }
    return esValido;
}

int cargarNombreColor(eColor colores[], int tam, int id, char nombre[]){
    int error = 1;
    if(colores != NULL && tam > 0 && id > 0 && nombre != NULL){
        for(int i = 0; i < tam; i++){
            if(colores[i].id == id){
                strcpy(nombre, colores[i].nombreColor);
                error = 0;
            break;
            }
        }
    }
    return error;
}
