import re

def soma_string(linha):
    linha = re.split(r',', linha)
    soma = 0
    for i in linha:
        soma += int(i)
    return soma

print(soma_string("4,10,-6,2,3,8,-3,0,2,-5,1"))
print(soma_string("4,5,-3"))