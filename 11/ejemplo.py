class Instrumento:
  def __init__(self, tipo, marca, precio):
    self.tipo = tipo
    self.marca = marca
    self.precio = precio
    # print('Se creo un instrumento')
  def __str__(self):
    return 'Instrumento de tipo: {}, Marca: {}, Precio {}'.format(self.tipo, self.marca, self.precio)
  def descuento(self):
    desc = 10
    nuevo_precio = self.precio - (self.precio * (desc/100))
    return nuevo_precio
  def sonar(self):
    return "ola estoy tocando un instrumento de tipo "+self.tipo+ " y marca " + self.marca 
  
  @property
  def PrecioFinal(self):
    return self.descuento()

class Producto:
  def __init__(self):
    print('Se ha creado un producto')

class Guitarra(Instrumento, Producto):
  def __init__(self, tipo, marca, precio, modelo):
    Instrumento.__init__(self, tipo, marca, precio)
    # super().__init__(tipo, marca, precio)
    Producto.__init__(self)
    self.modelo = modelo
  def __str__(self):
    return super().__str__() + ' modelo: '+ self.modelo
  def sonar(self):
    return 'E A D G B E'
    
class Bajo(Instrumento):
  def __init__(self, tipo, marca, precio, modelo):
    super().__init__(tipo, marca, precio)
    self.modelo = modelo
  def __str__(self):
    return super().__str__() + ' modelo: '+ self.modelo
  def sonar(self):
    return 'E A D G'

def TocarMusica( ins ) : 
  print( ins.sonar() )


i = Instrumento('clásico','takamine',1000)
g = Guitarra('Electrica', 'Gibson', 3000, 'Les Paul')
b = Bajo('Eléctrico', 'Fender', 2000, 'Jazz Bass')
# print(g)
# print(g.sonar())
'''print(b)
print(b.sonar())'''

# print(b.PrecioFinal )
TocarMusica(i)
TocarMusica(g)
TocarMusica(b)

# print(i)
# print(Instrumento.descuento(i))
  