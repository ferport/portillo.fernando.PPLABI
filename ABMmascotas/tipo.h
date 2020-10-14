#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
   int id;
   char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief Muestra un array de estructuras eColor
 *
 * \param array de eColor
 * \param tamaño del array
 *
 */
void mostrarTipos(eTipo tipos[], int tam);

/** \brief Muestra una estructura eColor
 *
 * \param estructura eColor
 *
 */
void mostrarTipo(eTipo tipos);

/** \brief Valida el id de un color
 *
 * \param array de eColor
 * \param array de eColor
 * \param id a verificar
 * \return 0 si es exitosa, 1 si hay error
 *
 */
int validarTipo(eTipo tipos[], int tam, int id);

/** \brief carga un string con el nombre de un color segun su id
 *
 * \param array de eColor
 * \param array de eColor
 * \param id para cargar
 * \param string para cargar
 * \return 0 si es exitosa, 1 si hay error
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
