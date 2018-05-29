using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class SeidelMethod : SimpleIterationMethod
    {
        public SeidelMethod(Matrix m, double e) : base(m, e)
        {
        }

        protected override void IterationProcces()
        {
            var X = new List<double>();

            for (int k = 0; k < Beta.Count; ++k)
                X.Add(Beta[k]);

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

                for (int k = 0; k < X.Count; ++k)
                    X0[k] = X[k];

                X = SeidelIter(X);
                eps0 = CalcEps(Vector.SumVec(X, Vector.DigitOnVector(-1, X0)));
                Console.WriteLine("********************************");
            }

            sys.Solution = X;
            sys.PrintSolution();
        }

        private List<double> SeidelIter(List<double> x)
        {
            for (int i = 0; i < x.Count; ++i)
                x[i] = Beta[i] + Vector.Scalar(Alpha.mtx[i], x);

            return x;
        }

        
    }
}
