import random

def nested_sum(vet):
    x = 0
    for i in vet:
        for j in i:
             x += j
    return x

def randomizer(x, y):
    vet = []
    for i in range(x):
        x = []
        for j in range(y):
            x.append(random.randint(1, 10))
        vet.append(x)
    return vet

print("Lista de Exercícios Extra – Listas\nExercicio 1\n")

print("1 -> Determinar o numero maximo de elementos na lista\n2 -> Determinar numero maximo de elementos aleatoriamente\n0 -> Sair do programa")
choice = (input("Digite a opcao que voce deseja: "))
while(choice > '3') or (choice < '0'):
    choice = (input("Digite uma opcao valida: "))

if choice == '1':
    x = int(input("Digite o numero de listas que a lista principal deve ter: "))
    y = int(input("Digite o numero maximo de elementos que as sublistas devem ter: "))
    l = randomizer(x, y)

if choice == '2':
    l = randomizer(random.randint(2, 6), random.randint(1, 5))

print("\nLista de Listas:\nLista l")
for i in l:
    print("|->", i)

print("Soma das listas: ", nested_sum(l))
