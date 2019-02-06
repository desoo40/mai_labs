using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    static class Vector
    {
        public static List<double> DigitOnVector(double d, List<double> right)
        {
            var res = new List<double>();

            foreach (var el in right)
                res.Add(d * el);

            return res;
        }

        public static void Print(List<double> right, string s = "")
        {
            Console.WriteLine($"Vector {s}:");
            Console.WriteLine("********************************");


            foreach (var el in right)
                Console.WriteLine(el);

            Console.WriteLine("********************************");
        }

        public static List<double> SumVec(List<double> left, List<double> right)
        {
            if (left.Count != right.Count)
            {
                Console.WriteLine("Несовместимые векторы");
                return null;
            }

            var res = new List<double>();

            for (int i = 0; i < left.Count; ++i)
                res.Add(left[i] + right[i]);

            return res;
        }
        public static double Scalar(List<double> a, List<double> x)
        {
            double res = 0;

            for (int i = 0; i < a.Count; ++i)
                res += a[i] * x[i];

            return res;
        }

        public static Matrix MultiplyVectors(List<double> left, List<double> right)
        {
            if (left.Count != right.Count)
            {
                Console.WriteLine("Несовместимые векторы!");
                return null;
            }

            var res = new Matrix(left.Count);

            for (int i = 0; i < left.Count; i++)
            {
                for (int j = 0; j < right.Count; j++)
                {
                    res.mtx[i][j] = left[i] * right[j];
                }
            }

            return res;
        }
    }
}
