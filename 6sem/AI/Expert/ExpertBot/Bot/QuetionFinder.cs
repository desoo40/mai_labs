using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aviators.Bot
{
    static class TextHelper
    {
        public static string FindText(string title)
        {
            var text = "";

            if (title.Contains("APPOINTMENT"))
                text = "Для чего тебе нужны коньки?";

            if (title.Contains("HOCKEY LEVEL"))
                text = "Какой у тебя уровень в хоккее?";

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
                text = "Хочешь термоформовку, чтобы ботинок мог принять форму твоей стопы?";

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

            if (title.Contains("RUNNING DISC"))
                text = "Для какой конькобежной дисциплины выбираешь?";

            if (title.Contains("KONKOBEZH"))
                text = "Подвижное лезвие или нет?";

            if (title.Contains("PODVIZH"))
                text = "Отлично! Вот что я нашел для тебя. Конькобежные коньки с подвижным лезвием:";

            if (title.Contains("NE PODVIZH"))
                text = "Эти коньки невероятно скоростные, тебе точно подойдут!";

            if (title.Contains("SHORT TRACK"))
                text = "Для тех, кто быстро нарезает круги подойдут такие ботинки:";

            if (title.Contains("FIGURE LEVEL"))
                text = "Какой у тебя уровень в фигурном катании?";

            if (title.Contains("FIGURE PRO"))
                text = "Для профессионалов безусловно эта модель!";

            if (title.Contains("FIGURE LOW"))
                text = "Эти коньки помогут тебе совершенствовать мастерство:";

            if (title.Contains("PLEASURE AGE"))
                text = "Для какого возроста подбираете прогулочные коньки?";

            if (title.Contains("JUNIOR"))
                text = "Хотите раздвижные коньки? Удобно, когда ребенок растет, а денег на новые коньки тратить не нужно!";

            if (title.Contains("RAZDVIZH") || title.Contains("NE RAZDVIZH"))
                text = "Для мальчика или девочки?";

            if (title.Contains("GIRL RAZDVIZH") || title.Contains("GIRL NE RAZDVIZH"))
                text = "Вот, что могу предложить для будущей чемпионки:";

            if (title.Contains("BOY RAZDVIZH") || title.Contains("BOY NE RAZDVIZH"))
                text = "Для будущих хоккеистов я нашел вот такие коньки:";

            if (title.Contains("SENIOR"))
                text = "Для парня или девушки?";

            if (title.Contains("ANSWER FEMALE"))
                text = "Идеальный варинт для катания в парках:";

            if (title.Contains("MALE"))
                text = "Для мужчин идеальный вариант: и с девушкой покататься в парке и в хоккей с друзьями сыграть!";

            return text;
        }
        public static string Translate(string s)
        {
            var buttonText = "";

            if (s == "hockey")
                buttonText = "Хоккей";

            if (s == "running")
                buttonText = "Конькобежный спорт";

            if (s == "figure skating")
                buttonText = "Фигурное катание";

            if (s == "pleasure skating")
                buttonText = "Прогулочное катание";

            if (s == "hockey low" || s == "figure low")
                buttonText = "Новичок";

            if (s == "hockey mid")
                buttonText = "Любитель";

            if (s == "hockey pro" || s == "figure pro")
                buttonText = "Профессионал";

            if (s == "bauer")
                buttonText = "Bauer";

            if (s == "ccm")
                buttonText = "CCM";

            if (s == "graf")
                buttonText = "Graf";

            if (s == "supreme")
                buttonText = "Supreme";

            if (s == "vapor")
                buttonText = "Vapor";

            if (s == "yes termo" || s == "yes clearance")
                buttonText = "Да";

            if (s == "no termo" || s == "no clearance")
                buttonText = "Нет";

            if (s == "yes cash")
                buttonText = "Деньги не проблема!";

            if (s == "no cash")
                buttonText = "Это папина...";

            if (s == "konkobezh")
                buttonText = "Бег на коньках";

            if (s == "short track")
                buttonText = "Шорт-трек";

            if (s == "podvizh")
                buttonText = "Подвижное";

            if (s == "ne podvizh")
                buttonText = "Не подвижное";

            if (s == "junior")
                buttonText = "Детские";

            if (s == "senior")
                buttonText = "Взрослые";

            if (s == "razdvizh")
                buttonText = "Раздвижные";

            if (s == "ne razdvizh")
                buttonText = "Не раздвижные";

            if (s == "girl razdvizh" || s == "girl ne razdvizh")
                buttonText = "Девочка";

            if (s == "boy razdvizh" || s == "boy ne razdvizh")
                buttonText = "Мальчик";

            if (s == "female")
                buttonText = "Девушка";

            if (s == "male")
                buttonText = "Парень";

            return buttonText;
        }
    }
}
