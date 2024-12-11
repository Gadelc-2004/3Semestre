import math

class Ponto2D:
    def __init__(self, x:float = 0, y:float = 0):
        self.__x = x
        self.__y = y

    def __str__(self) -> str:
        return f"({self.x}, {self.y})"

    @property
    def x(self) -> float:
        return self.__x
    @property
    def y(self) -> float:
        return self.__y

    @x.setter
    def x(self, nx:float):
        self.__x = nx
 
    @y.setter
    def y(self, ny:float):
        self.__y = ny

    def comparar(self, a:"Ponto2D") -> bool:
        if((self.x == a.x) and (self.y == a.y)):
            return True
        else:
            return False

    def distance(self, a:"Ponto2D") -> float:
        return math.sqrt(((self.x - a.x) ** 2) + ((self.y - a.y) ** 2))
    
    def clonar(self) -> "Ponto2D":
        return(self)

class Circulo:
    def __init__(self, raio:float, ponto:Ponto2D = Ponto2D()):
        self.__raio = raio
        self.__ponto = ponto

    def __str__(self) -> str:
        return f"(r = {self.__raio}, P = {self.__ponto})"

    @property
    def raio(self) -> float:
        return self.__raio

    @raio.setter
    def raio(self, nr:float):
        self.__raio = nr

    @property
    def ponto(self) -> Ponto2D:
        return self.__ponto

    def inflar(self, x:float):
        if(x < 0):
           return
        else:
            self.raio += x

    def desinflar(self, x:float):
        if(x < 0):
            return
        else:
            self.raio -= x

    def mover(self, cord:Ponto2D = Ponto2D()):
        self.__ponto = cord

    def area(self) -> float:
        return (3.1415 * (self.raio ** 2))

class Retangulo:
    def __init__(self, largura:float = 1, altura:float = 1, ponto:Ponto2D = Ponto2D()):
        self.__largura = largura
        self.__altura = altura
        self.__ponto = ponto

    def __str__(self) -> str:
        return f"(l = {self.largura}, a = {self.altura}, P = {self.ponto})"

    @property
    def largura(self) -> float:
        return self.__largura

    @property
    def altura(self) -> float:
        return self.__altura

    @property
    def ponto(self) -> Ponto2D:
        return self.__ponto


    @largura.setter
    def largura(self, larg):
        if(larg < 0):
            self.__largura = 0
        else:
            self.__largura = larg

    @altura.setter
    def altura(self, alt):
        if(alt < 0):
            self.__altura = 0
        else:
            self.__altura = alt

    def mover(self, cord:Ponto2D = Ponto2D()):
        self.ponto = cord

    def area(self) -> float:
        return (self.largura * self.altura)

    def intersecao(self, rn: "Retangulo") -> bool:
        if((((rn.ponto.x + rn.largura) < self.ponto.x) or (rn.ponto.y > (self.ponto.y + self.altura))) or
            ((rn.ponto.x > (self.ponto.x + self.largura)) or ((rn.ponto.y + rn.altura) < self.ponto.y))):
            return False 
        return True

#comeco dos testes do exercicio 2
print("Testes - Lista de Exercícios – Classes e Objetos - Exercicio 2\n")
p1 = Ponto2D(2.5, 2.5)
print(f'Teste de desclaracao e impressao: {p1}\n')

p2 = Ponto2D(2.5, 4.5)
print(f'Teste do metodo de comparacao\np1(2.5, 2.5) == p2(2.5, 4.5): {p1.comparar(p2)}')
p3 = Ponto2D(2.5, 2.5)
print(f'p1(2.5, 2.5) == p3(2.5, 2.5): {p1.comparar(p3)}\n')

print(f"Teste do metodo de calculo de distancia\nDistancia entre p1(2.5, 2.5) e p2(2.5, 4.5): {p1.distance(p2)}")
print(f"Distancia entre p1(2.5, 2.5) e p3(2.5, 2.5): {p1.distance(p3)}")
p4 = Ponto2D(-2.5, -2.5)
print(f"Distancia entre p1(2.5, 2.5) e p4(2.5, 2.5): {p1.distance(p4)}\n")

print("Teste de clonagem")
p5 = Ponto2D()
print(f"Declaracao de p5 sem parametro para a criacao: p5: {p5}")
p5 = p1.clonar()
print(f"p5 pos clonar o p1: p5 {p5}\n\n\n")
#fim dos testes do exercicio 2

#comeco dos testes do exercicio 3
print("Testes - Lista de Exercícios – Classes e Objetos - Exercicio 3\n")
c1 = Circulo(2)
print(f"Criacao e impressao de circulo\nCirculo c1 com 2 de raio e sem ponto2d: c1 = {c1}\n")
c2 = Circulo(4, p1)
print(f"Circulo c2 com 4 de raio e Ponto2D p1: c2 = {c2}\n")

print("Mestodos de inflar, desinflar, mover e area\n")

c1.inflar(10)
#ao tentar inflar ou desinflar com o numero negativo, o metodo apenas retorna
c1.inflar(-10)
print(f"Inflando o raio do c1 em 10\nc1: {c1}\n")

c1.desinflar(10)
c1.desinflar(-10)
print(f"Desinflando o raio do c1 em 10\nc1: {c1}\n")

c1.mover(p1)
print(f"Movendo o centro de c1 para as coordenadass de p1\nc1 pos mover: {c1}\n")

print(f"Area do c1: {c1.area()}\n\n\n")
#fim dos testes do exercicio 3
#comeco dos testes do exercicio 4
print("Testes - Lista de Exercícios – Classes e Objetos - Exercicio 4\n")
r1 = Retangulo(2, 4, p1)
r2 = Retangulo(10, 10, p4)
print(f"Criacao e impressao do Retangulo: r1 = {r1}\n")
print(f"Calculo da area de r1: {r1.area()}\n")
print(f"Teste de intersecao entre r1 e r2\nr1: {r1}\nr2: {r2}\nOs retangulos se sobrepoe: {r1.intersecao(r2)}\n")
r3 = Retangulo(4, 4, Ponto2D(-2, -2))
print(f"Teste de intersecao entre r1 e r3\nr1: {r1}\nr3: {r3}\nOs retangulos se sobrepoe: {r1.intersecao(r3)}")
#fim dos testes do exercicio 4
