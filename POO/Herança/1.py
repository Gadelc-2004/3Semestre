class FormaGeometrica:
    def __init__(self):
        pass

    def area(self):
        pass

    def perimetro(self):
        pass

class Quadrado(FormaGeometrica):
    def __init__(self, lado:float):
        self.lado = lado

    def area(self) -> float:
        return self.lado * self.lado

    def perimetro(self) -> float:
        return 4 * self.lado

class Circulo(FormaGeometrica):
    PI=3,141359
    def __init__(self, raio: float):
        self.raio = raio

    def area(self) -> float:
        return (self.PI * self.raio ** 2)

C1 = Circulo(raio = 5)
print(C1.area())
print("Valor de PI: ", Circulo.PI)
print("Valor do raio do objeto: ", C1.raio)
