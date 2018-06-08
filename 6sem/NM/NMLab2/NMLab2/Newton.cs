using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    static class Newton
    {
        private static double a = 0.0;
        private static double b = 2.0;
        private static double eps = 0.001;


        public static void Start(double e)
        {
            Console.WriteLine("*****************************************");

            eps = e;

            var xk = b;


            for (int i = 0; i < 100; i++)
            {
                var fx = Math.Sin(xk) - xk * xk + 1;
                var f1x = Math.Cos(xk) - 2 * xk;
                var dlt = -fx / f1x;

                Console.WriteLine();
                Console.WriteLine($"x{i} = {xk}");
                Console.WriteLine($"f(x){i} = {fx}");
                Console.WriteLine($"f'(x){i} = {f1x}");
                Console.WriteLine($"delta{i} = {dlt}");

                Console.WriteLine();


                if (Math.Abs(dlt) < eps)
                    break;

                xk = xk + dlt;
            }

            Console.WriteLine($"Answer:\nx = {xk}");

            Console.WriteLine("*****************************************");
        }

    }
}
