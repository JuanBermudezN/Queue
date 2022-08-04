#include "pila.h"
#include "cola.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>

/*Pruebas para una pila recien creada*/
static void pruebas_cola_vacia(void) {
    printf("INICIO DE PRUEBAS DE COLA SIN ELEMENTOS\n");
    // se crea una cola sin elementos
    cola_t *cola = cola_crear();

    
    print_test("la cola está vacía", cola_esta_vacia(cola));
    
    // desapilar elementos de una cola vacia es inválido
    print_test("Desencolar en una cola vacía es inválido", cola_desencolar(cola) == NULL);

    // ver_primero en una cola vacía devuelve NULL
    print_test("Ver primero de una cola vacia es invaĺido", cola_ver_primero(cola) == NULL);

   cola_destruir(cola, NULL);

}

static void pruebas_algunos_elementos(void){
    printf("INICIO DE PRUEBAS DE COLA CON ELEMENTOS\n");
    // se crea una cola sin elementos
    cola_t *cola = cola_crear();

    // se encolan varios elementos
    int elem_1 = 1;
    int elem_2 = 2;
    int elem_3 = 3;

    int* p_elem_1 = &elem_1;
    int* p_elem_2 = &elem_2;
    int* p_elem_3 = &elem_3;

    print_test("encolar primer elemento", cola_encolar(cola, p_elem_1));
    print_test("ver primero es igual al primer elemento que encolé", cola_ver_primero(cola));
    print_test("encolar segundo elemento", cola_encolar(cola, p_elem_2));
    print_test("ver primero es igual al primer elemento que encolé", cola_ver_primero(cola));
    print_test("encolar tercer elemento", cola_encolar(cola, p_elem_3));
    print_test("ver primero es igual al primer elemento que encolé", cola_ver_primero(cola));
    
    print_test("desencolar primer elemento", cola_desencolar(cola));
    print_test("ver primero es igual al segundo elemento que encolé", cola_ver_primero(cola));
    print_test("desencolar segundo elemento", cola_desencolar(cola));       
    print_test("ver primero es igual al tercer elemento que encolé", cola_ver_primero(cola));
    print_test("desencolar tercer elemento", cola_desencolar(cola));       
    print_test("la cola esta vacia", cola_esta_vacia(cola));

    cola_destruir(cola, NULL);


}

static void pruebas_volumen(void){
    printf("INICIO DE PRUEBAS DE VOLUMEN\n");

    // se crea una cola sin elementos
    cola_t *cola = cola_crear();

    int arr[10000];

    int i;
    bool ok = true;

    for(i = 0; i < 10000; i++){
        arr[i] = i;
        ok&= cola_encolar(cola, &arr[i]);
        ok&= (cola_ver_primero(cola) == &arr[0]);
    }

    print_test("se encolaron 10000 elementos y se mantuvo el invariante", ok);

    for(i = 9999; i > 0; i--){
        ok&= (cola_desencolar(cola) != NULL);
        ok&= (cola_ver_primero(cola) == &arr[10000 - i]);
    }

    print_test("se desencolaron 9999 elementos y se mantuvo el invariante", ok);

    cola_desencolar(cola);

    print_test("la cola está vacía", cola_esta_vacia(cola));

    cola_destruir(cola, NULL);

}

static void pruebas_destruir_con_free(void){
    printf("INICIO DE PRUEBAS DE DESTRUIR CON FREE\n");
    // se crea una cola sin elementos
    cola_t *cola = cola_crear();
    bool ok = true;

    for(int i = 0; i < 300; i++){
        int* p = malloc(sizeof(int));
        *p = i;
        ok&= cola_encolar(cola, p);
        ok&= (*((int *)cola_ver_primero(cola)) == 0);
    }
    print_test("se encolaron 500 elementos y se mantuvo el invariante", ok);
    cola_destruir(cola, free);

}


void pruebas_cola_estudiante() {
    pruebas_cola_vacia();
    pruebas_algunos_elementos();
    pruebas_volumen();
    pruebas_destruir_con_free();

}

/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_cola_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
