using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab3
{
    public static class Lagrange
    {
        static List<double> X = new List<double>();
        static List<double> Fi = new List<double>();
        static List<double> W = new List<double>();

        static double X_ = 0.0;

        public static void Start(string path)
        {
            Console.WriteLine("*****************************************");
            Parse(path);

            FillFi();
            FillW();

            MakePolynomial();
            Console.WriteLine("*****************************************");
        }

        private static void MakePolynomial()
        {
            string s = "L(x) = ";
            double L = 0;

            for (int i = 0; i < X.Count; ++i)
            {
                var tmp = Fi[i] / W[i];

                if (i == 0)
                    s += "[";
                else
                    s += "       [";

                s += tmp.ToString("0.000");

                for (int j = 0; j < X.Count; ++j)
                {
                    if (j == i)
                        continue;

                    s += "(x ";

                    if (X[j] > 0)
                    {
                        s += "- (";
                        s += X[j].ToString("0.000") + ")";
                    }

                    s += ")";

                    tmp *= (X_ - X[j]);
                }

                if (i == X.Count - 1)
                    s += "]";
                else
                    s += "] +\n";

                L += tmp;
            }

            Console.WriteLine(s + "\n");
            Console.WriteLine("L(" + X_ + ") = " + L);
            Console.WriteLine("y(" + X_ + ") = " + MyFun(X_));

            Console.WriteLine("delta(" + X_ + ") = " + Math.Abs(Math.Abs(L) - Math.Abs(MyFun(X_))));
        }

        private static void FillW()
        {
            for (int i = 0; i < X.Count; ++i)
            {
                double tmp = 1;

                for (int j = 0; j < X.Count; ++j)
                {
                    if (i == j)
                        continue;

                    tmp *= (X[i] - X[j]);
                }

                W.Add(tmp);
            }
        }

        private static void PrintList(List<double> fi)
        {
            foreach (var el in fi)
            {
                Console.WriteLine(el);
            }
        }

        private static void FillFi()
        {
            foreach (var x in X)
            {
                Fi.Add(MyFun(x));
            }
        }

        private static double MyFun(double x)
        {
            return 1 / Math.Tan(x) + x;
        }

        private static void Parse(string path)
        {
            var lines = File.ReadAllLines(path);

            var str = lines[0].Split(' ');
            X_ = Convert.ToDouble(lines[1]);

            foreach (var s in str)
                X.Add(Convert.ToDouble(s));

        }
    }
}
