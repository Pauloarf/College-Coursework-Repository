module Ficha5 where

import Data.Char
import Data.List

-- Pergunta 1 a)
-- que testa se um predicado é verdade para algum elemento de uma lista.
any2 :: (a -> Bool) -> [a] -> Bool
any2 f [x] = f x
any2 f (x:xs) = f x || any2 f xs

-- Pergunta 2 b)
-- que combina os elementos de duas listas usando uma função específica.
zipWith2 :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith2 f [x] [y] = [(f x y)]
zipWith2 f (x:xs) (x1:xs1) = f x x1 : zipWith2 f xs xs1