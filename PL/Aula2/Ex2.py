import re

def palavra_magica(frase):
    pattern = "(por favor[?!.])$"
    res = re.search(pattern, frase)
    return res

print(palavra_magica("Posso ir à casa de banho, por favor?"))
print(palavra_magica("Preciso de um favor."))