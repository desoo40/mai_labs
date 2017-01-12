bro_or_sist(X, Y) :-
    parents(X, F, M),
    parents(Y, F, M),
    X\=Y.

double(X, Y) :-
    parents(X, F1, M1),
    parents(Y, F2, M2),
    X\=Y,
    
    (bro_or_sist(F1, F2);
    bro_or_sist(F1, M2);
    bro_or_sist(M1, F2);
    bro_or_sist(M1, M2)).
    
triple(X, Y) :-
    parents(X, F1, M1),
    parents(Y, F2, M2),
    X\=Y,
    
   (double(F1, F2);
    double(F1, M2);
    double(M1, F2);
    double(M1, M2)).

relative(child, Child, Parent) :-
    parents(Child, _, Parent);
    parents(Child, Parent, _).

relative(husband, Husband, Wife) :-
    parents(_, Husband, Wife).

relative(wife, Wife, Husband) :-
    parents(_, Husband, Wife).

relative(bro_or_sist, X, Y) :-
	bro_or_sist(X, Y).

relative(double, X, Y) :-
	double(X, Y).

relative(triple, X, Y) :-
	triple(X, Y).

relative(father, Father, Child) :-
    parents(Child, Father, _).

relative(mother, Mother, Child) :-
    parents(Child, _, Mother).

relative(Way, First, Last) :- 
    dpath(First, Last, Way), !. 

print_ans([]).
print_ans([H|Tail]):-
    print_ans(Tail),
    write(H),  write(' - ').

next(Curr, HasBeen, Y, Rel) :-
   (relative(Rel, Curr, Y);
   relative(Rel, Y, Curr)),
   not(member(Y, HasBeen)).

dFS(X, X, _, _).

dFS(Curr, Last, T, [Rev|Tl]) :- 
    next(Curr, T, Next, Rev),
    dFS(Next, Last, [Curr|T], Tl),
    !.

dpath(First, Last, Way) :- 
    dFS(First, Last, [], RevWay),
    reverse(RevWay, Way),
	print_ans(Way),
	!.
