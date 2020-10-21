#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "validaciones.h"

int mostrarXTipoElegido(eMascota mascotas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int idTipo;
    int flag = 0;


    if(mascotas != NULL && tipos != NULL && colores != NULL && clientes != NULL &&tamM > 0 && tamT > 0 && tamC > 0 && tamCl > 0){
        system("cls");
        printf("*** MASCOTAS POR TIPO ***\n\n");
        mostrarTipos(tipos, tamT);
        printf("Ingrese id del tipo a mostrar: ");
        scanf("%d", &idTipo);
        while(!validarTipo(tipos, tamT, idTipo)){
            printf("Id invalido. Reingrese id del tipo a mostrar: ");
            scanf("%d", &idTipo);
        }
        system("cls");
        printf("*** MASCOTAS POR TIPO ***\n\n");
        printf("    ID       NOMBRE         TIPO          COLOR      EDAD     CLIENTE\n");
        printf("<--------------------------------------------------------------------->\n");
        for(int i = 0; i < tamM; i++){
            if(mascotas[i].idTipo == idTipo){
                mostrarMascota(mascotas[i],tipos,tamT,colores,tamC,clientes,tamCl);
                flag = 1;
            }
        }
        if(!flag){
            printf("        No hay mascotas en la lista\n");
        }

    }
    return error;

}

int mostrarXColorElegido(eMascota mascotas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int idColor;
    int flag = 0;


    if(mascotas != NULL && tipos != NULL && colores != NULL && clientes != NULL &&tamM > 0 && tamT > 0 && tamC > 0 && tamCl > 0){
        system("cls");
        printf("*** MASCOTAS POR COLOR ***\n\n");
        mostrarColores(colores, tamC);
        printf("Ingrese id del color a mostrar: ");
        scanf("%d", &idColor);
        while(!validarColor(colores, tamC, idColor)){
            printf("Id invalido. Reingrese id del tipo a mostrar: ");
            scanf("%d", &idColor);
        }

        system("cls");
        printf("*** MASCOTAS POR COLOR ***\n\n");
        printf("    ID       NOMBRE         TIPO          COLOR      EDAD     CLIENTE\n");
        printf("<--------------------------------------------------------------------->\n");
        for(int i = 0; i < tamM; i++){
            if(mascotas[i].idColor == idColor){
                mostrarMascota(mascotas[i],tipos,tamT,colores,tamC,clientes,tamCl);
                flag = 1;
            }
        }
        if(!flag){
            printf("        No hay mascotas en la lista\n");
        }

    }
    return error;

}

int mascotaMasJoven(eMascota mascotas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int flag = 0;
    int flagMin = 0;
    int error = 1;
    int min;

    if(mascotas != NULL && tipos != NULL && colores != NULL && clientes != NULL &&tamM > 0 && tamT > 0 && tamC > 0 && tamCl > 0){

        printf("  *** MASCOTAS MAS JOVENES ***  \n\n");
        printf("    ID       NOMBRE         TIPO          COLOR      EDAD     CLIENTE\n");
        printf("<--------------------------------------------------------------------->\n");
        for(int i = 0; i < tamM; i++){
            if(!mascotas[i].isEmpty && (mascotas[i].edad < min || flagMin == 0)){
                min = mascotas[i].edad;
                flagMin = 1;
            }
        }
        for(int i = 0; i < tamM; i++){
            if(!mascotas[i].isEmpty && mascotas[i].edad == min){
                mostrarMascota(mascotas[i],tipos,tamT,colores,tamC,clientes,tamCl);
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

int contarXTipoYColor(eMascota mascotas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int idColor;
    int idTipo;
    int flag = 0;
    int cont = 0;

    if(mascotas != NULL && tipos != NULL && colores != NULL && clientes != NULL &&tamM > 0 && tamT > 0 && tamC > 0 && tamCl > 0){
        system("cls");
        printf("*** CONTADOR POR TIPO Y COLOR ***\n\n");
        mostrarColores(colores, tamC);
        printf("Ingrese id del color a mostrar: ");
        scanf("%d", &idColor);
        while(!validarColor(colores, tamC, idColor)){
            printf("Id invalido. Reingrese id del tipo a mostrar: ");
            scanf("%d", &idColor);
        }


        system("cls");
        printf("*** CONTADOR POR TIPO Y COLOR ***\n\n");
        mostrarTipos(tipos, tamT);
        printf("Ingrese id del tipo a mostrar: ");
        scanf("%d", &idTipo);
        while(!validarTipo(tipos, tamT, idTipo)){
            printf("Id invalido. Reingrese id del tipo a mostrar: ");
            scanf("%d", &idTipo);
        }


        system("cls");
        printf("*** CONTADOR POR TIPO Y COLOR ***\n\n");
        for(int i = 0; i < tamM; i++){
            if(mascotas[i].idColor == idColor && mascotas[i].idTipo == idTipo){
                cont++;
                flag = 1;
            }
        }
        if(!flag){
            printf("        No hay mascotas en la lista\n");
        }

        printf("Hay %d mascotas de ese color  y tipo\n\n", cont);

    }
    return error;

}

int colorMayorCantidad(eMascota mascotas[],int tamM, eColor colores[], int tamC){
    int error = 1;
    int contadores[tamC];
    int mayor;
    int flag = 0;

    if(mascotas != NULL && colores != NULL && tamM > 0 && tamC > 0){
        for(int i = 0; i < tamC; i++){
            contadores[i] = 0;
        }

        for(int i = 0; i < tamC; i++){

            for(int j = 0; j < tamM; j++){
                if(mascotas[j].isEmpty == 0 && mascotas[j].idColor == colores[i].id){
                    contadores[i]++;
                }
            }
        }

        for(int i = 0; i < tamC; i++){
            if(contadores[i] > mayor || flag == 0){
                mayor = contadores[i];
                flag = 1;
            }
        }

        printf("*** COLOR CON MAYOR CANTIDAD ***\n\n");
        printf("\nEL o los colores con mayor cantidad son: \n");
        for(int i = 0; i < tamC; i++){
            if(contadores[i] == mayor){
                printf("-%s\n", colores[i].nombreColor);
            }
        }

        error = 0;
    }

    return error;
}

int trabajoXMascota(eTrabajo trabajos[], int tamTr, eMascota mascotas[], int tamM, eServcio servicios[], int tamS, int id, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int flag = 0;
    int idMascota;

    if(trabajos != NULL && tamTr > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0 && clientes != NULL && tamCl > 0){
        system("cls");
        printf("*** TRABAJOS POR MASCOTA ***\n\n");
        mostrarMascotas(mascotas, tamM, tipos, tamT, colores, tamC, clientes, tamCl);
            printf("Ingrese id de la mascota: ");
            scanf("%d", &idMascota);
            while(validarMascota(mascotas, tamM, idMascota)){
                printf("Id invalido. Reingrese id de la mascota: ");
                scanf("%d", &idMascota);
            }
        system("cls");
        printf("    *** TRABAJO POR MASCOTA ***  \n\n");
        printf("     ID         DESCRIPCION       PRECIO\n");
        printf("<------------------------------------------------>\n");
        for(int i = 0; i < tamTr; i++){
            if(!trabajos[i].isEmpty && trabajos[i].idMascota == idMascota){
                mostrarTrabajo(trabajos[i],servicios,tamS);
                flag = 1;
            }
        }
        if(!flag){
            printf("No se le realizo ningun trabajo a esta mascota.\n\n");
        }
    }


    return error;
}

int importesXMascota(eTrabajo trabajos[], int tamTr, eMascota mascotas[], int tamM, eServcio servicios[], int tamS, int id, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int flag = 0;
    int idMascota;
    int precioServicios = 0;

    if(trabajos != NULL && tamTr > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0 && clientes != NULL && tamCl > 0){
        system("cls");
        printf("*** IMPORTE POR MASCOTA ***\n\n");
        mostrarMascotas(mascotas, tamM, tipos, tamT, colores, tamC, clientes, tamCl);
            printf("Ingrese id de la mascota: ");
            scanf("%d", &idMascota);
            while(validarMascota(mascotas, tamM, idMascota)){
                printf("Id invalido. Reingrese id de la mascota: ");
                scanf("%d", &idMascota);
            }
        system("cls");
        for(int i = 0; i < tamTr; i++){
            if(!trabajos[i].isEmpty && trabajos[i].idMascota == idMascota){
                for(int j = 0; j < tamM; j++){
                    if(servicios[j].id == trabajos[i].idServicio){
                        precioServicios += servicios[j].precio;
                        flag = 1;
                    }
                }
            }
        }
        printf("    *** IMPORTE POR MASCOTA ***  \n\n");
        printf("La suma de los importes por los servicios de esta mascota es de $%d\n\n", precioServicios);
        if(!flag){
            printf("No se le realizo ningun trabajo a esta mascota.\n\n");
        }
    }

    return error;
}

int serviciosXfecha(eTrabajo trabajos[], int tamTr, eMascota mascotas[], int tamM, eServcio servicios[], int tamS, int id, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int flag = 0;
    eFecha fecha;

    if(trabajos != NULL && tamTr > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0 && clientes != NULL && tamCl > 0){
        system("cls");
        printf("*** SERVICIOS POR FECHA ***\n\n");
        printf("Ingrese fecha del trabajo dd/mm/aaaa: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
        while(validarFecha(fecha) == 1){
            printf("Fecha invalida. Reingrese fecha del trabajo dd/mm/aaaa(año no menor a 2020 o mayor a 2021): ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
        }

        system("cls");
        printf("*** SERVICIOS POR FECHA ***\n\n");
        printf("<------------------------------------------->\n");
        printf("     ID         DESCRIPCION       PRECIO\n");
        printf("<------------------------------------------->\n");
        for(int i = 0; i < tamTr; i++){
            if(!trabajos[i].isEmpty && trabajos[i].fecha.dia == fecha.dia && trabajos[i].fecha.mes == fecha.mes && trabajos[i].fecha.anio == fecha.anio){
                for(int j = 0; j < tamS; j++){
                    if(servicios[j].id == trabajos[i].idServicio){
                        mostrarServicio(servicios[j]);
                        flag = 1;
                }
            }
            if(!flag){
                printf("No se le realizo ningun trabajo a esta mascota.\n\n");
            }
            error = 0;
            }
        }
    }
    return error;
}

int serviciosXMascota(eTrabajo trabajos[], int tamTr, eMascota mascotas[], int tamM, eServcio servicios[], int tamS, int id, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl){
    int error = 1;
    int flag = 0;
    int idServicio;

    if(trabajos != NULL && tamTr > 0 && mascotas != NULL && tamM > 0 && servicios != NULL && tamS > 0 && clientes != NULL && tamCl > 0){
        system("cls");
        printf("*** SERVICIOS POR MASCOTAS ***\n\n");
        mostrarServicios(servicios, tamS);
        printf("Ingrese id del servicio: ");
        scanf("%d", &idServicio);
        while(validarServicio(servicios, tamS, idServicio) == 0){
            printf("Id invalido. Reingrese id del servicio: ");
            scanf("%d", &idServicio);
        }

        system("cls");
        printf("    *** MASCOTAS POR SERVICIOS ***  \n\n");
        printf("<--------------------------------------------------------------------->\n");
        printf("    ID       NOMBRE         TIPO          COLOR      EDAD     CLIENTE\n");
        printf("<--------------------------------------------------------------------->\n");
        for(int i = 0; i < tamTr; i++){
            if(!trabajos[i].isEmpty && trabajos[i].idServicio == idServicio){
                for(int j = 0; j < tamM; j++){
                    if(mascotas[j].id == trabajos[i].idMascota){
                        mostrarMascota(mascotas[j],tipos,tamT,colores,tamC,clientes,tamCl);
                        flag = 1;
                    }
                }
            }
        }
        if(!flag){
            printf("No se le realizo ningun trabajo a esta mascota.\n\n");
        }

        error = 0;
    }
    return error;

}
