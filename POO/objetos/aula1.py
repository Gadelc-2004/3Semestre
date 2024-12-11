class pessoa:
    def __init__(self, nome:str, sobrenome:str, ano_nasc:int):
        self.__nome = nome #privado
        self.__sobrenome = sobrenome #privado
        self.__ano = ano_nasc #privado

    def getAno(self):
        return self.__ano

    def setAno(self, novoValor:int):
        if (novoValor <= 2024) and (novoValor >= 1900):
            self.__ano = novoValor
        return

    def nome_completo(self) -> str:
        return self.__nome + " " + self.__sobrenome

    def idade(self) -> int:
        return 2024 - self.__ano

p1 = pessoa("Gabriel", "Almeida", 2004)

print("Nome: ", p1.nome_completo(), "Idade: ", p1.idade())

#print(p1.ano_nasc) #nao funciona pois esta privado

print(p1.getAno())
p1.setAno(3000)
print(p1.getAno())
