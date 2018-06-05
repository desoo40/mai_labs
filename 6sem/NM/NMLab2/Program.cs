using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace NelineynyeUravneniya
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите точность: ");

            var input = Convert.ToDouble(Console.ReadLine());

            var a = 1.5;
            double b = 0;

            for (int i = 0; i < 2; i++)
            {
                double xk = 0;

                if (i == 0) xk = a;
                if (i == 1) xk = b;

                Console.WriteLine("");
                Console.WriteLine($"x0={xk}");

                var k = 0;

                while (true)
                {
                    var fx = Math.Sin(xk) - xk * xk + 1;
                    var f1x = Math.Cos(xk) - 2 * xk;
                    var dlt = -fx / f1x;

                    Console.WriteLine($"k={k} xk={xk} fx={fx} f1x={f1x} dlt={dlt}");

                    if (Math.Abs(dlt) < input) break;

                    xk = xk + dlt;

                    k++;

                    if (k > 100) break;
                }

                Console.WriteLine($"Kорень x={xk}");
            }

            Console.ReadLine();
        }
    }
}
