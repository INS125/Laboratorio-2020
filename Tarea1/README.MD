# Tarea 1 - Tablas hash con arreglos

El enunciado de la tarea 1 lo encuentra en el archivo Tarea1-Laboratorio.pdf

# Actualización
El archivo pdf del enunciado fue actualizado. A grandes rasgos, los cambios son:
- No considerar coliciones. Si dos palabras entregan el mismo hash, cuentelas como si fueran la misma palabra.
- Actualizada funcion de hash hasta l-1.
- En caso que el hash calculado sea mayor a un millon (1.000.000), el hash correspondiente será el resto de la división por 1.000.000 del hash calculado.
- Arreglos en ejemplo de archivos de entrada/salida

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
