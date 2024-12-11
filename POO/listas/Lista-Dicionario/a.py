def convertion(l1:list, l2:list):
    dict = {} 
    for i in range(len(l1)):
        dict[l1[i]] = l2[i]
    return dict

keys = ['Ten', 'Twenty', 'Thirty']
values = [10, 20, 30]

d = convertion(keys, values)
print(d)
