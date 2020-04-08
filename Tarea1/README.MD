# Tarea 1 - Tablas hash con arreglos

El enunciado de la tarea 1 lo encuentra en el archivo Tarea1-Laboratorio.pdf

# Actualización
**El código inicial debe ser actualizado.**

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
