using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1
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
                if (line.Contains("Title"))
                {
                    if (line.Contains("COLOUR"))
                        Title = "Colour";

                    if (line.Contains("APPOINTMENT"))
                        Title = "Appointment";

                    if (line.Contains("HOCKEY LEVEL"))
                        Title = "Hockey level";

                    if (line.Contains("RUNNING DISC"))
                        Title = "Running disc";
                }

                if (line.Contains("Res"))
                {
                    var kek = line.Replace("Res = [", "");
                    var kek1 = kek.Replace("].", "");
                    var kek2 = kek1.Replace(", ", ",");

                    Result = kek2.Split(',').ToList();
                }
            }
        }
    }
}
