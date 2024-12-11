import os

class conta_corrente:
    numero: int
    saldo : float

    def __init__(self, numero:int, saldo:float):
        self.numero = numero
        self.saldo = saldo

    def depositar(self):
        print("Saldo atual: ", self.saldo)
        a = float(input("Digite o valor a ser depositado: "))
        if a <= 0:
            a = float(input("Digite um valor valido  a ser depositado: "))

        self.saldo += a
        return

    def sacar(self):
        print("Saldo atual: ", self.saldo)
        a = float(input("Digite o valor a ser sacado: "))
        if a <= 0 or a > self.saldo:
            a = float(input("Digite um valor valido  a ser sacado: "))

        self.saldo -= a
        return

    def mostrar_saldo(self):
        print("Numero da conta: ", self.numero)
        print("Saldo diponivel: ", self.saldo)
        return

p1 = conta_corrente(1, 166.90)

choice = '1'
while(choice != '0'):
    os.system("clear")
    p1.mostrar_saldo
    print("1 -> Depositar dinheiro\n2 -> Sacar dinheiro\n0 -> Sair")
    choice = input("Digite a opcao que deseja: ")
    while (choice < '0') or (choice > '2'):
        choice = input("Digite a opcao que deseja: ")
    if choice == '1':
        p1.depositar()
    if choice == '2':
        p1.sacar()
    if choice == '0':
        break


p1.mostrar_saldo()
print(p1)
