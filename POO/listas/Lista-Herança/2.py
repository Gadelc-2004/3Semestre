class FormaGeometrica:
    def __init__(self, area:float = 0, perimetro:float = 0):
        self.__area = area
        self.__perimetro = perimetro

    def __str__(self) -> str:
        return f"Area: {self.area}, Perimetro: {self.perimetro}"

    @property
    def area(self) -> float:
        return self.__area
    @property
    def perimetro(self) -> float:
        return self.__perimetro

    def calcula_area(self):
        if isinstance(self, Retangulo):
            self.__area = self.base * self.altura
        if isinstance(self, Triangulo):
            s = (self.lado1 + self.lado2 + self.lado3) / 2 
            self.__area = ((s * (s - self.lado1) * (s - self.lado2) * (s - self.lado3)) ** 0.5)

    def calcula_perimetro(self):
        if isinstance(self, Retangulo):
            self.__perimetro = (2 * ((self.base) + (self.altura)))
        if isinstance(self, Triangulo):
            self.__perimetro = (self.lado1 + self.lado2 + self.lado3)

class Retangulo(FormaGeometrica):
    def __init__(self, base:float, altura:float):
        super().__init__()
        self.__base = base
        self.__altura = altura

    def __str__(self) -> str:
        return f"Base: {self.base}, Altura: {self.altura}, Area: {self.area}, Perimetro: {self.perimetro}"
    
    @property
    def base(self) -> float:
        return self.__base
    @property
    def altura(self) -> float:
        return self.__altura

    @base.setter
    def base(self, a):
        self.__base = abs(a)
    @altura.setter
    def altura(self, a):
        self.__altura = abs(a)

class Triangulo(FormaGeometrica):
    def __init__(self, lado1:float, lado2:float, lado3:float):
        super().__init__()
        self.__lado1 = lado1
        self.__lado2 = lado2
        self.__lado3 = lado3

    def __str__(self) -> str:
        return f"Lado1: {self.lado1}, Lado2: {self.lado2}, Lado3: {self.lado3}, Area: {self.area}, Perimetro: {self.perimetro}"
    
    @property
    def lado1(self) -> float:
        return self.__lado1
    @property
    def lado2(self) -> float:
        return self.__lado2
    @property
    def lado3(self) -> float:
        return self.__lado3

    @lado1.setter
    def lado1(self, a):
        self.__lado1 = abs(a)
    @lado2.setter
    def lado2(self, a):
        self.__lado2 = abs(a)
    @lado3.setter
    def lado3(self, a):
        self.__lado3 = abs(a)

r1 = Retangulo(2, 4)
t1 = Triangulo(3, 3, 3)

print(f"r1 == Retangulo: {isinstance(r1, Retangulo)}")
print(f"r1 == FormaGeometrica: {isinstance(r1, FormaGeometrica)}")
print(f"r1 == Triangulo: {isinstance(r1, Triangulo)}\n")

print(r1)
r1.calcula_area()
r1.calcula_perimetro()
print(r1, '\n')

print(t1)
t1.calcula_area()
t1.calcula_perimetro()
print(t1)
