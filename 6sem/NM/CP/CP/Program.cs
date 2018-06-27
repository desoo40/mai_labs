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
        static Matrix Q;
        static Matrix H;

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



                Arnoldi(A);
            }
        }

        private static void Arnoldi(Matrix A)
        {
            var n = A.mtx.Count();

            var q = new List<decimal>();
            q.Add(Convert.ToDecimal(0.78289));
            q.Add(Convert.ToDecimal(0.62216));

            for (int i = 0; i < n - 2; ++i)
                q.Add(0);

            Q = new Matrix(n, n + 1);
            H = new Matrix(n + 1, n);

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
                    return;

                H.Print("H");

                q = Vector.FindNormVec(v);
                //q = Vector.DigitOnVector(1 / H.mtx[i + 1][i], v);


                Q.SetColumn(i + 1, q);
                Q.Print("Q");

            }


            Q.Print("Result Q");
            H.Print("Result H");
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
