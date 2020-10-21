#include "fecha.h"

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief valida una fecha
 *
 * \param estructura fecha a validar
 * \return retorna 0 si no hay erros y 1 si hay error
 *
 */
int validarFecha(eFecha fecha);

/** \brief Valida que en un string solo se puedan poner letras o espacios
 *
 * \param string a validar
 * \return 0 si no hay fallos, 1 si hay fallos
 *
 */
int validacionCadena(char cadena[]);
