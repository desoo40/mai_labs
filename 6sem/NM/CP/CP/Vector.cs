using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    static class Vector
    {
        public static List<decimal> DigitOnVector(decimal d, List<decimal> right)
        {
            var res = new List<decimal>();

            foreach (var el in right)
                res.Add(d * el);

            return res;
        }

        public static List<decimal> SumVec(List<decimal> left, List<decimal> right)
        {
            if (left.Count != right.Count)
            {
                Console.WriteLine("Несовместимые векторы");
                return null;
            }

            var res = new List<decimal>();

            for (int i = 0; i < left.Count; ++i)
                res.Add(left[i] + right[i]);

            return res;
        }

        internal static void Print(List<decimal> q, string str = " ")
        {
            Console.WriteLine(str);
            Console.WriteLine("********************************");

            foreach (var el in q)
                Console.WriteLine(el);

            Console.WriteLine("********************************");
        }

        public static decimal Scalar(List<decimal> a, List<decimal> x)
        {
            decimal res = 0;

            for (int i = 0; i < a.Count; ++i)
                res += a[i] * x[i];

            return res;
        }

        public static Matrix MultiplyVectors(List<decimal> left, List<decimal> right)
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

        public static decimal Norm(List<decimal> l)
        {
            //var norm = new List<decimal>();

            decimal sum = 0;

            foreach (var el in l)
                sum += el * el;

            var mod = (decimal)Math.Sqrt((double)sum);

            //foreach (var el in l)
            //    norm.Add(el / mod);

            return mod;
        }

        public static List<decimal> FindNormVec(List<decimal> l)
        {
            var norm = new List<decimal>();

            decimal sum = 0;

            foreach (var el in l)
                sum += el * el;

            var mod = (decimal)Math.Sqrt((double)sum);

            if (mod == 0)
                return l;

            foreach (var el in l)
                norm.Add(el / mod);

            return norm;
        }
    }
}
