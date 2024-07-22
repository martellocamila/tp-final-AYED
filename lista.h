#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

typedef struct Lista * ListaPtr;

ListaPtr crearLista();

int obtenerTamanioLista(ListaPtr lista);

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertar(ListaPtr lista, DatoPtr dato, int pos);
void insertarEnOrden(ListaPtr lista, DatoPtr dato, int(*ptrFuncionComparar)(DatoPtr, DatoPtr));

DatoPtr obtener(ListaPtr lista, int pos);
DatoPtr obtenerUltimo(ListaPtr lista);

void mostrarListaGenerico(ListaPtr lista, void(*ptrFuncionMostrar)(DatoPtr));

int buscarElemento(ListaPtr lista, int(*ptrFuncionComparar)(DatoPtr, DatoPtr), DatoPtr buscado);
void dobleOrdenamientoLista(ListaPtr lista, int (*ptrFuncionComparar1)(DatoPtr, DatoPtr), int (*ptrFuncionComparar2)(DatoPtr, DatoPtr));

#endif // LISTA_H_INCLUDED
