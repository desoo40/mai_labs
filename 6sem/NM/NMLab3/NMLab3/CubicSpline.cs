using NMlab1;
using System;
using System.Collections.Generic;
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
            //MakePolynomial();
            Console.WriteLine("*****************************************");


        }

        private static void MakeMatrixC()
        {
            CMtx = new Matrix(X.Count - 1, X.Count);

            for (int i = 0; i < CMtx.rows; ++i)
            {
                if (i == 0)
                {
                    CMtx.mtx[0][0] = 2 * (H[0] + H[1]);
                    CMtx.mtx[0][1] = H[1];

                    var tmp = (F[2] - F[1]) / H[1] - (F[1] - F[0]) / H[0];
                    CMtx.mtx[0][CMtx.columns - 1] = 3 * (tmp);
                }

                if (i == CMtx.rows - 1)
                {
                    CMtx.mtx[0][0] = 2 * (H[0] + H[1]);
                    CMtx.mtx[0][1] = H[1];

                    var tmp = (F[2] - F[1]) / H[1] - (F[1] - F[0]) / H[0];
                    CMtx.mtx[0][CMtx.columns - 1] = 3 * (tmp);
                }



            }

            CMtx.Print("lel");
        }

        private static void FillH()
        {
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
