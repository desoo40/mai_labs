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
    public static class LeastSquares
    {
        static List<double> X = new List<double>();
        static List<double> Y = new List<double>();
        static List<double> A1 = new List<double>();
        static List<double> A2 = new List<double>();


        static List<double> F1 = new List<double>();
        static List<double> F2 = new List<double>();


        public static void Start(string path)
        {
            Console.WriteLine("*****************************************");
            Parse(path);

            ListHelper.Print(X, "X");
            ListHelper.Print(Y, "Y");

            Console.WriteLine("Find First power polynome: ");

            FindFirstPower();
            Console.WriteLine("Find Second power polynome: ");

            FindSecondPower();
            Console.WriteLine("*****************************************");

        }
        private static void FindFirstPower()
        {
            var A = new Matrix(2, 3);

            

            A.mtx[0][0] = X.Count;
            A.mtx[0][1] = FindSum("X", 1);
            A.mtx[0][2] = FindSum("Y", 1);
            A.mtx[1][0] = FindSum("X", 1);
            A.mtx[1][1] = FindSum("X", 2);
            A.mtx[1][2] = FindSum("XY", 1);

            A.Print("AAA");

            var aSys = new LESystem(A);

            var sol = new LUDecomposition(aSys);

            sol.LU_Algorithm();
            A1 = aSys.Solution;

            ListHelper.Print(A1, "A1");
            FillF1();
            ListHelper.Print(F1, "F1");
            //foreach (var el in F1)
            //{
            //    Console.WriteLine(el);
            //}

            var bigF = 0.0;

            for (int i = 0; i < X.Count; i++)
                bigF += Math.Pow(F1[i] - Y[i], 2);



            Console.WriteLine("Sum of quadro error: " + bigF + "\n");
        }

        private static void FillF1()
        {
            for (int i = 0; i < X.Count; i++)
            {
                F1.Add(A1[0] + A1[1] * X[i]);
            }
        }

        private static double FindSum(string s, int i)
        {
            double sum = 0.0;

            if (s == "X")
            {
                for (int j = 0; j < X.Count; j++)
                    sum += Math.Pow(X[j], i);
            }

            if (s == "Y")
            {
                for (int j = 0; j < X.Count; j++)
                    sum += Math.Pow(Y[j], i);
            }

            if (s == "XY")
            {
                for (int j = 0; j < X.Count; j++)
                {
                    sum += Y[j] * Math.Pow(X[j], i);
                }
            }

            return sum;
        }
    


        private static void FindSecondPower()
        {
            var A = new Matrix(3, 4);

            A.mtx[0][0] = X.Count;
            A.mtx[0][1] = FindSum("X", 1);
            A.mtx[0][2] = FindSum("X", 2);
            A.mtx[0][3] = FindSum("Y", 1);
            A.mtx[1][0] = FindSum("X", 1);
            A.mtx[1][1] = FindSum("X", 2);
            A.mtx[1][2] = FindSum("X", 3);
            A.mtx[1][3] = FindSum("XY", 1);
            A.mtx[2][0] = FindSum("X", 2);
            A.mtx[2][1] = FindSum("X", 3);
            A.mtx[2][2] = FindSum("X", 4);
            A.mtx[2][3] = FindSum("XY", 2);

            A.Print("AAAA");

            var aSys = new LESystem(A);

            var sol = new LUDecomposition(aSys);

            sol.LU_Algorithm();
            A2 = aSys.Solution;

            ListHelper.Print(A2, "A2");
            FillF2();
            ListHelper.Print(F2, "F2");
            //foreach (var el in F1)
            //{
            //    Console.WriteLine(el);
            //}

            var bigF = 0.0;

            for (int i = 0; i < X.Count; i++)
                bigF += Math.Pow(F2[i] - Y[i], 2);



            Console.WriteLine("Sum of quadro error: " + bigF + "\n");
        }

        private static void FillF2()
        {
            for (int i = 0; i < X.Count; i++)
                F2.Add(A2[0] + A2[1] * X[i] + A2[2] * X[i] * X[i]);
        }

        private static void Parse(string path)
        {
            var lines = File.ReadAllLines(path);

            var str = lines[0].Split(' ');
            var str1 = lines[1].Split(' ');

            foreach (var s in str)
                X.Add(Convert.ToDouble(s));

            foreach (var s in str1)
                Y.Add(Convert.ToDouble(s));
        }
    }
}
