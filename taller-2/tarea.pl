%Ejercicio 1
progenitor(clara,jose).
progenitor(thomas,jose).
progenitor(tomas,isabel).
progenitor(jose,ana).
progenitor(jose,patricia).
progenitor(patricia,jaime).

%progenitor(Y,X), progenitor(X, jaime)
% progenitor(Z,Y),progenitor(Y,X),progenitor(X, jaime)

%ejercicio 2
es(oro, valioso).
es(ana, mujer).
esPadre(juan,maria).
presta(juan,lapiz,pedro).
presta(juan,libro,maria).
presta(pedro,borrador,juan).
tiene(juan,oro).

%ejercicio 3
varon(albert).
varon(edward).
mujer(alice).
mujer(victoria).
padres(edward, victoria, albert).
padres(alice, victoria, albert).
hermanaDe(X,Y):- X\=Y, mujer(X), padres(X,W,M),padres(Y,W,M).

%ejercicio 4
miembro(Caracter, [Caracter|_]) :- !.
miembro(Caracter, [_|C]) :- miembro(Caracter, C).

%ejercicio 5
inversa(L1,L):- inversa(L1,[],L).
inversa([],L,L).
inversa([X|L1],L2,L3):- inversa(L1,[X|L2],L3).

%ejercicio 6
longitud([], 0).
longitud([_|Cola], I)
    :- longitud(Cola, A),
    I is A + 1.

%ejercicio 7

acontecimiento(2008, 'Nacimiento de mi Hermana').
acontecimiento(2019, 'Pandemia').
acontecimiento(2023, 'clases presenciales').
acontecimiento(2018, 'Mundial de Rusia').

consulta:-
pth(['Que',fecha,desea,'consultar? ']),
read(D),
acontecimiento(D,S),
pth(S).