#ifndef _PILA_H
#define _PILA_H

#include <stdbool.h>


/* *****************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* Se trata de una pila que contiene datos de tipo void*
 * (punteros genéricos).  La pila en sí está definida en el .c.  */

struct pila;  // Definición completa en pila.c.
typedef struct pila pila_t;


/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// Crea una pila.
// Post: devuelve una nueva pila vacía.
pila_t *pila_crear(void);

// Destruye la pila.
// Pre: la pila fue creada.
// Post: se eliminaron todos los elementos de la pila.
void pila_destruir(pila_t *pila);
#endif  // _PILA_H