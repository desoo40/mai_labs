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
        public Matrix ()
        {
            rows = 0;
            columns = 0;
        }

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
            Console.WriteLine("********************************");

            for (int i = 0; i < mtx.Count; ++i)
            {
                for (int j = 0; j < mtx[i].Count; ++j)
                    Console.Write(mtx[i][j] + " ");
                Console.WriteLine();
            }

            Console.WriteLine("********************************\n");
        }

        public void PrintLikeSystem()
        {
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

    }
}
