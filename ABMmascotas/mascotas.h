#include "tipo.h"
#include "color.h"

#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{
int id;
char nombre[20];
int idTipo;
int idColor;
int edad;
int isEmpty;
}eMascota;

#endif // MASCOTAS_H_INCLUDED

int altaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, int id);
int buscarLibre(eMascota mascotas[], int tam);
int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
void mostrarMascota(eMascota unaMascota, eTipo tipos[], int tamT, eColor colores[], int tamC);
int buscarMascotas(eMascota mascotas[], int tam, int id);
int bajaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int inicializarMascotas(eMascota mascotas[], int tam);
int mostrarMascotasXTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
