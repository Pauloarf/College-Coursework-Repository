# Exemplo de teste
# 2025-02-20 by jcr 
from classe_afd import AutomatoFinitoDeterminista
import sys
import re

# Exemplo: Números inteiros da forma '(+|\-)?\d+'
# Desenhar no quadro o AFND ==> AFD
# Define estados, alfabeto, ftransicao, estado inicial, e conjunto de estados finais
estados = ['0', '1', '2']
alfabeto = ['+', '-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
ftransicao = {'0': {'+': '1', '-': '1', '0': '2', '1': '2', '2': '2', '3': '2', '4': '2', '5': '2', '6': '2', '7': '2', '8': '2', '9': '2'}, 
              '1': {'0': '2', '1': '2', '2': '2', '3': '2', '4': '2', '5': '2', '6': '2', '7': '2', '8': '2', '9': '2'}, 
              '2': {'0': '2', '1': '2', '2': '2', '3': '2', '4': '2', '5': '2', '6': '2', '7': '2', '8': '2', '9': '2'}}
estado_inicial = '0'
estados_finais = {'2'}

# Cria a instância do AFD
afd = AutomatoFinitoDeterminista(estados, alfabeto, ftransicao, estado_inicial, estados_finais)

# Processa as sequências de input
for linha in sys.stdin:
    # Filtra os carateres brancos
    linha = re.sub(r'[ \t\n]', '', linha)
    res = afd.process_input(linha)
    print(f"Resultado para '{linha}': {res}")
    afd.debug()
    afd.reset()
    afd.debug()