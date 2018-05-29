using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class SimpleIterationMethod
    {
        protected LESystem sys;
        protected Matrix Alpha;
        protected List<double> Beta = new List<double>();
        protected double eps = 0;

        public SimpleIterationMethod(Matrix m, double e)
        {
            sys = new LESystem(m);
            eps = e;

            CalcBeta();
            CalcAlpha();
            Console.WriteLine("Alpha Matrix:");
            Alpha.Print();
            Console.WriteLine("Beta Vector:");
            PrintBeta();
            Console.WriteLine("Alpha measure:");
            Alpha.CalcMeasure();

            Console.WriteLine("||Alpha||c = " + Alpha.measure);

            if (Alpha.measure >= 1)
            {
                Console.WriteLine("Не выполнено достаточное условие сходимости метода");
                return;
            }

            Console.WriteLine("Выполнено достаточное условие сходимости метода");

            IterationProcces();
        }

        virtual protected void IterationProcces()
        {
            var X = Beta;
            var X0 = new List<double>();

            for (int i = 0; i < Beta.Count; ++i)
                X0.Add(0);

            var eps0 = CalcEps(Vector.SumVec(X, Vector.DigitOnVector(-1, X0)));

            Console.WriteLine("Start iterations:");

            for (int i = 0; eps0 > eps; ++i)
            {
                Console.WriteLine("Iteration #" + i + "\n");
                Console.WriteLine(eps0 + " > " + eps);
                Console.Write("X = (");

                for (int j = 0; j < X.Count; ++j)
                {
                    if (j + 1 == X.Count)
                        Console.Write("{0:0.00}", X[j]);
                    else
                        Console.Write("{0:0.00  }", X[j]);
                }
                Console.WriteLine(")");

                X0 = X;
                X = Vector.SumVec(Beta, Alpha * X);
                eps0 = CalcEps(Vector.SumVec(X, Vector.DigitOnVector(-1, X0)));
                Console.WriteLine("********************************");
            }

            sys.Solution = X;
            sys.PrintSolution();
        }

        virtual protected double CalcEps(List<double> list)
        {
            double max = 0;

            foreach(var el in list)
            {
                if (Math.Abs(el) > max)
                    max = Math.Abs(el);
            }

            return max;
        }

        private void PrintBeta()
        {
            foreach (var el in Beta)
            {
                Console.WriteLine(el);
            }
        }

        private void CalcAlpha()
        {
            var n = sys.Mtx.columns;

            Alpha = new Matrix(n);

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i == j)
                        continue;

                    Alpha.mtx[i][j] = - sys.Mtx.mtx[i][j] / sys.Mtx.mtx[i][i];
                }
            }
        }

        private void CalcBeta()
        {
            var n = sys.Mtx.columns;

            for (int i = 0; i < n; ++i)
                Beta.Add(sys.Right[i] / sys.Mtx.mtx[i][i]);
        }

        

       
    }

   
}

