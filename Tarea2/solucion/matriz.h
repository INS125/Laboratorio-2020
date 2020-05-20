#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define largoFiltro 3

int ** suma(int **matriz1, int **matriz2, int tamano);

int ** convolucion(int **matriz, int **filtro, int tamano);

void escrituraMatriz(char *filename, int **matriz, int size);

int ** lecturaMatriz(char *filename, int size);

int ** convolucion2(int **matriz, int **filtro, int tamano);