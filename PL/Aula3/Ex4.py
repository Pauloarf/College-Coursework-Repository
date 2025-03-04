import re

lista = [
    "4700-000", # válido
    "9876543", # inválido
    "1234-567", # válido
    "8x41-5a3", # inválido
    "84234-12", # inválido
    "4583--321", # inválido
    "9481-025" # válido
]


def codigos_postais(lista):
    resultado = []

    for codigo_postal in lista:
        m = re.match(r"(\d{4})-(\d{3})$", codigo_postal)
        if m:
            resultado.append(m.groups())

    return resultado

print(codigos_postais(lista))