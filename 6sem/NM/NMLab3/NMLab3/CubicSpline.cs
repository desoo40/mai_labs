using NMlab1;
using System;
using System.Collections.Generic;
using System.ComponentModel.Design.Serialization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab3
{
    public static class CubicSpline
    {
        static List<double> X = new List<double>();
        static List<double> F = new List<double>();
        static List<double> A = new List<double>();
        static List<double> B = new List<double>();
        static List<double> C = new List<double>();
        static List<double> D = new List<double>();
        static List<double> H = new List<double>();

        static Matrix CMtx;


        static double X_ = 0.0;

        public static void Start(string path)
        {
            Console.WriteLine("*****************************************");
            Parse(path);

            FillH();
            MakeMatrixC();

            var ans = ThomasAlgorythm.TA(CMtx);

            C = ans;

            C.Insert(0, 0.0);
            C.Insert(0, 0.0);


            FillUnknown();

            MakePolynomial();
            Console.WriteLine("*****************************************");


        }

        private static void MakePolynomial()
        {
            var iForX = 0;
            var iRight = 0;

            for (int i = 1; i < X.Count; i++)
            {
                if (X[i - 1] <= X_ && X[i] >= X_)
                {
                    iForX = i;
                    iRight = i - 1;
                    break;
                }
            }

            Console.WriteLine($"\nX[{iForX}-1] = {X[iForX - 1]} <= X = {X_} <= X[{iForX}] = {X[iForX]}\ni = {iForX}\n");

            Console.WriteLine($"A[{iForX}] = {A[iRight]}");
            Console.WriteLine($"B[{iForX}] = {B[iRight]}");
            Console.WriteLine($"C[{iForX}] = {C[iRight]}");
            Console.WriteLine($"D[{iForX}] = {D[iRight]}");

            var xTmp = X_ - X[iForX - 1];

            var ans0 = A[iRight];
            var ans1 = B[iRight] * xTmp;
            var ans2 = C[iRight] * Math.Pow(xTmp, 2);
            var ans3 = D[iRight] * Math.Pow(xTmp, 3);

            var ans = ans0 + ans1 + ans2 + ans3;

            Console.WriteLine($"\nF({X_}) = {ans}");
        }

        private static void FillUnknown()
        {
            var n = X.Count;
            for (int i = 1; i < n; i++)
                A.Add(F[i - 1]);

            for (int i = 1; i < n - 1; i++)
            {
                B.Add((F[i] - F[i-1]) / H[i] - H[i]*(C[i+1] + 2 * C[i]) / 3.0);
                D.Add((C[i + 1] - C[i]) / (3 * H[i]));
            }


            B.Add((F[n - 1] - F[n - 2]) / H[n - 1] - H[n - 1] * C[n - 1] * 2.0 / 3.0);
            D.Add(- C[n - 1] / (3 * H[n - 1]));

            C.RemoveAt(0);
        }

        private static void MakeMatrixC()
        {
            CMtx = new Matrix(X.Count - 2, X.Count - 1);

            // H здесь номер берется как в методичке, у всех остальных переменных i сдвигается на один меньше


            CMtx.mtx[0][0] = 2 * (H[1] + H[2]);
            CMtx.mtx[0][1] = H[2];

            var tmp1 = (F[2] - F[1]) / H[2] - (F[1] - F[0]) / H[1];
            CMtx.mtx[0][CMtx.columns - 1] = 3 * (tmp1);

            //for (int i = 1; i < n; ++i)
            //{
            //    // однако тут у  H на один больше, т.к. i с нуля...
            //  я запутался в индексах и спустился до такого...
            CMtx.mtx[1][0] = H[2];
            CMtx.mtx[1][1] = 2 * (H[2] + H[3]);
            CMtx.mtx[1][2] = H[3];

            var tmp2 = (F[3] - F[2]) / H[3] - (F[2] - F[1]) / H[2];
            CMtx.mtx[1][3] = 3 * (tmp2);
            //}

            CMtx.mtx[2][1] = H[3];
            CMtx.mtx[2][2] = 2 * (H[3] + H[4]);

            var tmp3 = (F[4] - F[3]) / H[4] - (F[3] - F[2]) / H[3];
            CMtx.mtx[2][3] = 3 * (tmp3);
        }

        private static void FillH()
        {
            H.Add(0);

            for (int i = 1; i < X.Count; ++i)
                H.Add(X[i] - X[i - 1]);
        }

        private static void Parse(string path)
        {
            var lines = File.ReadAllLines(path);

            var str1 = lines[0].Split(' ');
            var str2 = lines[1].Split(' ');
            

            foreach (var s in str1)
                X.Add(Convert.ToDouble(s));

            foreach (var s in str2)
                F.Add(Convert.ToDouble(s));

            X_ = Convert.ToDouble(lines[2]);
        }
    }
}
