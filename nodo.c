#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo {

    DatoPtr dato;
    struct Nodo * siguiente;

};

DatoPtr getDato(NodoPtr nodo) {
    return nodo->dato;
}

NodoPtr getSiguiente(NodoPtr nodo) {
    return nodo->siguiente;
}

void setDato(NodoPtr nodo, DatoPtr nuevoDato) {
    nodo->dato = nuevoDato;
}

void setSiguiente(NodoPtr nodo, NodoPtr siguiente) {
    nodo->siguiente = siguiente;
}

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente) {

    NodoPtr n = (NodoPtr)malloc(sizeof(struct Nodo));

    n->dato = dato;
    n->siguiente = siguiente;

    return n;

}

void liberarNodo(NodoPtr nodo) {
    free(nodo);
}
