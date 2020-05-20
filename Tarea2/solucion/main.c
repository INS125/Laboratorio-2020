#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "matriz.h"

int main(int argc, char **argv){
    
    int index;
    int c;
    
    int largo = 0;
    char *filenameMatrizA;
    char *filenameMatrizB;
    char *filenameMatrizFiltro;
    
    char *filenameMatrizSuma;
    char *filenameMatrizConv;
    
    
    extern char *optarg;
    opterr = 0;
    
    
    //Captura los elementos por parametros
    while ((c = getopt (argc, argv, "a:b:l:f:s:c:")) != -1){
        switch (c){
            case 'a':
                filenameMatrizA = optarg;
                break;
            case 'b':
                filenameMatrizB = optarg;
                break;
            case 'l':
                largo = atoi(optarg);
                break;
            case 'f':
                filenameMatrizFiltro = optarg;
                break;
            case 's':
                filenameMatrizSuma = optarg;
                break;
            case 'c':
                filenameMatrizConv = optarg;
                break;
            default:
                abort ();
        }
    }


    int **matrizA = lecturaMatriz(filenameMatrizA, largo);
    int **matrizB = lecturaMatriz(filenameMatrizB, largo);
    int **matrizF = lecturaMatriz(filenameMatrizFiltro, largoFiltro);

    int **mSuma = suma(matrizA, matrizB, largo);
    escrituraMatriz(filenameMatrizSuma, mSuma, largo);

    int **mConv = convolucion(mSuma, matrizF, largo);
    escrituraMatriz(filenameMatrizConv, mConv, largo-2);
    
}