def extratic(sdict, lista):
    new_dict = {}
    for i in sdict:
        print(i)
        if(i in lista):
            new_dict[i] = sdict[i]
    return new_dict

sample_dict = {
    "name": "Kelly",
    "age": 25,
    "salary": 8000,
    "city": "New York"}

keys = ["name", "salary"]

new_dic = extratic(sample_dict, keys)
print(new_dic)
