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
