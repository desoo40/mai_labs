using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    static class JacobiMethod
    {
        static Matrix A;
        static double Eps;
        static int N;

        public static void JM(Matrix mtx, double e)
        {
            A = mtx;
            Eps = e;
            N = A.columns;

            IterationProccess();
        }

        private static void IterationProccess()
        {
            Console.WriteLine("Start iterations:");

            double eps0 = CalcEps();
            var UList = new List<Matrix>();

            for (int i = 0; eps0 > Eps; ++i)
            {
                Console.WriteLine("Iteration #" + i + "\n");
                Console.WriteLine(eps0 + " > " + Eps);

                var U = MakeU();
                U.Print();

                A = U.FindTransparent() * A * U;

                A.Print();
                eps0 = CalcEps();

                UList.Add(U);
            }

            Matrix finalU = null;

            for(int i = 0; i < UList.Count - 1; ++i)
                finalU = UList[i] * UList[i + 1];

            finalU.Print();
        }

        private static Matrix MakeU()
        {
            double maxEl = 0;

            int iMax = 0;
            int jMax = 0;

            for (int i = 0; i < N; ++i)
            {
                for (int j = i + 1; j < N; ++j)
                {
                    if (Math.Abs(A.mtx[i][j]) > maxEl)
                    {
                        iMax = i;
                        jMax = j;
                        maxEl = Math.Abs(A.mtx[i][j]);
                    }
                }
            }

            double phi = FindPhi(iMax, jMax);
            Console.WriteLine("\nPhi: " + phi + "\n");
            Console.WriteLine("Sin: " + Math.Sin(phi));
            Console.WriteLine("Cos: " + Math.Cos(phi));
            Matrix U = new Matrix(N);

            U.mtx[iMax][jMax] = -Math.Sin(phi);
            U.mtx[jMax][iMax] = Math.Sin(phi);


            for (int i = 0; i < N; ++i)
                U.mtx[i][i] = (i == iMax || i == jMax) ? Math.Cos(phi) : 1;

            return U;
        }

        private static double FindPhi(int iMax, int jMax)
        {
            if (A.mtx[iMax][iMax] == A.mtx[jMax][jMax])
                return Math.PI / 4;

            Console.WriteLine("\n^ - " + 2 * A.mtx[iMax][jMax]);
            Console.WriteLine("\n| - " + (A.mtx[iMax][iMax] - A.mtx[jMax][jMax]) + "\n");


            return 0.5 * Math.Atan(2.0 * A.mtx[iMax][jMax] / (A.mtx[iMax][iMax] - A.mtx[jMax][jMax]));
        }

        private static double CalcEps()
        {
            double sum = 0;

            for(int i = 0; i < N; ++i)
            {
                for (int j = i + 1; j < N; ++j)
                {
                    sum += Math.Pow(A.mtx[i][j], 2);
                }
            }

            Console.WriteLine("Sum: " + sum);

            return Math.Pow(sum, 0.5);
        }
    }
}
