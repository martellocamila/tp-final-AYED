#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materiaAprobada.h"

struct MateriaAprobada {

    char nombre[40];
    float promedio;

};

MateriaAprobadaPtr crearMateriaAprobada(char nombre[45]) {

    MateriaAprobadaPtr m = (MateriaAprobadaPtr)malloc(sizeof(struct MateriaAprobada));

    strcpy(m->nombre, nombre);
    m->promedio = generarPromedio();

    return m;

}

float generarPromedio() {

    float promedio = (float)(400 + rand() % 601) / 100;

    return promedio;

}

void mostrarMateriaAprobada(MateriaAprobadaPtr m) {

    printf("\n\t%s - %.2f\n", m->nombre, m->promedio);

}

void mostrarMateriaAprobadaDatoPtr(void * dato) {

    //MateriaAprobadaPtr m = (MateriaAprobadaPtr)dato;
    MateriaAprobadaPtr m = dato;
    mostrarMateriaAprobada(m);

}

void liberarMateriaA(MateriaAprobadaPtr m) {

    free(m);

}

// getters
char* getNombreMateriaA(MateriaAprobadaPtr m) {
    return m->nombre;
}

float getPromedioMateriaA(MateriaAprobadaPtr m) {
    return m->promedio;
}

// setters
void setNombreMateriaA(MateriaAprobadaPtr m, char nuevoNombre[40]) {
    strcpy(m->nombre, nuevoNombre);
}

void setPromedioMateriaA(MateriaAprobadaPtr m, float nuevoProm) {
    m->promedio = nuevoProm;
}

