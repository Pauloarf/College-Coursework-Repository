REALIZANDO O A* : f(n) = g(n) + h(n)
      -------- 1 --------
-> f(Alandroal) = 40 + 180 = 220 <-
   f(Arrailos) = 50 + 220 = 270
   f(Borba) = 15 + 250 = 265
      -------- 2 --------
-> f(Redondo) = 65 + 170 = 235 <-
   f(Arrailos) = 50 + 220 = 270
   f(Borba) = 15 + 250 = 265
      -------- 3 --------
-> f(Monsaraz) = 95 + 120 = 215 <-
   f(Arrailos) = 50 + 220 = 270
   f(Borba) = 15 + 250 = 265
      -------- 4 --------
-> f(Barreio) = 215 + 30 = 245 <-
   f(Arrailos) = 50 + 220 = 270
   f(Borba) = 15 + 250 = 265
      -------- 5 --------
-> f(Baixa da Banheira) = 220 + 33 = 253 <-
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
   f(Borba) = 15 + 250 = 265
      -------- 6 --------
-> f(Moita) = 227 + 35 = 262 <-
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
   f(Borba) = 15 + 250 = 265
      -------- 7 --------
   f(Alcochete) = 247 + 26 = 273
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
-> f(Borba) = 15 + 250 = 265 <-
      -------- 8 --------
   f(Alcochete) = 247 + 26 = 273
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
-> f(Estremoz) = 30 + 145 = 175 <-
      -------- 9 --------
   f(Alcochete) = 247 + 26 = 273
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
-> f(Evora) = 70 + 95 = 165 <-
      -------- 10 --------
   f(Alcochete) = 247 + 26 = 273
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
-> f(Montemor) = 90 + 70 = 160 <-
      -------- 11 --------
   f(Alcochete) = 247 + 26 = 273
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
-> f(Vendas Novas) = 105 + 45 = 150 <-
      -------- 12 --------
   f(Alcochete) = 247 + 26 = 273
   f(Palmela) = 240 + 85 = 325
   f(Arrailos) = 50 + 220 = 270
-> f(Lisboa) = 155 + 0 = 155 <-
      -------- x --------
CHEGAMOS A LISBOA
S = [Elvas, Borba, Estremoz, Evora, Montemor, Vendas Novas, Lisboa]
C = 155


REALIZANDO O Greedy : f(n) = h(n)
      -------- 1 --------
-> f(Alandroal) = 180 <-
 X f(Arrailos) = 220 X
 X f(Borba) = 250 X
      -------- 2 -------- (Os que não são escolhidos são esquecidos)
   f(Redondo) = 170 
      -------- 3 --------
   f(Monsaraz) = 120
      -------- 4 --------
   f(Barreiro) = 30
      -------- 5 --------
-> f(B. Banheira) = 32 <-
 X f(Palmela) = 85 X
      -------- 6 --------
   f(Moita) = 35
      -------- 7 --------
   f(Alcochete) = 25
      -------- 8 --------
   f(Lisboa) = 0
      -------- x --------
CHEGAMOS A LISBOA
S = [Elvas, Alandroal, Redondo, Monsaraz, Barreiro, Baixa da Banheira, Moita, Alcochete]
C = 267









