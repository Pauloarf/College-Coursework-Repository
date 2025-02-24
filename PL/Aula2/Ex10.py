import re

lista = [
    "4700-000",
    "1234-567",
    "8541-543",
    "4123-974",
    "9481-025",
    "9481-02512",
    "9481-025-123"
]

lista2 = "1100-3#1234-777#1198-999#4715-012"

def codigos(listaCPs):
    listaPares = []
    for codPostal in listaCPs:
        a = re.split(r'-',codPostal)
        if len(a)==2 and re.search(r'^\d{4}$',a[0]) and re.search(r'^\d{3}$',a[1]):
            listaPares.append(a)
    return listaPares


print(codigos(lista))
print(codigos(re.split(r'#',lista2)))

