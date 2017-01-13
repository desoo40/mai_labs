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

dFS(Goal,[Goal|Tail]) :-
        !, print_ans([Goal|Tail]).
       
dFS(Goal, [Curr|Tail]) :-
    step(Curr, Tmp),
    not(member(Tmp,Tail)),
    dFS(Goal, [Tmp, Curr|Tail]). 

next(X, HasBeen, Y) :-
    step(X,Y),
    not(member(Y,HasBeen)). 

bFS([First|_],Goal,First) :- 
    First = [Goal|_].
bFS([[LastWay|HasBeen]|OtherWays],Finish,Way):-  
    findall([Z,LastWay|HasBeen],
            next(LastWay, HasBeen, Z), List),
    		append(List,OtherWays,NewWays), 
    		bFS(NewWays,Finish,Way).
                  
solve(Start, Goal):-
    write('ÏÎÈÑÊ Â ÃËÓÁÈÍÓ START'), nl,
    get_time(DFS),
    dFS(Goal, [Start]),
    write('ÏÎÈÑÊ Â ÃËÓÁÈÍÓ END'), nl, nl,
    write('TIME IS '), write(DFS), nl, nl,
    
    write('ÏÎÈÑÊ Â ØÈĞÈÍÓ START'), nl,
    get_time(BFS),
	bFS([[Start]],Goal,Way), 
	print_ans(Way),
	write('ÏÎÈÑÊ Â ØÈĞÈÍÓ END'), nl, nl,
    write('TIME IS '), write(BFS), nl, nl,
    !.
