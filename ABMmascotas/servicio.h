#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
   int id;
   char descripcion[25];
   int precio;
}eServcio;

#endif // SERVICIO_H_INCLUDED

void mostrarServicios(eServcio servicios[], int tam);
void mostrarServicio(eServcio servicio);
int validarServicio(eServcio servicios[], int tam, int id);
int cargarDescripcionServicio(eServcio servicios[], int tam, int id, char descripcion[]);
