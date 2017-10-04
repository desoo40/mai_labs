using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = 1;
            var b = true | a / (a -1) == 1;

            Console.WriteLine(b);
        }
    }
}
