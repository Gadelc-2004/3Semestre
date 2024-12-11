def is_sorted(vet):
    vet = list(vet)
    #for i in range(1, (len(vet) - 1)):
     #   if(vet[i] < vet[i - 1]):
      #      return False
    x = sorted(vet)
    #print("Lista original: ", vet)
    #print("Lista ordenada: ", x)
    if(vet == x):
        return True
    else:
        return False

x = {1, 2, 2, 3}
y = {'b', 'a', 'c', 'd'}

print(is_sorted(x))
print(is_sorted(y))
