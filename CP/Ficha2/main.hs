module Main where

import Cp  -- Import the Cp module

data X =
    B Bool | P (Bool,Int)

-- Exercicio 2
myand :: Bool -> Bool -> Bool
myand = (&&)

xor :: Bool -> Bool -> Bool
xor = (/=)

f :: ((Bool, Bool), Bool) -> Bool
f ((b1, b2), b3) = xor (myand b1 b2) b3


main :: IO ()
main = do
    print("---Exercise 2---")
    print(f((True, False), True))    -- True
    print(f((True, True), True))     -- False
    print(f((False, False), True))   -- True
    print(f((True, False), False))   -- False
    print("----------------")

