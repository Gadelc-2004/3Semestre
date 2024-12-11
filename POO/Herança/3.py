#Herança multipla

class Atleta:
    def __init__(self, aposentado:bool, peso:float):
        self.aposentado = aposentado
        self.peso = peso

    def aposentar(self):
        self.aposentado = True

    def aquecer(self):
        print("Atleta aquecendo...")

class Corredor(Atleta):
    def correr(self):
        print("Corredor correndo")

class Nadador(Atleta):
    def nadar(self):
        print("Nadador nadando...")

class Ciclista(Atleta):
    def pedalar(self):
        print("Ciclista pedalando...")

class TriAtleta(Corredor, Nadador, Ciclista):
    pass

t = TriAtleta(aposentado=False, peso = 60)

t.aquecer()
t.correr()
t.nadar()
t.pedalar()
