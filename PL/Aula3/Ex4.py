import re

def troca_de_curso(linha, novo_curso):
    # USAMOS O r POR CONVENSÃO PARA O PYTHON NAO COMPILAR A STRING (OU ALGO ASSIM)
    nova_lista = re.sub(r"LEI", novo_curso, linha)
    return nova_lista

fonte = "LEI é o melhor curso! Adoro LEI! Gostar de LEI devia ser uma lei."
curso = input("Novo curso? ")
print(troca_de_curso(fonte, curso))