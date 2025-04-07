import ply.lex as lex

# Define um parser para uma linguagem de lógica simples que pode ter proposições, negações, conjunções, disjunções, implicações, equivalências e parênteses
data = """
P -> (Q & R) | ~S
"""

tokens = (
    'LETRA', 
    'NOT',
    'AND',
    'OR',
    'IMPL',
    'EQUIV',
    'LPAR',
    'RPAR'
)

t_ignore = ' \t\n'

def t_LETRA(t):
    "[A-Z]"
    return t

def t_NOT(t):
    "[~]"
    return t

def t_AND(t):
    "[&]"
    return t

def t_OR(t):
    "[|]"
    return t

def t_IMPL(t):
    "->"
    return t

def t_EQUIV(t):
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