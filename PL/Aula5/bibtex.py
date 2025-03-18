import ply.lex as lex

data = '''
@incollection {HDYE78,
author = "Ricardo Martini and Pedro Rangel Henriques and Giovani Libreloto",
title = "Storing Archival Emigration Documents to Create Virtual Exhibition Rooms",
booktitle = "New Contributions in Information Systems and Technologies",
series="Advances in Intelligent Systems and Computing",
editor="Rocha, Alvaro and Correia, Ana and Costanzo, S. and Reis, Luis Paulo",
volume="353",
pages="403-409",
year = "2015",
month =  "April"
}


@book {H787,
author = {Vitor T. Martins and Pedro Rangel Henriques and Daniela da Cruz},
title = {An AST-based tool, Spector, for Plagiarism Detection},
booktitle = {Proceedings of SLATE'15},
pages = {173--178},
ISBN = {},
year = {2015},
month =   {},
publisher = {Fundacion General UCM},
annote = {Keywords: software, plagiarism, detection, comparison, test}}

@book {H787,
author = {Vitor T. Martins and Pedro Rangel Henriques and Daniela da Cruz},
title = "{A}n {AST}-based tool, {S}pector, for Plagiarism Detection",
booktitle = {Proceedings of SLATE'15},
pages = {173--178},
ISBN = {},
year = {2015},
month =   {},
publisher = {Fundaci ́on General UCM},
annote = {Keywords: software, plagiarism, detection, comparison, test}
}
'''

# Define states
states = (
    ('book', 'exclusive'),
    ('incollection', 'exclusive')
)

# Define tokens
tokens = (
    'STATEWORD',
    'LBRACKET',
    'RBRACKET',
    'EQUALS',
    'COMMA',
    'IDENTIFIER',
    'KEY',
    'VALUE',
)

t_ANY_ignore = ' '

# Token rules for incollection state
def t_incollection_VALUE(t):
    r'".*"'
    return t

# Token rules for book state
def t_book_VALUE(t):
    r'".*"|{.*}'
    return t

# Token rules for both states
def t_ANY_KEY(t):
    r'^[\w]+'
    return t

def t_ANY_STATEWORD(t):
    r'@[\w]+'
    if t.value.lower() == "@incollection":
        t.lexer.begin('incollection')
    elif t.value.lower() == "@book":
        t.lexer.begin('book')
    return t

def t_ANY_LBRACKET(t):
    r"\{"
    return t

def t_ANY_RBRACKET(t):
    r"\}"
    return t

def t_ANY_EQUALS(t):
    r'='
    return t

def t_ANY_COMMA(t):
    r','
    return t

def t_ANY_IDENTIFIER(t):
    r'[\w]+'
    return t

def t_ANY_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_ANY_error(t):
    print(f"Carácter ilegal \"{t.value[0]}\"")
    t.lexer.skip(1)

# Build the lexer
lexer = lex.lex()

# Input data to the lexer
lexer.input(data)

# Tokenize
while tok := lexer.token():
    print(tok)