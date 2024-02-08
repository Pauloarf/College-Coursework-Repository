module Ficha1 where

import Data.List
import Data.Char

-- 1 (a)
-- calcula o perímetro de uma circunferência, dado o comprimento do seu raio.
perimetro :: Double -> Double
perimetro x = 2 * x * pi

-- 1 (b)
-- calcula a distância entre dois pontos no plano Cartesiano. Cada ponto é um par de Valores do Tipo Double.
dist :: (Double,Double) -> (Double,Double) -> Double
dist (x1,y1) (x2,y2) = sqrt((x2 - x1)^2 + (y2 - y1)^2)
 
-- 1 (c)
-- recebe uma lista e devolve um par com o primeiro e o último elemento dessa lista.
primUlt :: [a] -> (a,a)
primUlt [] = error "No items in the list"
primUlt x = (head x, last x)    

-- 1 (d)
-- tal que multiplo m n testa se o número inteiro m é múltiplo de n.
multiplo :: Int -> Int -> Bool
multiplo x y = mod x y == 0

-- 1 (e)
-- recebe uma lista e, se o comprimento da lista for ímpar retira-lhe o primeiro elemento, caso contrário devolve a própria lista.
truncaImpar :: [a] -> [a]
truncaImpar [] = []
truncaImpar x
    | mod (length x) 2 == 0 = x
    | otherwise = tail x

truncaImpar2 :: [a] -> [a]
truncaImpar2 l = if even (length l) then l else tail l

-- 1 (f)
-- calcula o maior de dois números inteiros.
max2 :: Int -> Int -> Int
max2 x y 
    | x > y = x
    | otherwise = y

-- 1 (g)
-- calcula o maior de três números inteiros, usando a função max2.
max3 :: Int -> Int -> Int -> Int
max3 x y z
    | m > z = m
    | otherwise = z
    where m = max2 x y

max3fast :: Int -> Int -> Int -> Int
max3fast x y z = max2 (max2 x y) z

-- 2 (a)
-- recebe os (3) coeficientes de um polinómio de 2º grau e calcula o número de raízes (reais) de polinómio.
nRaizes :: Double -> Double -> Double -> Double
nRaizes a b c
    | b^2 - 4*a*c > 0 = 2
    | b^2 - 4*a*c == 0 = 1
    | otherwise = 0

-- 2 (b)
-- usando a função anterior, recebe os coeficientes do polinómio e calcula a lista das suas raízes reais.
raizes :: Double -> Double -> Double -> [Double]
raizes a b c
    | nRaizes a b c == 0 = []
    | nRaizes a b c == 1 = [(-b)/(2*a)]
    | otherwise = [((-b)-m)/(2*a),((-b)+m)/(2*a)]
    where m = sqrt (b^2 - 4*a*c)

type Hora = (Int,Int)

-- 3 (a)
-- testar se um par de inteiros representa uma hora do dia válida.
hourVerify :: Hora -> Bool
hourVerify (h,m)
    | h >= 0 && h <= 23 && m >= 0 && m <= 59 = True
    | otherwise = False

hourVerifyBetter :: Hora -> Bool
hourVerifyBetter (h,m) = elem h [0..23] && elem m [0..59]

-- 3 (b)
-- testar se uma hora é ou não depois da outra.
hourComp :: Hora -> Hora -> Bool
hourComp (h1,m1) (h2,m2)
    | h1 == h2 && m1 > m2 = True
    | h1 > h2 = True
    | otherwise = False

-- 3 (c)
-- converter um valor em horas (par de inteiros) para minutos (inteiro).
hourToMin :: Hora -> Int
hourToMin (h,m) = h * 60 + m

-- 3 (d)
-- converter um valor em minutos para horas.
minToHour :: Int -> Hora
minToHour m = (div m 60, mod m 60)

-- 3 (e)
-- calcular a diferença entre duas horas (o resultado deve ser em minutos).
hourMinusHour :: Hora -> Hora -> Int
hourMinusHour (h1,m1) (h2,m2)
    | hourComp (h1,m1) (h2,m2) == False = hourToMin (h2 - h1, m2 - m1)
    | otherwise = hourToMin (h1 - h2, m1 - m2)

-- 3 (f)
-- adicionar um determinado número de minutos a uma dada hora.
hourPlusMin :: Hora -> Int -> Hora
hourPlusMin h m = minToHour ((hourToMin h) + m)

data Horas = H Int Int deriving (Show, Eq)

-- 4 (a)
-- testar se um par de inteiros representa uma hora do dia válida.
hourVerify2 :: Horas -> Bool
hourVerify2 (H h m)
    | h >= 0 && h <= 23 && m >= 0 && m <= 59 = True
    | otherwise = False

-- 4 (b)
-- testar se uma hora é ou não depois da outra.
hourComp2 :: Horas -> Horas -> Bool
hourComp2 (H h1 m1) (H h2 m2)
    | h1 > h2 = True
    | h1 == h2 && m1 > m2 = True
    | otherwise = False

-- 4 (c)
-- converter um valor em horas (par de inteiros) para minutos (inteiro).
hourToMin2 :: Horas -> Int
hourToMin2 (H h m) = h * 60 + m

-- 4 (d)
-- converter um valor em minutos para horas.
minToHour2 :: Int -> Horas
minToHour2 m = H (div m 60) (mod m 60)

-- 4 (e)
-- calcular a diferença entre duas horas (o resultado deve ser em minutos).
hourMinusHour2 :: Horas -> Horas -> Int
hourMinusHour2 (H h1 m1) (H h2 m2)
    | hourComp2 (H h1 m1) (H h2 m2) == False = hourToMin2 (H (h2 - h1) (m2 - m1))
    | otherwise = hourToMin2 (H (h1 -h2) (m1 - m2))

-- 4 (f)
-- adicionar um determinado número de minutos a uma dada hora.
hourPlusMin2 :: Horas -> Int -> Horas
hourPlusMin2 (H h1 m1) m = minToHour2 (hourToMin2 (H h1 m1) + m)

data Semaforo = Verde | Amarelo | Vermelho deriving (Show, Eq)

-- 5 (a)
-- defina a função next :: Semaforo -> Semaforo que calcula o próximo estado de um semáforo.
next :: Semaforo -> Semaforo
next x = case x of Verde -> Amarelo
                   Amarelo -> Vermelho
                   Vermelho -> Verde

-- 5 (b)
-- determina se é obrigatório parar num semáforo.
stop :: Semaforo -> Bool
stop x = x == Vermelho

-- 5 (c)
-- Testa se o estado de dois semáforos num cruzamento é seguro.
safe :: Semaforo -> Semaforo -> Bool
safe s1 s2 = s1 == Vermelho || s2 == Vermelho

data Ponto = Cartesiano Double Double | Polar Double Double deriving (Show, Eq)

-- 6 (a)
-- Calcula a distância de um ponto ao eixo vertical.
posx :: Ponto -> Double
posx ponto = case ponto of Cartesiano x _ -> x
                           Polar d a -> if a == pi/2 then 0 else d * cos a
-- Utilizamos aqui um `if` porque `cos (pi/2)` não dá exatamente 0, devido à forma como os valores do tipo Double são armazenados no computador.

-- 6 (b)
-- Calcula a distância de um ponto ao eixo horizontal.
posy:: Ponto -> Double
posy ponto = case ponto of Cartesiano _ y -> y
                           Polar d a -> if a == pi then 0 else d * sin a

-- 6 (c)
-- calcula a distância de um ponto à origem.
raio :: Ponto -> Double
raio ponto = case ponto of Cartesiano x y -> sqrt (x^2 + y^2)
                           Polar d _ -> d

-- 6 (d)
-- cálcula o ângulo entre o vetor que liga a origem ao ponto e o eixo horizontal.
angulo :: Ponto -> Double
angulo ponto = case ponto of Polar _ a -> a
                             Cartesiano x y -> if x < 0 && y == 0 then pi else
                                               if x < 0 then pi + atan (y/x) else
                                               atan (y/x)

-- 6 (e)
-- cálcula a distância entre dois pontos.
distEntrePontos :: Ponto -> Ponto -> Double
distEntrePontos ponto1 ponto2 = sqrt ((posx ponto2 - posx ponto1)^2 + (posy ponto2 - posy ponto1)^2)

data Figura = Circulo Ponto Double
            | Rectangulo Ponto Ponto
            | Triangulo Ponto Ponto Ponto

-- 7 (a)
-- testa se uma figura é um poligno.
poligno :: Figura -> Bool
poligno (Circulo c r) = False
poligno (Rectangulo p1 p2) = posx p1 /= posx p2 && posy p1 /= posy p2
poligno (Triangulo p1 p2 p3) = (posy p2 - posy p1) / (posx p2 - posx p1) /= (posy p3 - posy p2) / (posx p3 - posx p2)

-- 7 (b)
-- calcula a lista dos vertices de uma figura.
vertices :: Figura -> [Ponto]
vertices (Circulo _ _) = []
vertices retang@(Rectangulo p1 p2) = if poligno retang then [p1, Cartesiano (posx p1) (posy p2), p2, Cartesiano (posy p2) (posx p1)] else []
vertices triang@(Triangulo p1 p2 p3) = if poligno triang then [p1,p2,p3] else []

-- 7 (c)
-- complete a seguinte definição.
{--
area :: Figura -> Double
area (Triangulo p1 p2 p3) =
    let a = distEntrePontos p1 p2
        b = distEntrePontos p2 p3
        c = distEntrePontos p3 p1
        s = (a+b+c) / 2 -- semi-perimetro
    in sqrt (s*(s-a)*(s-b)*(s-c)) -- formula de Heron
--}
area :: Figura -> Double
area (Triangulo p1 p2 p3) =
    let a = distEntrePontos p1 p2
        b = distEntrePontos p2 p3
        c = distEntrePontos p3 p1
        s = (a+b+c) / 2 -- semi-perimetro
    in sqrt (s*(s-a)*(s-b)*(s-c)) -- formula de Heron
area (Circulo _ r) = pi * (r^2)
area (Rectangulo p1 p2) = abs (posx p2 - posx p1) * abs (posy p2 - posy p1)

-- 7 (d)
-- que calcula o prerímetro de uma figura.
perimetro2 :: Figura -> Double
perimetro2 x = case x of Circulo p1 r -> 2 * pi * r
                         Rectangulo p1 p2 -> 2 * abs (posx p2 - posx p1) + 2 * abs (posy p2 - posy p1)
                         Triangulo p1 p2 p3 -> distEntrePontos p1 p2 + distEntrePontos p2 p3 + distEntrePontos p3 p1

-- 8 (a)
-- testa se um Char é uma minúscula.
isLower2 :: Char -> Bool
isLower2 ch = ord ch >= ord 'a' && ord ch <= ord 'z'
-- ou --
isLower3 :: Char -> Bool
isLower3 ch = elem ch ['a'..'z']

-- 8 (b)
-- testa se um Char é um digito.
isDigit2 :: Char -> Bool
isDigit2 ch = ord ch >= ord '0' && ord ch <= ord '9'

-- 8 (c)
-- testa se um Char é uma letra.
isAlpha2 ::  Char -> Bool
isAlpha2 ch = isLower2 ch || isUpper2 ch
    where isUpper2 ch = ord ch >= ord 'A' && ord ch <= ord 'Z'

-- 8 (d)
-- converter uma letra para a respetiva maiúscula.
toUpper2 :: Char -> Char
toUpper2 ch = if isLower2 ch then chr (ord ch - 32) else ch

-- 8 (e)
-- que converte um número entre 0 e 9 para o respetivo dígito.
intToDigit2 :: Int -> Char
intToDigit2 n = chr (n + 48)

-- 8 (e)
-- que converte um dígito para o respetivo inteiro.
digitToInt2 :: Char -> Int
digitToInt2 ch = ord ch - 48
