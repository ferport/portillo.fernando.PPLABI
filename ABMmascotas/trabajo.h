#include "fecha.h"
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "cliente.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
   int id;
   int idMascota;
   int idServicio;
   eFecha fecha;
   int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int altaTrabajo(eTrabajo trabajos[], int tam, eMascota mascotas[], int tamM, eServcio servicios[], int tamS, int id, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);
void mostrarTrabajo(eTrabajo trabajo, eServcio servicios[], int tamS);
int mostrarTrabajos(eTrabajo trabajos[],int tam, eServcio servicios[], int tamS);
int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant);
int inicializarTrabajo(eTrabajo trabajos[], int tam);
