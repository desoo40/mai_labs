using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ч.М.Лаб._4._2_Герасименко_Н.А._8о_303
{
    class BVP
    {
        public BVP(double t0, double tk, double stepOfRg4) 
        {
            this.t0 = t0;
            this.tk = tk;
            this.stepOfRg4 = stepOfRg4;
            razm = 3;
            double temp1 = 1 / Math.E;
            double temp2 = 1 / (2*Math.E*Math.E);
            x0 = new double[3] { temp1, 0, t0 };
            xk = new double[3] { temp2, 0, tk };
            nnode = (int)((tk - t0) / stepOfRg4);
            n1 = 1;
            n2 = 0.9;
        }

        private double t0, tk, stepOfRg4, n1, n2;
        private int nnode, razm;
        private double[] x0, xk;

        public void calcMS(double[,] res, double[,] RRpogr) 
        {
            for (int i = 0; true; i++)
            {
                double nImin1 = n2;
                double nImin2 = n1;
                double n = 0;
                if (i < 2) { if (i == 0) { n = n1; } else n = n2; }
                else
                {
                    double Fimin1, Fimin2;
                    x0[1] = nImin1;
                    rg4(nnode, stepOfRg4, t0, x0, res, razm);
                    Fimin1 = res[nnode - 1, 0] - xk[0];
                    x0[1] = nImin2;
                    rg4(nnode, stepOfRg4, t0, x0, res, razm);
                    Fimin2 = res[nnode - 1, 0] - xk[0];

                    n = nImin1 - (nImin1 - nImin2) * Fimin1 / (Fimin1 - Fimin2);
                }
                x0[1] = n;
                rg4(nnode, stepOfRg4, t0, x0, res, razm);
                if (Math.Abs(res[nnode - 1, 0] - xk[0]) < 0.0001) { break; }
                else { if (i > 1) { n1 = n2; n2 = n; } }
            }
            double[,] tempXout = new double[nnode / 2, 3];
            rg4(nnode / 2, stepOfRg4 * 2, t0, x0, tempXout, razm);
            for (int i = 0; i < nnode / 2; i++)
            {
                double temp = (res[2 * i, 0] - tempXout[i, 0]) / (2 * 2 - 1);
                RRpogr[i, 0] = temp;
                RRpogr[i, 1] = t0 + 2 * i * stepOfRg4;
            }
        }

        public void calcKR(double[,] res, double[,] RRpogr) 
        {
            Matrix A = new Matrix(nnode, '0');
            A.matrix[0, 0] = - 2 - stepOfRg4 * stepOfRg4;
            A.matrix[0, 1] = 1 + stepOfRg4 / ((t0 + stepOfRg4));
            A.matrix[nnode - 1, nnode - 2] = 1 - stepOfRg4 / ((t0 + stepOfRg4 * (nnode)));
            A.matrix[nnode - 1, nnode - 1] = -2 - stepOfRg4 * stepOfRg4;

            for (int i = 1; i < nnode - 1; i++)
            {
                A.matrix[i, i - 1] = 1 - stepOfRg4 / ((t0 + stepOfRg4 * (i + 1)));
                A.matrix[i, i] = -2 - stepOfRg4 * stepOfRg4;
                A.matrix[i, i + 1] = 1 + stepOfRg4 / ((t0 + stepOfRg4 * (i + 1)));
            }

            Vector b = new Vector(nnode);
            b.vector[0] = -(1 - stepOfRg4 / ((t0 + stepOfRg4))) * x0[0];
            b.vector[nnode - 1] = -(1 + stepOfRg4 / ((t0 + stepOfRg4 * (nnode)))) * xk[0];

            SLAU slau = new SLAU(A, b);
            Vector vecRes = slau.ProgonCalculate();

            res[0, 0] = x0[0];
            res[0, 2] = t0;

            for (int i = 0; i < nnode; i++)
            {
                res[i+1, 0] = vecRes.vector[i];
                res[i+1, 2] = t0 + (i+1) * stepOfRg4;
            }

            Matrix A1 = new Matrix(nnode/2, '0');
            A1.matrix[0, 0] = -2 - stepOfRg4*2 * stepOfRg4*2;
            A1.matrix[0, 1] = 1 + stepOfRg4*2 / ((t0 + stepOfRg4*2));
            A1.matrix[nnode/2 - 1, nnode/2 - 2] = 1 - stepOfRg4*2 / ((t0 + stepOfRg4*2 * (nnode/2)));
            A1.matrix[nnode/2 - 1, nnode/2 - 1] = -2 - stepOfRg4*2 * stepOfRg4*2;

            for (int i = 1; i < nnode/2 - 1; i++)
            {
                A1.matrix[i, i - 1] = 1 - stepOfRg4*2 / ((t0 + stepOfRg4*2 * (i + 1)));
                A1.matrix[i, i] = -2 - stepOfRg4*2 * stepOfRg4*2;
                A1.matrix[i, i + 1] = 1 + stepOfRg4*2 / ((t0 + stepOfRg4*2 * (i + 1)));
            }

            Vector b1 = new Vector(nnode/2);
            b1.vector[0] = -(1 - stepOfRg4*2 / ((t0 + stepOfRg4*2))) * x0[0];
            b1.vector[nnode/2 - 1] = -(1 + stepOfRg4*2 / ((t0 + stepOfRg4*2 * (nnode/2)))) * xk[0];

            SLAU slau1 = new SLAU(A1, b1);
            Vector vecRes1 = slau1.ProgonCalculate();

            RRpogr[0, 0] = 0;
            RRpogr[0, 2] = t0;

            for (int i = 0; i < nnode/2; i++)
            {
                double temp = (vecRes.vector[i] - vecRes1.vector[i]) / (2 * 4 - 1);
                RRpogr[i+1, 0] = temp;
                RRpogr[i+1, 2] = t0 + 2 * (i+1) * stepOfRg4;
            }
        }

        public void OdeSystem(double t, double[] x, double[] f)
        {
            f[0] = x[1];
            f[1] = x[0] - 2 * x[1]/t;
        }

        private void rg4(int nnode, double stepOfRg4, double t0, double[] x0, double[,] xout, int razm)
        {
            double t1, t2, t3, t4;
            double[] x1, x2, x3, x4;
            x1 = new double[razm];
            x2 = new double[razm];
            x3 = new double[razm];
            x4 = new double[razm];
            double[] k1, k2, k3, k4;
            k1 = new double[razm];
            k2 = new double[razm];
            k3 = new double[razm];
            k4 = new double[razm];


            for (int i = 0; i < razm; i++)
            {
                x1[i] = x0[i];
                xout[0, i] = x0[i];
            }

            for (int j = 1; j < nnode; j++)
            {
                t1 = t0 + (j - 1) * stepOfRg4;
                OdeSystem(t1, x1, k1);

                t2 = t1 + stepOfRg4 / 2;
                for (int i = 0; i < razm; i++) { x2[i] = x1[i] + stepOfRg4 * k1[i] / 2.0; }
                OdeSystem(t2, x2, k2);

                t3 = t2;
                for (int i = 0; i < razm; i++) { x3[i] = x1[i] + stepOfRg4 * k2[i] / 2.0; }
                OdeSystem(t3, x3, k3);

                t4 = t1 + stepOfRg4;
                for (int i = 0; i < razm; i++) { x4[i] = x1[i] + stepOfRg4 * k3[i]; }
                OdeSystem(t4, x4, k4);

                for (int i = 0; i < razm; i++) { x1[i] = x1[i] + stepOfRg4 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6.0; }
                for (int i = 0; i < razm; i++) { xout[j, i] = x1[i]; }
                xout[j, razm-1] = t4;
            }
        }
    }
}
