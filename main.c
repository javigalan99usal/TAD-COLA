#include <stdio.h>
#include "cola.h"

// Programa que utiliza el TAD cola a modo de ejemplo de funcionamiento

int main() {
    Cola cola;
    colaCreaVacia(&cola);

    printf(" -> Cola vacía creada.\n");

    // Insertar elementos en la cola
    colaInserta(10, &cola);
    colaInserta(20, &cola);
    colaInserta(30, &cola);

    printf(" -> Elementos insertados en la cola.\n");

    // Suprimir elementos de la cola y mostrarlos
    printf("Elementos de la cola:\n");
    while (!colaVacia(&cola)) {
        printf("%d\n", colaSuprime(&cola));
    }

    return 0;
}