using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    static class SimpleIteration
    {
        private static double a = -3.0;
        private static double b = 2.0;
        private static double eps = 0.001;


        public static void Start(double e)
        {
            Console.WriteLine("*****************************************");

            eps = e;

            var xk = (a + b) / 2;

            var q1 = Math.Cos(a) / (2 * Math.Sqrt(Math.Sin(a) + 1));
            var q2 = Math.Cos(b) / (2 * Math.Sqrt(Math.Sin(b) + 1));

            var q = Math.Min(Math.Abs(q1), Math.Abs(q2));

            for (int i = 0; i < 100; i++)
            {
                var fx = Math.Sqrt(Math.Sin(xk) + 1);

                Console.WriteLine();
                Console.WriteLine($"x{i} = {xk}");
                Console.WriteLine($"f(x){i} = {fx}");
                Console.WriteLine();

                if ((q * Math.Abs(fx - xk)) / (1 - q) < eps) break;

                xk = fx;
            }

            Console.WriteLine($"Answer:\nx = {xk}");

            Console.WriteLine("*****************************************");
        }
    }
}
