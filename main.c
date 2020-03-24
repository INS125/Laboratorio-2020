#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  //*** Ejemplo, Uso de rand con srand para números aleatorios ***
  /*srand (time(NULL));
  int random = rand() % 20;
  printf("el numero es: %i", random);*/

  //*** Ejemplo, solicitar por pantalla y asignar a variable ***
  /*int numero;
  printf("indique un numero: ");
  scanf("%i",&numero);
  printf("el numero ingresado fue: %i", numero);*/

  //*** Ejemplo: definiciones y validación para tarea ***
  // Declarar Variables
	int num, min, max,rango_random,mult;
	mult = 2;
  min = 5;
  max = 10;
    // Solicitar tamaño de arreglo
    
    printf("Ingrese un numero entre %i y %i: ", min, max);
    scanf("%i",&num);
    
    // Validar rango del tamaño de arreglo
    
    if (num < 5 || num > 10)
	{
		printf("rango no aceptado !!!");
		return 1;
	}
	else
	
	rango_random = mult * num;
    int array[num];
  return 0;
}
