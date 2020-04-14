# Punteros

Un puntero es una variable que almacena (en vez de un dato) una dirección de memoria.

# Operadores
- **&**: Dirección de memoria en la cual esta almacenado el puntero 
- **\***: Valor almacenado en la dirección de memoria a la que apunta
- **nada**: La direccion a la que apunta, ya que es una variable que almacena una direccion de memoria.

# Ejemplo: Operadores

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
  int var;
  int *ptr;
  ptr = &var // ptr apunta a la direccion de var

  printf("var es una variable automatica que tiene el valor &d y esta almacenada en %d \n", var, (int)&var);

  printf("ptr es un puntero que esta almacenado en %d apunta a %d y tiene el valor %d",(int)&ptr, (int)ptr, *ptr );

  // Como ptr apunta a la direccion de var, al hacer cambios en uno, producimos cambios en los dos.

  *ptr = 5000;

  printf("En *ptr tiene el valor %d. En var tiene el valor %d", *ptr, var );

  return 0;
}
```

# Ejemplo: Punteros dobles
```c
#include <stdio.h> 
#include <stdlib.h>

int main(){
	int i;
	int *ptrToi; /* Puntero a entero */
	int **ptrToPtrToi; /* Puntero a puntero a entero */
	ptrToPtrToi = &ptrToi; /* Puntero contiene dirección de puntero */
	ptrToi = &i;
	/* Puntero contiene dirección de entero */
	/* Asignación directa */
	/* Asignación indirecta */
	i = 10;
	*ptrToi = 20;
	**ptrToPtrToi = 30; /* Asignación con doble indirección */

	return 0; 
}

```

# Ejemplo: Estructuras

Las estructuras, tienen distinta forma para llamar a sus propiedades de acuerdo a si está declarada como puntero o como variable.
```c
#include <stdio.h> 
#include <stdlib.h>

typedef struct ESTRUCTURA{
  int x;
}ESTRUCTURA;

int main(){
	ESTRUCTURA aa;
  	ESTRUCTURA *bb;

	aa.x = 10;
	bb-> = 20;
  
	printf("%d %d\n", aa.x, bb->x);

	return 0;
}

```

# Ejercicio:
Generar una matriz con doble puntero.