#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "estudiante.h"
#include "materia.h"
#include "materiaAprobada.h"

struct Estudiante {

    char nombre[40];
    int dni;
    ListaPtr materiasAprobadas;
    float promedio;

};

EstudiantePtr crearEstudiante(char nombre[40], int dni, ListaPtr listaMateriasTotales) {

    EstudiantePtr e = (EstudiantePtr)malloc(sizeof(struct Estudiante));

    strcpy(e->nombre, nombre);
    e->dni = dni;
    e->materiasAprobadas = crearLista();
    agregarMateriasAprobadasAleatorio(e, listaMateriasTotales);
    // si tiene materias aprobadas calcular el promedio
    if(obtenerTamanioLista(e->materiasAprobadas) > 0) {
        e->promedio = calcularPromedioEstudiante(e);
    } else {
        e->promedio = 0;
    }

    return e;

}

float calcularPromedioEstudiante(EstudiantePtr e) {

    int tam = obtenerTamanioLista(e->materiasAprobadas);
    float promedio = 0;

    for(int i=0; i<tam; i++) {
        promedio += getPromedioMateriaA(obtener(e->materiasAprobadas, i));
    }

    promedio = promedio / tam;

    return promedio;

}

void mostrarEstudiante(EstudiantePtr e) {

    printf("\t----------------------------\n");
    printf("\t%s - %d\n", e->nombre, e->dni);
    printf("\tCantidad de materias aprobadas: %d\n", obtenerTamanioLista(e->materiasAprobadas));
    printf("\tPromedio: %.2f\n", e->promedio);
    printf("\t----------------------------\n");

}

void mostrarEstudianteDatoPtr(DatoPtr dato) {

    //EstudiantePtr e = (EstudiantePtr)dato;
    EstudiantePtr e = dato;
    mostrarEstudiante(e);

}

void agregarMateriasAprobadasAleatorio(EstudiantePtr e, ListaPtr listaMateriasTotales) {

    int cantMateriasTotales = obtenerTamanioLista(listaMateriasTotales);
    int cantMateriasAprobadas = 0 + rand() % (cantMateriasTotales+1); // genera un numero aleatorio entre 0 y la cantidad de materias agregadas en el sistema
    int posAleatoria;
    int* posicionesUsadas = (int*)malloc(cantMateriasAprobadas * sizeof(int));
    int repetido;

    for(int i=0; i<cantMateriasAprobadas; i++) {

        // obtiene una posicion sin repetir
        do {
            posAleatoria = 0 + rand() % cantMateriasTotales;
            repetido = 0;

            for(int j=0; j<i; j++) {
                if(posicionesUsadas[j] == posAleatoria) {
                    repetido = 1;
                    break;
                }
            }

        } while (repetido == 1);

        posicionesUsadas[i] = posAleatoria;

        MateriaPtr m = obtener(listaMateriasTotales, posAleatoria); // obtiene una materia aleatoria de la lista de materias del sistema
        MateriaAprobadaPtr mAprobada = crearMateriaAprobada(getNombreMateria(m)); // crea la materiaAprobada que ya incluye el promedio aleatorio
        insertarPrimero(e->materiasAprobadas, mAprobada);

    }

    free(posicionesUsadas);

}

int compararCantMateriasAprobadasPtr(DatoPtr dato1, DatoPtr dato2) {

    //EstudiantePtr e1 = (EstudiantePtr)dato1;
    //EstudiantePtr e2 = (EstudiantePtr)dato2;

    EstudiantePtr e1 = dato1;
    EstudiantePtr e2 = dato2;


    int cant1 = obtenerTamanioLista(e1->materiasAprobadas);
    int cant2 = obtenerTamanioLista(e2->materiasAprobadas);

    if (cant1 > cant2) {
        return 1;
    } else if (cant1 < cant2) {
        return -1;
    } else {
        return 0;
    }

}

int compararPromediosEstudiantePtr(DatoPtr dato1, DatoPtr dato2) {

    //EstudiantePtr e1 = (EstudiantePtr)dato1;
    //EstudiantePtr e2 = (EstudiantePtr)dato2;

    EstudiantePtr e1 = dato1;
    EstudiantePtr e2 = dato2;

    if (e1->promedio > e2->promedio) {
        return 1;
    } else if (e1->promedio < e2->promedio) {
        return -1;
    } else {
        return 0;
    }

}

void liberarEstudiante(EstudiantePtr e) {

    free(e);

}

// getters
char* getNombreEstudiante(EstudiantePtr e) {
    return e->nombre;
}

int getDniEstudiante(EstudiantePtr e) {
    return e->dni;
}

ListaPtr getListaMateriasAprobadas(EstudiantePtr e) {
    return e->materiasAprobadas;
}

float getPromedio(EstudiantePtr e) {
    return e->promedio;
}

// setters
void setNombreEstudiante(EstudiantePtr e, char nuevoNombre[40]) {
    strcpy(e->nombre, nuevoNombre);
}

void setDniEstudiante(EstudiantePtr e, int nuevoDni) {
    e->dni = nuevoDni;
}

void setListaMateriasA(EstudiantePtr e, ListaPtr nuevaLista) {
    e->materiasAprobadas = nuevaLista;
}

void setPromedio(EstudiantePtr e, float nuevoProm) {
    e->promedio = nuevoProm;
}

