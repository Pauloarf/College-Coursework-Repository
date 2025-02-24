import re

def underscores(frase):
    res = re.sub(r"\s+","_", frase)
    return res

print(underscores("Aqui temos   um belo  exemplo   de frase!"))