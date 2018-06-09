using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab4
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Choose part:\n" +
                    "1 - 4.1\n" +
                    "2 - 4.2\n");

                var ans = Console.ReadLine();

                if (ans == "1")
                    ERKA.Start();

                if (ans == "2")
                {
                    Console.WriteLine("Shooting method:");
                    Console.WriteLine("*****************************");
                    double t0 = 1;
                    double tk = 2;
                    double stepOfRg4 = 0.1;
                    var skr = new SKR(t0, tk, stepOfRg4);
                    int nnode = (int)((tk - t0) / stepOfRg4);
                    double[,] tempXout = new double[nnode, 3];
                    double[,] tempRRpogr = new double[nnode / 2, 2];

                    skr.calcMS(tempXout, tempRRpogr);
                    PrintSol(tempXout, tempRRpogr);
                    Console.WriteLine("*****************************");

                    Console.WriteLine("Konechno-raznostniy method:");

                    Console.WriteLine("*****************************");

                    t0 = 1;
                    tk = 2;
                    stepOfRg4 = Convert.ToDouble(0.1);
                    skr = new SKR(t0, tk, stepOfRg4);
                    nnode = (int)((tk - t0) / stepOfRg4);
                    tempXout = new double[nnode + 1, 3];
                    tempRRpogr = new double[nnode / 2 + 1, 3];

                    skr.calcKR(tempXout, tempRRpogr);

                    PrintSol(tempXout, tempRRpogr);
                    Console.WriteLine("*****************************");

                }
            }
        }

        private static void PrintSol(double[,] tempXout, double[,] tempRRpogr)
        {
            Console.WriteLine("i\txi\tyi");

            for (int i = 0; i < tempXout.Length / 3; ++i)
            {
                Console.Write(i + "\t");

                for (int j = 0; j < 2; ++j)
                {
                    Console.Write($"{tempXout[i, j]}\t");
                }
                Console.WriteLine();
            }

            Console.WriteLine("i\trr\trreps");

            for (int i = 0; i < tempRRpogr.Length / 3; ++i)
            {
                Console.Write(2*i + "\t"); 
                    Console.Write($"{tempRRpogr[i, 0]}\t");
                Console.WriteLine();
            }

        }
    }
}
