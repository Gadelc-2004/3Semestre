def pow_dict(x:int):
    new_dict = {}
    for i in range(1 , x + 1):
        new_dict[i] = i ** 2
    return new_dict

print(pow_dict(5))
