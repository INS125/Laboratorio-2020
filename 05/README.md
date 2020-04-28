# Matrices y arreglos dinámicos

En esta actividad revisaremos como utilizar la memoria heap para almacenar datos estructurados como arreglos y matrices, junto con repasar conceptos de paso por valor y por referencia.


Una matriz debe ser declarada como un doble puntero. En resumen, consiste en declarar un arreglo, dentro de los elementos del arreglo. Este segmento de código crea una matriz de  N\*M 

```c
int** Matriz; 
Matriz = (int**)malloc(sizeof(int*)*ancho); 
for(int i = 0; i<ancho; i++){
	Matriz[i] = (int*)malloc(sizeof(int) * alto); //
}
```

Una vez declarada la matriz, puedo acceder a ella a traves de procedimientos, entregandole Matriz como referencia. En el ejemplo, se declara la funcion `RellenarConRandom()` la cual accede por referencia a la matriz `Matriz`, invocandola como `RellenarConRandom(M, ancho, alto)`

```c
void RellenarConRandom(int **matriz, int tam_filas, int tam_columnas){
  for(int i=0; i<tam_columnas; i++){
    for(int j=0; j<tam_filas; j++){
      //*(*(matriz+i)+j) = 20+rand()%30; //se puede usar esa notacion, son equivalentes
      matriz[i][j] =  20+rand()%30;
    }
  }
}

```
Notar que la funcion RellenarConRandom no tiene return, pero es capaz de cambiar los valores que recibe por referencia.



El codigo final es
```c
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int **CrearMatriz(int ancho, int alto){
  int** Matriz;
  Matriz = (int**)malloc(sizeof(int*)*ancho);
  for(int i = 0; i<ancho; i++){
    Matriz[i] = (int*)malloc(sizeof(int) * alto); //
  }

  return Matriz;
}

void RellenarConRandom(int **matriz, int tam_filas, int tam_columnas){
  //matriz[0][0] // *(*(matriz+0)+0)
  
  for(int i=0; i<tam_columnas; i++){
    for(int j=0; j<tam_filas; j++){
      //*(*(matriz+i)+j) = 20+rand()%30;
      matriz[i][j] =  20+rand()%30;
    }
  }
}

void Imprimir(int **matriz, int tam_filas, int tam_columnas){
  for(int i=0; i<tam_columnas; i++){
    for(int j=0; j<tam_filas; j++){
      printf("%d\t", *(*(matriz+i)+j) );
    }
    printf("\n");
  }
}

int main(void) {

  int ancho=10;
  int alto = 5;

  int **M;
  srand(time(NULL));
  M = CrearMatriz(ancho, alto);

  // Mostrar M
  printf("Matriz antes de rellenar\n\n");
  Imprimir(M, ancho, alto);


  RellenarConRandom(M, ancho, alto);

  // Mostrar M
  printf("\n\nMatriz despues de rellenar\n\n");
  Imprimir(M, ancho, alto);
 
  for(int i=0; i<alto; i++)
  	free(*(M+i));

  return 0;
}
```
