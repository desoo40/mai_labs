using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    public class Vector
    {
        public Vector(double[] vector)
        {
            this.vector = vector;
            this.razm = vector.Length;
        }

        public Vector(int razm)
        {
            this.razm = razm;
            this.vector = new double[razm];
        }

        public void StrSwap(int str1, int str2)
        {
            double temp = vector[str1];
            vector[str1] = vector[str2];
            vector[str2] = temp;
        }

        public void StrPlusStrUmnCh(int str1, int str2, double chislo)
        {
            vector[str1] = vector[str1] + chislo * vector[str2];
        }

        static public Vector operator +(Vector left, Vector right)
        {
            int razm = left.razm;
            double[] res = new double[razm];

            for (int i = 0; i < razm; ++i)
                res[i] = left.vector[i] + right.vector[i];

            return new Vector(res);
        }

        static public Vector operator -(Vector left, Vector right)
        {
            int razm = left.razm;
            double[] res = new double[razm];

            for (int i = 0; i < razm; ++i)
                res[i] = left.vector[i] - right.vector[i];

            return new Vector(res);
        }

        public double Norma()
        {
            double res = 0;
            for (int i = 0; i < razm - 1; ++i)
                res = Math.Max(vector[i], vector[i+1]);
            return Math.Abs(res);
        }

        public double[] vector;
        private int razm;
    }
}
