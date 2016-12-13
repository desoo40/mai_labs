:- use_rendering(table,
		 [header( t('Surname', 'Sex', 'Subject', 'University'))]).

lenght([], 0).
lenght([_|Tail], N) :-
      lenght(Tail, M), N is M + 1.

%      t(Surname, Sex, Subject, University)

not_eq(X, Y) :-
    not(X = Y).

teachers(Tch) :-
    lenght(Tch, 6),

    % нем и матем занимались худ. гимнастикой
    member(t(_, f, math, _), Tch),
    member(t(_, f, germ, _), Tch),
    
    % ильин старше флерова, но стаж меньше чем у географа
    member(t(ilin, m, _, _), Tch),
    member(t(flerov, m, _, _), Tch),
    not_eq(t(ilin, _, _, _), t(_, _, geog, _)),
    
    % аркадьева бабанова - в одном институте
    member(t(arcadeva, f, _, inst), Tch),
    member(t(babanova, f, _, inst), Tch),
    
    % остальные в педе
    member(t(ilin, m, _, ped), Tch),
    member(t(flerov, m, _, ped), Tch),
    member(t(korsakova, f, _, ped), Tch),
    member(t(dashkov, m, _, ped), Tch),

	% преподаватель английского - он
	
	member(t(_, m, eng, ped), Tch).
