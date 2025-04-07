import ply.yacc as yacc
from lexerProf import tokens

"""
PROFESSORA
"""

def p_pred_and(p):
    "pred : pred AND pred"
    p[0] = p[1] and p[3]

def p_pred_or(p):
    "pred : pred OR pred"
    p[0] = p[1] or p[3]
    
def p_pred_not(p):
    "pred : NOT pred"
    p[0] =  not p[3]

def p_pred_impl(p):
    "pred : pred IMPL pred"
    p[0] = not p[1] or p[3]    

def p_pred_equiv(p):
    "pred : pred EQUIV pred"
    p[0] = p[1] == p[3]    

def p_pred_pars(p):
    "pred : LPAR pred RPAR"
    p[0] = p[2]   

def p_pred_letra(p):
    "pred : LETRA"
    p[0] = input(f'Valor lógico de {p[1]}: ').lower() in ["t", "v", "true", "verdade"]   

parser = yacc.yacc()

r = parser.parse(input("Introduz uma proposição lógica: "))
print(r)