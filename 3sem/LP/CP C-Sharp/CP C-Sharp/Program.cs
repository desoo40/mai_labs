using System;
using System.IO;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CP_C_Sharp
{
    class Program
    {
        public static StreamReader Reader = File.OpenText("Sorokin Family.ged");
        //public static StreamWriter Writer = File.CreateText("cp_sorokin.txt");

        static void Main(string[] args)
        { 
            var dictOfMembers = new Dictionary<string, string>();
            dictOfMembers["He"] = "Неизвестен";
            dictOfMembers["She"] = "Неизвестена";

            List<string> predicats = new List<string>();

            string tmp = "";
            string ID = "";
            string Name = "";

            for (var i = 0; (tmp = Reader.ReadLine()) != null; i++)
            {
                if (tmp.StartsWith("0 @I"))
                {
                    ID = tmp.Substring(3, 7);
                }

                if (tmp.StartsWith("1 NAME"))
                {
                    Name = tmp.Substring(7);
                    Name = Name.Replace("/", "");

                    if (Name == " ")
                    {
                        Name = "Неизвестно";
                    }
                    dictOfMembers[ID] = Name;
                    ID = "";
                    

                }

                if (tmp.StartsWith("0 @F"))
                {
                    predicats = PredicatsWriter(dictOfMembers, predicats);
                }
            }


            File.WriteAllLines("cp_sorokin.pl", predicats);

        }

        private static List<string> PredicatsWriter(Dictionary<string, string> dict, List<string> predicats)
        {
            string tmp = " ";
            string husband = "He";
            string wife = "She";
            
            List<string> children = new List<string>(); 

            while (!tmp.StartsWith("1 RIN"))
            {
                tmp = Reader.ReadLine();

                if (tmp.StartsWith("1 HUSB"))
                {
                    husband = tmp.Substring(8, 7);
                }

                if (tmp.StartsWith("1 WIFE"))
                {
                    wife = tmp.Substring(8, 7);
                }

                if (tmp.StartsWith("1 CHIL"))
                {
                    children.Add(tmp.Substring(8, 7));
                }

            }


            foreach (var child in children)
            {
                string pred = string.Format("parents(\"{0}\", \"{1}\", \"{2}\").\n", dict[child], dict[husband], dict[wife].TrimEnd());
                predicats.Add(pred);
            }

            return predicats;
        }

    }
}
