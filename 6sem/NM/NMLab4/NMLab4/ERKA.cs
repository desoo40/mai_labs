using NMLab3;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab4
{
    public static class ERKA
    {
        static double h = 0;
        static double yOt1 = 1;
        static double y1Ot1 = 1;
        static double a = 1;
        static double b = 2;


        public static void Start()
        {
            Console.WriteLine("\nEnter step:");

            h = Convert.ToDouble(Console.ReadLine().Replace('.', ','));

            Console.WriteLine("\nEuler method:");
            Euler();
            RungeKuttaAndAdams();
        }

        private static void RungeKuttaAndAdams()
        {
            var steps = Convert.ToInt16((b - a) / h);

            var xk = a;
            var yk = yOt1;
            var zk = y1Ot1;

            #region
            Console.WriteLine("\nRunge-Kutta method:");

            var X = new List<double> { xk };
            var Xhalf = new List<double> { xk };
            var Y = new List<double> { yk };
            var Z = new List<double> { zk };
            var YIst = new List<double> { OriginalFunc(xk) };
            var Eps = new List<double>();

            for (int i = 0; i < steps; ++i)
            {
                var k1 = h * zk;
                var l1 = h * MyFunc(xk, zk);
                var k2 = h * (zk + 0.5 * l1);
                var l2 = h * MyFunc(xk + 0.5 * h, zk + 0.5 * l1);
                var k3 = h * (zk + 0.5 * l2);
                var l3 = h * MyFunc(xk + 0.5 * h, zk + 0.5 * l2);
                var k4 = h * (zk + l3);
                var l4 = h * MyFunc(xk + h, zk + l3);

                xk += h;
                yk += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
                zk += (l1 + 2 * l2 + 2 * l3 + l4) / 6;

                X.Add(xk);
                Y.Add(yk);
                Z.Add(zk);
                YIst.Add(OriginalFunc(xk));
            }

            var runge = h / 2;
            var rungeSteps = Convert.ToInt16((b - a) / runge);

            for (int i = 0; i <= rungeSteps; ++i)
            {
                var k1 = h * zk;
                var l1 = h * MyFunc(xk, zk);
                var k2 = h * (zk + 0.5 * l1);
                var l2 = h * MyFunc(xk + 0.5 * h, zk + 0.5 * l1);
                var k3 = h * (zk + 0.5 * l2);
                var l3 = h * MyFunc(xk + 0.5 * h, zk + 0.5 * l2);
                var k4 = h * (zk + l3);
                var l4 = h * MyFunc(xk + h, zk + l3);

                xk += h;
                yk += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
                zk += (l1 + 2 * l2 + 2 * l3 + l4) / 6;

                if (i % 2 == 0)
                    Xhalf.Add(yk);
            }

            var Acc = new List<double>();

            for (int i = 0; i < X.Count; ++i)
            {
                Acc.Add(YIst[i] - Y[i]);
                Eps.Add((X[i] - Xhalf[i]) / (2 * 2 - 1));
            }

            var ll = new List<List<double>>();
            var ss = new List<string>();

            ll.Add(X);
            ss.Add("X");
            ll.Add(Y);
            ss.Add("Y");
            ll.Add(Z);
            ss.Add("Z");
            ll.Add(YIst);
            ss.Add("YIst");
            ll.Add(Acc);
            ss.Add("YIst-Y");
            ll.Add(Eps);
            ss.Add("Runge Eps");

            ListHelper.PrintTable(ll, ss);
            #endregion

            Console.WriteLine("\nAdams method:");

            xk = X[2];
            yk = Y[2];
            zk = Z[2];

            for (int i = 3; i < steps; ++i)
            {

                zk += h / 24 * (55 * MyFunc(X[i], Z[i]) -
                             59 * MyFunc(X[i - 1], Z[i - 1]) +
                             37 * MyFunc(X[i - 2], Z[i - 2]) -
                             9 * MyFunc(X[i - 3], Z[i - 3]));

                yk += h / 24 * (55 * Z[i] - 59 * Z[i - 1] +
                                  37 * Z[i - 2] - 9 * Z[i - 3]);

                xk += h;

                X[i] = xk;
                Y[i] = yk;
                Z[i] = zk;
            }

            Acc = new List<double>();

            for (int i = 0; i < X.Count; ++i)
                Acc.Add(YIst[i] - Y[i]);

            ll = new List<List<double>>();
            ss = new List<string>();

            ll.Add(X);
            ss.Add("X");
            ll.Add(Y);
            ss.Add("Y");
            ll.Add(Z);
            ss.Add("Z");
            ll.Add(YIst);
            ss.Add("YIst");
            ll.Add(Acc);
            ss.Add("YIst-Y");

            ListHelper.PrintTable(ll, ss);
        }

        private static void Euler()
        {
            var steps = Convert.ToInt16((b - a) / h);

            var xk = a;
            var yk = yOt1;
            var y1k = y1Ot1;


            var X = new List<double> { xk };
            var Xhalf = new List<double> { xk };
            var Y = new List<double> { yk };
            var YIst = new List<double> { OriginalFunc(xk) };
            var Eps = new List<double>();

            for (int i = 0; i < steps; ++i)
            {
                y1k += h * MyFunc(xk, y1k);
                yk += h * y1k;
                xk += h;

                X.Add(xk);
                Y.Add(yk);
                YIst.Add(OriginalFunc(xk));
            }

            var runge = h / 2;
            var rungeSteps = Convert.ToInt16((b - a) / runge);

            for (int i = 0; i <= rungeSteps; ++i)
            {
                y1k += runge * MyFunc(xk, y1k);
                yk += runge * y1k;
                xk += runge;
                if (i % 2 == 0)
                    Xhalf.Add(yk);
            }

            var Acc = new List<double>();

            for (int i = 0; i < X.Count; ++i)
            {
                Acc.Add(YIst[i] - Y[i]);
                Eps.Add((X[i] - Xhalf[i]) / (2 * 2 - 1));
            }

            var ll = new List<List<double>>();
            var ss = new List<string>();

            ll.Add(X);
            ss.Add("X");
            ll.Add(Y);
            ss.Add("Y");
            ll.Add(YIst);
            ss.Add("YIst");
            ll.Add(Acc);
            ss.Add("YIst-Y");
            ll.Add(Eps);
            ss.Add("Runge Eps");

            ListHelper.PrintTable(ll, ss);

            //ListHelper.Print(X, "X");
            //ListHelper.Print(Y, "Y");
            //ListHelper.Print(YIst, "YIst");


        }

        private static double OriginalFunc(double x)
        {
            return 1.0 + Math.Log(Math.Abs(x));
        }

        private static double MyFunc(double x, double y1)
        {
            return - y1 / x;
        }
    }
}
