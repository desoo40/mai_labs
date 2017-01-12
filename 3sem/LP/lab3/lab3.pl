%member
member(X, [X|_]).
member(X, [_|Tail]) :-
    member(X, Tail).
    

%append
append([], X, X).
append([X|T], Y, [X|A]) :-
	append(T, Y, A).
 
step(A,B):-
    append(Begin,["_","w"|Tail],A),
    append(Begin,["w","_"|Tail],B).

step(A,B):-
    append(Begin,["b","_"|Tail],A),
    append(Begin,["_","b"|Tail],B).

step(A,B):-
    append(Begin,["_","b","w"|Tail],A),
    append(Begin,["w","b","_"|Tail],B).

step(A,B):-
    append(Begin,["b","w","_"|Tail],A),
    append(Begin,["_","w","b"|Tail],B).

print_ans([]).
print_ans([H|Tail]):-
    print_ans(Tail),
    write(H), nl.

dFS(End,[End|Tail]) :-
        !, print_ans([End|Tail]).
       
dFS(End, [Curr|Tail]) :-
    step(Curr, Tmp),
    not(member(Tmp,Tail)),
    dFS(End, [Tmp, Curr|Tail]). 
                  
solve(Start, End) :-
    dFS(End, [Start]).