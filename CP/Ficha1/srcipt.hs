---- Exercício 1
myLength:: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + mylength xs

myReverse:: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = reverse xs ++ [x]

---- Exercicio 2
take :: Int -> [a] -> [a]
take _ [] = []
take 0 _ = []
take n (x:xs) = x : take (n-1) xs
-- take m (take n x) = take (m `min` n) x

---- Exercicio 3
map:: (a -> b) -> [a] -> [b]
map _ [] = []
map f (x:xs) = f x : map f xs

filter:: (a -> bool) -> [æ] -> [a]
filter _ [] = []
filter f (x:xs)
    | f x = x : filter f xs
    | otherwise = filter f xs

uncurry:: (a -> b ->c) -> (a,b) -> c
uncurry f (x,y) = f x y

curry:: ((a,b) -> c) -> a -> b -> c
curry f x y = f (x,y)

flip:: (a -> b -> c) -> b -> a -> c
flip f x y = f y x