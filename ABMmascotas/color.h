#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
   int id;
   char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief Muestra un array de estructuras eColor
 *
 * \param array de eColor
 * \param tamaño del array
 *
 */
void mostrarColores(eColor colores[], int tam);

/** \brief Muestra una estructura eColor
 *
 * \param estructura eColor
 *
 */
void mostrarColor(eColor colores);

/** \brief Valida el id de un color
 *
 * \param array de eColor
 * \param array de eColor
 * \param id a verificar
 * \return 0 si es exitosa, 1 si hay error
 *
 */
int validarColor(eColor colores[], int tam, int id);

/** \brief carga un string con el nombre de un color segun su id
 *
 * \param array de eColor
 * \param array de eColor
 * \param id para cargar
 * \param string para cargar
 * \return 0 si es exitosa, 1 si hay error
 *
 */
int cargarNombreColor(eColor colores[], int tam, int id, char nombre[]);
