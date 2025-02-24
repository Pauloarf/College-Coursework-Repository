import re

def narcissismo(linha):
    pattern = r"eu"
    res = re.findall(pattern, linha, re.I)
    return len(res)

print(narcissismo("Eu não sei se eu quero continuar a ser eu. Por outro lado, eu ser eu é uma parte importante de quem EU sou."))