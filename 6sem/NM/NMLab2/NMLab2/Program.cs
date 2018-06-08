using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    class Program
    {
        static void Main(string[] args)
        {

            while (true)
            {
                Console.WriteLine("Choose part:\n" +
                                  "1 - 2.1\n" +
                                  "2 - 2.2\n");

                var ans = Console.ReadLine();

                if (ans == "1")
                {
                    Console.Write("Введите точность: ");

                    var eps = Convert.ToDouble(Console.ReadLine().Replace('.', ','));

                    Console.WriteLine("\nNewton method:");
                    Newton.Start(eps);

                    Console.WriteLine("\nSimple iteration method:");
                    SimpleIteration.Start(eps);
                }

            }
        }

    }
}
