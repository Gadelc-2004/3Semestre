pessoa = {
    "ID": 120,
    "Idade": 22,
    "Nome": "Gabriel",
    "Sobrenome": "Almeida",
}

print(pessoa, "\n")

altura = float(input("Informe a altura: "))

pessoa["Altura"] = altura
print(pessoa)

pessoa["Endereco"] = {
                    "Rua": 'jose bonifacio',
                    'Numero': 2317,
                    'bairro': 'benfica',
}

print(pessoa)

#del pessoa['Endereco']
print(pessoa["Nome"], pessoa["Endereco"]["Rua"])
