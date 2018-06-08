using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab4
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Choose part:\n" +
                    "1 - 4.1\n" +
                    "2 - 4.2\n");

                var ans = Console.ReadLine();

                if (ans == "1")
                    ERKA.Start();

                if (ans == "2")
                {
                    SKR.Start();
                }
            }
        }
    }
}
