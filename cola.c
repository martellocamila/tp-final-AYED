#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

struct Cola {

    NodoPtr primero;
    NodoPtr ultimo;

};

ColaPtr crearCola() {

    ColaPtr cola = (ColaPtr)malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;

}

void encolar(ColaPtr cola, DatoPtr dato) {

    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    if(cola->primero == NULL) {
        cola->primero = nuevoNodo;
        cola->ultimo = nuevoNodo;
    } else {
        setSiguiente(cola->ultimo, nuevoNodo);
        cola->ultimo = nuevoNodo;
    }

}

void encolarDatosDesdeLista(ColaPtr cola, ListaPtr lista) {

    for(int i=0; i<obtenerTamanioLista(lista); i++) {
        DatoPtr dato = obtener(lista, i);
        encolar(cola, dato);
    }

}

DatoPtr desencolar(ColaPtr cola) {

    if(cola->primero) {
        NodoPtr nodoEliminar = cola->primero;
        cola->primero = getSiguiente(cola->primero);
        DatoPtr datoEliminado = getDato(nodoEliminar);
        liberarNodo(nodoEliminar);
        return datoEliminado;
    } else {
        cola->ultimo = NULL;
        printf("Cola vacia");
        return NULL;
    }

}

ColaPtr duplicarCola(ColaPtr cola) {

    ColaPtr copia = crearCola();
    ColaPtr colaTemp = crearCola();

    while(cola->primero) {
        DatoPtr dato = desencolar(cola);
        encolar(copia, dato);
        encolar(colaTemp, dato);
    }

    while(colaTemp->primero) {
        encolar(cola, desencolar(colaTemp));
    }

    liberarCola(colaTemp);

    return copia;

}

NodoPtr getPrimero(ColaPtr cola) {
    return cola->primero;
}

NodoPtr getUltimo(ColaPtr cola) {
    return cola->ultimo;
}

void liberarCola(ColaPtr cola) {

    while(cola->primero) {
        desencolar(cola);
    }

    free(cola);

}
