#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "validaciones.h"
#include "fecha.h"

int validarFecha(eFecha fecha){
    int error = 0;

    if(fecha.dia < 1 || fecha.dia > 31 || fecha.mes < 1 || fecha.mes > 12 || fecha.anio < 2020 || fecha.anio > 2021){
        error = 1;
    }

    return error;
}

int validacionCadena(char cadena[]){
    int error = 0;
    int flag = 0;
    int tamanio;

    tamanio = strlen(cadena);
    for(int i = 0; i < tamanio; i++){
        if(!((cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122) || cadena[i] == ' ')){
            flag = 1;
            error = 1;
        }
    }
    if(cadena[0] == '\0' || cadena[0] == ' '){
        flag = 1;
        error = 1;
    }
    if(flag == 1){
        printf("Ingrese cadena valida(solo letras o espacios).\n");
    }
    return error;
}
