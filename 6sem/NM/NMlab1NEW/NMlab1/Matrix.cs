using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    public class Matrix
    {

        public List<List<double>> mtx = new List<List<double>>();
        public int rows;
        public int columns;
        public double det;
        public double measure;

        public Matrix()
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

        public void MakeUnitMatrix()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (i == j)
                        mtx[i][j] = 1;
                    else
                        mtx[i][j] = 0;
                }
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
                        res.mtx[i][j] += left.mtx[i][k] * right.mtx[k][j];
            }
            return res;
        }

        public List<double> GetColumn(int i)
        {
            if (i + 1 > columns)
                return null;

            var col = new List<double>();

            for (int j = 0; j < rows; j++)
                col.Add(mtx[j][i]);

            return col;
        }

        public static Matrix operator *(double digit, Matrix right)
        {
            Matrix res = new Matrix(right.rows, right.columns);

            for (int i = 0; i < right.rows; ++i)
            {
                for (int j = 0; j < right.columns; ++j)
                    res.mtx[i][j] = digit * right.mtx[i][j];
            }
            return res;
        }

        public static Matrix operator +(Matrix left, Matrix right)
        {
            if (left.columns != right.columns || left.rows != right.rows)
            {
                Console.WriteLine("Несовместимые матрицы!");
                return null;
            }

            Matrix res = new Matrix(left.rows, left.columns);

            for (int i = 0; i < left.rows; ++i)
            {
                for (int j = 0; j < left.columns; ++j)
                    res.mtx[i][j] = left.mtx[i][j] + right.mtx[i][j];
            }

            return res;
        }

        // matrix on vector multiplication
        public static List<double> operator *(Matrix left, List<double> right)
        {
            if (left.columns != right.Count)
            {
                Console.WriteLine("Несовместимые матрица и вектор!");
                return null;
            }

            var res = new List<double>(right.Count);

            for (int i = 0; i < right.Count; ++i)
            {
                res.Add(0);
                for (int j = 0; j < left.columns; ++j)
                    res[i] += left.mtx[i][j] * right[j];

            }
            return res;
        }

       

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

        public void Print(string str = " ")
        {
            if (mtx == null)
                return;

            if (str != " ")
                Console.WriteLine("Matrix: " + str);
            Console.WriteLine("********************************");

            for (int i = 0; i < mtx.Count; ++i)
            {
                for (int j = 0; j < mtx[i].Count; ++j)
                    Console.Write("{0:0.0000  }", mtx[i][j]);
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

        public void CalcMeasure()
        {
            double max = 0;

            for (int i = 0; i < rows; ++i)
            {
                double temp = 0;

                for (int j = 0; j < columns; ++j)
                {
                    temp += Math.Abs(mtx[i][j]);
                }

                if (temp > max)
                    max = temp;
            }

            measure = max;
        }

        public Matrix FindTransparent()
        {
            var trans = new Matrix(columns, rows);

            for (int i = 0; i < trans.rows; ++i)
            {
                for (int j = 0; j < trans.columns; ++j)
                {
                    trans.mtx[i][j] = mtx[j][i];
                }
            }

            return trans;
        }



    }
}
