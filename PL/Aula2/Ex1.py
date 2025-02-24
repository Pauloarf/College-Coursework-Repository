line1 = "hello world"
line2 = "goodbye world"
line3 = "hi, hello there"

import re

print("1. Linhas que contêm a palavra: hello no início (à esquerda)")
pattern = r"^hello"
res1 = re.search(pattern, line1)
res2 = re.search(pattern, line2)
res3 = re.search(pattern, line3)
print(f"{line1} -> {res1}")
print(f"{line2} -> {res2}")
print(f"{line3} -> {res3}")

print("\n2. Linhas que contêm a palavra: hello")
pattern = r"hello"
res1 = re.search(pattern, line1)
res2 = re.search(pattern, line2)
res3 = re.search(pattern, line3)
print(f"{line1} -> {res1}")
print(f"{line2} -> {res2}")
print(f"{line3} -> {res3}")

line = "Hello there! Uh, hi, hello, it's me... Heyyy, hello? HELLO!"
print("\n3. Todas as ocorrencias da palavra 'hello'")
pattern = r"hello"
res = re.findall(pattern, line, re.I)
print(res)


line = "Hello there! Uh, hi, hello, it's me... Heyyy, hello? HELLO!"
print("\n4. Substituir todas as ocorrencias da palavra 'hello' por 'YEP'")
pattern = r"hello"
res = re.sub(pattern, "YEP", line)
print(res)

line = "bananas, laranjas, maçãs, uvas, melancias, cerejas, kiwis, etc."
print("\n5. Pesquisa por todas as ocorrências do caracter vírgula, separando cada parte da linha por esse caracter.")
pattern = r","
res = re.split(pattern, line)
print(res)