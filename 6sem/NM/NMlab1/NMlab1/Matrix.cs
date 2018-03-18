using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class Matrix
    {

        public List<List<double>> mtx = new List<List<double>>();
        public int rows;
        public int columns;
        public double det;

        public Matrix ()
        {
            rows = 0;
            columns = 0;
        }

        public Matrix(int a, int b)
        {
            rows = a;
            columns = b;


            for (int i = 0; i < a; ++i) 
            {
                mtx.Add(new List<double>());

                for (int j = 0; j < b; ++j)
                    mtx[i].Add(0);
                
            }

        }

        public Matrix(int a)
        {
            rows = a;
            columns = a;


            for (int i = 0; i < a; ++i)
            {
                mtx.Add(new List<double>());

                for (int j = 0; j < a; ++j)
                    mtx[i].Add(0);

            }

        }

        public Matrix(Matrix m)
        {
            rows = m.rows;
            columns = m.columns;

            for (int i = 0; i < rows; ++i)
            {
                mtx.Add(new List<double>());

                for (int j = 0; j < columns; ++j)
                    mtx[i].Add(m.GetElement(i, j));

            }
        }

        #region Math Operations

        // equalation

        // matrix multiplication
        public static Matrix operator *(Matrix left, Matrix right)
        {
            if (left.columns != right.rows)
            {
                Console.WriteLine("Несовместимые матрицы!");
                return null;
            }

            Matrix res = new Matrix(left.rows, right.columns);

            for (int i = 0; i < left.rows; ++i)
            {
                for (int j = 0; j < right.columns; ++j)
                    for (int k = 0; k < left.columns; ++k)
                        res.SetElement(i, j, res.GetElement(i, j) + left.GetElement(i, k) * right.GetElement(k, j));
            }
            return res;
        }

        // matrix on vector multiplication
        //public static Matrix operator *(Matrix left, List<double> right)
        //{
        //    if (left.columns != right.Count)
        //    {
        //        Console.WriteLine("Несовместимые матрица и вектор!");
        //        return null;
        //    }

        //    Matrix res = new Matrix(left.rows, right.columns);

        //    for (int i = 0; i < left.rows; ++i)
        //    {
        //        for (int j = 0; j < right.columns; ++j)
        //            for (int k = 0; k < left.columns; ++k)
        //                res.SetElement(i, j, res.GetElement(i, j) + left.GetElement(i, k) * right.GetElement(k, j));
        //    }
        //    return res;
        //}

        #endregion

        public void ReadFromFile(string path)
        {
            var lines = File.ReadAllLines(path).ToList();
            int i = 0;

            foreach (var line in lines)
            {
                mtx.Add(new List<double>());

                var str = line.Split(' ');

                foreach (var s in str)
                {
                    mtx[i].Add(Convert.ToDouble(s));
                }
                ++i;
            }

            rows = mtx.Count;
            columns = mtx[0].Count;
        }

        public void Print()
        {
            if (mtx == null)
                return;

            Console.WriteLine("********************************");

            for (int i = 0; i < mtx.Count; ++i)
            {
                for (int j = 0; j < mtx[i].Count; ++j)
                    Console.Write("{0:0.00  }", mtx[i][j]);
                Console.WriteLine();
            }

            Console.WriteLine("********************************\n");
        }

        public void PrintLikeSystem()
        {
            if (mtx == null)
                return;

            Console.WriteLine("********************************");
            for (int i = 0; i < mtx.Count; ++i)
            {
                for (int j = 0; j < mtx[i].Count; ++j)
                {
                    if (j == mtx[i].Count - 1)
                    {
                        Console.Write("= " + mtx[i][j]);
                        continue;
                    }

                    if (mtx[i][j] == 0)
                        continue;

                    if (mtx[i][j] > 0)
                        Console.Write("+");


                    if (mtx[i][j] == 1)
                    {
                        Console.Write("x" + (j + 1) + " ");
                        continue;
                    }

                    Console.Write(mtx[i][j] + "x" + (j + 1) + " ");
                }

                Console.WriteLine();
            }
            Console.WriteLine("********************************\n");
        }

        public void SwipeRows(int f, int s)
        {
            var tmp = new List<double>();

            tmp = mtx[s];
            mtx[s] = mtx[f];
            mtx[f] = tmp;
        }

        public double GetElement(int a, int b)
        {
            return mtx[a][b];
        }

        public void SetElement(int a, int b, double val)
        {
            mtx[a][b] = val;
        }

    }
}
