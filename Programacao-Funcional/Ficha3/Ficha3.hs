module Ficha3 where
    
data Hora = H Int Int deriving (Show, Eq, Ord)
type Etapa = (Hora,Hora)
type Viagem = [Etapa]

-- FUNÇÕES FICHA 1 --
-- testar se um par de inteiros representa uma hora do dia válida.
hourVerify2 :: Hora -> Bool
hourVerify2 (H h m)
    | h >= 0 && h <= 23 && m >= 0 && m <= 59 = True
    | otherwise = False

-- testar se uma hora é ou não depois da outra.
hourComp2 :: Hora -> Hora -> Bool
hourComp2 (H h1 m1) (H h2 m2)
    | h1 > h2 = True
    | h1 == h2 && m1 > m2 = True
    | otherwise = False

-- converter um valor em horas (par de inteiros) para minutos (inteiro).
hourToMin2 :: Hora -> Int
hourToMin2 (H h m) = h * 60 + m

-- converter um valor em minutos para horas.
minToHour2 :: Int -> Hora
minToHour2 m = H (div m 60) (mod m 60)

-- calcular a diferença entre duas horas (o resultado deve ser em minutos).
hourMinusHour2 :: Hora -> Hora -> Int
hourMinusHour2 (H h1 m1) (H h2 m2)
    | hourComp2 (H h1 m1) (H h2 m2) == False = hourToMin2 (H (h2 - h1) (m2 - m1))
    | otherwise = hourToMin2 (H (h1 -h2) (m1 - m2))

-- adicionar um determinado número de minutos a uma dada hora.
hourPlusMin2 :: Hora -> Int -> Hora
hourPlusMin2 (H h1 m1) m = minToHour2 (hourToMin2 (H h1 m1) + m)

-- Pergunta 1 (a)
-- Testar se uma Etapa está bem construida (o tempo de chegada é superior ao de partida e as horas são válidas).
etapaVerify :: Etapa -> Bool
etapaVerify (h1,h2) = hourComp2 h2 h1 && hourVerify2 h1 && hourVerify2 h2

-- Pergunta 1 (b)
-- Testa se uma viagem está bem construida (se para cada etapa, o tempo de chegada é superior ao de partida, e se a etapa seguinte começa depois da etapa anterior ter terminado).
viagemVerify :: Viagem -> Bool
viagemVerify [] = True
viagemVerify [h] = etapaVerify h
viagemVerify (h:t) = etapaVerify h && hourComp2 (fst (head t)) (snd h) && viagemVerify t 

-- Pergunta 1 (c)
-- Calcular a Hora de partida e de chegada de uma dada viagem.
tripStartEnd :: Viagem -> Etapa
tripStartEnd [] = error "No trip availble"
tripStartEnd [h] = h 
tripStartEnd (h:t) = (fst h, snd (last t))

-- Pergunta 1 (d)
-- Dada uma viagem válida, calcular o tempo total da viagem efetiva.
travelTime :: Viagem -> Int
travelTime [] = 0
travelTime (h:t) | etapaVerify h == True = etapaTime + travelTime t
                 | otherwise = error "not a valid trip"
                 where etapaTime = hourToMin2 (snd h) - hourToMin2 (fst h)

-- Pergunta 1 (e)
-- Calcular o tempo total de espera.
waitingTime :: Viagem -> Int
waitingTime [] = 0
waitingTime [(h,t)] = 0
waitingTime [h,t] = hourToMin2 (fst t) - hourToMin2 (snd h)
waitingTime l@(h:t) | viagemVerify l == True = waitTime + waitingTime t
                    | otherwise = error "not a valid trip"
                    where waitTime = hourToMin2 (fst (head t)) - hourToMin2 (snd h)

-- Pergunta 1 (f)
-- Calcular o tempo total da viagem.
tripTime :: Viagem -> Int
tripTime [] = 0
tripTime l = travelTime l + waitingTime l

-- Pergunta 2
type Poligonal = [Ponto]
data Ponto = Cartesiano Double Double | Polar Double Double deriving (Show, Eq)

-- Calcula a distância de um ponto ao eixo vertical.
posx :: Ponto -> Double
posx ponto = case ponto of Cartesiano x _ -> x
                           Polar d a -> if a == pi/2 then 0 else d * cos a
-- Utilizamos aqui um `if` porque `cos (pi/2)` não dá exatamente 0, devido à forma como os valores do tipo Double são armazenados no computador.

-- Calcula a distância de um ponto ao eixo horizontal.
posy:: Ponto -> Double
posy ponto = case ponto of Cartesiano _ y -> y
                           Polar d a -> if a == pi then 0 else d * sin a

-- calcula a distância de um ponto à origem.
raio :: Ponto -> Double
raio ponto = case ponto of Cartesiano x y -> sqrt (x^2 + y^2)
                           Polar d _ -> d

-- cálcula o ângulo entre o vetor que liga a origem ao ponto e o eixo horizontal.
angulo :: Ponto -> Double
angulo ponto = case ponto of Polar _ a -> a
                             Cartesiano x y -> if x < 0 && y == 0 then pi else
                                               if x < 0 then pi + atan (y/x) else
                                               atan (y/x)

-- cálcula a distância entre dois pontos.
distEntrePontos :: Ponto -> Ponto -> Double
distEntrePontos ponto1 ponto2 = sqrt ((posx ponto2 - posx ponto1)^2 + (posy ponto2 - posy ponto1)^2)

-- Pergunta 2 (a)
-- Defina a função para calcular o comprimento de uma linha poligonal.
compLinha :: Poligonal -> Double
compLinha [] = 0
compLinha [x] = 0
compLinha (h:t) = distEntrePontos h (head t) + compLinha t

-- Pergunta 2 (b)
-- Defina uma função para testar se uma dada linha poligonal é ou não fechada.
linhaFechada :: Poligonal -> Bool
linhaFechada [x] = False
linhaFechada l = length l >= 3 && head l == last l

-- Pergunta 2 (c)
-- dada uma linha poligonal fechada e convexa, calcule uma lista de triângulos cuja soma das areas seja igual à area delimitada pela linha poligonal.
-- O tipo figura é idéntico ao definido na Ficha1.


-- Pergunta 3
data Contacto = Casa Integer
                | Trab Integer
                | Tlm Integer
                | Email String
                deriving (Show)

type Nome = String
type Agenda = [(Nome,[Contacto])]

-- Pergunta 3 (b)
-- Defina a função  que, dado um nome e uma agenda, retorna a lista dos emails associados a esse nome. Se esse nome não existir na agenda a função deve retornar Nothing.
verEmails :: Nome -> Agenda -> Maybe [String]
verEmails _ [] = Nothing
verEmails n ((no,c):t) | n == no = Just (retiraEmail c)
                      | otherwise = verEmails n t

retiraEmail :: [Contacto] -> [String]
retiraEmail [] = []
retiraEmail (h:t) = case h of Email x -> x : retiraEmail t
                              _ -> retiraEmail t

-- Pergunta 3 (c)
-- que, dada uma lista de contactos, retorna a lista de todos os numeros de telefone dessa lista (tanto telefones fixos como telemoveis)
consTelefs :: [Contacto] -> [Integer]
consTelefs [] = []
consTelefs (h:t) = case h of Email x -> consTelefs t
                             Casa x -> x : consTelefs t
                             Trab x -> x : consTelefs t
                             Tlm x -> x : consTelefs t

-- Pergunta 3 (d)
-- que, dado um nome e uma agenda, retorna o numero de telefone de casa (caso exista).
casa :: Nome -> Agenda -> Maybe Integer
casa _ [] = Nothing
casa nome [(n,(c:t))] | nome == n = case c of Casa x -> Just x
                                              _ -> casa nome [(n,t)]
                      |otherwise = Nothing

casa nome ((n,c):t) | nome == n = casa nome [(n,c)]
                    | otherwise = casa nome t

-- Pergunta 4

type Dia = Int
type Mes = Int
type Ano = Int

data Data = D Dia Mes Ano
          deriving (Show)

type TabDN = [(Nome,Data)]

-- Pergunta 4 (a)
-- que indica a data de nascimento de uma dada pessoa, caso o seu nome exista na tabela.
procura :: Nome -> TabDN -> Maybe Data
procura _ [] = Nothing
procura nome ((n,d):t) = if nome == n then Just d else procura nome t 

-- Pergunta 4 (b)
-- que calcula a idade de uma pessoa numa dada Data
idade :: Data -> Nome -> TabDN -> Maybe Int
idade _ _ [] = Nothing
idade d nome ((n,d2):t) = if nome == n then idadeData d d2 else idade d nome t

idadeData :: Data -> Data -> Maybe Int
idadeData (D d m a) (D d2 m2 a2) | m > m2 = Just (a - a2)
                                 | m == m2 && d > d2 = Just (a - a2)
                                 | otherwise = Just (a - a2 - 1)

-- Pergunta 4 (c)
-- que testa se uma data é anterior a uma data.
anterior :: Data -> Data -> Bool
anterior (D d m a) (D d2 m2 a2) = d < d2 && m == m2 && a == a2 || m < m2 && a == a2 || a < a2

-- Pergunta 4 (d)
-- que ordena uma tabela de datas de nascimento, por ordem crescente das datas de nascimento.
ordena :: TabDN -> TabDN
ordena [] = []
ordena ((n,d):ts) = insere (n,d) (ordena ts)
    where insere (n,d) [] = [(n,d)]
          insere (n,d) ((nh,dh):t) | anterior dh d = (nh,dh):insere (n,d) t
                                   | otherwise = (n,d):(nh,dh):t

-- Pergunta 4 (e)
-- que apresenta o nome e a idade das pessoas, numa dada data, por ordem crescente da idade das pessoas.
porIdade :: Data -> TabDN -> [(Nome,Int)]
porIdade d [] = []
porIdade d tabela = (porIdade d t) ++ [(n, idadeData2 d d2)]
    where ((n,d2):t) = ordena tabela

idadeData2 :: Data -> Data -> Int
idadeData2 (D d m a) (D d2 m2 a2) | m > m2 = (a - a2)
                                  | m == m2 && d > d2 = (a - a2)
                                  | otherwise = (a - a2 - 1)

-- Pergunta 5

data Movimento = Credito Float | Debito Float
               deriving Show

data Extracto = Ext Float [(Data, String, Movimento)]
              deriving Show

-- Pergunta 5 (a)
-- produz uma lista de todos os movimentos (créditos ou débitos) superiores a um determinado valor.
extValor :: Extracto -> Float -> [Movimento]
extValor (Ext _ []) _ = [] 
extValor (Ext x ((_,_,mov):ls)) valor = case mov of Credito n -> if n >= valor then mov : extValor (Ext x ls) valor else extValor (Ext x ls) valor
                                                    Debito n -> if n >= valor then mov : extValor (Ext x ls) valor else extValor (Ext x ls) valor

-- Pergunta 5 (b)
-- que retorna informação relativa apenas aos movimentos cuja descrição esteja incluída na lista fornecida no segundo parâmetro.
filtro :: Extracto -> [String] -> [(Data,Movimento)]
filtro (Ext _ []) _ = []
filtro (Ext x ((dat,strout,mov):ls)) strinp = if strout `elem` strinp then (dat,mov) : filtro (Ext x ls) strinp else filtro (Ext x ls) strinp

-- Pergunta 5 (c)
-- retorna o total de créditos e de débitos de um extrato no primeiro e segundo elementos de um par, respetivamente.
creDeb :: Extracto -> (float,float)
creDeb (Ext _ lm) = foldl (\(c,d) (_,_,mov) -> case mov of Credito x -> (c + x, d)
                                                          Debito x -> (c, d + x)) (0,0) lm

-- Pergunta 5 (d)
-- que devolve o saldo final que resulta da execução de todos os movimentos no extracto sobre o saldo inicial.
saldo :: Extracto -> Float 
saldo (Ext x lm) = foldl (\acc (_,_,mov) -> case mov of Credito n -> acc + n
                                                        Debito n -> acc - n) x lm