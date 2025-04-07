import ply.yacc as yacc
from .lexer import tokens

"""
S : frase

frase :  frase operacao2 resultado  
      |  resultado

resultado : resultado operacao2 operacao1
          | operacao1 
      
operacao1 : NEGACAO PROPOSICAO
          | PROPOSICAO

operacao2 : EQUIVALENCIA 
          | IMPLICACAO 
          | CONJUNCAO 
          | DISJUNCAO 
"""


