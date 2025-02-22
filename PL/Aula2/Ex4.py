import re

def troca_de_curso(linha, novo_curso):
  nova_linha = re.sub(r"LEI", novo_curso, linha)
  return nova_linha

fonte = "LEI é o melhor curso! Adoro LEI! Gostar de LEI devia ser uma lei."
curso = input("Novo curso? ")
print(troca_de_curso(fonte, curso))
