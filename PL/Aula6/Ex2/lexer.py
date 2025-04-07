import ply.lex as lex

# Define um parser para uma linguagem de lógica simples que pode ter proposições, negações, conjunções, disjunções, implicações, equivalências e parênteses
data = """
P -> (Q & R) | ~S
"""

tokens = (
    'PROPOSICAO', 
    'NEGACAO',
    'CONJUNCAO',
    'DISJUNCAO',
    'IMPLICACAO',
    'EQUIVALENCIA',
    'LPAR',
    'RPAR'
)

t_ignore = ' \t\n'

def t_PROPOSICAO(t):
    "[A-Z]"
    return t

def t_NEGACAO(t):
    "[~]"
    return t

def t_CONJUNCAO(t):
    "[&]"
    return t

def t_DISJUNCAO(t):
    "[|]"
    return t

def t_IMPLICACAO(t):
    "->"
    return t

def t_EQUIVALENCIA(t):
    "<->"
    return t

def t_LPAR(t):
    r'\('
    return t

def t_RPAR(t):
    r'\)'
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