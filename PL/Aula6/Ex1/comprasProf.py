import ply.lex as lex
import ply.yacc as yacc
import re
import json

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
    'NOMECAT',
    'TEXTO',
    'REAL',
    'NUMERO',
    'DOISPONTOS',
    'INICIOPROD',
    'SEP',
    'PONTOVIRG',
)

def t_REAL(t):
    r"\d+\.\d+"
    t.value = float(t.value)
    return t

def t_NUMERO(t):
    r"\d+"
    t.value = int(t.value)
    return t

def t_NOMECAT(t):
    r"[A-Z]{2,}"
    return t

def t_TEXTO(t):
    r"[\w\s]+"
    return t

t_DOISPONTOS = r"\:"
t_INICIOPROD = r"\-"
t_SEP = r"\:\:"
t_PONTOVIRG = r"\;"

t_ignore = " \n\t"

def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

lexer = lex.lex()

lexer.input(data)

# Gramática 
"""
S : categorias

categorias: categoria
          | categorias categoria

categoria : NOMECAT DOSIPONTOS produtos

produtos : produto
         | produtos produto

produto : INICIOPROD NUMERO SEP TEXTO SEP REAL SEP NUMERO PONTOVIRG 
"""

# Análisador Sintático

def p_categorias_categoria(p):
    'categorias : categoria'
    p[0] = p[1]
    
def p_categorias_categorias(p):
    'categorias : categorias categoria'
    p[0] = {
        "lista": p[1]["lista"] + p[2]["lista"],
        "total": p[1]["total"] + p[2]["total"]
	} 
    
def p_categoria(p):
	'categoria : NOMECAT DOISPONTOS produtos'
	p[0] = {
        "lista": list(map(lambda prod: prod | {"categoria" : p[1]}, p[3])),
        "total": sum(prod["preco"] * prod['quantidade'] for prod in p[3])
	}
    
def p_produtos(p):
    """produtos : produto
                | produtos produto"""
    if len(p) == 2:
        p[0] = [ p[1] ]
    else:
        p[0] = p[1] + [p[2]]

def p_produto(p):
    'produto : INICIOPROD NUMERO SEP TEXTO SEP REAL SEP NUMERO PONTOVIRG'
    p[0] = {
        "id": p[2], # É opcional, podemos ter o id com a sua posição na lista
        "nome": p[4],
        "preco": p[6],
        "quantidade" : p[8]
	}

def p_error(p):
    print("Syntax error in input!")

parser = yacc.yacc()

result = parser.parse(data)

print(json.dumps(result))