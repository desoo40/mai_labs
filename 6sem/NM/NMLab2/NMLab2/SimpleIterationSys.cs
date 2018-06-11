using NMlab1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    static class SimpleIterationSys
    {

        public static void Start(double eps)
        {
            Console.WriteLine("*****************************************");

            var x1k = 1.5;
            var x2k = 2.0;

            //var q1 = Math.Abs(phi11(x1k, x2k)) + Math.Abs(phi12(x1k, x2k));
            //var q2 = Math.Abs(phi21(x1k, x2k)) + Math.Abs(phi22(x1k, x2k));

            //var q = Math.Max(q1, q2);

            var q = 0.99;

            for (int i = 0; i < 100; i++)
            {
                var ph1k = phi1(x1k, x2k);
                var ph2k = phi2(x1k, x2k);

                Console.WriteLine("*****************");
                Console.WriteLine("Iteration #" + i);
                Console.WriteLine();
                Console.WriteLine($"x1 = {x1k}");
                Console.WriteLine($"x2 = {x2k}");
                Console.WriteLine();
                Console.WriteLine($"phi1 = {ph1k}");
                Console.WriteLine($"phi2 = {ph2k}");
                Console.WriteLine("*****************");


                if (q / (1 - q) * Math.Max(Math.Abs(ph1k - x1k), Math.Abs(ph2k - x2k)) < eps) break;

                x1k = ph1k;
                x2k = ph2k;
            }

            Console.WriteLine($"Answer:\n");
            Console.WriteLine($"x1 = {x1k}");
            Console.WriteLine($"x2 = {x2k}");
            Console.WriteLine("*****************************************");
        }

        private static double phi1(double x1k, double x2k)
        {
            //return 2 + Math.Cos(x2k);
            return 2 * Math.Sqrt(Math.Abs(4 - x2k * x2k));
            //return 0.3 - 0.1 * x1k * x1k - 0.2 * x2k * x2k;
        }
        private static double phi2(double x1k, double x2k)
        {
            //return 0.7 - 0.2 * x1k * x1k + 0.1 * x1k * x2k;
            //return 2 + Math.Sin(x1k);
            return (Math.Pow(Math.E, x1k) + x1k) / 4;
        }

        private static double phi11(double x1k, double x2k)
        {
            return 0;
            //return -0.2 * x1k;
        }
        private static double phi12(double x1k, double x2k)
        {
            return - 2 * x2k / (Math.Sqrt(Math.Abs(4 - x2k * x2k)));
        }
        private static double phi21(double x1k, double x2k)
        {
            return (Math.Pow(Math.E, x1k) - 1) / 4;
        }
        private static double phi22(double x1k, double x2k)
        {
            return 0;
        }
    }
}