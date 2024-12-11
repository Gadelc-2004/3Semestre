import re
CONTA = r"^\d{3}\s\d{4}-[0-9a-zA-Z]\s\d{5,10}-[0-9a-zA-Z]$"
class ContaCorrente:
    def __init__(self, nconta:str = "0", titular:str = "N", saldo:float = 0, limite:float = 0):
        self.__nconta = nconta
        self.__titular = titular
        self.__saldo = saldo
        self.__limite = limite

    def __str__(self) -> str:
        if(self.nconta == "0"):
           return "Conta invalida"
        return f"Num da conta: {self.nconta}\nTitular da conta = {self.titular}\nSaldo: {self.saldo}\nLimite: {self.limite}"

    @property
    def nconta(self) -> str:
        return self.__nconta
    @property
    def titular(self) -> str:
        return self.__titular
    @property
    def saldo(self) -> float:
        return self.__saldo
    @property
    def limite(self) -> float:
        return self.__limite
    
    @nconta.setter
    def nconta(self, nc:str):
        if(re.match(nc, CONTA)):
            self.__nconta = "0"
        else:
            self.__nconta = nc

    @titular.setter
    def titular(self, t:str):
        self.__titular = t
        
    @saldo.setter
    def saldo(self, s:float):
        if(s < 0):
            self.__saldo = 0
        else:
            self.__saldo = s

    @limite.setter
    def limite(self, l:float):
        if(l < 0):
            self.__limite = 0
        else:
            self.__limite = l
    
    def depositar(self, n:float):
        self.saldo += abs(n)

    def sacar(self, n:float) -> int:
        if(abs(n) < self.saldo):
            self.saldo -= n
        else:
            return 0

    def transferir(self, conta:"ContaCorrente", x:float):
        if(self.sacar(x) == 0):
           return "Transicao invalida"
        conta.depositar(x)
        print(f"{x} transferido da conta: {self.nconta} para a conta: {conta.nconta}")

c1 = ContaCorrente(f"001 1234-5 67890-1", "Gabriel Almeida", 1900.99, 2000.99)
print(f"C1\n{c1}\n")

c2 = ContaCorrente()
print(c2)
c3 = ContaCorrente(f"023 4234-5 67890-1", "Ester Almeida", 2222.99, 4200.99)
print(f"C3\n{c3}\n")

c1.transferir(c3, 99)
print(f"C1\n{c1}\n")
print(f"C3\n{c3}\n")
print(c1.transferir(c3, 999999))
