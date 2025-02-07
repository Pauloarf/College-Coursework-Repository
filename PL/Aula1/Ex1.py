def pot_recursiva(b: float, e: int) -> float:
    if e > 0:
      return b * pot_recursiva(b,e-1)  
    else:
      return 1

def pot_iterativa(b, e):
    if e == 0:
      b = 1
    for i in range (2, e+1):
      b *= b
    return b


base = input('Intruduza a base: ')
Einf = input('Introduza a variabel Einf: ')
Esup = input('Introduza a variabel Esup: ')

print('RECURSIVO: ')
res = ''
for i in range(int(Einf), int(Esup)+1):
   res += str(pot_recursiva(int(base), i)) + ';'
print(res)

print('Imperativo: ')
res = ''
for i in range(int(Einf), int(Esup)+1):
   res += str(pot_recursiva(int(base), i)) + ';'
print(res)