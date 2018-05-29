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

        private static void ItarationProccess()
        {
            Console.WriteLine("Start iterations:");

            FindQR();

            for (int i = 0; FindEps(A.GetColumn(0)) > eps; i++)
            {
                Console.WriteLine("Iteration #" + i + "\n");

                R.Print("R");
                Q.Print("Q");

                A = R * Q;

                A.Print("A");

                FindQR();
            }

            A.Print("Final A");
        }

        public static double FindEps(List<double> l)
        {
            double sum = 0;

            for (int i = 1; i < l.Count; i++)
                sum += Math.Pow(l[i], 2);

            return Math.Pow(sum, 0.5);
        }

        private static void FindQR()
        {
            R = new Matrix(A);
            var HList = new List<Matrix>();

            for (int i = 0; i < R.rows - 1; i++)
            {
                var b = R.GetColumn(i);
                var v = CalcV(b, i);
                var H = HouseholderCalc(v);

                HList.Add(H);

                R = H * R;
            }
            

            Q = new Matrix(A.columns);
            Q.MakeUnitMatrix();

            foreach (var h in HList)
                Q *= h;


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
            var e = new  List<double>();
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
