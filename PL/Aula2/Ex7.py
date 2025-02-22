import re

def variavel_valida(var):
    pattern = r"^\w+$"
    res = re.search(pattern, var)
    return res

print(variavel_valida("aa11_aa aa"))
