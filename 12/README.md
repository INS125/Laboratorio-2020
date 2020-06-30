# Concurrencia - Hilos y Procesos con concurrent.futures

La biblioteca concurrent.futures provee una interfaz de alto nivel que simplifica el acceso a funciones básicas de concurrencia. Permite generar ejecuciones asincronas, ya sea en formato multiproceso o multithread, con mínimos cambios en la programación.

Su utilización se basa en la declaración de un objeto `executor` utilizando las clases `ProcessPoolExecutor` y `ThreadPoolExecutor`, para multiprocesos o multi hilos, respectivamente. Estas dos clases son heredadas de la clase Executor, por lo que comparten los mismos métodos.

## Multiples procesos

Vamos a definir una funcion que simplemente aumente en uno un valor hasta llegar a un numero n y retorne el tiempo que le tomó hacer esa operación. El tiempo de ejecución de esta función crece linealmente en la medida que aumenta el valor del parámetro de entrada `n`. En mi computador, ejecutar esta funcion con `n=98582115` demora 4.8 segundos.

```python
def contar_hasta(n):
	start = time.time()
	i = 0
	while i<n:
		i+=1

	tiempo = time.time()-start
	print("En contar hasta",n,"me demore",tiempo)
	return tiempo
```

Podemos ejecutar esta funcion en multiples procesos con un objeto de tipo `ProcessPoolExecutor`, que se encargará de ejecutar la función. Ahora contaremos hasta todos los valores de forma concurrente:

```python
valores = [
14724292,
98582115,
46434954,
53716608,
73600540,
24820679,
55962544,
11746328]
```
Y en el main, invocaremos al método map, que aplica un valor a una función de manera concurrente.

```python
if __name__ == '__main__':
	print("HOLA, ESTOY EN LA PRIMERA LINEA DE EJECUCIÓN")

	executor = ProcessPoolExecutor(max_workers=5)
	resultado = executor.map(contar_hasta, valores)

	print("HASTA LUEGO AMIGOS, ESTOY EN LA ULTIMA LINEA")
```

La salida de nuestro programa es la siguiente:

```
HOLA, ESTOY EN LA PRIMERA LINEA DE EJECUCIÓN
HASTA LUEGO AMIGOS, ESTOY EN LA ULTIMA LINEA
En contar hasta 14724292 me demore 0.7969694137573242
En contar hasta 24820679 me demore 1.6234183311462402
En contar hasta 46434954 me demore 2.5657970905303955
En contar hasta 11746328 me demore 0.9541699886322021
En contar hasta 53716608 me demore 3.9742071628570557
En contar hasta 73600540 me demore 4.518940448760986
En contar hasta 55962544 me demore 2.7584378719329834
En contar hasta 98582115 me demore 5.548259496688843
[Finished in 5.6s]
```

Podemos observar, que aunque la operación que se encarga de mostrar el mensaje `HASTA LUEGO AMIGOS` está en la última linea de ejecución, debido a que la utilización del objeto executor es asincrona, lo muestra al final. 

Podemos ejecutar el mismo programa pero, en vez de multiples procesos, utilizar multiples hilos. En ese caso, nuestro main quedaría asi:

```python
if __name__ == '__main__':
	print("HOLA, ESTOY EN LA PRIMERA LINEA DE EJECUCIÓN")

	executor = ThreadPoolExecutor(max_workers=5)
	resultado = executor.map(contar_hasta, valores)

	print("HASTA LUEGO AMIGOS, ESTOY EN LA ULTIMA LINEA")
```

y la salida del programa será la siguiente:

```
HOLA, ESTOY EN LA PRIMERA LINEA DE EJECUCIÓN
HASTA LUEGO AMIGOS, ESTOY EN LA ULTIMA LINEA
En contar hasta 14724292 me demore 3.893723726272583
En contar hasta 24820679 me demore 5.6058855056762695
En contar hasta 46434954 me demore 10.350748777389526
En contar hasta 53716608 me demore 12.245936632156372
En contar hasta 11746328 me demore 3.272231340408325
En contar hasta 73600540 me demore 16.384231090545654
En contar hasta 55962544 me demore 8.67614483833313
En contar hasta 98582115 me demore 18.76377034187317
[Finished in 18.8s]
```

Observamos que ejecutar el mismo programa con multiples procesos demora tan solo 5.6 s, mientras que ejecutarlo con multiples hilos demora 18.8 s.

### Variables compartidas

Veamos que pasa si declaramos una lista, y hacemos que cada vez que ejecutamos el procedimiento `contar_hasta` agregue el tiempo que tarda en una lista. Para eso, agregamos unas pocas lineas a nuestro programa. Además, agregamos un ciclo que itere y permita esperar a que la ejecución asincrona termine antes de ejecutar las lineas siguientes

```python 
contador = []

def contar_hasta(n):
	start = time.time()
	i = 0
	while i<n:
		i+=1

	tiempo = time.time()-start
	print("En contar hasta",n,"me demore",tiempo)
	contador.append(tiempo)
	return tiempo

if __name__ == '__main__':
	print("HOLA, ESTOY EN LA PRIMERA LINEA DE EJECUCIÓN")

	executor = ProcessPoolExecutor(max_workers=5)
	resultado = executor.map(contar_hasta, valores)

	for r in resultado:
		print("OK", future)

	print("HASTA LUEGO AMIGOS, ESTOY EN LA ULTIMA LINEA")
	print("Los tiempos fueron:",contador)
```
La salida es la siguiente:
```
HOLA, ESTOY EN LA PRIMERA LINEA DE EJECUCIÓN
En contar hasta 14724292 me demore 1.114682674407959
OK 1.114682674407959
En contar hasta 24820679 me demore 1.4825208187103271
En contar hasta 46434954 me demore 2.9889938831329346
En contar hasta 53716608 me demore 3.302863597869873
En contar hasta 11746328 me demore 0.9616260528564453
En contar hasta 73600540 me demore 4.228123903274536
En contar hasta 55962544 me demore 2.6294679641723633
En contar hasta 98582115 me demore 5.738171577453613
OK 5.738171577453613
OK 2.9889938831329346
OK 3.302863597869873
OK 4.228123903274536
OK 1.4825208187103271
OK 2.6294679641723633
OK 0.9616260528564453
HASTA LUEGO AMIGOS, ESTOY EN LA ULTIMA LINEA
Los tiempos fueron: []
[Finished in 5.8s]
```
Observamos que al imprimir los valores en la lista contador, esta se encuentra vacia.

Si cambiamos el objeto executor a uno de tipo `ProcessPoolExecutor`, la salida es la siguiente:
```
HOLA, ESTOY EN LA PRIMERA LINEA DE EJECUCIÓN
En contar hasta 14724292 me demore 3.440847873687744
OK 3.440847873687744
En contar hasta 46434954 me demore 7.773011922836304
En contar hasta 24820679 me demore 7.505795001983643
En contar hasta 11746328 me demore 2.1656227111816406
En contar hasta 53716608 me demore 16.161118268966675
En contar hasta 73600540 me demore 16.16681671142578
En contar hasta 55962544 me demore 10.976693153381348
En contar hasta 98582115 me demore 19.31981372833252
OK 19.31981372833252
OK 7.773011922836304
OK 16.161118268966675
OK 16.16681671142578
OK 7.505795001983643
OK 10.976693153381348
OK 2.1656227111816406
HASTA LUEGO AMIGOS, ESTOY EN LA ULTIMA LINEA
Los tiempos fueron: [3.440847873687744, 7.773011922836304, 7.505795001983643, 2.1656227111816406, 16.161118268966675, 16.16681671142578, 10.976693153381348, 19.31981372833252]
[Finished in 19.4s]
```
Observamos que, si bien tardó mas tiempo, la lista contador si contiene valores.


## Multiples hilos

Como vimos en el ejemplo anterior, el utilizar multiples procesos es mas rápido que utilizar multiples hilos. Veamos que pasa ahora si, en vez de ejecutar una función que realiza cómputo en la CPU (como la funcion contar_hasta), ejecutamos una función que simplemente espera.

```python
def dormir_hasta(n):
	start = time.time()

	time.sleep(n)
	
	tomo = time.time()-start
	print("Esto se demoro",tomo)
	return n
```

Si lo ejecutamos en multiples procesos

```python
if __name__ == '__main__':
	
	ex = ProcessPoolExecutor(max_workers=8)
	
	print("Hola estoy comenzando la ejecucion")
	
	resultado = list(ex.map(dormir_hasta, dormir))

	print("Chao me voy a almorzar")
	print(resultado)
	print(valores)
```
La salida del programa será:
```
Hola estoy comenzando la ejecucion
Esto se demoro 1.0003166198730469
Esto se demoro 3.0031185150146484
Esto se demoro 3.00307035446167
Esto se demoro 4.003916501998901
Esto se demoro 5.003007888793945
Esto se demoro 6.004042387008667
Esto se demoro 7.003390789031982
Esto se demoro 8.007596254348755
Chao me voy a almorzar
[1, 6, 4, 8, 3, 7, 3, 5]
[14724292, 98582115, 46434954, 53716608, 73600540, 24820679, 55962544, 11746328]
[Finished in 8.1s]
```
Mientras que si cambiamos el objeto `ex` a uno de la clase `ThreadPoolExecutor` 


```python
if __name__ == '__main__':
	
	ex = ThreadPoolExecutor(max_workers=8)
	
	print("Hola estoy comenzando la ejecucion")
	
	resultado = list(ex.map(dormir_hasta, dormir))

	print("Chao me voy a almorzar")
	print(resultado)
	print(valores)
```
La salida será:
```
Hola estoy comenzando la ejecucion
Esto se demoro 1.0010466575622559
Esto se demoro 3.001880407333374
Esto se demoro 3.0022623538970947
Esto se demoro 4.002374887466431
Esto se demoro 5.001781702041626
Esto se demoro 6.005478382110596
Esto se demoro 7.005982398986816
Esto se demoro 8.006256341934204
Chao me voy a almorzar
[1, 6, 4, 8, 3, 7, 3, 5]
[14724292, 98582115, 46434954, 53716608, 73600540, 24820679, 55962544, 11746328]
[Finished in 8.1s]
```

Se observa que, tanto en concurrencia de procesos como de hilos, ambas ejecuciones tardaron lo mismo. Entonces, en casos como este, es mejor utilizar threads.


### Global Interpreter Lock (GIL)

GIL es un mecanismo que impide que multiples Threads modifiquen objetos a la vez, e impedir que ocurran condiciones de carrera. Los métodos de python que usen el GIL se consideran Thread-safe, es decir, que son seguros para su utilización en multiples hilos. La labor del GIL es que el interprete de python no puede interpretar bytecode de manera concurrente. 

# Conclusión

- Cuando tenemos un programa o subprograma en el que gran parte del tiempo lo utiliza realizando computo, debemos utilizar un sistema multiproceso, ya que este puede evitar el GIL.

- Por otra parte, cuando tenemos un sistema en el que gran parte de la ejecución se utiliza esperando respuestas (IDLE), como solicitudes http o metodos de entrada/salida de archivos, deberíamos utilizar threads.