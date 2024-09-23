module Ficha2 where

import Data.Char
import Data.List

-- Pergunta 1 (a)
-- Qual o valor de funA [2,3,5,1]
funA :: [Double] -> Double
funA [] = 0
funA (y:ys) = y^2 + (funA ys)
{-
funA [2,3,5,1] = 2^2 + (3^2 + (5^2 + (1^2)))
-}

-- Pergunta 1 (b)
-- Qual o valor de funB [8,5,12]
funB :: [Int] -> [Int]
funB [] = []
funB (h:t) = if (mod h 2)==0 then h : (funB t)
                             else (funB t)
{-
funB [8,5,12] <=> mod 8 2 == 0 , 8 : funB [5,12]
              <=> mod 5 2 /= 0 , 8 : funB [12]
              <=> mod 12 2 == 0, 8 : 12 : funB []
              <=> funB [] = [], 8 : 12 : [] = [8,12]
-}

-- Pergunta 1 (c)
-- Qual o valor de funC [1,2,3,4,5]
funC (x:y:t) = funC t
funC [x] = [x]
funC [] = []
{-
funC [1,2,3,4,5] = funC [3,4,5] =
                 = funC 5 =
                 = [5]
-}

-- Pergunta 1 (d)
-- Qual o valor de funD "otrec"
funD l = g [] l
g acc [] = acc
g acc (h:t) = g (h:acc) t
{-
funD "otrec" = funD ['o','t','r','e','c'] = 
             = g [] "otrec"
             = g ('o' : []) "trec"
             = g ('t' : "o") "rec"
             = g ('r' : "to") "ec"
             = g ('e' : "rto") "c"
             = g ('c' : "erto") []
             = "certo"
-}

-- Pergunta 2 (a)
-- recebe uma lista e produz a lista em que cada elemento é o dobro do valor correspondente na lista de entrada.
dobros :: [Float] -> [Float]
dobros [] = []
dobros (h:t) = 2*h : dobros t

-- Pergunta 2 (b)
-- calcula o número de vezes que um carater ocorre numa String.
numOcorre :: Char -> String -> Int
numOcorre _ [] = 0
numOcorre c (h:t) 
    | c == h = 1 + numOcorre c t
    | otherwise = numOcorre c t

-- Pergunta 2 (c)
-- testa se uma lista só tem elementos positivos
positivos :: [Int] -> Bool
positivos [] = error "No elements on the list"
positivos [x] = if x < 0 then False else True
positivos (h:t)
    | h >= 0 = positivos t
    | otherwise = False

-- Pergunta 2 (d)
-- retira todos os elementos não positivos de uma lista de inteiros.
soPos :: [Int] -> [Int]
soPos [] = []
soPos (h:hs) | h >= 0 = h : soPos hs
             | otherwise = soPos hs

-- Pergunta 2 (e)
-- soma todos os números negativos da lista de entrada.
somaNeg :: [Int] -> Int
somaNeg [] = 0
somaNeg (h:hs) | h < 0 = h + somaNeg hs
               | otherwise = somaNeg hs

-- Pergunta 2 (f)
-- devolve os últimos três elementos de uma lista. Se a lista de entrada tiver menos de três elementos, devolve a própria lista.
tresUlt :: [a] -> [a]
tresUlt [] = []
tresUlt l@(x : []) = l
tresUlt l@(x : y : []) = l
tresUlt l@(x : y : z : []) = l
tresUlt (h:xs) = tresUlt xs

tresUlt2 :: [a] -> [a]
tresUlt2 [] = []
tresUlt2 l = case l of (_:a:b:c:xs) -> tresUlt2 (a:b:c:xs)
                       _ -> l

-- Pergunta 2 (g)
-- calcula a lista das segundas componentes dos pares.
segundos :: [(a,b)] -> [b]
segundos [] = []
segundos ((a,b):t) = b : segundos t

segundos2 :: [(a,b)] -> [b]
segundos2 [] = []
segundos2 (h:t) = (snd h) : segundos2 t

-- Pergunta 2 (h)
-- testa se um elemento aparece na lista como primeira componente de algum dos pares.
nosPrimeiros :: (Eq a) => a -> [(a,b)] -> Bool
nosPrimeiros _ [] = False
nosPrimeiros x ((a,b):t) | x == a = True
                         | otherwise = nosPrimeiros x t

nosPrimeiros2 :: (Eq a) => a -> [(a,b)] -> Bool
nosPrimeiros2 x [(a,_)] = x == a
nosPrimeiros2 x (h:t) = x == fst h || nosPrimeiros x t

-- Pergunta 2 (i)
-- soma uma lista de triplos componente a componente.
sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)
sumTriplos [] = error "Not enough elements on the list"
sumTriplos [x] = x
sumTriplos ((a,b,c):t) = (a + sumA,b + sumB,c + sumC)
                       where (sumA, sumB, sumC) = sumTriplos t

-- Pergunta 3 (a)
-- recebe uma lista de caracteres, e seleciona dessa lista os caracteres que são algarismos.
soDigitos :: [Char] -> [Char]
soDigitos [] = []
soDigitos (h:t) = if 47 <= ord h && ord h <= 57 then h : soDigitos t
                                                else soDigitos t

soDigitos2 :: [Char] -> [Char]
soDigitos2 [] = []
soDigitos2 (h:t) | isDigit h = h : soDigitos t
                | otherwise = soDigitos t


-- Pergunta 3 (b)
-- recebe uma lista de carateres, e conta quantos desses caracteres são letras minusculas.
minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (h:t) | 97 <= ord h && ord h <= 122 = 1 + minusculas t
                 | otherwise = minusculas t

minusculas2 :: [Char] -> Int
minusculas2 [] = 0
minusculas2 (c:str) = if isLower c then 1 + minusculas str
                                  else minusculas str

-- Pergunta 3 (c)
-- recebe uma String e devolve uma lista com os algarismos que ocorrem nessa linha pela mesma ordem.
nums :: String -> [Int]
nums [] = []
nums (h:t) | isDigit h = digitToInt h : nums t
           | otherwise = nums t

-- Pergunta 4
type Polinomio = [Monomio]
type Monomio = (Float,Int)

-- Pergunta 4 (a)
-- de forma a que (conta n p) indica quantos monómios de grau n existem em p.
conta :: Int -> Polinomio -> Int
conta _ [] = 0
conta n ((_,e):t) | n == e = 1 + conta n t
                  | otherwise = conta n t

-- Pergunta 4 (b)
-- indica o grau de um polinomio.
grau :: Polinomio -> Int
grau [(_,b)] = b
grau ((a,b):(a2,b2):t) | b > b2 = grau ((a,b):t)
                       | otherwise = grau ((a2,b2):t)

-- Perfunta 4 (c)
-- que seleciona os monómios com um dado grau de um polinómio.
selgrau :: Polinomio -> Int -> Polinomio
selgrau [] _ = []
selgrau (h:t) g | (snd h) == g = h : selgrau t g
                | otherwise = selgrau t g

-- Pergunta 4 (d)
-- que calcula a derivada de um polinomio.
deriv :: Polinomio -> Polinomio
deriv [] = []
deriv ((cof,exp):t) = if exp < 0 then ((cof * exp2),(exp - 1)) : deriv t else deriv t
                    where exp2 = fromIntegral exp

-- Pergunta 4 (e)
-- que calcula o valor de um polinómio para um dado valor de x.
calcula :: Float -> Polinomio -> Float
calcula x [] = 0
calcula x [(cof,exp)] = cof*(x^exp)
calcula x ((cof,exp):t) = cof*(x^exp) + calcula x t

-- Pergunta 4 (f)
-- retira de um polinómio os monómios de coeficiente 0.
simp :: Polinomio -> Polinomio
simp [] = []
simp (h:t) | (fst h) == 0 = simp t
           | otherwise = h : simp t 

-- Pergunta 4 (g)
-- que calcula o resultado da multiplicação de um monómio por um polinómio.
mult :: Monomio -> Polinomio -> Polinomio
mult _ [] = []
mult m@(cof,exp) (h:t) = ((cof * (fst h)),(exp + (snd h))) : mult m t

-- Pergunta 4 (h)
-- que dado um polinómio constrói um polinómio equivalente em que não podem aparecer vários monómios com o mesmo grau.
normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza [(c,e)] = [(c,e)]
normaliza ((c,e):(c2,e2):t) | e == e2 = normaliza ((c + c2, e2) : t)
                            | conta e t == 0 = (c,e) : normaliza ((c2,e2) : t)
                            | otherwise = normaliza ((c,e) : t ++ [(c2,e2)])

-- Pergunta 4 (i)
-- que faz a soma de dois polinomios de forma que se os polinomios que recebe estiverem normalizados produz também um polinómio normalizado.
soma :: Polinomio -> Polinomio -> Polinomio
soma p1 p2 = normaliza (p1 ++ p2) 
-- Esta versão é mais "Preguiçosa". Se quisermos respeitar a 100% o enunciado, podemos defini-la da seguinte forma:
soma2 :: Polinomio -> Polinomio -> Polinomio
soma2 [] p = p
soma2 p [] = p
soma2 ((b1,e1):p1) p2 = adiciona (b1,e1) (soma2 p1 p2)
                      where adiciona :: Monomio -> Polinomio -> Polinomio
                            adiciona p [] = [p]
                            adiciona (b,e) ((bp,ep):p) | e == ep = (b + bp, e) : p
                                                       | otherwise = (bp,ep) : adiciona (b,e) p

-- Pergunta 4 (j) 
-- que calcula o produto de dois polinomios.
produto :: Polinomio -> Polinomio -> Polinomio
produto [] _ = []
produto (p:p1) p2 = soma (mult p p2) (produto p1 p2)

-- Pergunta 4 (k)
-- ordena um polinomio por ordem crescente dos graus dos seus monomios.
ordena :: Polinomio -> Polinomio
ordena [] = []
ordena ((b,e):ps) = ordena (maisAltos ps) ++ [(b,e)] ++ ordena (maisBaixos ps)
                  where maisAltos [] = []
                        maisAltos ((bx,ex):xs) = if ex > e || (ex == e && bx >= b) then (bx,ex) : maisAltos xs else maisAltos xs
                        maisBaixos [] = []
                        maisBaixos ((bx,ex):xs) = if ex < e || (ex == e && bx < b) then (bx,ex) : maisBaixos xs else maisBaixos xs
-- A este metodo de ordenar listas chamamos "quick sort"

-- Pergunta 4 (l)
-- testa se dois polinomios são equivalentes.
equiv :: Polinomio -> Polinomio -> Bool
equiv p1 p2 = ordena (normaliza p1) == ordena (normaliza p2)
