#include "tipo.h"
#include "color.h"
#include "cliente.h"

#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{
int id;
char nombre[20];
int idTipo;
int idColor;
int edad;
int idCliente;
int isEmpty;
}eMascota;

#endif // MASCOTAS_H_INCLUDED

int altaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl, int id);
int buscarLibre(eMascota mascotas[], int tam);
int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
int mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
void mostrarMascota(eMascota unaMascota, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
int buscarMascotas(eMascota mascotas[], int tam, int id);
int bajaMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
int inicializarMascotas(eMascota mascotas[], int tam);
int mostrarMascotasXTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
int validarMascota(eMascota mascotas[], int tam, int id);
int hardcodearMascotas(eMascota mascotas[], int tam, int cant);
 void formatearCadena(char cadena[]);
