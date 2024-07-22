#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include "lista.h"

typedef struct Estudiante * EstudiantePtr;

// getters
char* getNombreEstudiante(EstudiantePtr e);
int getDniEstudiante(EstudiantePtr e);
ListaPtr getListaMateriasAprobadas(EstudiantePtr e);
float getPromedio(EstudiantePtr e);

// setters
void setNombreEstudiante(EstudiantePtr e, char nuevoNombre[40]);
void setDniEstudiante(EstudiantePtr e, int nuevoDni);
void setListaMateriasA(EstudiantePtr e, ListaPtr nuevaLista);
void setPromedio(EstudiantePtr e, float nuevoProm);

EstudiantePtr crearEstudiante(char nombre[40], int dni, ListaPtr listaMateriasTotales);

float calcularPromedioEstudiante(EstudiantePtr e);

void mostrarEstudiante(EstudiantePtr e);
void mostrarEstudianteDatoPtr(DatoPtr dato);

void agregarMateriasAprobadasAleatorio(EstudiantePtr e, ListaPtr listaMateriasTotales);

int compararCantMateriasAprobadasPtr(DatoPtr dato1, DatoPtr dato2);
int compararPromediosEstudiantePtr(DatoPtr dato1, DatoPtr dato2);

void liberarEstudiante(EstudiantePtr e);


#endif // ESTUDIANTE_H_INCLUDED
