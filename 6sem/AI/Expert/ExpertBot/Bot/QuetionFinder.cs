using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aviators.Bot
{
    static class QuetionFinder
    {
        public static string Find(string title)
        {
            var text = "";

            if (title.Contains("APPOINTMENT"))
                text = "Для чего Вам нужны коньки?";

            if (title.Contains("HOCKEY LEVEL"))
                text = "Какой у Вас уровень в хоккее?";

            if (title.Contains("RUNNING DISC"))
                text = "Для какой беговой дисциплины подбираете?";

            if (title.Contains("HOCKEY PRO"))
                text = "Приятно иметь дело с профессионалами! Для тебя все самое топовое! Какую фирму предпочитаешь?";

            if (title.Contains("BAUER"))
                text = "Bauer - отличный вкус! Твоя линейка? Vapor - для быстрых и резвых атакующих игроков или Supreme - для массивных и грубых игроков оборонительного плана?";

            if (title.Contains("VAPOR"))
                text = "Вот что мне удалось подобрать для тебя. Хорошей игры!";

            if (title.Contains("SUPREME"))
                text = "Для тебя я нашёл вот эту модель. Отзывы наилучшие!";

            if (title.Contains("CCM"))
                text = "Любителям CCM могу предложить такие модели. Удачи на поле!";

            if (title.Contains("GRAF"))
                text = "Довольно необычный выбор, мало кто в таких играет... Однако и для тебя у меня найдется вариант!";

            if (title.Contains("TERMO"))
                text = "Хочешь термоформовку, чтобы ботинок мог принять форму вашей стопы?";

            if (title.Contains("CASH"))
                text = "Смотрю, ты приехал сюда на крутой машине, с денгами проблем нет?";

            if (title.Contains("CLEARANCE"))
                text = "Хочешь подкачивать воздухом стенки ботинка, чтобы нога сидела там плотнее?";

            if (title.Contains("CLEARANCE YES"))
                text = "Ну что ж, не подкачай! Вот такие две модели для тебя у меня.";

            if (title.Contains("CLEARANCE NO"))
                text = "С такими условиями для тебя пойдут средненькие модели всех фирм, гляди, что я нашел:";

            if (title.Contains("HOCKEY LOW"))
                text = "Пополняешь ряды хоккеистов, класс! Начинать игру советую на таких коньках: ";


            return text;   
        }
    }
}
