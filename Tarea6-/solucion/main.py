import urllib3
import xmltodict
import argparse
from concurrent.futures import ThreadPoolExecutor
import time

http = urllib3.PoolManager(1)
def ObtenerDatosNorma(id_norma):
	http_response = 0
	try:		
		# Si la respuesta http es distinta a 200 (OK, satisfactoria) vuelve a intentar hasta que entregue 200. Por error del servidor la respuesta puede ser 500
		while http_response != 200:
			req = http.request('GET', 'https://www.leychile.cl/Consulta/obtxml?opt=7&idNorma='+str(id_norma))  
			http_response = req.status
		return req.status,xmltodict.parse(req.data)
	except:
		#print("Error al rescatar norma: ",id_norma,". La respuesta http fue: ", req.status)
		return 0,dict()


# Generador: Recibe un archivo csv y lo lee linea a linea.
def generadorArchivo(NombreArchivo):
    with open(NombreArchivo,'r') as f:
    	for line in f.readlines():
        	yield int(line) # esto elimina el caracter de salto de linea y lo separa por ;


def GetData(id_norma):
	response,result = ObtenerDatosNorma(id_norma)
	
	if response == 200:		
		try :
			datos = [str(id_norma), result['Norma']['@fechaVersion'], result['Norma']['@derogado'], result['Norma']['@esTratado'], result['Norma']['Encabezado']['Texto'].split('\n')[0] ]	
			return str('\t'.join(datos)) 
		except Exception as e:
			return str(id_norma) + '\t' + "Error al obtener norma"
	else :
		return str(id_norma) + '\t' + "Error al obtener norma"

if __name__ == "__main__":
	# Lee los parametro de entrada. Si no se definen, se utiliza el valor por defecto.
	parser = argparse.ArgumentParser(description='Genera un archivo con la salida del detalle de las normas')
	parser.add_argument('--workers', type=int, default="100", help='Define el numero de threads a utilizar')
	parser.add_argument('--input',   type=str, default="input2.tsv", help='Define el nombre del archivo de entrada con los ID de norma correspondiente')
	parser.add_argument('--output',   type=str, default="salida.tsv", help='Define el nombre del archivo de salida correspondiente')
	args = parser.parse_args()

	# Usted puede acceder a los parametros utilizando las propiedades args.workers y args.input
	print("Comienza la ejecucion")
	print("Workers:\t", args.workers)
	print("Input:\t",args.input)
	
	ex = ThreadPoolExecutor(max_workers=args.workers)	
	results = ex.map(GetData, generadorArchivo(args.input), timeout=60 )

	with open(args.output, 'a') as o :
		for f in results:
			o.write(f+'\n')	
