filho(joao,jose).
filho(jose,manuel).
filho(carlos,jose).

pai(paulo,filipe).
pai(paulo,maria).
pai(R,F):-filho(F,R).

avo(antonio,nadia).
avo(A,N):-filho(N,X),pai(A,X).
avo(A,N):-descendente(A,N,2).

bisavo(B,P):-descendenteG(P,B,3).
trisavo(T,P):-descendenteG(P,T,4).

neto(nuno,ana).
neto(N,A):-avo(A,N).

descendente(X,Y):-filho(X,Y).
descendente(X,Y):-filho(X,Z),descendente(Z,Y).

descendenteG(X,Y,_):-filho(X,Y).
descendenteG(X,Y,G):-G1 is G+1,filho(X,Z),descendenteG(Y,Z,G1).

sexo(joao,masculino).
sexo(jose,masculino).
sexo(maria,feminino).
sexo(joana,feminino).
