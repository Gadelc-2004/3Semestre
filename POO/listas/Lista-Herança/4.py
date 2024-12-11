class ContaBancaria:
    def __init__(self, nome:str = "0", saldo:float = 0):
        self.__nome = nome
        self.__saldo = saldo

    def __str__(self) -> str:
        return f"Titular da conta = {self.nome}\nSaldo: {self.saldo}"

    @property
    def nome(self) -> str:
        return self.__nome

    @property
    def saldo(self) -> float:
        return self.__saldo

    @nome.setter
    def nome(self, t:str):
        self.__nome = t
        
    @saldo.setter
    def saldo(self, s:float):
        if(s < 0):
            self.__saldo = 0
        else:
            self.__saldo = s
   
    def depositar(self, n:float):
        self.saldo += abs(n)

    def sacar(self, n:float) -> int:
        if(abs(n) < self.saldo):
            self.saldo -= n

    def exibir_saldo(self):
        print(self.saldo)

class ContaCorrente(ContaBancaria):
    def __init__(self, nome:str, saldo:float, limite:float):
        super().__init__(nome, saldo)
        self.__limite = limite

    @property
    def limite(self) -> float:
        return self.__limite

    @limite.setter
    def limite(self, l):
        self.__limite = abs(l)

    def sacar(self, saque):
        if(abs(saque) < self.limite) and (!((saldo - abs(saldo)) - saldo - self.limite)):
            self.saldo -= n

    def exibir_saldo(self):
        print(f"Saldo: {self.saldo}\tLimite: {self.limite}")

class ContaPolpanca(ContaBancaria):
    def __init__(self, nome:str, saldo:float, taxa:float):
        super().__init__(nome, saldo)
        self.__taxa = taxa

    @property
    def taxa(self) -> float:
        return self.__taxa

    @taxa.setter
    def taxa(self, t):
        self.__taxa = abs(t)

    def aplicar_juros(self):
        self.saldo += (self.saldo * (self.taxa / 100))

c0 = ContaBancaria("Andre", 1000)
print(c0)
print(f"Exibir saldo da bancaria: ")
c0.exibir_saldo()

c1 = ContaCorrente("Gabriel", 1200, 200)
print(c1)
print(f"Exibir saldo da corrente: ")
c1.exibir_saldo()
c2 = ContaPolpanca("Ester", 2000, 2.3)
print(c2)
c2.aplicar_juros()
print(c2)
c2.exibir_saldo()
