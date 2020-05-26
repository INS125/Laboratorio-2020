
from datetime import *

def leerArchivo(NombreArchivo):
	salida = []
	with open(NombreArchivo, 'r') as f:
		for line in f.readlines():
			yield line.split('\n')[0].split(';')
	#return salida

if __name__ == "__main__":
	datos = leerArchivo('test.txt')
	los_mayores = filter( lambda registro: datetime.strptime('25-02-1996', '%d-%m-%Y') > datetime.strptime(registro[1], '%d-%m-%Y'), datos )
	datos = leerArchivo('test.txt')
	los_menores = filter( lambda registro: datetime.strptime('25-02-1996', '%d-%m-%Y') < datetime.strptime(registro[1], '%d-%m-%Y'), datos )

	print("los mayores son")
	print(los_mayores)
	print("los menores son")
	print(los_menores)
