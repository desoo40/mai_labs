using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Console.WriteLine("Choose part:\n" +
                "1 - 1.1\n" +
                "2 - 1.2\n" +
                "3 - 1.3\n" +
                "4 - 1.4\n" +
                "5 - 1.5\n");

            var ans = Console.ReadLine();
            var matr = new Matrix();

            if (ans == "1")
            {
                matr.ReadFromFile("11.txt");
                Console.WriteLine("Решаем систему LU - методом:");

                matr.PrintLikeSystem();

                var sys = new LUDecomposition(matr);

                sys.LU_Algorithm();

                Console.WriteLine("L Matrix:");
                sys.L.Print();

                Console.WriteLine("U Matrix:");
                sys.U.Print();

                Console.WriteLine("Right side:");
                sys.PrintRight();

                Console.WriteLine();

                sys.PrintSolution();
                sys.FindDescrim();
                sys.FindInvertMtx();
            }

            if (ans == "2")
            {
                matr.ReadFromFile("12.txt");
                Console.WriteLine("Решаем систему методом прогонки:");
            
                matr.PrintLikeSystem();

                ThomasAlgorythm(matr);
            }
                
            if (ans == "9")
            {
                var test1 = new Matrix();
                var test2 = new Matrix();

                test1.ReadFromFile("test1.txt");
                test2.ReadFromFile("test2.txt");

                var test3 = test1 * test2;

                if (test3 != null)
                    test3.Print();
            }


        }

        

        private static void ThomasAlgorythm(Matrix matr)
        {
            var P = new List<double>();
            var Q = new List<double>();
            var X = new List<double>();

            for (var i = 0; i < matr.rows; ++i)
            {
                double a = 0;
                double b = 0;
                double c = 0;
                double d = matr.GetElement(i, matr.columns - 1);

                if (i - 1 >= 0)
                    a = matr.GetElement(i, i - 1);

                b = matr.GetElement(i, i);

                if (i + 1 < matr.rows)
                    c = matr.GetElement(i, i + 1);

                P.Add(CalcP(a, b, c, P, i));
                Q.Add(CalcQ(a, b, c, d, P, Q, i));
                X.Add(0);
            }


            X[matr.rows - 1] = Q[matr.rows - 1];

            for (int i = matr.rows - 2; i != 0; --i)
                X[i] = P[i] * X[i + 1] + Q[i];

            Console.WriteLine("Ответ:");
            for (int i = 0; i < matr.rows; ++i)
            {
                Console.WriteLine("x" + (i + 1) + " = " + X[i]);
            }
        }

        private static double CalcP(double a, double b, double c, List<double> p, int i)
        {
            if (i == 0)
                return -c / b;

            return -c / (b + a * p[i-1]);
        }

        private static double CalcQ(double a, double b, double c, double d, List<double> p, List<double> q, int i)
        {
            if (i == 0)
                return d / b;

            return (d - a * q[i - 1]) / (b + a * p[i - 1]);
        }
    }
}
