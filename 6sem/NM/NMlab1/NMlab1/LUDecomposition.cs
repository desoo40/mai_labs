using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class LUDecomposition
    {
        public LESystem Sys;
        public Matrix L;
        public Matrix U;


        public LUDecomposition(LESystem s)
        {
            Sys = s;
        }

        public LUDecomposition(Matrix stand, List<double> right)
        {
            Sys = new LESystem(stand, right);
        }

        

        public void FindSolution()
        {
            var n = U.columns;
            Sys.Solution = new List<double>();

            for (int i = 0; i < n; ++i)
                Sys.Solution.Add(0);

            for (int i = n - 1; i >= 0; --i)
            {
                if (i == n - 1)
                {
                    Sys.Solution[i] = Sys.Right[i] / U.GetElement(i, i);
                    continue;
                }

                double sum = 0;

                for (int j = i + 1; j < n; ++j)
                    sum += U.GetElement(i, j) * Sys.Solution[j];

                Sys.Solution[i] = (Sys.Right[i] - sum) / U.GetElement(i, i);
            }
        }

        public void LU_Algorithm()
        {
            var n = Sys.Mtx.columns;
            U = new Matrix(Sys.Mtx);

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
                    sum += L.GetElement(i, j) * Sys.Right[j];

                Sys.Right[i] -= sum;
            }

            //Console.WriteLine("Right side:");
            //PrintRight();


            FindSolution();
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
            var n = Sys.Mtx.columns;
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


                var tempSys = new LESystem(Sys.Mtx, tempList);
                var tempLU = new LUDecomposition(tempSys);
                tempLU.LU_Algorithm();

                for (int j = 0; j < n; ++j)
                {
                    //InvertMtx.SetElement(j, i, tempSys.Solution[j]);
                    InvertMtx.mtx[j][i] = tempSys.Solution[j];
                }
            }
            Console.WriteLine("Invert mtx:");
            InvertMtx.Print();

        }
    }
}
