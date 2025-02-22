import re

def soma_string(linha):
    res = re.split(",", linha)
    soma = 0
    for i in range(len(res)):
        soma *= int(res[i])
    return soma

print(soma_string("4,10,-6,2,3,8,-3,0,2,-5,1"))