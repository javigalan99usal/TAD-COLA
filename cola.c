#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

/* ============== Implementación de un TAD cola con memoria dinámica ============== */

// Función para crear una cola vacía
void creaVacia(Cola *c) {
    c->frente = NULL;
    c->final = NULL;
}

// Función para verificar si la cola está vacía
bool vacia(Cola *c) {
    if (c->frente == NULL) {
        return true;
    } else {
        return false;
    }
}

// Función para insertar un elemento en la cola
void inserta(int x, Cola *c) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->dato = x;
    nuevoNodo->siguiente = NULL;
    if (c->frente == NULL) {
        c->frente = nuevoNodo;
        c->final = nuevoNodo;
    } else {
        c->final->siguiente = nuevoNodo;
        c->final = nuevoNodo;
    }
}

// Función para suprimir el primer elemento de la cola y devolver su valor
int suprime(Cola *c) {
    if (vacia(c)) {
        printf("Error: La cola está vacía.\n");
        exit(EXIT_FAILURE);
    }
    Nodo* nodoSuprimido = c->frente;
    int datoSuprimido = nodoSuprimido->dato;
    c->frente = nodoSuprimido->siguiente;
    if (c->frente == NULL) {
        c->final = NULL;
    }
    free(nodoSuprimido);
    return datoSuprimido;
}

int main() {
    Cola cola;
    creaVacia(&cola);

    printf(" -> Cola vacía creada.\n");

    // Insertar elementos en la cola
    inserta(10, &cola);
    inserta(20, &cola);
    inserta(30, &cola);

    printf(" -> Elementos insertados en la cola.\n");

    // Suprimir elementos de la cola y mostrarlos
    printf("Elementos de la cola:\n");
    while (!vacia(&cola)) {
        printf("%d\n", suprime(&cola));
    }

    return 0;
}
