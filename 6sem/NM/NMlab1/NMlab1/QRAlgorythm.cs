using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    public static class QRAlgorythm
    {
        private static Matrix A;
        private static Matrix Q;
        private static Matrix R;
        private static double eps;

        public static void QR(Matrix m, double e)
        {
            A = m;
            eps = e;

            ItarationProccess();
        }

        public static void QR(Matrix m)
        {
            A = m;

            FindQR();

            (R * Q).Print("R * Q");
        }

        private static void ItarationProccess()
        {
            Console.WriteLine("Start iterations:");

            FindQR();

            for (int i = 0; FindEps(A.GetColumn(0)) > eps; i++)
            {
                Console.WriteLine("Iteration #" + i + "\n");

                

                A = R * Q;

                A.Print("A");

                FindQR();
            }

            A.Print("Final A");

            var l1 = A.mtx[0][0];

            var c = A.mtx[2][2] * A.mtx[1][1] - A.mtx[1][2] * A.mtx[2][1];
            var b = -A.mtx[2][2] - A.mtx[1][1];

            var l2R = -b / 2;
            var l3R = l2R;

            var l2I = Math.Sqrt(Math.Abs(b * b - 4 * c)) / 2;
            var l3I = - l2I;

            Console.WriteLine("Eigenvalues:");
            Console.WriteLine("Lyambda 1 = " + l1);
            Console.WriteLine($"Lyambda 2 = {l2R} + {l2I}i");
            Console.WriteLine($"Lyambda 3 = {l3R} - {l2I}i");




        }

        public static double FindEps(List<double> l)
        {
            double sum = 0;

            //for (int i = 1; i < l.Count; i++)
            //    sum += Math.Pow(l[i], 2);

            //return Math.Pow(sum, 0.5);

            return l[l.Count - 1];
        }

        private static void FindQR()
        {
            R = new Matrix(A);
            Q = new Matrix(A.columns);
            Q.MakeUnitMatrix();

            for (int i = 0; i < R.rows - 1; i++)
            {
                var b = R.GetColumn(i);
                var v = CalcV(b, i);
                var H = HouseholderCalc(v);

                Q *= H;

                R = H * R;
            }
            

            Q.Print("Q");
            R.Print("R");
        }

        public static Matrix HouseholderCalc(List<double> v)
        {
            Matrix E = new Matrix(v.Count);
            E.MakeUnitMatrix();

            var koef = -2 / Vector.Scalar(v, v);

            Matrix H = E + koef * Vector.MultiplyVectors(v, v);

            return H;
        }

        public static double CalcNorm(List<double> b)
        {
            double norm = 0;

            foreach (var el in b)
                norm += Math.Pow(el, 2);

            norm = Math.Pow(norm, 0.5);

            return norm;
        }

        public static List<double> CalcV(List<double> b, int i)
        {
            var e = new List<double>();
            var v = b;

            for (int j = 0; j < b.Count; j++)
            {
                if (i > j)
                    v[j] = 0;

                if (i == j)
                   e.Add(1);
                else
                   e.Add(0);
            }

            var res = Vector.SumVec(v, Vector.DigitOnVector(Math.Sign(b[i]) * CalcNorm(b), e));

            return res;
        }
    }
}
