using NMlab1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    class Program
    {
        static double f(double x, double t)
        {
            return (x * t) / (1 + x * x + 4 * t * t);
        }

        static double f1(double t)
        {
            return -t / Math.Exp(-t);
        }

        static double f2(double t)
        {
            return t * t / Math.Exp(-t);
        }

        static double f3(double x)
        {
            return Math.Sin(x);
        }
        static double f4(double x)
        {
            return Math.Cos(x);
        }

        static void Main(string[] args)
        {
            double a = 0;
            double b = Math.PI;

            double hx = Math.PI / 4;
            double ht = 0.1;

            double T_end = 0.5;

            double alph1 = -4;
            double alph2 = 3;
            double alph3 = -1;
            double alph4 = -4;

            double phi2 = -5;
            double phi5 = -1;

            int n = Convert.ToInt16(T_end / ht) + 1;
            int m = Convert.ToInt16(b / hx) + 1;

            Matrix U = new Matrix(n, m);

            U.Print();

            for (int j = 0; j < m; ++j)
            {
                double xj = hx * j;
                U.mtx[0][j] = f3(xj);
                U.mtx[1][j] = U.mtx[0][j] + ht * f4(xj);
            }

            for (int k = 1; k < n - 1; ++k)
            {
                for (int i = 1; i < m - 1; ++i)
                {
                    U.mtx[k + 1][i] =
                        (1 / (2 + alph1 * ht)) *
                        (4 * U.mtx[k][i] +
                        (alph1 * ht - 2) * U.mtx[k - 1][i] +
                        2 * alph2 * ht * ht / (hx * hx) *
                        (U.mtx[k][i - 1] - 2 * U.mtx[k][i] + U.mtx[k][i + 1])  +
                        alph3 * ht * ht / hx * (U.mtx[k][i + 1] - U.mtx[k][i - 1]) +
                        2 * ht * ht * (alph4 * U.mtx[k][i] + f(hx * i, ht * k)));
                }
            }

            for (int k = 1; k < n - 1; ++k)
            {
                U.mtx[k + 1][0] =     2 * hx * f1(ht * (k + 1)) / (2 * phi2 * hx);//здесь некоторые слагаемые обнуляются, т.к. равны нулю 
                U.mtx[k + 1][m - 1] = 2 * hx * f2(ht * (k + 1)) / (2 * phi5 * hx);//учесть в отчете
            }

            U.Print();
        }
    }
}
