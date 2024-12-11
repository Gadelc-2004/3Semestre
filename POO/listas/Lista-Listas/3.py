def middle(vet):
    l = []
    for i in range(1, len(vet) - 1):
        l.append(vet[i])
    return l

t = [1, 2, 5, 7, 3, 4]
print('t = ', t)

l = middle(t)

print('l = ', l)
