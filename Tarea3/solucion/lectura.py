# Generador: Recibe un archivo csv y lo lee linea a linea.
def generadorArchivo(NombreArchivo):
    with open(NombreArchivo,'r') as f:
    	for line in f.readlines():
        	yield line.split("\n")[0].split(";") # esto elimina el caracter de salto de linea y lo separa por ;
