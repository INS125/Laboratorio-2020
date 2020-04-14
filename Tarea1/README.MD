# Tarea 1 - Tablas hash con arreglos

El enunciado de la tarea 1 lo encuentra en el archivo Tarea1-Laboratorio.pdf

# Actualización

**(14/04/2020)**
Luego de haber recibido la tarea N° 1 de laboratorio, notamos que cometieron muchos errores triviales los cuales, a pesar de haber realizado avances en su tarea, hacen imposible su revisión, por lo que tendrían la nota mínima. En otras palabras, si su programa no escribe un archivo con el formato explicado en los ejemplos, su tarea no será revisada dado que el proceso de revisión es automatizado.

Por lo tanto, hemos decidido otorgar un plazo extra para subsanar solo este problema hasta HOY Martes 14 de abril a las 20:00 hrs. 

Usted podrá hacer nuevos commits en su repositorio solucionando problemas que hagan imposible su revisión de manera automatizada, como:

- Programa no lee archivo de entrada o lee un archivo de entrada con nombre distinto a entrada.txt.
- Programa no genera un archivo de salida o el archivo de salida tiene un nombre distinto a salida.txt
- Programa genera un archivo de salida en un formato distinto a <HASH><ESPACIO><CONTADOR>. Escribir el hash correspondiente y el contador de las veces que se encuentra ese hash separados por un solo espacio en blanco.
- Programa recibe parámetros o valores ingresados por teclado que detienen su ejecución.
- Programa no compila con el comando gcc main.c -lm -o main.o

Si su tarea contiene alguno de estos errores y estos no son subsanados en la fecha dada, usted tendrá la nota mínima.

Esta es una oportunidad excepcional, que se dará solo por esta vez. Las próximas tareas tendrán formatos de revisión similares y si su programa no cumple con los especificado para su revisión, su calificación será mínima.


# Actualizaciones previas

El código inicial debe ser actualizado.

- La linea 8, en la declaración del arreglo char linea, debe cambiar el tamaño de linea a 5000 elementos.
Linea 8, donde dice: 
```
char linea[255];
```
Debe decir:
```
char linea[5000];
```

- La función fgets de la linea 10 debe ser invocada con un buffer de tamaño 1000. Ese buffer corresponde a la cantidad máxima de caracteres que se leerán por linea.**

Linea 10, donde dice: 
```
while ( fgets (linea, 60, fp) != NULL ) {
```
Debe decir:
```
while ( fgets (linea, 1000, fp) != NULL ) {
```


El archivo pdf del enunciado fue actualizado. Agradecemos a Tomas por sus observaciones. A grandes rasgos, los cambios son:
- No considerar coliciones. Si dos palabras entregan el mismo hash, cuentelas como si fueran la misma palabra.
- En caso que el hash calculado sea mayor a un millon (1.000.000), el hash correspondiente será el resto de la división por 1.000.000 del hash calculado.
- Arreglos en ejemplo de archivos de entrada/salida

- 07/04/2020 Actualizado salida de ejemplo2, el hash generado por la palabra revolutionary.

# Evaluación
Para evaluar su tarea, se utilizarán 2 archivos de entrada, con distintos textos y distintos valores de k. 

| Item                                                           | Puntaje |
|----------------------------------------------------------------|---------|
| Generar archivo salida.txt                                     | 0.5     |
| Escribir en archivo los hash correspondientes                  | 2.5     |
| Escribir en archivo la cantidad de apariciones de cada palabra | 3.0     |
| Total                                                          |  6      |

Si su programa falla en calcular el valor de algún hash en particular o en calcular la cantidad de apariciones de una palabra en particular, tendrá un descuento proporcional.

# Preguntas o dudas
Utilice la sección de Issues de este repositorio. No utilice la sección de issues de su repositorio personal, ya que nadie las leerá.
