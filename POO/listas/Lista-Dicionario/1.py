def uniao(vetx, vety):
    vetx = list(vetx)
    vety = list(vety)
    dicionario = dict(zip(vetx, vety))
    return dicionario

keys = ['Ten', 'Twenty', 'Thirty']
values = [10, 20, 30]

p = uniao(keys, values)

print(p)
