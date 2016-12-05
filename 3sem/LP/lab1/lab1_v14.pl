% Первая лабораторная. Логическое программирование. Сорокин Денис. Вариант 14.

% Предикаты обработки списков

myLenght([], 0).
myLenght([_|T], N) :- 
    myLenght(T, N1), N is N1 + 1.

myMember(X, [X|_]).
myMember(X, [_|T]) :-
	myMember(X, T).

myAppend([], X, [X]).
myAppend([_|T], Y, [_|A]) :-
	myAppend(T, Y, A).

myRemove(X, [X|T], T).
myRemove(X, [H|T], [H|R]) :-
	myRemove(X, T, R).

myPermute([], []).
myPermute(L, [X|T]) :-
	myRemove(X, L, R),
	myPermute(R, T).

mySublist(L, R) :-
	myAppend(_, T, L),
	myAppend(R, _, T).

findAfterElem(X, [X|_]).
	findAfterElem(X, [_|T]) :-
    	myMember(X, T + 1).