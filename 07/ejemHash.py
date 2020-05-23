from functools import reduce

def calcular_hash(pal_):
    elem_suma = list(map(lambda x, y: ord(x) * k_value**y, pal_.replace('\n',''), range(0,len(pal_))))
    suma_hash = reduce(lambda x,y: x + y, elem_suma)
    return suma_hash

def guardar_hash(palabra_):
    hash_calculado = calcular_hash(palabra_)
    hash_calculado = hash_calculado if hash_calculado < 1000000 else hash_calculado%1000000
    if hash_calculado in hash_info.keys():
        hash_info[hash_calculado] += 1
    else:
        hash_info[hash_calculado] = 1

file_in = 'data.in'
file_out = 'data.out'
k_value = 0
hash_info = {}
with open(file_in, 'r') as input_file:
    lines = input_file.readlines()
    k_value = int(lines[0])

    data = list(map(guardar_hash, lines[1].replace('\n','').split(' '))) 
    
    palabras_buscar = list(map(calcular_hash, lines[3:]))
    with open(file_out, 'w') as output_file:
        escribir = list(map(lambda pal: output_file.write(f'{pal} {hash_info[pal] if pal in hash_info.keys() else "0"}\n'), palabras_buscar))