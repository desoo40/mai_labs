using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class LESystem
    {
        public Matrix Mtx;
        public List<double> Right;
        public List<double> Solution;

        public LESystem(Matrix big)
        {
            var r = big.rows;
            var c = big.columns;

            Mtx = new Matrix(r, c - 1);
            Right = new List<double>();

            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    if (j == c - 1)
                    {
                        Right.Add(big.GetElement(i, j));
                        continue;
                    }

                    Mtx.SetElement(i, j, big.GetElement(i, j));
                }
            }
        }

        public LESystem(Matrix m, List<double> l)
        {
            Mtx = m;
            Right = l;
        }

        public void PrintRight()
        {
            foreach (var el in Right)
            {
                Console.WriteLine(el);
            }
        }

        public void PrintSolution()
        {
            Console.WriteLine("Solution:");

            for (var el = 1; el <= Solution.Count; ++el)
            {
                Console.Write("X" + el + " = ");
                Console.WriteLine("{0:0.00}", Solution[el - 1]);
            }
        }
    }

}
