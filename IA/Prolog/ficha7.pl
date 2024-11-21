%LICENCIATURA EM ENGENHARIA INFORMATICA

%Inteligencia Artificial
%2024/25

%Draft Ficha 7


% Parte I
%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão de um predicado que calcule a soma de três valores.
soma( X,Y,Z,Soma ):-
    Soma is X+Y+Z.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão de um predicado que calcule a soma de um conjunto de valores.
somaL([],0).
somaL([H | T],Soma):-somaL(T,G), G is H+Soma.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão de um predicado que calcule o maior valor entre dois valores.
maior(X,Y,R):-
    R is max(X,Y).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão de um predicado que calcule o maior de um conjunto de valores.
maiorL([Max],Max).
maiorL([H | T], Max):-maiorL(T, MaxT), Max is max(H,MaxT).  

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão de um predicado que calcule a média aritmética de um conjunto de valores.
mediaL(Lista, Media):- 
    somaL(Lista, Soma),
    quantidade(Lista,Tamanho),
    Tamanho > 0,
    Media is Soma/Tamanho.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão de um predicado que ordene de modo crescente uma sequência de valores.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construa a extensão de um predicado capaz de caracterizar os números pares
par(X):- mod(X,2) =:= 0.

impar(X):- not(par(X)).



% Parte II--------------------------------------------------------- - - - - -
%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «pertence» que verifica se um elemento existe dentro de uma lista de elementos.
pertence(X,[X|T]).
pertence(X,[H|T]):-
    X \= H,
    pertence(X,T).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «comprimento» que calcula o número de elementos existentes numa lista.
comprimento([],0).
comprimento([H | T], R):- comprimento(T, QuantidadeT), R is QuantidadeT+1.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «diferentes» que calcula a quantidade de elementos diferentes existentes numa lista.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «apaga1» que apaga a primeira ocorrência de um elemento de uma lista.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «apagaT» que apaga todas as ocorrências de um dado elemento numa lista.   

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «adicionar» que insere um elemento numa lista, sem o repetir.
adicionar(X,L,L):- pertence(X,L).
adicionar(X,L,[X|L]):- not(pertence(X,L)).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «concatenar», que resulta na concatenação dos elementos da lista L1 com os elementos da lista L2.
concatenar([],L2,L2).
concatenar([H|T],L2,[H|T2]):-
    concatenar(T,L2,T2)!
%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «inverter» que inverte a ordem dos elementos de uma lista.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Construir a extensão do predicado «sublista» que determina se uma lista S é uma sublista de outra lista L.
