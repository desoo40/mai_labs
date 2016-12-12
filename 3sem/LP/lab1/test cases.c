Test Cases first LP lab:

lenght([], X).
lenght(X, 0).
lenght(X, 3).
lenght([first, second, last], X).

member(_, []).
member(X, []).
member(X, [3]).
member(6, [3, 4, 5, 6]).
member(5, X).

append([], [], X).
append([1], [], X).
append([1], [_], X).
append(X, Y, [1, 2, 4, 5]).
append([left], [right], X).