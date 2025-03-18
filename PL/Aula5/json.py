import ply.lex as lex

# Primeira coisa a fazer é identificar os tokens

# De seguida temos de identificar os tokes, para isso utilizamos regex
    # Dentro disto podemos definir um conjunto de carateres a ignorar
    # Precisaamos ainda definir o compportamento para o t_erro

tokens = (
    'LSQRBRACKET',
    'RSQRBRACKET',
    'LBRACKET',
    'RBRACKET',
    'BOOL',
    'WORD',
    'INT',
    'REAL',
    'SEPARATOR',
    'SEPARATOR2'
)

t_ignore = ' \t'

def t_LSQRBRACKET(t):
    r"\["
    return t

def t_RSQRBRACKET(t):
    r"\]"
    return t

def t_LBRACKET(t):
    r"\{"
    return t

def t_RBRACKET(t):
    r'\}'
    return t

def t_SEPARATOR(t):
    r':'
    return t

def t_SEPARATOR2(t):
    r','
    return t

def t_REAL(t):
    r'\d+\.\d+'
    return t

def t_INT(t):
    r'\d+'
    return t

def t_BOOL(t):
    r'true|false'
    return t

def t_WORD(t):
    r'"[\w: ]+"'
    t.value = lexer.lexmatch.group(0)
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_error(t):
    print(f"Carácter ilegal \"{t.value[0]}\"")
    t.lexer.skip(1)

lexer = lex.lex()

lexer.input(open("./json.json", "r").read())

while tok := lexer.token():
    print(tok)
