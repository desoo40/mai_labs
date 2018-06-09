using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab2
{
    class Systems
    {
        public Systems()
        {
        }

        private double f1(double[] x)
        {
            return x[0] * x[0] / 16 + x[1] * x[1] / 4 - 1;
        }

        private double f11(double[] x)
        {
            return x[0] / 8;
        }

        private double f12(double[] x)
        {
            return x[1] / 2;
        }

        private double f2(double[] x)
        {
            return 4 * x[1] - Math.Pow(Math.E, x[0]) - x[0];
        }

        private double f21(double[] x)
        {
            return - Math.Pow(Math.E, x[0]) - 1;
        }

        private double f22(double[] x)
        {
            return 4;
        }

        private Matrix J(double[] x)
        {
            Matrix J = new Matrix(2, '0');
            J.matrix[0, 0] = f11(x);
            J.matrix[0, 1] = f12(x);
            J.matrix[1, 0] = f21(x);
            J.matrix[1, 1] = f22(x);

            return J;
        }


        private Matrix A1(double[] x)
        {
            Matrix A1 = new Matrix(2, '0');
            A1.matrix[0, 0] = f1(x);
            A1.matrix[0, 1] = f12(x); ;
            A1.matrix[1, 0] = f2(x);
            A1.matrix[1, 1] = f22(x); ;

            return A1;
        }


        private Matrix A2(double[] x)
        {
            Matrix A2 = new Matrix(2, '0');
            A2.matrix[0, 0] = f11(x);
            A2.matrix[0, 1] = f1(x);
            A2.matrix[1, 0] = f21(x);
            A2.matrix[1, 1] = f2(x);

            return A2;
        }

        private double[] phi(double[] x)
        {
            double[] res = new double[2];
            res[0] = 2 * Math.Sqrt(4 - x[1]*x[1]);
            res[1] = (x[0] + Math.Pow(Math.E, x[0])) / 4;
            return res;
        }

        public void SimpleIteration(double eps)
        {
            Console.WriteLine("*****************************************");
            Console.WriteLine("Simple iteration method for system: ");

            double[] res = new double[2];
            res[0] = 1.9;
            res[1] = 2.0;
            double q = 0.99;
            double[] xk = new double[2];


            for (int i = 0; (q / (1 - q)) * Math.Max(Math.Abs(xk[0] - res[0]), Math.Abs(xk[1] - res[1])) >= eps; ++i)
            {
                xk[0] = res[0];
                xk[1] = res[1];

                Console.WriteLine("*******************");

                Console.WriteLine("Iteration #" + i);
                Console.WriteLine();

                Console.WriteLine($"x1 = {xk[0]}");
                Console.WriteLine($"x2 = {xk[1]}");

                Console.WriteLine("*******************");

                res[0] = phi(xk)[0];
                res[1] = phi(xk)[1];
            }

            Console.WriteLine();
            Console.WriteLine($"Answer:");
            Console.WriteLine($"x1 = {res[0]}");
            Console.WriteLine($"x2 = {res[1]}");

            Console.WriteLine("*****************************************");
        }

        public void Newton(double eps)
        {
            Console.WriteLine("*****************************************");
            Console.WriteLine("Newton method for system: ");

            double[] res = new double[2];
            res[0] = 5.0;
            res[1] = 0.0;
            double[] xk = new double[2];

            for (int i = 0;  Math.Max(Math.Abs(xk[0] - res[0]), Math.Abs(xk[1] - res[1])) >= eps; ++i)
            {
                xk[0] = res[0];
                xk[1] = res[1];

                double detA1 = !A1(xk);
                double detA2 = !A2(xk);
                double detJ = !J(xk);

                Console.WriteLine("*******************");

                Console.WriteLine("Iteration #" + i);
                Console.WriteLine();

                Console.WriteLine($"x1 = {xk[0]}");
                Console.WriteLine($"x2= {xk[1]}");
                Console.WriteLine($"detA1= {detA1}");
                Console.WriteLine($"detA2= {detA2}");
                Console.WriteLine($"detJ= {detJ}");

                Console.WriteLine("*******************");

                res[0] = xk[0] - detA1 / detJ;
                res[1] = xk[1] - detA2 / detJ;
            }

            Console.WriteLine();
            Console.WriteLine($"Answer:");
            Console.WriteLine($"x1 = {res[0]}");
            Console.WriteLine($"x2 = {res[1]}");

            Console.WriteLine("*****************************************");
        }
    }
}
