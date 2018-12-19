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
        static Matrix finalU;
        static List<List<double>> eigVectors;
        static List<double> eigValues;
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

            finalU = new Matrix(A.columns);
            finalU.MakeUnitMatrix();

            for (int i = 0; eps0 > Eps; ++i)
            {
                Console.WriteLine("Iteration #" + i + "\n");
                Console.WriteLine(eps0 + " > " + Eps);

                var U = MakeU();
                U.Print("U");

                A = U.FindTransparent() * A * U;

                A.Print("A");
                eps0 = CalcEps();

                Console.WriteLine("eps = " + eps0 + "\n");

                finalU *= U;
            }

            WriteEigenvalues();

            Console.WriteLine("Eigenvectors:");

            Console.WriteLine("x1       x2      x3");
            finalU.Print();
        }

        private static void WriteEigenvalues()
        {
            Console.WriteLine("Eigenvalues:");

            for (int i = 0; i < A.columns; ++i)
            {
                Console.WriteLine("Lyambda" + (i + 1) + " = " + A.mtx[i][i]);

            }

            Console.WriteLine();
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
            Console.WriteLine("\nSin: " + Math.Sin(phi));
            Console.WriteLine("Cos: " + Math.Cos(phi));
            Console.WriteLine("Phi: " + phi + "\n");
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

            return Math.Pow(sum, 0.5);
        }
    }
}
