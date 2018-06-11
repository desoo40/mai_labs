using NMlab1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    static class NewtonSys
    {
        
        public static void Start(double eps)
        {
            Console.WriteLine("*****************************************");

            var x1k = 2.0;
            var x2k = 2.0;


            for (int i = 0; i < 100; i++)
            {
                var A1 = FindDetA1(x1k, x2k);
                var A2 = FindDetA2(x1k, x2k);
                var J = FindDetJ(x1k, x2k);

                var tmp1 = A1 / J;
                var tmp2 = A2 / J;

                Console.WriteLine("*****************");
                Console.WriteLine("Iteration #" + i);
                Console.WriteLine();
                Console.WriteLine($"x1 = {x1k}");
                Console.WriteLine($"x2 = {x2k}");
                Console.WriteLine();
                Console.WriteLine($"det A1 = {A1}");
                Console.WriteLine($"det A2 = {A2}");
                Console.WriteLine($"det J = {J}");
                Console.WriteLine($"dlt1 = {tmp1}");
                Console.WriteLine($"dlt2 = {tmp2}");
                Console.WriteLine("*****************");


                if (Math.Max(Math.Abs(tmp1), Math.Abs(tmp2)) < eps)
                    break;

                x1k -= tmp1;
                x2k -= tmp2;

            }

            Console.WriteLine($"Answer:\n");
            Console.WriteLine($"x1 = {x1k}");
            Console.WriteLine($"x2 = {x2k}");
            Console.WriteLine("*****************************************");
        }

        private static double FindDetJ(double x1k, double x2k)
        {
            Matrix m = new Matrix(2);

            m.mtx[0][0] = F11(x1k, x2k);
            m.mtx[0][1] = F12(x1k, x2k);
            m.mtx[1][0] = F21(x1k, x2k);
            m.mtx[1][1] = F22(x1k, x2k);

            return m.CalcDet2();
        }

        private static double FindDetA1(double x1k, double x2k)
        {
            Matrix m = new Matrix(2);

            m.mtx[0][0] = F1(x1k, x2k);
            m.mtx[0][1] = F12(x1k, x2k);
            m.mtx[1][0] = F2(x1k, x2k);
            m.mtx[1][1] = F22(x1k, x2k);

            return m.CalcDet2();
        }

        private static double F22(double x1k, double x2k)
        {
            return 4;
            //return 1 - 0.1 * x1k;
        }

        private static double F12(double x1k, double x2k)
        {
            return x2k / 2;
            //return 0.4 * x2k;
        }

        private static double FindDetA2(double x1k, double x2k)
        {
            Matrix m = new Matrix(2);

            m.mtx[0][0] = F11(x1k, x2k);
            m.mtx[0][1] = F1(x1k, x2k);
            m.mtx[1][0] = F21(x1k, x2k);
            m.mtx[1][1] = F2(x1k, x2k);

            return m.CalcDet2();
        }

        private static double F21(double x1k, double x2k)
        {
            return -Math.Pow(Math.E, x1k)  - 1;
            //return 0.4 * x1k - 0.1 * x2k;
        }

        private static double F11(double x1k, double x2k)
        {
            return x1k / 8;
            //return 0.2 * x1k + 1;
        }

        private static double F2(double x1k, double x2k)
        {
            return 4.0 * x2k - Math.Pow(Math.E, x1k) - x1k;
            //return 0.2 * 0.2 * x1k + x2k - 0.1 * x1k * x2k - 0.7;
        }

        private static double F1(double x1k, double x2k)
        {
            return x1k * x1k / 16.0 + x2k * x2k / 4.0 - 1.0;
            //return 0.1 * x1k * x1k + x1k + 0.2 * x2k * x2k - 0.3;
        }
    }
}
