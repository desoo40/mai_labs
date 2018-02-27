1. Пара игроков в одной игре
SELECT player.* FROM player, roster;
WHERE player.id_player = roster.id_player;
AND id_game = 33 ORDER BY number top 2


SELECT first.id_player, second.id_player, first.id_game FROM roster first, roster second;
WHERE first.id_game = second.id_game AND first.id_player > second.id_player


2. Игроки не забившие голов за турнир

SELECT * FROM player;
WHERE id_player NOT IN;
(SELECT  id_player FROM goal_player, goal, game;
WHERE goal_player.id_goal = goal.id_goal;
AND goal.id_game = game.id_game;
AND game.id_tour = 1)

3. Игроки забившие максимальное число голов за сезон
SELECT  id_player , COUNT(*) AS goals FROM goal_player, goal, game INTO CURSOR tmp;
WHERE goal_player.id_goal = goal.id_goal;
AND goal_player.assistant = 'F';
AND goal.id_game = game.id_game;
AND game.id_season = 1;
GROUP BY id_player

SELECT player.id_player, player.name, player.surname, tmp.goals FROM player, tmp;
WHERE player.id_player = tmp.id_player ORDER BY goals DESC

SELECT player.id_player, player.name, player.surname, tmp.goals FROM player, tmp;
WHERE player.id_player = tmp.id_player AND tmp.goals IN (SELECT MAX(tmp.goals) FROM tmp)

4. Наиболее опасные команды (больше всего забитых голов)

SELECT  gamestat.id_team , SUM(game.op_score) AS GoalsQTY FROM game, gamestat INTO CURSOR tmp;
WHERE game.id_game = gamestat.id_game  AND gamestat.id_team != 1;
GROUP BY gamestat.id_team

SELECT team.team_name, tmp.GoalsQTY FROM team, tmp;
WHERE team.id_team = tmp.id_team;
AND tmp.GoalsQTY IN (SELECT MAX(tmp.GoalsQTY) FROM tmp)

5. Самые удачные турниры (больше всего побед)

SELECT  id_tour, SUM (CAST(game.score > game.op_score as INT)) as wins, COUNT(game.id_game) as games;
FROM game INTO CURSOR tmp;
GROUP BY id_tour

SELECT tour_name, wins, games FROM tournament, tmp;
WHERE tournament.id_tour = tmp.id_tour;
AND tmp.wins IN (SELECT MAX(tmp.wins) FROM tmp)

6. Турниры, побед в которых выше среднего

SELECT  id_tour, SUM (CAST(game.score > game.op_score as INT)) / COUNT(game.id_game) as WtoG;
FROM game INTO CURSOR tmp;
GROUP BY id_tour

SELECT SUM(WtoG) / COUNT(WtoG) as avgWtG FROM tmp INTO CURSOR ratmp

SELECT tournament.tour_name, WtoG, avgWtG FROM tournament, tmp, ratmp;
WHERE tournament.id_tour = tmp.id_tour AND tmp.WtoG > ratmp.avgWtG;

7. Игроки не участвовавшие в данном турнире

SELECT * FROM player;
WHERE id_player NOT IN ;
(SELECT  id_player FROM roster, game  ;
WHERE roster.id_game = game.id_game AND game.id_tour = 1)

