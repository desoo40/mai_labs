using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using NMlab1;

namespace CP
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {

                Console.WriteLine("Gen new mtx?");
                var ansMtx = Console.ReadLine();

                if (ansMtx == "y")
                    GenerateMatrix();

                var A = new Matrix();

                A.ReadFromFile("mtx.txt");
                A.Print("A");

                var H = Arnoldi(A);

                for (int i = 0; i < 50; ++i)
                {
                    if (H == null)
                    {
                        Console.WriteLine("Неподходящая матрица");
                        break;
                    }

                    H = QR(H);
                }

                if (H == null)
                    continue;

                H.Print("H after QR");

                FindEigvalues(H);
            }
        }

        private static void FindEigvalues(Matrix H)
        {
            decimal eps = Convert.ToDecimal(0.000001);
            var n = H.mtx.Count;

            var eigvalues = new List<Complex>();

            for (int i = 0; i < n - 1; ++i)
            {
                var lower = H.mtx[i + 1][i];

                if (Math.Abs(lower) < eps)
                {
                    eigvalues.Add(new Complex(H.mtx[i][i], 0));
                    continue;
                }

                var b = -H.mtx[i][i] - H.mtx[i + 1][i + 1];
                var c =  H.mtx[i][i] * H.mtx[i + 1][i + 1] - H.mtx[i][i + 1] * H.mtx[i + 1][i];

                var D = Convert.ToDouble(b * b - 4 * c);

                var sqrtD = Convert.ToDecimal(Math.Sqrt(Math.Abs(D)));

                if (D < 0)
                {
                    eigvalues.Add(new Complex(-b / 2,  sqrtD / 2));
                    eigvalues.Add(new Complex(-b / 2, -sqrtD / 2));
                }
                else
                {
                    eigvalues.Add(new Complex(-b / 2 + sqrtD / 2, 0));
                    eigvalues.Add(new Complex(-b / 2 - sqrtD / 2, 0));
                }
                ++i;
            }


            if (eigvalues.Count < n)
                eigvalues.Add(new Complex(H.mtx[n - 1][n - 1], 0));

            LambdaPrint(eigvalues);
        }

        private static void LambdaPrint(List<Complex> lambda)
        {
           for (int i = 0; i < lambda.Count; ++i)
            {
                if (lambda[i].I >= 0)
                    Console.WriteLine($"l{i} = {lambda[i].R} + {lambda[i].I}i");
                else
                    Console.WriteLine($"l{i} = {lambda[i].R} - {Math.Abs(lambda[i].I)}i");
            }
        }

        private static Matrix Arnoldi(Matrix A)
        {
            var n = A.mtx.Count();

            var q = new List<decimal>();
            q.Add(Convert.ToDecimal(0.78289));
            q.Add(Convert.ToDecimal(0.62216));

            for (int i = 0; i < n - 2; ++i)
                q.Add(0);

            var Q = new Matrix(n, n + 1);
            var H = new Matrix(n + 1, n);

            Q.SetColumn(0, q);

            Q.Print("Q");

            for (int i = 0; i < n; ++i)
            {
                var v = A * q;

                for (int j = 0; j < i + 1; ++j)
                {
                    H.mtx[j][i] = Vector.Scalar(Q.GetColumn(j), v);
                    v = Vector.SumVec(v, Vector.DigitOnVector(-1, Vector.DigitOnVector(H.mtx[j][i], Q.GetColumn(j))));
                }

                Vector.Print(v, "V");

                H.mtx[i + 1][i] = Vector.Norm(v);

                if (H.mtx[i + 1][i] == 0)
                    return null;

                H.Print("H");

                q = Vector.FindNormVec(v);
                //q = Vector.DigitOnVector(1 / H.mtx[i + 1][i], v);


                Q.SetColumn(i + 1, q);
                Q.Print("Q");

            }


            Q.Print("Result Q");
            H.Print("Result H");

            H.mtx.RemoveAt(H.mtx.Count - 1);
            --H.rows;
            //var H1 = new Matrix();

            //for (int i = 0; i < n; ++i)
            //{
            //    H1.mtx.Add(H.mtx[i]);
            //}

            H.Print("H1");

            return H;
        }

        private static Matrix QR(Matrix A)
        {
            var R = new Matrix(A);
            var Q = new Matrix(A.columns);
            Q.MakeUnitMatrix();

            for (int i = 0; i < R.rows - 1; i++)
            {
                var b = R.GetColumn(i);
                var v = CalcV(b, i);
                var H = HouseholderCalc(v);

                if (H == null)
                    return null;

                Q *= H;

                R = H * R;
            }


            //Q.Print("Q");
            //R.Print("R");

            return R * Q;
        }

        public static Matrix HouseholderCalc(List<decimal> v)
        {
            Matrix E = new Matrix(v.Count);
            E.MakeUnitMatrix();

            if (Vector.Scalar(v, v) == 0)
                return null;


            var koef = -2 / Vector.Scalar(v, v);

            Matrix H = E + koef * Vector.MultiplyVectors(v, v);

            return H;
        }

        public static decimal CalcNorm(List<decimal> b)
        {
            double norm = 0;

            foreach (var el in b)
                norm += Math.Pow(Convert.ToDouble(el), 2);

            norm = Math.Pow(norm, 0.5);

            return Convert.ToDecimal(norm);
        }

        public static List<decimal> CalcV(List<decimal> b, int i)
        {
            var e = new List<decimal>();
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

        private static void GenerateMatrix()
        {
            if (File.Exists("mtx.txt"))
                File.Delete("mtx.txt");

            var kek = new Random();

            Console.WriteLine("Size?");
            var n = Convert.ToInt16(Console.ReadLine());

            var mtx = new Matrix(n);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (kek.Next(10) % 3 == 0)
                    {
                        var next = kek.Next(-20, 20);
                        mtx.mtx[i][j] = next;
                        File.AppendAllText("mtx.txt", next.ToString());
                    }
                    else
                    {
                        mtx.mtx[i][j] = 0;
                        File.AppendAllText("mtx.txt", "0");
                    }

                    if (j != n - 1)
                        File.AppendAllText("mtx.txt", " ");

                }
                if (i != n - 1)
                    File.AppendAllText("mtx.txt", "\n");
            }

            mtx.Print("Generated new mtx");
        }
    }
}
