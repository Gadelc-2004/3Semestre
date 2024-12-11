class Pais:
    def __init__(self, iso:str = 0, nome:str = 0, dimensao:float = 0, populacao:int = 0, fronteira:list = None):
        self.__iso = iso 
        self.__nome = nome
        self.__dimensao = dimensao
        self.__populacao = populacao
        self.__fronteira = fronteira if fronteira is not None else []

    def __str__(self):
        return (f"País: {self.nome} ({self.iso})\n"
                f"População: {self.populacao}\n"
                f"Dimensão: {self.dimensao} km²\n"
                f"Densidade populacional: {self.densidade():.2f} hab/km²\n"
                f"Fronteiras: {self.fronteira}")

    @property
    def iso(self) -> str:
        return self.__iso
    @property
    def nome(self) -> str:
        return self.__nome
    @property
    def populacao(self) -> int:
        return self.__populacao
    @property
    def dimensao(self) -> float:
        return self.__dimensao
    @property
    def fronteira(self) -> list:
        return self.__fronteira

    @iso.setter
    def iso(self, niso:str):
        if (len(niso) <= 3):
            self.__iso = niso
        else:
            self.__iso = None

    @nome.setter
    def nome(self, n:str):
        self.__nome = n

    @dimensao.setter
    def dimensao(self, nd:float):
        self.__dimensao = abs(nd)

    @populacao.setter
    def populacao(self, pop:int):
        self.__populacao = abs(pop)
    
    def exist(self, np:"pais") -> bool:
        return self.iso == np.iso

    def limitrofe(self, np:"Pais") -> int:
        if np in self.fronteira:
            return 1
        return 0

    def add_front(self, np:"Pais"):
        if np not in self.fronteira and np != self:
            self.fronteira.append(np.nome)

    def densidade(self) -> float:
        return (float(self.populacao) / float(self.dimensao))

    def vizinhos(self, np: "Pais") -> list:
        l = []
        for i in self.fronteira:
            if i in np.fronteira:
                l.append(i)
        return l


brasil = Pais("BRA", "Brasil", 8515767.049, 193946886)

argentina = Pais("ARG", "Argentina", 2780400.02, 44780677)

paraguai = Pais("PRY", "Paraguai", 406752.03, 7152703)

uruguai = Pais("URY", "Uruguai", 176215.40, 3518552)

brasil.add_front(argentina)
brasil.add_front(paraguai)


paraguai.add_front(brasil)
paraguai.add_front(argentina)

print(brasil.exist(paraguai))  
print(brasil.exist(brasil))  
print(brasil)
print(brasil.limitrofe(argentina))  
print(brasil.densidade()) 
print(brasil.vizinhos(paraguai)) 
