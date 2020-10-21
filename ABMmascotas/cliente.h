#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
int id;
char nombre[20];
int sexo;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int cargarNombreCliente(eCliente clientes[], int tam, int id, char nombre[]);
int validarCliente(eCliente clientes[], int tam, int id);
void mostrarCliente(eCliente cliente);
void mostrarClientes(eCliente clientes[], int tam);
