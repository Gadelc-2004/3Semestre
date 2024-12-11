class Data:
    def __init__(self, dia:int, mes:int, ano:int):
        self.__mes = mes
        self.__ano = ano
        self.__dia = dia

    @property
    def dia(self) -> int:
        return self.__dia
    @property
    def mes(self) -> int:
        return self.__mes
    @property
    def ano(self) -> int:
        return self.__ano

    @dia.setter
    def dia(self, dia: int):
        if  (((dia < 1) or (dia > 31)) or
            (((self.mes == 2) and (((dia > 28) and (self.ano % 4 != 0)) or ((dia > 29) and (self.ano % 4 == 0)))) or 
            (((self.mes <= 7) and (((self.mes % 2) == 0) and (dia > 30))) or
            ((self.mes >= 8) and (((self.mes % 2) == 1) and (dia > 30)))))):
            self.__dia = 0
        else:
            self.__dia = dia

    @mes.setter
    def mes(self, mes:int):
        if((mes < 1) or (mes > 12)):
            self.__mes = 0
        else:
            self.__mes = mes
        return

    @ano.setter
    def ano(self, ano:int):
        if(ano < 1):
            self.__ano = 0
        else:
            self.__ano = ano
        return
    
    def __str__(self) -> str:
        if self.dia == 0 or self.mes == 0 or self.ano == 0:
            return "Data Invalida"
        else:
            return f"{self.dia}/{self.mes}/{self.ano}"

    def advance(self):
        if(self.dia <= 27):
            self.dia += 1
        if((self.mes == 2) and (((self.dia == 29) and (self.ano % 4 == 0)) or ((self.dia == 28) and ((self.ano % 4) != 0)))):
            self.dia = 1
            self.mes += 1
        if((self.mes == 12) and (self.dia == 31)):
            self.mes = 1
            self.dia = 1
            self.ano += 1
        if((self.mes <= 7) and ((((self.mes % 2) == 0) and (self.dia == 30)) or (((self.mes % 2) == 1) and (self.dia == 31)))): 
            self.mes += 1
            self.dia = 1
        if((self.mes <= 8) and ((((self.mes % 2) == 0) and (self.dia == 31)) or (((self.mes % 2) == 1) and (self.dia == 30)))):
            self.mes += 1
            self.dia = 1
        return

def testar_classe(d:Data):
    print(f"Data pre advance: {d}")
    d.advance()
    print(f"Data pos advance: {d}\n")
    return

print("Testes - Lista de Exercícios – Classes e Objetos - Exercicio 1\n")
datas = [
    Data(24, 3, 2004),
    Data(28, 2, 2005),
    Data(29, 2, 2024),
    Data(31, 12, 2005),
    Data(30, 4, 2023),
    Data(31, 8, 2023)
]

print("Caso ocorra a tentativa de criacao de uma data invalida(dia, mes, ano negativos e dia que nao condiz no mes respectivo),o campo errado sera preenchido com 0")
print("Na tentativa de imprimir uma data que tenha 0 em algum dos campos, sera imprimido Data Invalida\n")
print("Por exemplo, ao tentar criar a data 42/13/-29, o objeto sera preenchido com o nos campos invalidos")
dx = Data(42, 13, -29)
print(dx, "\n")

print("Testes de avanco de data: ")
for d in datas:
    testar_classe(d)
