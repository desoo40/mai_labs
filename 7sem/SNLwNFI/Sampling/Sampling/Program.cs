using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using NMlab1;

namespace Sampling
{
    class Program
    {
        private int k;
        private double delta;
        private double t;
        private List<double> cnst;
        private List<double> vt;
        private static Matrix mtx;
        private static List<double> eigVal;
        private static List<List<double>> eigVec;

        static void Main(string[] args)
        {
            mtx = new Matrix();

            mtx.ReadFromFile("input.txt");
            mtx.Print("Matrix");
            Console.WriteLine(mtx.det);

            var jm = new JacobiMethod();
            
            jm.JM(mtx, 0.0001);

            eigVal = jm.eigValues;
            eigVec = jm.eigVectors;

            Vector.Print(eigVal, "EigValues");

            var i = 0;

            foreach (var el in eigVec)
            {
                ++i;
                Vector.Print(el, $"EigVec{i}");
            }

            var param = 2;

            MakeFMatrix(param);
        }

        private static void MakeFMatrix(double param)
        {

        }
    }
}
