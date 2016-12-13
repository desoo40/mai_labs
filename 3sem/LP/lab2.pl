:- use_rendering(table,
         [header( t('Surname', 'Gender', 'Subject', 'University'))]).

lenght([], 0).
lenght([_|Tail], N) :-
      lenght(Tail, M), N is M + 1.

%t(Surname, Sex, Subject, University)

teachers(Tch) :-
    lenght(Tch, 6),
        
    % вносим все предметы
    member(t(_, _, math, _), Tch),
    member(t(_, _, geog, _), Tch),
    member(t(_, _, french, _), Tch),
    member(t(_, _, germ, _), Tch),
    member(t(_, _, hist, _), Tch),
    member(t(_, _, math, _), Tch),
       
    % вносим фамилии и пол соотвественно
    member(t(arcadeva, f, _, _), Tch),
    member(t(babanova, f, _, _), Tch),
    member(t(korsakova, f, _, _), Tch),
    member(t(dashkov, m, _, _), Tch),
    member(t(ilin, m, _, _), Tch),
    member(t(flerov, m, _, _), Tch),

    % немец и математик занимались художественной
    % гимнастикой, значит они - женщины, хотя мужчины тоже занимаются! 
    % https://www.youtube.com/watch?v=HrI0G1RTYS4
    member(t(_, f, math, _), Tch),
    member(t(_, f, germ, _), Tch),
    
    % т.к. англичанин самый старший и опытный,
    % а Ильин старшне флерова,но опыта меньше 
    % чем у географа
    not(member(t(ilin, _, eng, _), Tch)),
    not(member(t(flerov, _, eng, _), Tch)),
    not(member(t(ilin, _, geog, _), Tch)),

    % ильин не француз, т.к. старше флерова,
    % который является отцом француза
    not(member(t(ilin, _, french, _), Tch)),

    % аркадьева бабанова - в одном институте
    member(t(arcadeva, f, _, inst), Tch),
    member(t(babanova, f, _, inst), Tch),
    
    % остальные в педе
    member(t(ilin, m, _, ped), Tch),
    member(t(flerov, m, _, ped), Tch),
    member(t(korsakova, f, _, ped), Tch),
    member(t(dashkov, m, _, ped), Tch),

    % флеров старше француза, т.к. отец
    not(member(t(flerov, _, french, _), Tch)),
    
    % преподаватель английского - он
    member(t(_, m, eng, ped), Tch),
    member(t(_, _, hist, ped), Tch),
    member(t(_, _, math, ped), Tch),
    not(member(t(arcadeva, _, germ, _), Tch)).
