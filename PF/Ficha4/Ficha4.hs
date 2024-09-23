module Ficha4 where

import Data.Char
import Data.List

-- Pergunta 1
-- que dada uma string, devolve um par de strings: uma apenas com as letras presentes nessa string, e a outra apenas com os números presentes na string.
digitAlpha :: String -> (String,String)
digitAlpha [] = ([],[])
digitAlpha (x:xs)
    | isAlpha x = (x : letters, digits)
    | isDigit x = (letters, x : digits)
    | otherwise = (letters, digits)
    where (letters, digits) = digitAlpha xs

-- Pergunta 2
-- que, dada uma lista de inteiros, conta o número de valores negativos, o número de zeros e o número de valores positivos, devolvendo um triplo com essa informação.
nzp :: [Int] -> (Int,Int,Int)
nzp [] = (0,0,0)
nzp (x:xs) 
      | x < 0 = (n + 1,z,p)
      | x == 0 = (n,z + 1,p)
      | x > 0 = (n,z,p + 1)
      where (n,z,p) = nzp xs

-- Pergunta 3
-- que calcula simultaneamente a divisão e o resto da divisão inteira por subtrações sucessivas.
divMod2 :: Integral a => a -> a -> (a, a)
divMod2 x y 
    | x <= 0 = if y < 0 then divMod (-x) (-y) else (0, x)
    | y < 0 = let (q', r') = divMod x (-y) in (-q', r')
    | x >= y = (1 + q, 0)
    | otherwise = (q, x)
    where (q, r) = divMod (x - y) y

-- Pergunta 4
-- Utilizando uma função auxiliar com um acumulador, optimize a seguinte definição recursiva que determina qual o número que corresponde a uma lista de digitos.
fromDigits :: [Int] -> Int
fromDigits l = fromDigitsAux l 0

fromDigitsAux :: [Int] -> Int -> Int
fromDigitsAux [] acc = acc
fromDigitsAux (h:t) acc = fromDigitsAux t (h + 10 * acc)

-- Pergunta 5
-- Utilizando uma função auxiliar com acumuladores, otimize a seguinte definição que determina a soma do segmento inicial de uma lista com soma máxima.
maxSumInit :: (Num a, Ord a) => [a] -> a
maxSumInit (h:t) = maxSumInitAux t h h

maxSumInitAux :: (Num a, Ord a) => [a] -> a -> a -> a
maxSumInitAux [] _ x = x
maxSumInitAux (h:t) prevSum prevMax = maxSumInitAux t newSum (if newSum > prevMax then newSum else prevMax)
    where newSum = prevSum + h

-- Pergunta 6
-- Otimize a seguinte definição recursiva da função que calcula o n-ésimo número da sequência de Fibonacci, usando uma função auxiliar com 2 acumuladores que representam, respectivamente, o n-ésimo e o n+1-ésimo números dessa sequência.
fib :: Int -> Int
fib n = fibAux n 0 1

fibAux :: Int -> Int -> Int -> Int
fibAux 0 n _ = n
fibAux n fib_n fib_n_plus_1 = fibAux (n - 1) fib_n_plus_1 (fib_n + fib_n_plus_1)

-- Pergunta 7
-- que converte um inteiro numa string.
intToString :: Integer -> String
intToString x = show x

-- Pergunta 8 a)
-- [6,12,18]
-- [x | x <- [1..20], mod x 6 == 0]

-- Pergunta 8 b)
-- [6,12,18]
-- [x | x <- [1..20], mod x 6 == 0]

-- Pergunta 8 c)
-- [(10,20),(11,19),(12,18),(13,17),(14,16),(15,15),(16,14),(17,13),(18,12),(19,11),(20,10)]
-- [(x, 30 - x) | x <- [10..20]]

-- Pergunta 8 d)
-- [1,1,4,4,9,9,16,16,25,25]
-- [ x^2 | x <- [1..5], y <- [1..2]]

-- Pergunta 9 a)
-- [ 2^x | x <- [0..10]]

-- Pergunta 9 b)
--[(x,y) | x <- [1..5], y <- [1..5], x + y == 6]

-- Pergunta 9 c)
-- [[1..x] | x <- [1..5]]

-- Pergunta 9 d)
-- [replicate x 1 | x <- [1..5]]

-- Pergunta 9 e)
-- [ product [y | y <- [1..x]] | x <- [1..6]]

