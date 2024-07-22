#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"
#include "estudiante.h"
#include "cola.h"
#include "menu.h"

struct Materia {

    char nombre[40];
    int cupo;
    ListaPtr inscriptos;
    ColaPtr colaDeEspera;
    ListaPtr listaAuxPendientes; // lista auxiliar para ordenarla y luego crear la cola de espera para que esta quede ordenada

};

MateriaPtr crearMateria(char nombre[40], int cupo) {

    MateriaPtr m = (MateriaPtr)malloc(sizeof(struct Materia));

    strcpy(m->nombre, nombre);
    m->cupo = cupo;
    m->inscriptos = crearLista();
    m->colaDeEspera = crearCola();
    m->listaAuxPendientes = crearLista();

    return m;

}

void mostrarMateria(MateriaPtr m) {

    printf("|| %s ||\n", m->nombre);
    printf("\n\tESTUDIANTES INSCRIPTOS: \n");
    mostrarListaGenerico(m->inscriptos, mostrarEstudianteDatoPtr);
    printf("\n\tESTUDIANTES EN COLA DE ESPERA: \n");
    mostrarColaDeEspera(m);
    printf("\n");

}

void mostrarMateriaDatoPtr(void * dato) {

   // MateriaPtr m = (MateriaPtr)dato;
    MateriaPtr m = dato;
    mostrarMateria(m);

}

void mostrarNombreMateria(MateriaPtr m) {
    printf("- %s\n", m->nombre);
}

void mostrarNombreMateriaDatoPtr(void * dato) {

   // MateriaPtr m = (MateriaPtr)dato;
    MateriaPtr m = dato;
    mostrarNombreMateria(m);

}

void mostrarColaDeEspera(MateriaPtr m) {

    ColaPtr aux = duplicarCola(m->colaDeEspera);

    while(getPrimero(aux) != NULL) {
        mostrarEstudiante((EstudiantePtr)desencolar(aux));
    }

}

void cargarMaterias(ListaPtr lista) {

    // materias con pocos cupos para chequear rapido el funcionamiento de la cola
    MateriaPtr m1 = crearMateria("Programacion", 5);
    MateriaPtr m2 = crearMateria("Organizacion de computadoras", 5);
    MateriaPtr m3 = crearMateria("Arquitectura de computadoras", 4);
    MateriaPtr m4 = crearMateria("Matematica 1", 6);
    MateriaPtr m5 = crearMateria("Matematica 2", 5);
    MateriaPtr m6 = crearMateria("Expresion de problemas y algoritmos", 4);
    MateriaPtr m7 = crearMateria("IPS", 4);

    insertarPrimero(lista, m1);
    insertarPrimero(lista, m2);
    insertarPrimero(lista, m3);
    insertarPrimero(lista, m4);
    insertarPrimero(lista, m5);
    insertarPrimero(lista, m6);
    insertarPrimero(lista, m7);

}

MateriaPtr buscarMateria(ListaPtr materias) {

    int encontrada = 0;
    char nombreMateria[40];
    MateriaPtr buscada = NULL;

    do {
        mostrarListaGenerico(materias, mostrarNombreMateriaDatoPtr);
        printf("\n> Ingrese el nombre de la materia a la que desea inscribirse: ");
        gets(nombreMateria);
        int busqueda = buscarElemento(materias, compararNombresMaterias, crearMateria(nombreMateria, -1));
        if (busqueda != -1) {
            encontrada = 1;
            buscada = (MateriaPtr)obtener(materias, busqueda);
        } else {
            printf("\nError! Esa materia no se encuentra en la lista\n");
        }
    } while(encontrada == 0);

    return buscada;

}

void cargarEstudiantes(ListaPtr materiasTotales) {

    EstudiantePtr e1 = crearEstudiante("Camila Martello", 46111438, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 0), e1);
    chequeoCupos(obtener(materiasTotales, 1), e1);
    chequeoCupos(obtener(materiasTotales, 2), e1);
    chequeoCupos(obtener(materiasTotales, 3), e1);

    EstudiantePtr e2 = crearEstudiante("Leonardo Junco", 12345678, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 0), e2);
    chequeoCupos(obtener(materiasTotales, 1), e2);
    chequeoCupos(obtener(materiasTotales, 2), e2);

    EstudiantePtr e3 = crearEstudiante("Andrea Gonzalez", 36912031, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 0), e3);
    chequeoCupos(obtener(materiasTotales, 1), e3);
    chequeoCupos(obtener(materiasTotales, 2), e3);
    chequeoCupos(obtener(materiasTotales, 3), e3);

    EstudiantePtr e4 = crearEstudiante("Olivia Rodriguez", 864457367, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 4), e4);
    chequeoCupos(obtener(materiasTotales, 5), e4);
    chequeoCupos(obtener(materiasTotales, 6), e4);
    chequeoCupos(obtener(materiasTotales, 0), e4);

    EstudiantePtr e5 = crearEstudiante("Matias Perez", 78263492, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 4), e5);
    chequeoCupos(obtener(materiasTotales, 5), e5);
    chequeoCupos(obtener(materiasTotales, 6), e5);
    chequeoCupos(obtener(materiasTotales, 1), e5);

    EstudiantePtr e6 = crearEstudiante("Mia Lopez", 47312312, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 2), e6);
    chequeoCupos(obtener(materiasTotales, 3), e6);
    chequeoCupos(obtener(materiasTotales, 6), e6);
    chequeoCupos(obtener(materiasTotales, 4), e6);

    EstudiantePtr e7 = crearEstudiante("Franco Munoz", 22135312, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 4), e7);
    chequeoCupos(obtener(materiasTotales, 3), e7);
    chequeoCupos(obtener(materiasTotales, 2), e7);
    chequeoCupos(obtener(materiasTotales, 6), e7);

    EstudiantePtr e8 = crearEstudiante("Lorena Dominguez", 33422121, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 0), e8);
    chequeoCupos(obtener(materiasTotales, 2), e8);
    chequeoCupos(obtener(materiasTotales, 5), e8);
    chequeoCupos(obtener(materiasTotales, 6), e8);

    EstudiantePtr e9 = crearEstudiante("Abril Lomonaco", 22345212, materiasTotales);
    chequeoCupos(obtener(materiasTotales, 6), e9);
    chequeoCupos(obtener(materiasTotales, 0), e9);
    chequeoCupos(obtener(materiasTotales, 4), e9);
    chequeoCupos(obtener(materiasTotales, 3), e9);

}

int chequeoCupos(MateriaPtr materia, EstudiantePtr estudiante) {

    if(materia->cupo > 0) {
        materia->cupo = materia->cupo - 1;
        insertarPrimero(materia->inscriptos, estudiante);
        return 1;
    } else {
        insertarPrimero(materia->listaAuxPendientes, estudiante);
        if(obtenerTamanioLista(materia->listaAuxPendientes) > 1) {
            dobleOrdenamientoLista(materia->listaAuxPendientes, compararCantMateriasAprobadasPtr, compararPromediosEstudiantePtr);
        }
        liberarCola(materia->colaDeEspera);
        materia->colaDeEspera = crearCola();
        encolarDatosDesdeLista(materia->colaDeEspera, materia->listaAuxPendientes);
        return -1;
    }

}

void inscribirEstudianteDinamico(ListaPtr listaMaterias) {

    printf("### INSCRIPCION ###\n\n");

    char nombreEstudiante[40];
    int dniEstudiante = 0;

    printf("> Ingrese su nombre y apellido: ");
    fgets(nombreEstudiante, sizeof(nombreEstudiante), stdin);
    nombreEstudiante[strcspn(nombreEstudiante, "\n")] = 0; // Elimina el salto de línea de fgets

    printf("> Ingrese su DNI: ");
    scanf("%d", &dniEstudiante);
    while (getchar() != '\n'); // Limpiar el buffer de entrada

    EstudiantePtr estudiante = crearEstudiante(nombreEstudiante, dniEstudiante, listaMaterias);

    MateriaPtr materiaAInscribirse = buscarMateria(listaMaterias);

    if(chequeoCupos(materiaAInscribirse, estudiante) == 1) {
        printf("\nTe has inscripto a la materia \n");
    } else {
        printf("\nAtencion! No puedes anotarte a la materia debido a que ya tiene todos sus cupos ocupados.\nEntraste a la cola de espera por cupos\n");
    }

}

int compararNombresMaterias(DatoPtr dato1, DatoPtr dato2) {

    //MateriaPtr m1 = (MateriaPtr)dato1;
    //MateriaPtr m2 = (MateriaPtr)dato2;

    MateriaPtr m1 = dato1;
    MateriaPtr m2 = dato2;

    return (strcmp(m1->nombre, m2->nombre) == 0);

}

void liberarMateria(MateriaPtr m) {

    free(m);

}

char* getNombreMateria(MateriaPtr m) {
    return m->nombre;
}

int getCupo(MateriaPtr m) {
    return m->cupo;
}

ListaPtr getListaInscriptos(MateriaPtr m) {
    return m->inscriptos;
}

ColaPtr getColaDeEspera(MateriaPtr m) {
    return m->colaDeEspera;
}

void setNombreMateria(MateriaPtr m, char nuevoNombre[40]) {
    strcpy(m->nombre, nuevoNombre);
}

void setCupo(MateriaPtr m, int nuevoCupo) {
    m->cupo = nuevoCupo;
}

void setListaInscriptos(MateriaPtr m, ListaPtr nuevaListaInscriptos) {
    m->inscriptos = nuevaListaInscriptos;
}

void setColaDeEspera(MateriaPtr m, ColaPtr nuevaCola) {
    m->colaDeEspera = nuevaCola;
}
