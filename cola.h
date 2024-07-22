#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "lista.h"

typedef struct Cola * ColaPtr;

ColaPtr crearCola();

void encolar(ColaPtr cola, DatoPtr dato);
void encolarDatosDesdeLista(ColaPtr cola, ListaPtr lista);
DatoPtr desencolar(ColaPtr cola);
ColaPtr duplicarCola(ColaPtr cola);

NodoPtr getPrimero(ColaPtr cola);
NodoPtr getUltimo(ColaPtr cola);

void liberarCola(ColaPtr cola);

#endif // COLA_H_INCLUDED
