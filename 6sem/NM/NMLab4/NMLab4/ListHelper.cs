using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab3
{
    static class ListHelper
    {
        public static void Print(List<double> l, string s)
        {
            for (int i = 0; i < l.Count; i++)
            {
                Console.WriteLine($"{s}[{i}] = {l[i]}");
            }
            Console.WriteLine();
        }


        public static void PrintTable (List<List<double>> l, List<string> s)
        {
            Console.Write($"i\t");

            for (int i = 0; i < s.Count; i++)
                Console.Write($"{s[i]}\t\t");

            Console.WriteLine();


            for (int i = 0; i < l[0].Count; i++)
            {
                Console.Write($"{i}\t");

                for (int j = 0; j < l.Count; j++)
                {
                    Console.Write($"{l[j][i].ToString("0.00000")}\t\t");
                }

                Console.WriteLine();
            }
        }
    }
}
