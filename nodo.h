#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef void * DatoPtr;

typedef struct Nodo * NodoPtr;

DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);
void setDato(NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr siguiente);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

void liberarNodo(NodoPtr nodo);

#endif // NODO_H_INCLUDED
