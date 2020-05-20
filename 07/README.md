# # Manejo de git en repl.it (Python)

En el siguiente documento se explicará cómo utilizar su repositorio remoto en un repl python. Recuerde que a diferencia de cuando crea su repl en lenguaje C, al crear un repl en Python se desplegará una consola Python al costado derecho y no de sistema, por lo cual usted no podrá usar los comandos de la misma forma que en un repl de C.

# Clonar repositorio (I)

## Paso 1:
Importe la biblioteca 'os' ejecutando lo siguiente en la consola.

    import os

> Recuerde que cada vez que haga "Run" deberá ejecutar este import si quiere utilizar comandos de sistema.
## Paso 2:
Utilice el siguiente comando para clonar su repositorio:

    os.system('git clone link-de-su-repositorio')
![ej1](https://i.ibb.co/k109Zrw/ej1.png)

Al hacer esto, verá en el costado izquierdo su repositorio clonado:
![enter image description here](https://i.ibb.co/Wg6KNwX/Captura-de-pantalla-2020-05-19-a-las-19-56-37.png)

## Paso 3:
Si usted presiona "run" el programa no ejecutará nada porque el archivo "main.py" creado por repl sigue vacío. Usted puede copiar el contenido del archivo "main.py" de su repositorio y copiarlo en el archivo "main.py" creado por repl. Si usted necesita más archivos haga click en el ícono de add file y realice la misma operación. 

## Paso 4:
Para esta tarea usted necesitará el archivo de entrada, denominado "usuarios.csv".
para tenerlo en su workspace puede crear un archivo con el mismo nombre y copiar su contenido, ó ejecutar el siguiente comando:

    os.system('wget https://raw.githubusercontent.com/INS125/Laboratorio/master/Tarea3/ejemplo1/usuarios.csv')
   
   Usted verá una salida por pantalla similar a esta:
   ![enter image description here](https://i.ibb.co/270M32c/e3.png)
 
Verá su archivo en el costado izquierdo:

![archivo csv](https://i.ibb.co/GF1dyQc/e4.png)

Realizando estos pasos tendrá todos los archivos necesarios para trabajar en su tarea.
> Algunos comandos sobrepasan la consola (a nivel visual) por lo que se recomienda escribir y copiar los comandos para simplemente dar enter.

# Realizar Commit (II)
## Paso 1
Para trabajar con git en la consola python deberá importar la biblioteca 'os' , y siempre que quiera trabajar en su repositorio deberá anteponer un "cd NOMBRE_REPOSITORIO;"  antes de su comando git, como se verá en los pasos descritos a continuación.

Debe setear sus credenciales para no tener problemas al realizar el commit:

    os.system('cd NOMBRE_REPOSITORIO; git config user.name "NOMBRE"')
    os.system('cd NOMBRE_REPOSITORIO; git config user.email "CORREO"')
![set variables](https://i.ibb.co/s6YV45b/e5.png)

## Paso 2
Asumiendo que usted estará trabajando en el archivo "main.py" creado por repl, y quiera subir un cambio sobre ese archivo en su repositorio remoto, deberá copiar su contenido y reemplazar el código del archivo "main.py" de su repositorio.

## Paso 3
Realice los pasos vistos para subir un cambio a su repositorio de la siguiente forma:

    os.system('cd NOMBRE_REPOSITORIO; git status')
    os.system('cd NOMBRE_REPOSITORIO; git add .')
    os.system('cd NOMBRE_REPOSITORIO; git commit -m "MENSAJE_COMMIT"')
    os.system('cd NOMBRE_REPOSITORIO; git push')

Realizando estos pasos sus cambios se verán reflejados en su repositorio remoto.

# Ejemplo (Realizar Commit):

Se tiene el siguiente cambio (return "He cambiado"):

![enter image description here](https://i.ibb.co/yY1Cm6s/c1.png)

Ejecutamos los comandos de git:

![enter image description here](https://i.ibb.co/d7T5YpD/c2.png)

   Vemos en nuestro repositorio de github, que se ha hecho el commit:
   ![enter image description here](https://i.ibb.co/3hjX6QR/c3.png)

Finalmente puede revisar el código en github para corroborar el cambio:

![enter image description here](https://i.ibb.co/xz2mZdD/c4.png)



