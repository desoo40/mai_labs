using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExpertBot.Bot
{
    class Response
    {
        public string Title = "";
        public List<string> Result = new List<string>();

        public Response(string path)
        {
            var lines = (File.ReadAllLines(path)).ToList();

            foreach (var line in lines)
            {
                if (line.Contains("false"))
                {
                    Title = "false";
                    break;
                }

                if (line.Contains("Title"))
                    Title = line;

                if (line.Contains("Res"))
                {
                    var kek = line.Replace("Res = [", "");
                    var kek1 = kek.Replace("].", "");
                    var kek11 = kek1.Replace("] ", "");
                    var kek2 = kek11.Replace(", ", ",");
                    var kek3 = kek2.Replace("'", "");



                    Result = kek3.Split(',').ToList();

                    
                }
            }
        }
    }
}
