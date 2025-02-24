# Exemplo de teste
# 2025-02-20 by jcr 
from classe_afd import AutomatoFinitoDeterminista
import sys
import re

# Exemplo: Strings binárias com pelo menos um '1'
# Define estados, alfabeto, ftransicao, estado inicial, e conjunto de estados finais
estados = {'A', 'B', 'C'}
alfabeto = {'0', '1'}
ftransicao = {'A': {'0': 'B', '1': 'C'}, 'B': {'0': 'A', '1': 'C'}, 'C': {'0': 'C', '1': 'C'}}
estado_inicial = 'A'
estados_finais = {'C'}

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