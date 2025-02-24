import re

def toupper(lista):
    newList = []
    for word in lista:
        newList.append(word.upper())
    return newList

def pronomes(frase):
    pattern = r"eu|tu|ele|nós|vós|eles"
    res = re.findall(pattern, frase, re.I)
    return res

pslist = pronomes("Ola eu vou de certeza. Tu tu e ele, vêm? Eu não espero por vós. Eu estou com pressa, ele tem de vir!")
print(pslist)

print(set(pslist))
psset = set(toupper(pslist))
print(psset)
