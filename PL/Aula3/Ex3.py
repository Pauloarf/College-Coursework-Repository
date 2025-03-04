import re

texto = """Este texto foi feito por Sofia Guilherme Rodrigues dos Santos, com
base no texto original de Pedro Rafael Paiva Moura, com a ajuda
do professor Pedro Rangel Henriques e do professor José João Antunes Guimarães
Dias De Almeida.
Apesar de partilharem o mesmo apelido, a Sofia não é da mesma família do famoso
autor José Rodrigues dos Santos."""

m = re.search("([A-Z]\w+)(?:\s(?:[A-Z]\w+|d[eao]s?))+\s([A-Z]\w+)", texto)
print(m.groups())

print(re.sub("([A-Z]\w+)(?:\s(?:[A-Z]\w+|d[eao]s?))+\s([A-Z]\w+)", r"\2, \1", texto))
