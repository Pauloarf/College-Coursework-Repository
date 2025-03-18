import ply.lex as lex

# Primeira coisa a fazer é identificar os tokens

# De seguida temos de identificar os tokes, para isso utilizamos regex
    # Dentro disto podemos definir um conjunto de carateres a ignorar
    # Precisaamos ainda definir o compportamento para o t_erro

tokens = (
    # Aqui podiamos separar ainda mais e fazer numeros inteiros e numeros reais
    'NUM',
    'WORD',
    'BOOL',
    'RBRACKET',
    'LBRACKET'
)

t_ignore = ', \t'

def t_BOOL(t):
    r"True|False"
    return t

def t_WORD(t):
    r"\b[A-Za-z]+\b"
    return t

def t_NUM(t):
    r"\d+(\.\d+)?"
    return t

def t_LBRACKET(t):
    r"\["
    return t

def t_RBRACKET(t):
    r"\]"
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_error(t):
    print(f"Carácter ilegal \"{t.value[0]}\"")
    t.lexer.skip(1)

data = '''
[1,5, palavra, False ,3.14, 0, fim]
'''

lexer = lex.lex()

lexer.input(data)

while tok := lexer.token():
    print(tok)
