#ifndef MATERIAAPROBADA_H_INCLUDED
#define MATERIAAPROBADA_H_INCLUDED

typedef struct MateriaAprobada * MateriaAprobadaPtr;

MateriaAprobadaPtr crearMateriaAprobada(char nombre[45]);
float generarPromedio();
void mostrarMateriaAprobada(MateriaAprobadaPtr m);
void mostrarMateriaAprobadaDatoPtr(void * dato);

void liberarMateriaA(MateriaAprobadaPtr m);

// getters
char* getNombreMateriaA(MateriaAprobadaPtr m);
float getPromedioMateriaA(MateriaAprobadaPtr m);

// setters
void setNombreMateriaA(MateriaAprobadaPtr m, char nuevoNombre[40]);
void setPromedioMateriaA(MateriaAprobadaPtr m, float nuevoProm);

#endif // MATERIAAPROBADA_H_INCLUDED
