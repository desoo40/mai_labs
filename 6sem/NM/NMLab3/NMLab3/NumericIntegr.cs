using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab3
{
    public static class NumericIntegr
    {
        static double X0 = 0.0;
        static double Xk = 0.0;
        static double H1 = 0.0;
        static double H2 = 0.0;

        public static void Start(string path)
        {
            Console.WriteLine("*****************************************");
            Parse(path);

            double rect1 = RectangleMethod(H1);
            double trap1 = TrapezMethod(H1);
            double simps1 = SimpsonMethod(H1);

            Console.WriteLine("Step = " + H1);
            Console.WriteLine("Rectangle = " + rect1);
            Console.WriteLine("Trapez = " + trap1);
            Console.WriteLine("Simpson = " + simps1);
            Console.WriteLine();

            double rect2 = RectangleMethod(H2);
            double trap2 = TrapezMethod(H2);
            double simps2 = SimpsonMethod(H2);

            Console.WriteLine("Step = " + H2);
            Console.WriteLine("Rectangle = " + rect2);
            Console.WriteLine("Trapez = " + trap2);
            Console.WriteLine("Simpson = " + simps2);
            Console.WriteLine();

            Console.WriteLine("Runge-Romberg-Richardson method adjustment:");

            Console.WriteLine("Rectangle");
            RRR(rect1, rect2, 1);
            Console.WriteLine("Trapez");
            RRR(trap1, trap2, 2);
            Console.WriteLine("Simpson");
            RRR(simps1, simps2, 4);

            Console.WriteLine("*****************************************");
        }

        private static void RRR(double x1, double x2, int p)
        {
            var k = 0.0;
            var rrr = 0.0;

            if (H1 >= H2)
            {
                k = H1 / H2;
                rrr = (x2 - x1) / (Math.Pow(k, p) - 1);
            }
            else
            {
                k = H2 / H1;
                rrr = (x1 - x2) / (Math.Pow(k, p) - 1);
            }                


            Console.WriteLine(rrr);
        }

        private static double SimpsonMethod(double h)
        {
            Console.WriteLine("Simpson method with step " + h + "\n");

            var x = SplitX(h);
            var y = FindY(x);

            ListHelper.Print(x, "X");
            ListHelper.Print(y, "Y");

            var steps = (Xk - X0) / h + 1;
            double ans = 0;

            ans += h / 3 * y[0];

            var simps = new List<double>{ans};

            for (int i = 1; i < steps - 1; ++i)
            {
                if (i % 2 == 0)
                {
                    ans += h / 3 * y[i] * 2;
                    simps.Add(ans);
                }
                else
                { 
                    ans += h / 3 * y[i] * 4;
                    simps.Add(ans);
                }
            }

            ans += h / 3 * y[y.Count - 1];
            simps.Add(ans);

            ListHelper.Print(simps, "Simpson");

            return ans;
        }

        private static double TrapezMethod(double h)
        {
            Console.WriteLine("Trapez method with step " + h + "\n");

            var x = SplitX(h);
            var y = FindY(x);

            ListHelper.Print(x, "X");
            ListHelper.Print(y, "Y");

            var steps = (Xk - X0) / h + 1;
            double ans = 0;

            var trap = new List<double>();

            trap.Add(ans);


            for (int i = 1; i < steps; i++)
            {
                ans += h / 2 * (y[i - 1] + y[i]);
                trap.Add(ans);
            }

            ListHelper.Print(trap, "Trapez");
            return ans;
        }

        private static double RectangleMethod(double h)
        {
            Console.WriteLine("Recatangle method with step " + h + "\n");

            var x = SplitX(h);
            var y = FindY(x);

            ListHelper.Print(x, "X");
            ListHelper.Print(y, "Y");

            var steps = (Xk - X0) / h + 1;
            double ans = 0;

            var rect = new List<double>();

            rect.Add(ans);


            for (int i = 1; i < steps; i++)
            {
                ans += MyFunc((x[i - 1] + x[i]) / 2) * h;
               rect.Add(ans);
            }

            ListHelper.Print(rect, "Rectangle");
            return ans;
        }

        private static List<double> FindY(List<double> x)
        {
            var Y = new List<double>();

            foreach (var el in x)
                Y.Add(MyFunc(el));

            return Y;
        }

        private static List<double> SplitX(double h)
        {
            var steps = (Xk - X0) / h + 1;
            var X = new List<double>();

            for (int i = 0; i < steps; i++)
                X.Add(X0 + h * i);

            return X;
        }

        private static double MyFunc(double x)
        {
            return x / (Math.Pow(x, 4) + 81);
        }

        private static void CalcInterg()
        {

        }

        private static void Parse(string path)
        {
            var lines = File.ReadAllLines(path);

            X0 = Convert.ToDouble(lines[0]);
            Xk = Convert.ToDouble(lines[1]);
            H1 = Convert.ToDouble(lines[2]);
            H2 = Convert.ToDouble(lines[3]);
        }
    }
}
