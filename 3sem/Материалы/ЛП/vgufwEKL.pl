:- use_rendering(svgtree, [list(false)]).

parents("Борис Сорокин", "Михаил Сорокин", "Татьяна Василенко").
parents("Денис Сорокин", "Михаил Сорокин", "Татьяна Василенко").
parents("Татьяна Василенко", "Иван Василенко", "Лидия Тимофеева").
parents("Наталья Василенко", "Иван Василенко", "Лидия Тимофеева").
parents("Михаил Сорокин", "Борис Сорокин", "Софья Каганович").
parents("Валерия Рыбакова", "Михаил Рыбаков", "Наталья Василенко").
parents("Захар Горбатенко", "Семен Горбатенко", "Наталья Василенко").


bro_or_sist(X, Y) :-
    parents(X, F, M),
    parents(Y, F, M),
    X\=Y.

double(X, Y) :-
    parents(X, F1, M1),
    parents(Y, F2, M2),
    X\=Y,
    
    bro_or_sist(F1, F2),
    bro_or_sist(F1, M2),
    bro_or_sist(M1, F2),
    bro_or_sist(M1, M2).
    
triple_brosist(X, Y) :-
    parents(X, F1, M1),
    parents(Y, F2, M2),
    
    parents(F1, F3, M3),
    parents(M1, F4, M4),
    parents(F2, F5, M5),
    parents(M2, F6, M6),


    bro_or_sist(F3, F5),
    bro_or_sist(F3, M5),
    bro_or_sist(F3, F6),
    bro_or_sist(F3, M6),

    bro_or_sist(M3, F5),
    bro_or_sist(M3, M5),
    bro_or_sist(M3, F6),
    bro_or_sist(M3, M6),
    
    bro_or_sist(F4, F5),
    bro_or_sist(F4, M5),
    bro_or_sist(F4, F6),
    bro_or_sist(F4, M6),
    
    bro_or_sist(M4, F5),
    bro_or_sist(M4, M5),
    bro_or_sist(M4, F6),
    bro_or_sist(M4, M6).

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
