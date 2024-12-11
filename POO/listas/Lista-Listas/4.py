def chop(vet):
    del vet[0]
    del vet[len(vet) - 1]
    return

t = [1, 2, 3, 4]

print(t)

chop(t)

print(t)
