import ply.lex as lex

# Primeira coisa a fazer é identificar os tokens

# De seguida temos de identificar os tokes, para isso utilizamos regex
    # Dentro disto podemos definir um conjunto de carateres a ignorar
    # Precisaamos ainda definir o compportamento para o t_erro

tokens = (
    'WORD',
    'COMMA',
    'MARK'
)

t_ignore = ' \t'

def t_WORD(t):
    r"\b\w+\b"
    return t

def t_COMMA(t):
    r","
    return t

def t_MARK(t):
    r"(\.\.\.)|[.!?]"
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_error(t):
    print(f"Carácter ilegal \"{t.value[0]}\"")
    t.lexer.skip(1)

data = '''
O João comeu a sopa. Aliás, comeu também o bife de... de pato!
'''

lexer = lex.lex()

lexer.input(data)

while tok := lexer.token():
    print(tok)
