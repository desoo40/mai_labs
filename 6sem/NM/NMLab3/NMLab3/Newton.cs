using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab3
{
    public static class Newton
    {
        static List<double> X = new List<double>();
        static List<double> Fi = new List<double>();

        static double X_ = 0.0;

        public static void Start(string path)
        {
            Console.WriteLine("*****************************************");
            Parse(path);

            FillFi();

            MakePolynomial();
            Console.WriteLine("*****************************************");



        }


        private static double DividedDifference(List<double> l)
        {
            if (l.Count < 2)
                return 0.0;

            if (l.Count == 2)
                return (MyFun(l[0]) - MyFun(l[1])) / (l[0] - l[1]);

            var f = new List<double>();
            var s = new List<double>();

            for (int i = 0; i < l.Count - 1; ++i)
                f.Add(l[i]);

            for (int i = 1; i < l.Count; ++i)
                s.Add(l[i]);

            return (DividedDifference(f) - DividedDifference(s)) / (l[0] - l[l.Count - 1]);
        }

        private static void MakePolynomial()
        {
            string s = "P(x) = ";
            double P = 0;

            for (int i = 0; i < X.Count; ++i)
            {
                if (i == 0)
                {
                    s += MyFun(X[i]).ToString("0.000") + " + ";

                    P += MyFun(X[i]);
                    continue;
                }

                var tmp = 1.0;

                var l = MakeList(i);

                if (i == 1)
                    l.Reverse();

                var DD = DividedDifference(l);

                s += "(" + DD.ToString("0.000");

                tmp *= DD;

                for (int j = 0; j < i; ++j)
                {
                    s += "(x - " + X[j].ToString("0.000") + ")";
                    tmp *= (X_ - X[j]);
                }

                s += ")";

                if (i != X.Count - 1)
                    s += " + ";

                P += tmp;
            }

            Console.WriteLine(s + "\n");
            Console.WriteLine("P(" + X_ + ") = " + P);
            Console.WriteLine("y(" + X_ + ") = " + MyFun(X_));

            Console.WriteLine("delta(" + X_ + ") = " + Math.Abs(Math.Abs(P) - Math.Abs(MyFun(X_))));
        }

        private static List<double> MakeList(int i)
        {
            var l = new List<double>();

            for (int j = 0; j <= i; ++j)
                l.Add(X[j]);

            return l;
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
