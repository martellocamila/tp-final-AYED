#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int mostrarMenuPrincipal(){

    int opcion;

    printf("--------------MENU--------------\n");
    printf("1- Inscribir estudiante a una materia.\n");
    printf("2- Mostrar lista de materias.\n");
    printf("3- Salir del programa\n");
    printf("--------------------------------\n");
    printf("\nElige una opcion -> ");
    scanf("%d", &opcion);
    while (getchar() != '\n'); // Limpiar el buffer de entrada después de scanf
    return opcion;

}

void borrarPantalla(){

    //while (_getch() != 13) {}
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition = {0, 0};
    DWORD charsWritten;
    // Obtén el tamaño de la consola
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    // Llena la pantalla con espacios en blanco
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, cursorPosition, &charsWritten);
    // Coloca el cursor en la parte superior izquierda
    SetConsoleCursorPosition(hConsole, cursorPosition);

}

void volverAlMenu(){

    printf("\nPresiona Enter para volver al menu...");
    while (_getch() != 13) {};
    borrarPantalla();

}
