is_node(X) :-
    sub_string(X, 0, 4, _, 'VERTEX ').

is_answer(X) :-
    sub_string(X, 0, 4, _, 'ANSWER ').

get_next(Choice, Title, ResList) :-
    edge(Choice, Title),
    get_variants(Title, [], ResList).

is_exist_else(Title, Curr, X) :-
    edge(Title, X),
    not(member(X, Curr)).

get_variants(Title, Curr, ResList) :-
    is_exist_else(Title, Curr, H),
    (get_variants(Title, [H|Curr], ResList), !;
    ResList = [H|Curr]).

edge('VERTEX ROOT', 'VERTEX APPOINTMENT').

edge('VERTEX APPOINTMENT', 'pleasure skating').
edge('VERTEX APPOINTMENT', 'running').
edge('VERTEX APPOINTMENT', 'figure skating').
edge('VERTEX APPOINTMENT', 'hockey').

edge('hockey', 'VERTEX HOCKEY LEVEL').
edge('running', 'VERTEX RUNNING DISC').
edge('figure skating', 'VERTEX FIGURE LEVEL').
edge('pleasure skating', 'VERTEX PLEASURE AGE').



edge('VERTEX HOCKEY LEVEL', 'hockey pro').
edge('VERTEX HOCKEY LEVEL', 'hockey mid').
edge('VERTEX HOCKEY LEVEL', 'hockey low').

edge('hockey pro', 'VERTEX HOCKEY PRO').

edge('VERTEX HOCKEY PRO', 'bauer').
edge('VERTEX HOCKEY PRO', 'ccm').
edge('VERTEX HOCKEY PRO', 'graf').

edge('bauer', 'VERTEX BAUER').

edge('VERTEX BAUER', 'supreme').
edge('VERTEX BAUER', 'vapor').

edge('supreme', 'ANSWER SUPREME').
edge('ANSWER SUPREME', 'https://www.hockeymonkey.com/bauer-hockey-skates-supreme-1s-sr.html').

edge('vapor', 'ANSWER VAPOR').
edge('ANSWER VAPOR', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/bauer-hockey-skates-vapor-1x-17-sr.html').

edge('ccm', 'ANSWER CCM').
edge('ANSWER CCM', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/ccm-hockey-skates-jetspeed-ft1-sr.html').
edge('ANSWER CCM', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/ccm-hockey-skates-super-tacks-sr.html').

edge('graf', 'ANSWER GRAF').
edge('ANSWER GRAF', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/graf-hockey-skates-peakspeed-pk7700-sr.html').

edge('hockey mid', 'VERTEX TERMO').

edge('VERTEX TERMO', 'no termo').
edge('VERTEX TERMO', 'yes termo').

edge('yes termo', 'VERTEX CASH').
edge('no termo', 'VERTEX CLEARANCE').

edge('VERTEX CASH', 'no cash').
edge('VERTEX CASH', 'yes cash').

edge('yes cash', 'VERTEX HOCKEY PRO').
edge('no cash', 'VERTEX CLEARANCE').

edge('VERTEX CLEARANCE', 'no clearance').
edge('VERTEX CLEARANCE', 'yes clearance').

edge('yes clearance', 'ANSWER CLEARANCE YES').
edge('no clearance', 'ANSWER CLEARANCE NO').

edge('ANSWER CLEARANCE YES', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/ccm-hockey-skates-50k-pump-sr.html').
edge('ANSWER CLEARANCE YES', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/ccm-hockey-skates-ribcor-50k-le-wht-sr.html').
edge('ANSWER CLEARANCE NO', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/ccm-hockey-skates-tacks-9080-sr.html').
edge('ANSWER CLEARANCE NO', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/graf-hockey-skates-g755-pro-sr.html').
edge('ANSWER CLEARANCE NO', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/bauer-hockey-skates-supreme-s180-sr.html').

edge('hockey low', 'ANSWER HOCKEY LOW').
edge('ANSWER HOCKEY LOW', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/bauer-hockey-skate-supreme-s140-sr.html').
edge('ANSWER HOCKEY LOW', 'https://www.hockeymonkey.com/equipment/hockey-skates/ice-hockey-skates-senior/ccm-hockey-skates-tacks-2092-sr.html').


edge('VERTEX RUNNING DISC', 'konkobezh').
edge('VERTEX RUNNING DISC', 'short track').

edge('konkobezh', 'VERTEX KONKOBEZH').

edge('VERTEX KONKOBEZH', 'podvizh').
edge('VERTEX KONKOBEZH', 'ne podvizh').

edge('podvizh', 'ANSWER PODVIZH').
edge('ANSWER PODVIZH', 'http://k4speed.ru/catalog/komplekty/konki_viking_gold_sapphire/').
edge('ANSWER PODVIZH', 'http://k4speed.ru/catalog/komplekty/konki_viking_silver/').

edge('ne podvizh', 'ANSWER NE PODVIZH').
edge('ANSWER NE PODVIZH', 'http://k4speed.ru/catalog/komplekty/konki_viking_original/').

edge('short track', 'ANSWER SHORT TRACK').
edge('ANSWER SHORT TRACK', 'http://k4speed.ru/catalog/komplekty-short-trek/konki_evo_proton_krypton/').

edge('VERTEX FIGURE LEVEL', 'figure pro').
edge('VERTEX FIGURE LEVEL', 'figure low').

edge('figure pro', 'ANSWER FIGURE PRO').
edge('ANSWER FIGURE PRO', 'http://www.figurist.ru/catalog/konki-figurnye/konki_jackson_competitor_aspire_xp_belye/').

edge('figure low', 'ANSWER FIGURE LOW').
edge('ANSWER FIGURE LOW', 'https://www.sportmaster.ru/product/10152240/').

edge('VERTEX PLEASURE AGE', 'junior').
edge('VERTEX PLEASURE AGE', 'senior').

edge('junior', 'VERTEX JUNIOR').

edge('VERTEX JUNIOR', 'ne razdvizh').
edge('VERTEX JUNIOR', 'razdvizh').

edge('razdvizh', 'VERTEX RAZDVIZH').

edge('VERTEX RAZDVIZH', 'girl razdvizh').
edge('VERTEX RAZDVIZH', 'boy razdvizh').

edge('girl razdvizh', 'ANSWER GIRL RAZDVIZH').
edge('ANSWER GIRL RAZDVIZH', 'https://www.sportmaster.ru/product/10055560/').

edge('boy razdvizh', 'ANSWER BOY RAZDVIZH').
edge('ANSWER BOY RAZDVIZH', 'https://www.sportmaster.ru/product/10059430/').

edge('ne razdvizh', 'VERTEX NE RAZDVIZH').
edge('VERTEX NE RAZDVIZH', 'girl ne razdvizh').
edge('VERTEX NE RAZDVIZH', 'boy ne razdvizh').

edge('girl ne razdvizh', 'ANSWER GIRL NE RAZDVIZH').
edge('ANSWER GIRL NE RAZDVIZH', 'https://www.sportmaster.ru/product/10058689/').

edge('boy ne razdvizh', 'ANSWER BOY NE RAZDVIZH').
edge('ANSWER BOY NE RAZDVIZH', 'https://www.sportmaster.ru/product/10060173/').

edge('senior', 'VERTEX SENIOR').

edge('VERTEX SENIOR', 'female').
edge('VERTEX SENIOR', 'male').

edge('male', 'ANSWER MALE').
edge('ANSWER MALE', 'https://www.sportmaster.ru/product/10155819/').

edge('female', 'ANSWER FEMALE').
edge('ANSWER FEMALE', 'https://www.sportmaster.ru/product/1192214/').
