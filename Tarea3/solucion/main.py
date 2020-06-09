from string import ascii_lowercase, ascii_uppercase
from datetime import datetime, timedelta
import functools
from functools import reduce
from lectura import generadorArchivo


def cifrado(string,rot):
    return (''.join(list(map(lambda x: ascii_lowercase[(ascii_lowercase.index(x)+int(string[2][-1].replace('K','1'))) % len(ascii_lowercase)] if (x in ascii_lowercase) else ascii_uppercase[(ascii_uppercase.index(x)+int(string[2][-1].replace('K','1'))) % len(ascii_uppercase)], map(lambda x: x.replace('á','a').replace('é','e').replace('í','i').replace('ó','o').replace('ú','u').replace('ñ','n').replace('Á','A').replace('É','E').replace('Í','I').replace('Ó','O').replace('Ú','U').replace('Ñ','N'),string[0]+string[1])))))


def sumaCod(string):
    return reduce(lambda x,y : int(x) + int(y), string)


def separadorCifrado(string,rut):
    return list(filter(lambda x: x!= None, list(map(lambda x: string[x]+string[x+1] if(x%2==0 and x<len(string)-1) else None, range(len(string))))))


def modificarMenores(lista):
    return list(map(lambda x: list(map(lambda y: str(int(y)+35) if(int(y)<35) else y, lista[x])), range(len(lista))))


def modificarEspeciales(lista,especiales):
    return list(map(lambda x: list(map(lambda y: str(int(y)+10) if(int(y) in especiales) else y, lista[x])), range(len(lista))))


def validador(suma,rut):
    return sumaCod(suma)*(int(rut[-1]))


def escribirArchivo(lista,nombre):
    f = open(nombre,'w')
    for x in range(len(lista)):
        f.write('{};{};{};{}'.format(lista[x][0],lista[x][1],lista[x][2],lista[x][3]))
        if x != len(lista)-1:
            f.write('\n')


if __name__ == "__main__":
    especiales = [*range(39,48),*range(58,63),*range(91,97)]
    escribirArchivo(list(filter(lambda x: datetime.strptime(x[3], '%d-%m-%Y') > datetime.strptime('01-01-1960', '%d-%m-%Y'), list(generadorArchivo('usuarios.csv')))),"permitidos.csv")
    escribirArchivo(list(filter(lambda x: datetime.strptime(x[3], '%d-%m-%Y') < datetime.strptime('01-01-1960', '%d-%m-%Y'), generadorArchivo('usuarios.csv'))),"riesgo.csv")
    permitidos = list(generadorArchivo('permitidos.csv'))
    list(map(lambda x: x.pop(3), permitidos))
    list(map(lambda x,y: x.append(y), permitidos,list(map(lambda x,y: x+str(y), list(map(lambda y: ''.join(list(map(lambda x: chr(int(x)), y))),
    modificarEspeciales(modificarMenores(list(map(lambda x,y: separadorCifrado(x,y[-2][-1].replace('K','1')) if(len(x)%2==0) else separadorCifrado(('{}{}'.format(x,y[-2][-1].replace('K','1'))),y[-2][-1].replace('K','1')),
    list(map(lambda y: ''.join(list(map(lambda x: str(ord(x)), y))),
    list(map(lambda x: cifrado(x,x[-2]), list(generadorArchivo('permitidos.csv')))))),
    list(generadorArchivo('permitidos.csv'))))),especiales))),
    list(map(lambda x,y: validador(x,y), list(map(lambda y: ''.join(list(map(lambda x: str(ord(x)), y))),
    list(map(lambda x: cifrado(x,x[-2]), list(generadorArchivo('permitidos.csv')))))),
    list(map(lambda y: y[-2][-1].replace('K','1'), list(generadorArchivo('permitidos.csv'))))))))))
    escribirArchivo(permitidos,'info.csv')