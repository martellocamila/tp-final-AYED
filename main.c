#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#include "materia.h"
#include "materiaAprobada.h"
#include "estudiante.h"
#include "menu.h"

int main()
{
    srand(time(NULL));

    ListaPtr listaMaterias = crearLista();
    cargarMaterias(listaMaterias);
    cargarEstudiantes(listaMaterias);

    int opcion;

    do {
        opcion = mostrarMenuPrincipal();

        switch(opcion) {

            case 1:
                borrarPantalla();
                inscribirEstudianteDinamico(listaMaterias);
                volverAlMenu();
                break;

            case 2:
                borrarPantalla();
                mostrarListaGenerico(listaMaterias, mostrarMateriaDatoPtr);
                volverAlMenu();
                break;

            case 3:
                exit(0);
                break;

            default:
                getchar();
                borrarPantalla();
                printf("Opcion no disponible! Por favor, ingrese una valida\n\n");
                break;
        }

    } while(1);

    return 0;
}
