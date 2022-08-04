#include "pila.h"
#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...

pila_t *pila_crear(void){
    pila_t *pila = malloc(sizeof(pila_t));

    if(pila == NULL){
        return NULL;
    }

    pila->capacidad = 2;
    pila->cantidad = 0;
    pila->datos = malloc(pila->capacidad * sizeof(void *));

    if(pila->datos == NULL){
        return NULL;
    } 
    return pila;
}

void pila_destruir(pila_t *pila){
    if(pila->datos == NULL){
        free(pila);
        return;
    }

    free(pila->datos);
    free(pila);
}
