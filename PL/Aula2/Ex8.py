import re

fonte = """
123 ddddd;
+345.77 gkmrm;
8766 yyyyy;
-1234 +3ddd4 -15
fim
"""

def extrai_inteiros(texto):
    pattern = r"[+-]?\d+"
    res = re.findall(pattern, texto)
    return res

print(extrai_inteiros(fonte))