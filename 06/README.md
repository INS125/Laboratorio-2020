# # Uso del depurador GDB

En el siguiente documento se explicará cómo utilizar el depurador GDB.


## Compilar programa

Debe compilar su programa como es de costumbre pero agregando *---debug*.

    gcc main.c -o main.o --debug

> Recuerde que si tiene más programas .c necesarios para el funcionamiento de su programa "main.c" debe agregarlos al momento de compilar.
> `gcc main.c programa1.c programa2.c -o main.o --debug`

## Ejecutar GDB

Teniendo su programa compilado, deberá ejecutar el siguiente comando para utilizar el depurador:

    gdb main.o

## Correr GDB

Con el comando anterior estará dentro del depurador, sólo resta ejecutar:

    run
## Salir del depurador
Para salir del depurador sólo debe ejecutar:

    quit

---------
# Ejemplo

![](https://i.ibb.co/hcxpDX8/ejemplo.png)

Como podemos ver en este ejemplo el depurador nos ayudó a identificar que el error de *Segmentation fault* se produce al llamar a la función *"RellenarMatriz"*.
