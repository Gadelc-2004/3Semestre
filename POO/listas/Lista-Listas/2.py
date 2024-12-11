def cumsum(vet):
    l = []
    vet = list(vet)
    for i in range(1, len(vet) + 1):
        l.append(add(vet, i))
    return l

def add(vet, end:int):
    x = 0
    for i in range(end):
        x += vet[i]
    return x

l = {1, 2, 3, 4, 5}

print(l)

t = cumsum(l)

print(t)
