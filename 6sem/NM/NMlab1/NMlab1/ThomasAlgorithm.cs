using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    static class ThomasAlgorythm
    {
        public static void TA(Matrix matr)
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

            for (int i = matr.rows - 2; i >= 0; --i)
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

            return -c / (b + a * p[i - 1]);
        }

        private static double CalcQ(double a, double b, double c, double d, List<double> p, List<double> q, int i)
        {
            if (i == 0)
                return d / b;

            return (d - a * q[i - 1]) / (b + a * p[i - 1]);
        }
    }
}
