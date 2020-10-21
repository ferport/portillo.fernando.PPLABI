#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "dataStore.h"
#include "validaciones.h"
#include "cliente.h"

int altaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl, int id){
    int error = 1;
    int indice;
    int idTipo;
    int idColor;
    int idCliente;
    eMascota nuevaMascota;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0){

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
            formatearCadena(gets(nuevaMascota.nombre));
            while(validacionCadena(nuevaMascota.nombre) == 1){
                printf("Nombre invalido. Reingrese nombre: ");
                fflush(stdin);
                formatearCadena(gets(nuevaMascota.nombre));
            }

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

            mostrarClientes(clientes, tamCl);
            printf("Ingrese id del cliente: ");
            scanf("%d", &idCliente);
            while(validarCliente(clientes, tamCl, idCliente) == 0){
                printf("Id invalido. Reingrese id del cliente: ");
                scanf("%d", &idCliente);
            }
            nuevaMascota.idCliente = idCliente;

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

int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int id;
    int indice;
    int error = 1;
    int opcion;
    char confirmacion;
    eMascota auxMascota;
    int flagSalir = 0;
    int flagDef = 0;
    int idTipo;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0){

        system("cls");
        printf("        *** MODIFICAR MASCOTA ***\n\n");

        mostrarMascotas(mascotas, tam, tipos, tamT, colores, tamC, clientes, tamCl);
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
            mostrarMascota(mascotas[indice], tipos, tamT, colores, tamC, clientes, tamCl);
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

int mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){

    //system("cls");
    int flag = 0;
    int error = 1;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0){

            printf("  *** LISTADO DE MASCOTAS ***  \n\n");
            printf("    ID       NOMBRE         TIPO          COLOR      EDAD     CLIENTE\n");
            printf("<--------------------------------------------------------------------->\n");
        for(int i = 0; i < tam; i++){
            if(!mascotas[i].isEmpty){
                mostrarMascota(mascotas[i], tipos, tamT, colores, tamC, clientes, tamCl);
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

void mostrarMascota(eMascota unaMascota, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    char descTipo[20];
    char nombreColor[20];
    char nombreCliente[20];
    if(!cargarDescripcionTipo(tipos, tamT, unaMascota.idTipo, descTipo) && !cargarNombreColor(colores, tamC, unaMascota.idColor, nombreColor) && !cargarNombreCliente(clientes, tamCl, unaMascota.idCliente, nombreCliente)){
        printf("  %4d   %10s     %10s      %10s    %02d    %10s \n",unaMascota.id,unaMascota.nombre,descTipo, nombreColor, unaMascota.edad, nombreCliente);
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

int bajaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int id;
    int indice;
    int error = 1;
    char confirma;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCl > 0){

        system("cls");
        printf("  *** BAJA DE MASCOTA ***\n\n");

        mostrarMascotas(mascotas, tam, tipos, tamT, colores, tamC, clientes, tamCl);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMascotas(mascotas, tam, id);

        if(indice == -1){
            printf("No hay ninguna mascota con ese ID\n");
        }else{
            mostrarMascota(mascotas[indice], tipos, tamT, colores, tamC, clientes, tamCl);
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

int mostrarMascotasXTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int flag;
    char tipo[20];

    if(mascotas != NULL && tipos != NULL && tam > 0 && tamT > 0){
        system("cls");
        printf("       *** MASCOTAS POR TIPO *** \n\n");
        printf("    ID       NOMBRE         TIPO          COLOR      EDAD     CLIENTE\n");
        printf("<--------------------------------------------------------------------->\n");
        for(int i = 0; i < tamT; i++){
            flag = 0;
            cargarDescripcionTipo(tipos, tamT, tipos[i].id, tipo);
            printf("\nTipo: %s\n\n",tipo);

            for(int j = 0; j < tam; j++){
                if(mascotas[j].isEmpty == 0 && mascotas[j].idTipo == tipos[i].id){
                    mostrarMascota(mascotas[j] , tipos, tamT, colores, tamC, clientes, tamCl);
                    flag = 1;
                }
            }
            if(flag == 0){
                printf("Ninguna mascota con este tipo\n");
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

int validarMascota(eMascota mascotas[], int tam, int id){
    int esValido = 1;
    for(int i =  0; i < tam; i++){
        if(mascotas[i].id == id){
            esValido = 0;
            break;
        }
    }
    return esValido;
}

int hardcodearMascotas(eMascota mascotas[], int tam, int cant){
    int retorno = -1;
    if(mascotas != NULL && tam > 0 && cant <= tam){
        retorno = 0;
        for(int i = 0; i < cant; i++){
            mascotas[i].id = idCien[i];
            strcpy(mascotas[i].nombre, nombresMascotas[i]);
            mascotas[i].idTipo = idTipo[i];
            mascotas[i].idColor = idColor[i];
            mascotas[i].edad = edadesMascotas[i];
            mascotas[i].idCliente = idCliente[i];
            mascotas[i].isEmpty = 0;
            retorno ++;
        }
    }

    return retorno;
}

void formatearCadena(char cadena[]){
    strlwr(cadena);
    int i = 0;
    cadena[0] = toupper(cadena[0]);
    while(cadena[i] != '\0'){
        if(cadena[i] == ' ' || cadena[i] == 39){
            cadena[i + 1] = toupper(cadena[i + 1]);
        }
        i++;
    }
}
