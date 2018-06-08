using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ч.М.Лаб._4._2_Герасименко_Н.А._8о_303
{
    class SLAU
    {
        public SLAU(Matrix A, Vector b)
        {
            this.A = A;
            this.b = b;
            lastKolvoIter = 0;
        }

        public Vector InverCalculate()
        {
            return --A * b;
        }

        public Vector LUCalculate()
        {
            Matrix L = new Matrix(4,'E');
            for (int j = 0; j < A.razm; j++)
            {
                int vedStr = 0;
                Matrix M = new Matrix(4, 'E');

                for (int i = j; i < A.razm; i++)
                {
                    if (A.matrix[i, j] != 0) { vedStr = i; break; }
                }
                A.StrSwap(j, vedStr);
                b.StrSwap(j, vedStr);

                for (int i = j+1; i < A.razm; i++)
                {
                    M.StrPlusStrUmnCh(i, j, A.matrix[i, j] / A.matrix[j, j]);

                    A.StrPlusStrUmnCh(i, j, (-1) * (A.matrix[i, j] / A.matrix[j, j]));
                    b.StrPlusStrUmnCh(i, j, (-1) * (A.matrix[i, j] / A.matrix[j, j]));
                }
                L = L * M;
            }

            List<double> z = new List<double>();
            for (int i = 0; i < A.razm; i++)
            {
                double summ = 0;
                for(int j = 0; j < z.Count; j++)
                {
                    summ = summ + L.matrix[i,j] * z[j];
                }
                z.Add(b.vector[i] - summ);
            }

            Vector res = new Vector(A.razm);
            for (int i = A.razm - 1; i >= 0; i--)
            {
                double summ = 0;
                for (int j = i+1; j < A.razm; j++)
                {
                    summ = summ + A.matrix[i, j] * res.vector[j];
                }
                res.vector[i] = ((1/A.matrix[i,i]) * ( z[i] - summ) );
            }

            return res;
        }



        private double Pi(double PiMinus1, int i)
        {
            if (i == A.razm - 1) return 0;
            return (- A.matrix[i, i + 1]) / (A.matrix[i, i] + A.matrix[i, i-1] * PiMinus1);
        }

        private double Qi(double QiMinus1, double PiMinus1, int i)
        {
            return (b.vector[i] - A.matrix[i, i - 1] * QiMinus1) / (A.matrix[i, i] + A.matrix[i, i - 1] * PiMinus1);
        }

        public Vector ProgonCalculate()
        {
            double[] P = new double[A.razm];
            P[0] = (-A.matrix[0, 1]) / (A.matrix[0, 0]);
            for (int i = 1; i < A.razm; i++)
            {
                P[i] = Pi(P[i - 1], i);
            }

            double[] Q = new double[A.razm];
            Q[0] = b.vector[0] / A.matrix[0, 0];
            for (int i = 1; i < A.razm; i++)
            {
                Q[i] = Qi(Q[i - 1], P[i -1], i);
            }

            Vector res = new Vector(A.razm);
            res.vector[A.razm - 1] = Q[A.razm - 1];
            for (int i = A.razm - 2; i >= 0; i--)
            {
                res.vector[i] = P[i] * res.vector[i + 1] + Q[i];
            }

            return res;
        }

        public Vector ProstItCalculate(double tochnost)
        {
            Vector res = new Vector(A.razm);
            Matrix alpha = new Matrix(A.razm, '0');
            Vector betta = new Vector(A.razm);

            for (int j = 0; j < A.razm; j++)
            {
                int vedStr = 0;
                for (int i = j; i < A.razm; i++)
                {
                    if (A.matrix[i, j] != 0) { vedStr = i; break; }
                }
                A.StrSwap(j, vedStr);
                b.StrSwap(j, vedStr);

                for (int i = 0; i < A.razm; i++)
                {
                    if (i == j) alpha.matrix[j, i] = 0;
                    else alpha.matrix[j, i] = - A.matrix[j, i] / A.matrix[j, j];
                }

                betta.vector[j] = b.vector[j] / A.matrix[j, j];

                res = betta;
            }


            double epsilon = 100;
            lastKolvoIter = 0;
            for (int i = 0; tochnost < epsilon; i++)
            {
                Vector temp;
                temp = betta + alpha * res;
                epsilon = (Math.Pow(alpha.Norma(), i + 1) / (1 - alpha.Norma()));
                epsilon = epsilon * (temp - res).Norma();
                res = temp;
                lastKolvoIter++;
            }

            return res;
        }

        public Vector ZeydelCalculate(double tochnost)
        {
            Vector res = new Vector(A.razm);
            Matrix alpha = new Matrix(A.razm, '0');
            Vector betta = new Vector(A.razm);
            Matrix B = new Matrix(A.razm, '0');
            Matrix C = new Matrix(A.razm, '0');

            for (int j = 0; j < A.razm; j++)
            {
                int vedStr = 0;
                for (int i = j; i < A.razm; i++)
                {
                    if (A.matrix[i, j] != 0) { vedStr = i; break; }
                }
                A.StrSwap(j, vedStr);
                b.StrSwap(j, vedStr);

                for (int i = 0; i < A.razm; i++)
                {
                    if (i == j) alpha.matrix[j, i] = 0;
                    else alpha.matrix[j, i] = -A.matrix[j, i] / A.matrix[j, j];
                }

                betta.vector[j] = b.vector[j] / A.matrix[j, j];

                res = betta;
            }

            for (int j = 0; j < A.razm; j++)
            {
                for (int i = 0; i < A.razm; i++)
                {
                    if (i <= j) { C.matrix[i, j] = alpha.matrix[i, j]; }
                    else B.matrix[i, j] = alpha.matrix[i, j];
                }
            }

            double epsilon = 100;
            lastKolvoIter = 0;
            for (int i = 0; tochnost < epsilon; i++)
            {
                Matrix E = new Matrix(A.razm, 'E');
                Vector temp;
                Matrix obrEminusB = E - B;
                obrEminusB = --obrEminusB;
                temp = obrEminusB * C * res + obrEminusB * betta;
                epsilon = C.Norma() / (1 - alpha.Norma());
                epsilon = epsilon * (temp - res).Norma();
                res = temp;
                lastKolvoIter++;
            }

            return res;
        }

        public Matrix A;
        public Vector b;
        public int lastKolvoIter;
    }

    
}
