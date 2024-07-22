#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include "lista.h"
#include "cola.h"
#include "estudiante.h"

typedef struct Materia * MateriaPtr;

MateriaPtr crearMateria(char nombre[40], int cupo);

void mostrarMateria(MateriaPtr m);
void mostrarMateriaDatoPtr(void * dato);
void mostrarNombreMateria(MateriaPtr m);
void mostrarNombreMateriaDatoPtr(void * dato);
void mostrarColaDeEspera(MateriaPtr m);

void cargarMaterias(ListaPtr lista);

MateriaPtr buscarMateria(ListaPtr materias);
int chequeoCupos(MateriaPtr materia, EstudiantePtr estudiante);
void cargarEstudiantes(ListaPtr materiasTotales);
void inscribirEstudianteDinamico(ListaPtr listaMaterias);

int compararNombresMaterias(DatoPtr dato1, DatoPtr dato2);

void liberarMateria(MateriaPtr m);

// getters
char* getNombreMateria(MateriaPtr m);
int getCupo(MateriaPtr m);
ListaPtr getListaInscriptos(MateriaPtr m);
ColaPtr getColaDeEspera(MateriaPtr m);

// setters
void setNombreMateria(MateriaPtr m, char nuevoNombre[40]);
void setCupo(MateriaPtr m, int nuevoCupo);
void setListaInscriptos(MateriaPtr m, ListaPtr nuevaListaInscriptos);
void setColaDeEspera(MateriaPtr m, ColaPtr nuevaCola);

#endif // MATERIA_H_INCLUDED
