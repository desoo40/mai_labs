using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class LUDecomposition
    {
        public Matrix Mtx;
        public Matrix L;
        public Matrix U;

        public List<double> Right;
        public List<double> Solution;


        public LUDecomposition(Matrix big)
        {
            var r = big.rows;
            var c = big.columns;

            Mtx = new Matrix(r, c - 1);
            Right = new List<double>();

            for(int i = 0; i < r; ++i)
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

        public LUDecomposition(Matrix stand, List<double> right)
        {
            Mtx = stand;
            Right = right;
        }

        public void PrintRight()
        {
            foreach(var el in Right)
            {
                Console.WriteLine(el);
            }
        }

        public void FindSolution()
        {
            var n = U.columns;
            Solution = new List<double>();

            for (int i = 0; i < n; ++i)
                Solution.Add(0);

            for (int i = n - 1; i >= 0; --i)
            {
                if (i == n - 1)
                {
                    Solution[i] = Right[i] / U.GetElement(i, i);
                    continue;
                }

                double sum = 0;

                for (int j = i + 1; j < n; ++j)
                    sum += U.GetElement(i, j) * Solution[j];

                Solution[i] = (Right[i] - sum) / U.GetElement(i, i);
            }
        }

        public void LU_Algorithm()
        {
            var n = Mtx.columns;
            U = new Matrix(Mtx);

            L = new Matrix(n);

            for (int j = 0; j < n; ++j)
            {

                for (int i = j + 1; i < n; ++i)
                {

                    L.SetElement(i, j, U.GetElement(i, j) / U.GetElement(j, j));

                    for (int k = j; k < n; ++k)
                    {
                        U.SetElement(i, k, U.GetElement(i, k) - U.GetElement(j, k) * L.GetElement(i, j));
                    }
                }
            }

            //Console.WriteLine("L Matrix:");
            //L.Print();
            //Console.WriteLine("U Matrix:");
            //U.Print();



            for (int i = 0; i < n; ++i)
            {
                double sum = 0;

                for (int j = 0; j < i; ++j)
                    sum += L.GetElement(i, j) * Right[j];

                Right[i] -= sum;
            }

            //Console.WriteLine("Right side:");
            //PrintRight();


            FindSolution();
        }

        public void PrintSolution()
        {
            Console.WriteLine("Solution:");

            for (var el = 1; el <= Solution.Count; ++el)
            {
                Console.WriteLine("X" + el + " = " + Solution[el - 1]);
            }
        }

        public void FindDeter()
        {
            U.det = 1;

            for (int i = 0; i < U.columns; ++i)
            {
                U.det *= U.GetElement(i, i);
            }

            Console.WriteLine("Deter:");
            Console.WriteLine(U.det);
        }

        public void FindInvertMtx()
        {
            var n = Mtx.columns;
            var InvertMtx = new Matrix(n);

            for (int i = 0; i < n; ++i)
            {
                var tempList = new List<double>();

                for (int j = 0; j < n; ++j)
                {
                    if (j == i)
                        tempList.Add(1);
                    else
                        tempList.Add(0);

                }


                var tempSys = new LUDecomposition(Mtx, tempList);
                tempSys.LU_Algorithm();
                
                for (int j = 0; j < n; ++j)
                    InvertMtx.SetElement(j, i, tempSys.Solution[j]);
            }
            Console.WriteLine("Invert mtx:");
            InvertMtx.Print();

        }
    }
}
