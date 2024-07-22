#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Lista {

    NodoPtr primero;

};

ListaPtr crearLista() {

    ListaPtr l = (ListaPtr)malloc(sizeof(struct Lista));

    l->primero = NULL;

    return l;

}

int obtenerTamanioLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;
    int i = 0;

    while(actual != NULL) {
        i++;
        actual = getSiguiente(actual);
    }

    return i;

}

void insertarPrimero(ListaPtr lista, DatoPtr dato) {

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;

}

void insertarUltimo(ListaPtr lista, DatoPtr dato) {

    NodoPtr actual = lista->primero;

    if(actual==NULL){ //Lista no tiene nodos
        insertarPrimero(lista, dato);
    }else{

        while(getSiguiente(actual) != NULL){

            actual = getSiguiente(actual);

        }

        setSiguiente(actual, crearNodo(dato, NULL));

    }

}

void insertar(ListaPtr lista, DatoPtr dato, int posicion) {

    int tam = obtenerTamanioLista(lista);

    if(posicion > tam+1){

        printf("\n\nERROR, no se puede insertar en pos que no existen!!!");

    }else{

        if(posicion<0){

            printf("\n\nERROR, no se puede insertar en pos negativas!!!");

        }else{

            if(posicion == 0){

                insertarPrimero(lista, dato);

            }else{

                if(posicion==tam){

                    insertarUltimo(lista, dato);

                }else{

                    if(posicion>0 && posicion<tam){

                        NodoPtr actual = lista->primero;

                        for ( int i = 0 ; i<posicion-1; i++){

                            actual = getSiguiente(actual);

                        }

                        setSiguiente(actual, crearNodo(dato, getSiguiente(actual)));

                    }
                }
              }
        }
    }
}

void insertarEnOrden(ListaPtr lista, DatoPtr dato, int(*ptrFuncionComparar)(DatoPtr, DatoPtr)) {

    int tam = obtenerTamanioLista(lista);
    NodoPtr actual = lista->primero;

    if (tam == 0 || ptrFuncionComparar(obtenerUltimo(lista), dato)) {
        insertarUltimo(lista, dato);
    } else {

        for (int i = 0; i < tam; i++) {
            if (ptrFuncionComparar(dato, getDato(actual))) {
                insertar(lista, dato, i);
                return;
            }
            actual = getSiguiente(actual);
        }

        insertarUltimo(lista, dato);
    }
}

DatoPtr obtener(ListaPtr lista, int pos) {

    int tam = obtenerTamanioLista(lista);

    if(pos < 0 || pos >= tam) {
        printf("\nEsa posicion no existe");
        return NULL;
    } else if(pos == 0) {
        return getDato(lista->primero);
    } else if(pos == tam-1) {
        NodoPtr actual = lista->primero;
        for(int i=0; i<tam-1; i++) {
            actual = getSiguiente(actual);
        }
        return getDato(actual);
    } else {
        NodoPtr actual = lista->primero;
        for(int i=0; i<pos; i++) {
            actual = getSiguiente(actual);
        }
        return getDato(actual);
    }

}

DatoPtr obtenerUltimo(ListaPtr lista) {

    NodoPtr actual = lista->primero;

    if(actual == NULL) {
        printf("Error! la lista esta vacia");
        return NULL;
    } else {
        for(int i=0; i<obtenerTamanioLista(lista)-1; i++) {
            actual = getSiguiente(actual);
        }

        return getDato(actual);
    }

}

void mostrarListaGenerico(ListaPtr lista, void(*ptrFuncionMostrar)(DatoPtr)) {

    printf("\n");
    NodoPtr actual = lista->primero;

    while(actual!=NULL) {
        ptrFuncionMostrar(getDato(actual));
        actual = getSiguiente(actual);
    }

    printf("\n");

}



int buscarElemento(ListaPtr lista, int(*ptrFuncionComparar)(DatoPtr, DatoPtr), DatoPtr buscado) {

    int tam = obtenerTamanioLista(lista);
    NodoPtr actual = lista->primero;

    for(int i=0; i<tam; i++) {
        if(ptrFuncionComparar(getDato(actual), buscado)) {
            return i;
        } else {
            actual = getSiguiente(actual);
        }
    }

    return -1;

}

void dobleOrdenamientoLista(ListaPtr lista, int(*ptrFuncionComparar1)(DatoPtr, DatoPtr), int (*ptrFuncionComparar2)(DatoPtr, DatoPtr)) {

    DatoPtr aux;

    NodoPtr actual = lista->primero;

    for (int i=0 ; i<obtenerTamanioLista(lista); i++){
        for (int j=0; j<obtenerTamanioLista(lista)-1; j++){
            if (ptrFuncionComparar1(getDato(actual), getDato(getSiguiente(actual))) < 0){
                aux = getDato(actual);
                setDato(actual, getDato(getSiguiente(actual)));
                setDato(getSiguiente(actual), aux);
            } else if (ptrFuncionComparar1(getDato(actual), getDato(getSiguiente(actual))) == 0) {
                if(ptrFuncionComparar2(getDato(actual), getDato(getSiguiente(actual))) < 0) {
                    aux = getDato(actual);
                    setDato(actual, getDato(getSiguiente(actual)));
                    setDato(getSiguiente(actual), aux);
                }
            }
            actual = getSiguiente(actual);
        }
        actual = lista->primero;
    }

}
