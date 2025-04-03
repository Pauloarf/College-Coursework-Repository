import ply.lex as lex
import re

data = """
CARNE :
  - 1 :: Bife :: 10.00 :: 1;
  - 2 :: Panado :: 5.00 :: 4;
  - 3 :: Hambúrguer :: 8.00 :: 3;
  - 4 :: Almôndegas :: 7.00 :: 5;

BEBIDA :
  - 5 :: Água :: 0.40 :: 16;
  - 6 :: Sumo :: 1.50 :: 9;
  - 7 :: Refrigerante :: 1.80 :: 10;

FRUTA :
  - 8 :: Maçã :: 0.60 :: 20;
  - 9 :: Banana :: 0.50 :: 15;
  - 10 :: Laranja :: 0.80 :: 18;
  - 11 :: Pêssego :: 0.70 :: 22;
  - 12 :: Uva :: 0.90 :: 17;

LEGUMES :
  - 13 :: Alface :: 1.00 :: 25;
  - 14 :: Tomate :: 0.75 :: 23;
  - 15 :: Cebola :: 0.50 :: 28;
  - 16 :: Batata :: 0.30 :: 30;
  - 17 :: Cenoura :: 0.40 :: 26;

PASTELARIA :
  - 18 :: Bolo de Chocolate :: 3.50 :: 1;
  - 19 :: Croissant :: 1.20 :: 14;
  - 20 :: Pastel de Nata :: 1.00 :: 5;
  - 21 :: Donut :: 0.80 :: 13;
  """

"""
TOKENS
- CATEGORIA
- IDENTIFICADOR
- PRODUTO
- PREÇO
- QUANTIDADE
- DELIMITADOR_CATEGORICO
- DELIMITADOR_VAR
- DELIMITADOR_PRODUTO
"""

# ANALISADOR LÉXICO
tokens = (
    'CATEGORIA',
    'IDENTIFICADOR',
    'PRODUTO',
    'PRECO',
    'QUANTIDADE',
    'DELIMITADOR_CATEGORICO',
    'DELIMITADOR_VAR',
    'DELIMITADOR_PRODUTO',
)

t_ignore = ' \t\n'

def t_CATEGORIA(t):
    '(CARNE)|(BEBIDA)|(FRUTA)|(LEGUMES)|(PASTELARIA)'
    return t

def t_IDENTIFICADOR(t):
    '\-\s(\d+)'
    t.value = int(t.value.strip()[2:])
    return t

def t_PRECO(t):
    '\d+\.\d{2}'
    return t

def t_QUANTIDADE(t):
    '\d+'
    return t

def t_DELIMITADOR_VAR(t):
    '::'
    return t

def t_DELIMITADOR_CATEGORICO(t):
    ':'
    return t


def t_DELIMITADOR_PRODUTO(t):
    ';'
    return t

def t_PRODUTO(t):
    '\w.*?::'
    return t

def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

lexer = lex.lex()

lexer.input(data)

while True:
    tok = lexer.token()
    if not tok:
        break
    print(tok)