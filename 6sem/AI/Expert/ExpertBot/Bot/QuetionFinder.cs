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



            return text;   
        }
    }
}
