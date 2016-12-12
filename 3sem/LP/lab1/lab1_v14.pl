% Реализация стандартных предикатов

%lenght

lenght([], 0).
lenght([_|Tail], N) :-
      lenght(Tail, M), N is M + 1.

%member

member(X, [X|_]).
member(X, [_|Tail]) :-
    member(X, Tail).
    

%append

append([], X, X).
append([X|T], Y, [X|A]) :-
	append(T, Y, A).

%remove

remove(X, [X|Tail1], Tail1).
remove(X, [H|Tail1], [H|Tail2]) :-
	remove(X, Tail1, Tail2).

%permute

permute([], []).
permute(L, [X|T]) :-
	permute(R, T),
    remove(X, L, R).
	
%sublist

sublist(List1, List2) :-
	append(_, T, List1),
	append(List2, _, T).

% Особый предикат вариант 14 (нахождение элемента, следующего за данным)

% С помощью стандартных предикатов

std_find_next(X, [X, Y|_], Y).
std_find_next(X, List, Y) :-
    remove(_, List, Tail),
    !,
    std_find_next(X, Tail, Y).

% Без помощи стандартных предикатов

find_next(X, [X, Y|_], Y).
find_next(X, [_|T], Y) :-
    find_next(X, T, Y).

% реализовать для порядкового представления списков


% Обработка числовых списков

% В стандартном предствалении

% Числовая последовательность является геометрической прогрессией тогда и только тогда,
% когда квадрат каждого ее члена, кроме первого (и последнего, в случае конечной последовательности),
% равен произведению предшествующего и последующего членов 
% (характеристическое свойство геометрической прогрессии).

is_geom([X,Y,Z|T]) :-
    !,
    X \= 0, % первый член прогрессии должен быть отличен от нуля
    Y * Y =:= X * Z,
    is_geom([Y,Z|T]).
is_geom(_).

% В порядковом представлении

%p_is_geom([e(1, X)|_]).

%p_is_geom([e(N, X]) :-
 %   !,
  %  X \= 0, % первый член прогрессии должен быть отличен от нуля
   % Y * Y =:= X * Z,
    %p_is_geom([Y,Z|T]).
%p_is_geom(_).
          
% Содержательный пример












          
          
          