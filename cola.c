#include "cola.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    void* dato;
    struct nodo* prox;
} nodo_t;

struct cola{
    nodo_t* prim;
    nodo_t* ult;
};


typedef void (*destruir_dato)(void *);
/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

// ...
nodo_t* nodo_crear(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if(!nodo){
        return NULL;
    }
    nodo->dato = valor;
    nodo->prox = NULL;
    return nodo;
}

cola_t *cola_crear(void){
    cola_t *cola = malloc(sizeof(cola_t));

    if(cola==NULL){
        return NULL;
    }
    cola->prim = NULL;
    cola->ult = NULL;
    return cola;
}

bool cola_esta_vacia(const cola_t *cola){
    return cola->ult == NULL;
}

void *cola_desencolar(cola_t *cola){
    if(cola_esta_vacia(cola)){
        return NULL;
    }
    nodo_t* viejo = cola->prim;
    void* valor = viejo->dato;
    cola->prim = cola->prim->prox;
    free(viejo);

    if(cola->prim == NULL){
        cola->ult = NULL;
    }
    return valor;
}

void cola_destruir(cola_t *cola, destruir_dato func){
    if(cola_esta_vacia(cola)){
        free(cola);
        return;
    }else if(func == NULL){
        while(!cola_esta_vacia(cola)){
            cola_desencolar(cola);
            }
    }else{
        while(!cola_esta_vacia(cola)){
            func(cola_desencolar(cola));
        }
    }
    free(cola);
}


bool cola_encolar(cola_t *cola, void* valor){
    nodo_t* nuevo = nodo_crear(valor);
    if (nuevo == NULL){
        return false;
    }
    if(cola->prim == NULL){
        cola->prim = nuevo;
    }else{
    cola->ult->prox = nuevo;
    }
    cola->ult = nuevo;
    return true;
}

void *cola_ver_primero(const cola_t *cola){
    if(cola_esta_vacia(cola)){
        return NULL;
    }
    return cola->prim->dato;
}

