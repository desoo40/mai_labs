using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab3
{
    public static class NumericDiff
    {
        static List<double> X = new List<double>();
        static List<double> Y = new List<double>();
        static double X_ = 0.0;

        public static void Start(string path)
        {
            Console.WriteLine("*****************************************");
            Parse(path);

            int i = FindNum();

            double left = CalcLeftSide(i);
            double right = CalcRightSide(i);
            double halfSum = (left + right) / 2;
            double secondAccuracy = CalcSecondAccuracy(i, left, right);
            double secondDerivative = CalcSecondDerivative(i, left, right);



            Console.WriteLine("Left side derivative:    " + left);
            Console.WriteLine("Right side derivative:    " + right);
            Console.WriteLine("Half-sum of left and right:    " + halfSum);
            Console.WriteLine("Second order of accuracy derivative:    " + secondAccuracy);
            Console.WriteLine("Second derivative:    " + secondDerivative);


            Console.WriteLine("*****************************************");

            Console.WriteLine("*****************************************");
            Console.WriteLine("By five dots:");
            var KF = CalcKoef();
            ByFiveDots(KF);
        }

        private static void ByFiveDots(List<double> kF)
        {
            var fd = FirstDirByFive(kF);

            Console.WriteLine("First");
            Console.WriteLine(fd);

            var sd = SecondDirByFive(kF);

            Console.WriteLine("Second");
            Console.WriteLine(sd/2.45);
        }

        private static double FirstDirByFive(List<double> kF)
        {
            var sum1 = kF[1] * ((X_ - X[0]) + (X_ - X[1]));
            var sum2 = kF[2] * ((X_ - X[0]) * (X_ - X[1]) + (X_ - X[0]) * (X_ - X[2]) + (X_ - X[1]) * (X_ - X[2]));
            var sum3 = kF[2] * kF[3] * ((X_ - X[0]) * (X_ - X[1]) * (X_ - X[2]) +
                                (X_ - X[0]) * (X_ - X[1]) * (X_ - X[3]) +
                                (X_ - X[0]) * (X_ - X[2]) * (X_ - X[3]) +
                                (X_ - X[1]) * (X_ - X[2]) * (X_ - X[3]));

            return kF[0] + sum1 + sum2 + sum3;
        }

        private static double SecondDirByFive(List<double> kF)
        {
            var sum1 = -kF[2] * 2 * (-3 * X_ + X[0] + X[1] + X[2]);
            var sum2 = kF[3] * 2 * (X[2] * (X[3] - 3 * X_ + X[0] + X[1]) +
                                    X[3] * (-3 * X_ + X[0] + X[1]) + 6 * X_ * X_ - 3 * X_ * X[0] -
                                    3 * X_ * X[1] + X[0] * X[1]);

            return 2 * kF[1] + sum1 + sum2;
        }

        private static double DividedDifference(List<List<double>> l, int j)
        {
            if (l[0].Count < 2)
                return 0.0;

            if (l[0].Count == 2)
                return (l[1][0] - l[1][1]) / (l[0][0] - l[0][1]);

            var f = new List<List<double>>();

            f.Add(new List<double>());
            f.Add(new List<double>());

            var s = new List<List<double>>();

            s.Add(new List<double>());
            s.Add(new List<double>());


            for (int i = 0; i < l[0].Count - 1; ++i)
            {
                f[0].Add(l[0][i]);
                f[1].Add(l[1][i]);
            }

            for (int i = 1; i < l[0].Count; ++i)
            {
                s[0].Add(l[0][i]);
                s[1].Add(l[1][i]);
            }

            return (DividedDifference(f, j) - DividedDifference(s, j + 1)) / (l[0][0] - l[0][l.Count - 1]);
        }

        private static List<double> CalcKoef()
        {
            List<double> KF = new List<double>();

            for (int i = 0; i < X.Count; ++i)
            {
                if (i == 0)
                    continue;

                var l = MakeLists(i);

                if (i == 1)
                {
                    l[0].Reverse();
                    l[1].Reverse();
                }

                var DD = DividedDifference(l, i);
                KF.Add(DD);
            }
            return KF;
        }

        private static List<List<double>> MakeLists(int i)
        {
            var l = new List<List<double>>();

            l.Add(new List<double>());
            l.Add(new List<double>());


            for (int j = 0; j <= i; ++j)
            {
                l[0].Add(X[j]);
                l[1].Add(Y[j]);
            }

            return l;
        }

        private static double CalcSecondDerivative(int i, double left, double right)
        {
            return 2 * ((right - left) / (X[3] - X[1]));
        }

        private static double CalcSecondAccuracy(int i, double left, double right)
        {
            return left + (right - left) / (X[3] - X[1]) * (2 * X_ - X[1] - X[2]);
        }


        private static double CalcRightSide(int i)
        {
            return (Y[i + 1] - Y[i]) / (X[i + 1] - X[i]);
        }

        private static double CalcLeftSide(int i)
        {
            return (Y[i] - Y[i - 1]) / (X[i] - X[i - 1]);
        }

        private static int FindNum()
        {
            int i = 0;

            for (int j = 0; j < X.Count; j++)
            {
                if (X_ == X[j])
                    i = j;
            }

            return i;
        }


        private static void Parse(string path)
        {
            var lines = File.ReadAllLines(path);

            var str = lines[0].Split(' ');
            var str1 = lines[1].Split(' ');

            X_ = Convert.ToDouble(lines[2]);

            foreach (var s in str)
                X.Add(Convert.ToDouble(s));

            foreach (var s in str1)
                Y.Add(Convert.ToDouble(s));

        }
    }
}
