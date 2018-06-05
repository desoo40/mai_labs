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
    }
}
