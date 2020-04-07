# Uso básico de la biblioteca string.h

La biblioteca string.h nos entrega algunas facilidades para trabajar con cadenas de char. Veremos algunas funciones fundamentales de esta biblioteca.

## strcpy

Recordemos que en C, la forma de representar una cadena de caracteres es a través de un arreglo de char.

Por lo tanto, este programa es válido para realizar una asignación

```
#include <stdio.h>

int main(void) {

  char palabra[10] = "HOLA CURSO";
  
  return 0;
}
```

Sin embargo, si queremos realizar la asignación de la cadena en una instrucción distinta a la de declaración, sucede esto:

```
#include <stdio.h>

int main(void) {

  char palabra[10];
  palabra = "HOLA CURSO";
  
  return 0;
}
```
`error: array type 'char [10]' is not assignable`

Para solucionarlo, podemos usar la función strcpy de la biblioteca string.h. Esta función se invoca como  `strcpy(dest, src)` y copia la cadena de `src` en `dest`.

Por lo tanto, una correcta asignación sería:
```
#include <stdio.h>
#include <string.h>

int main(void) {

  char palabra[10];
  strcpy(palabra, "HOLA CURSO");
  
  return 0;
}
```


## strlen()

La función strlen(), parte de string.h, sirve para obtener el largo de una cadena de caracteres.

```
#include <stdio.h>
#include <string.h>

int main(void) {

  char palabra[10] = "HOLA";
  int largo = strlen(palabra);

  printf("El largo de la cadena es %d",largo);
  
  return 0;
}
```
Este programa imprimirá `El largo de la cadena es 4`




## Convertir un valor char a un entero

La función `atoi(numeroenchar)` convierte un char a un entero. Esta función es parte de la biblioteca stdlib.h, por lo tanto deben agregar el macro `#include <stdlib.h>`

```
char numerocomoletra[10] = "123";
int numerocomoentero = atoi(numerocomoletra);
```
