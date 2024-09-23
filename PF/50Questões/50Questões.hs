module FiftyQ where

import Data.List

-- Pergunta 1
-- constrói a lista dos números inteiros compreendidos entre dois limites.
enumFromTo2 :: Int -> Int -> [Int]
enumFromTo2 x y
    | x > y = []
    | otherwise = x : enumFromTo2 (x+1) y

-- Pergunta 2
-- constrói a lista dos números inteiros compreendidos entre dois limites e espaçados de um valor constante.
enumFromThenTo2 :: Int -> Int -> Int -> [Int]
enumFromThenTo2 start next end
    | start > end && next > start || start > end && start == next || start < end && next < start = []
    | otherwise = start : enumFromThenTo2 next (2 * next - start) end

-- Pergunta 3
-- função recursiva que concatena duas listas.
(+++) :: [a] -> [a] -> [a]
(+++) [] y = y
(+++) (x1:t) y = x1 : (+++) t y

-- Pergunta 4
-- dada uma lista e um inteiro, calcula o elemento da lista que se encontra nessa posição (assume-se que o primeiro elemento está na posição 0).
(!!!) :: [a] -> Int -> a
(!!!) [] n = error "A lista não possui tantos elementos"
(!!!) (x1:t) n
    | n == 0 = x1
    | otherwise = (!!!) t (n-1)

-- Pergunta 5
-- dada uma lista calcula uma lista com os elementos dessa lista pela ordem inversa.
reverse2 :: [a] -> [a]
reverse2 [] = []
reverse2 (h:t) = (++) (reverse2 t) [h]

-- Pergunta 6
-- dado um inteiro n e uma lista l calcula a lista com os (no máximo) n primeiros elementos de l.
take2 :: Int -> [a] -> [a]
take2 _ [] = []
take2 n (h:t)
    | n <= 0 = [] 
    | otherwise = h : take2 (n-1) t

-- Pergunta 7
-- dado um inteiro n e uma lista l calcula a lista sem os (no máximo) n primeiros elementos de l.
drop2 :: Int -> [a] -> [a]
drop2 _ [] = []
drop2 n (h:t)
    |  n <= 0 = (h:t)
    | otherwise = drop2 (n-1) t

-- Pergunta 8
-- contrói uma lista de pares a partir de duas listas.
zip2 :: [a] -> [b] -> [(a,b)]
zip2 _ [] = []
zip2 [] _ = []
zip2 (h:t) (h1:t1) = (h,h1) : zip2 t t1

-- Pergunta 9
-- dado um inteiro n e um elemento x constrói uma lista com n elementos, todos iguais a x
replicate2 :: Int -> a -> [a]
replicate2 0 _ = []
replicate2 n x
    | n < 0 = []
    | otherwise = x : replicate2 (n-1) x

-- Pergunta 10
-- dado um elemento e uma lista, constrói uma lista em que o elemento fornecido é intercalado entre os elementos da lista fornecida
intersperse2 :: a -> [a] -> [a]
intersperse2 _ [] = []
intersperse2 _ [a] = [a]
intersperse2 x (h:t) = h : x : intersperse2 x t

-- Pergunta 11
-- agrupa membros iguais e consecutivos de uma lista
group2 :: Eq a => [a] -> [[a]]
group2 [] = []
group2 [x] = [[x]]
group2 (h:t)
    | elem h (head r) = (h : (head r)) : tail r
    | otherwise = [h] : r
    where r = group2 t

group3 :: Eq a => [a] -> [[a]]
group3 [] = []
group3 [x] = [[x]]
group3 (h:t) = (h : takeWhile (==h) t) : group (dropWhile (==h) t)

-- Pergunta 12
-- que concatena a lista dos sufixos de uma lista.
concat2 :: [[a]] -> [a]
concat2 [] = []
concat2 [[x]] = [x]
concat2 (h:t) = h ++ concat t

-- Pergunta 13
-- que calcula a lista dos prefixos de uma lista
inits2 :: [a] -> [[a]]
intis2 [] = []
inits2 (l:ls) = inits2 ls ++ [(l:ls)]

-- Pergunta 14
-- que calcula a lista dos sufixos de uma lista.
tails2 :: [a] -> [[a]]
tails2 [] = []
tails2 (l:ls) = [(l:ls)] ++ tails2 ls

-- Pergunta 15
-- que recebe uma lista de listas e produz a lista com o primeiro elemento de cada lista.
heads2 :: [[a]] -> [a]
heads2 [] = []
heads2 ([]:t) = heads2 t
heads2 (h:t) = (head h) : (heads2 t)

-- Pergunta 16
-- que recebe uma lista de listas e conta o total de elementos (de todas as listas).
total :: [[a]] -> Int
total [] = 0
total ([]:t) = total t
total (h:t) = (length h) + total t

-- Pergunta 17
-- que recebe uma lista de triplos e produz a lista de pares com o primeiro e o terceiro elemento de cada triplo
fun :: [(a,b,c)] -> [(a,c)]
fun [] = []
fun [(a,b,c)] = [(a,c)]
fun ((a,b,c):l) = (a,c) : (fun l)

-- Pergunta 18
-- que recebe uma lista de triplos e concatena as strings que estão na primeira componente dos triplos.
cola :: [(String,b,c)] -> String
cola [] = []
cola ((s,_,_) : t) = s ++ (cola t)

-- Pergunta 19
-- que recebe o ano, a idade e uma lista de pares com o nome e o ano de nascimento de cada pessoa, e devolve a lista de nomes das pessoas que nesse ano atingirão ou já ultrapassaram a idade indicada.
idade :: Int -> Int -> [(String,Int)] -> [String]
idade _ _ [] = []
idade a i (h:t) | a - (snd h) >= i = (fst h) : (idade a i t)
                | otherwise = idade a i t
                
-- Pergunta 20
-- dado um valor n e um valor m constrói a lista [n^0,...,n^m-1].
powerEnumFrom2 :: Int -> Int -> [Int]
powerEnumFrom2 x 0 = []
powerEnumFrom2 x y = (powerEnumFrom2 x (y-1)) ++ [x^(y-1)]

-- Pergunta 21
-- que dado um número inteiro maior ou igual a 2 determina se esse numero é primo. Para determinar se um número n não é primo, descubra se existe algum numero inteiro m tal que 2 <= m <= sqrt n e mod n m = 0.
isPrime :: Int -> Bool
isPrime x | x >= 2 = primeCheck x 2
          | otherwise = False

primeCheck :: Int -> Int -> Bool
primeCheck n m | m * m > n = True
               | mod n m == 0 = False
               | otherwise = primeCheck n (m + 1)

-- Pergunta 22
-- que testa se uma lista é prefixo de outra.
isPrefixOf2 :: Eq a => [a] -> [a] -> Bool 
isPrefixOf2 [] [] = True
isPrefixOf2 [x] y = if x == (head y) then True else False 
isPrefixOf2 (h:t) (h2:t2) | h == h2 = isPrefixOf t t2
                          | otherwise = False

-- Pergunta 23
-- que testa se uma lista é sufixo de outra.
isSuffixOf2 :: Eq a => [a] -> [a] -> Bool
isSuffixOf2 [] _ = True
isSuffixOf2 l1 l2 | (last l1) == (last l2) = isSuffixOf2 (tail l1) (tail l2)
                  | otherwise = False

-- Pergunta 24 
-- que testa se os elementos de uma lista ocorrem noutra pela mesma ordem relativa.
isSubsequenceOf2 :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf2 [] [] = True
isSubsequenceOf2 _ [] = False
isSubsequenceOf2 [] _ = True
isSubsequenceOf2 (h:t) (h2:t2) | h == h2 = isSubsequenceOf2 t t2
                               | otherwise = isSubsequenceOf2 (h:t) t2

-- Pergunta 25
-- que calcula a lista de posições em que um dado elemento ocorre numa lista.
elemIndices2 :: Eq a => a -> [a] -> [Int]
elemIndices2 _ [] = []
elemIndices2 x l = elemIndicesAux x l 0

elemIndicesAux :: Eq a => a -> [a] -> Int -> [Int]
elemIndicesAux _ [] _ = []
elemIndicesAux x (h:t) i | x == h = i : elemIndicesAux x t (i+1)
                         | otherwise = elemIndicesAux x t (i+1)

-- Pergunta 26
-- que calcula uma lista com os mesmos elementos da recebida, sem repetições.
nub2 :: Eq a => [a] -> [a]
nub2 [] = []
nub2 (h:t) | elem h t = nub2 t
           | otherwise = h : (nub2 t) 

-- Pergunta 27
-- que retorna a lista resultante de remover (a primeira ocorrência) de um dado elemento da lista.
delete2 :: Eq a => a -> [a] -> [a]
delete2 _ [] = []
delete2 x (h:t) | x == h = t
                | otherwise = h : delete2 x t

-- Pergunta 28
-- que retorna a lista resoltante de remover (as primeiras ocorrências) dos elementos da segunda lista da primeira.
(\\\) :: Eq a => [a] -> [a] -> [a]
(\\\) [] _ = []
(\\\) l [] = l
(\\\) (h:t) (h2:t2) = (\\\) (delete2 h2 (h:t)) t2

-- Pergunta 29
-- que retorna a lista resultante de acrescentar à primeira lista os elementos da segunda que não ocorrem na primeira.
union2 :: Eq a => [a] -> [a] -> [a]
union2 l [] = l
union2 [] l = l
union2 l (h2:t2) | elem h2 l == True = union2 l t2
                 | otherwise = union2 (l ++ [h2]) t2
                 
-- Pergunta 30
-- que retorna a lista resultante de remover da primeira lista os elementos que não pertencem à segunda.
intersect2 :: Eq a => [a] -> [a] -> [a]
intersect2 [] [] = []
intersect2 [] _ = []
intersect2 (h1:t1) l | elem h1 l == True = h1 : intersect t1 l
                     | otherwise = intersect t1 l

-- Pergunta 31
-- que dado um elemento e uma lista ordenada retorna a lista resultante de inserir ordenadamente esse elemento na lista. 
insert2 :: Ord a => a -> [a] -> [a]
insert2 x [] = [x]
insert2 x (h:t) | x <= h = x : h : t
                | otherwise = h : insert2 x t

-- Pergunta 32
-- que junta todas as strings da lista numa só, separando-as por um espaço.
unwords2 :: [String] -> String
unwords2 [] = []
unwords2 (h:hs) = h ++ (if null hs then "" else " ") ++ unwords2 hs

-- Pergunta 33
-- que junta todas as strings da lista numa só, separando-as pelos caracter '\n'.
unlines2 :: [String] -> String
unlines2 [] = []
unlines2 (h:hs) = h ++ "\n" ++ unwords2 hs

-- Pergunta 34
-- dada uma lista não vazia, retorna a posição onde se encontra o maior elemento da lista.
pMaior :: Ord a => [a] -> Int
pMaior [_] = 0
pMaior (h:t) | h >= (t !! x) = 0
             | otherwise = 1 + x
             where x = pMaior t

-- Pergunta 35 
-- que retorna uma lista construída a partir de elementos de uma lista (o segundo argumento) atendendo a uma condição dada pelo primeiro argumento.
lookup2 :: Eq a => a -> [(a,b)] -> Maybe b
lookup2 _ [] = Nothing
lookup2 x ((a,b):t) | x == a = Just b
                    | otherwise = lookup2 x t

-- Pergunta 36
-- calcular o maior prefixo crescente de uma lista.
preCrescente2 :: Ord a => [a] -> [a]
preCrescente2 [] = []
preCrescente2 [x] = [x]
preCrescente2 (h:s:t)
    | s >= h = h : preCrescente2 (s:t)
    | otherwise = [h]

-- Pergunta 37 
-- que calcula o resultado de ordenar a lista. 
iSort2 :: Ord a => [a] -> [a]
iSort2 [] = []
iSort2 [x] = [x]
iSort2 (h:hs) = insert h (iSort2 hs)

-- Pergunta 38
-- que dadas duas Strings, retorna True se e só se a primeira for menor do que a segunda.
menor2 :: String -> String -> Bool
menor2 _ "" = False
menor2 "" _ = True
menor2 (h:t) (h':t')
    | h < h' = True
    | h == h' = menor2 t t'
    | otherwise = False

-- Pergunta 39
-- testa se um elemento pertence a um multi-conjunto.
eleMSet :: Eq a => a -> [(a,Int)] -> Bool
eleMSet _ [] = False
eleMSet x ((a,_):t) | x == a = True
                    | otherwise = eleMSet x t
                
-- Pergunta 40
-- converte um multi-conjunto na lista dos seus elementos.
converteMSet :: [(a,Int)] -> [a]
converteMSet [] = []
converteMSet ((x,1):xs) = x : converteMSet xs
converteMSet ((x,n):xs) = x : converteMSet ((x,n-1) : xs)

-- Pergunta 41 
-- que acrescenta um elemento a um multi-conjunto.
insereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet x [] = [(x,1)]
insereMSet x ((a,b):t) | x == a = ((a,b+1):t)
                       | otherwise = (a,b) : insereMSet x t

-- Pergunta 42
-- que remove um elemento a um multi-conjunto. Se o elemento não existir, deve ser retornado o multi-conjunto recebido.
removeMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removeMSet _ [] = []
removeMSet x ((a,b):t) | x == a && b == 1 = t
                       | x == a = ((a,b-1):t)
                       | otherwise = (a,b) : removeMSet x t

-- Pergunta 43
-- dada uma lista ordenada por ordem crescente, calcula o multi-conjunto dos seus elementos.
constroiMSet :: Ord a => [a] -> [(a,Int)]
constroiMSet [] = []
constroiMSet l = insereMSet (last l) (constroiMSet (init l))

-- Pergunta 45
-- que coleciona os elementos do tipo a de uma lista.
catMaybes :: [Maybe a] -> [a]
catMaybes [] = []
catMaybes (h:hs) = case h of Nothing -> catMaybes hs
                             Just a -> a : catMaybes hs

-- Pergunta 46
-- dadas as posições inicial e final (coordenadas) do robot, produz uma lista de movimentos suficientes para que o robot passe de uma posição para outra.
data Movimento = Norte | Sul | Este | Oeste
               deriving Show

caminho :: (Int,Int) -> (Int,Int) -> [Movimento]
caminho (x1,y1) (x2,y2) | y1 > y2 = Sul : caminho (x1,y1-1) (x2,y2)
                        | y1 < y2 = Norte : caminho (x1,y1+1) (x2,y2)
                        | x1 < x2 = Este : caminho (x1+1,y1) (x2,y2)
                        | x1 > x2 = Oeste : caminho (x1-1,y1) (x2,y2)
                        | otherwise = []

-- Pergunta 47
-- que dada uma posição inicial e uma lista de movimentos (correspondentes a um percurso) verifica se o robot alguma vez volta a passar pela posição inicial ao longo do percurso correspondente.
posicao :: (Int,Int) -> [Movimento] -> (Int,Int)
posicao x [] = x
posicao (x,y) (h:t) = case h of Norte -> posicao (x,y+1) t
                                Sul -> posicao (x,y-1) t
                                Este -> posicao (x+1,y) t
                                Oeste -> posicao (x-1,y) t

hasLoops :: (Int,Int) -> [Movimento] -> Bool
hasLoops _ [] = False
hasLoops x l = x == posicao x l || hasLoops x (init l)

-- Pergunta 48
-- que, dada uma lista com rectângulos, conta quantos deles são quadrados.
type Ponto = (Float,Float)
data Rectangulo = Rect Ponto Ponto

contaQuadrados :: [Rectangulo] -> Int
contaQuadrados [] = 0
contaQuadrados ((Rect (x1,y1) (x2,y2)):t) | abs (x2 - x1) == abs (y2 - y1) = 1 + contaQuadrados t
                                          | otherwise = contaQuadrados t

-- Pergunta 49
-- que, dada uma lista com rectângulos, determina a área total que eles ocupam.
areaTotal :: [Rectangulo] -> Float
areaTotal [] = 0
areaTotal (h:t) = areaUm h + areaTotal t

areaUm :: Rectangulo -> Float
areaUm (Rect (x1,y1) (x2,y2)) = (abs (x2 - x1)) * (abs (y2 - y1))

-- Pergunta 50
-- que determina a quantidade de equipamentos que não estão avariados.
data Equipamento = Bom | Razoavel | Avariado 
                 deriving Show

naoReparar :: [Equipamento] -> Int
naoReparar [] = 0
naoReparar (h:t) = case h of Bom -> 1 + naoReparar t
                             Razoavel -> 1 + naoReparar t
                             Avariado -> naoReparar t
