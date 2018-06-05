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

            Console.Write("Введите точность: ");

            var input = Convert.ToDouble(Console.ReadLine());

            var a = 1.5;
            double b = 1.3;
            double xk = 0;
            var k = 0;


            #region Первый метод

            xk = a;
                

                Console.WriteLine("");
                Console.WriteLine("Метод Ньютона");
                Console.WriteLine($"x0={xk}");

                k = 0;

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
            

            #endregion

            xk = (a + b) / 2;

            var q1 = Math.Cos(a) / (2 * Math.Sqrt(Math.Sin(a) + 1));
            var q2 = Math.Cos(b) / (2 * Math.Sqrt(Math.Sin(b) + 1));

            var q = Math.Min(Math.Abs(q1), Math.Abs(q2));


            Console.WriteLine("");
            Console.WriteLine("Метод простой итерации");
            Console.WriteLine($"x0={xk}");

            k = 0;

            while (true)
            {
                var fx = Math.Sqrt(Math.Sin(xk) + 1);

                Console.WriteLine($"k={k} xk={xk} fx={fx} ");

                if ((q * Math.Abs(fx - xk)) / (1 - q) < input) break;

                xk = fx;

                k++;

                if (k > 100) break;
            }
            Console.WriteLine($"Kорень x={xk}");

            Console.ReadLine();
        }

    }
}
