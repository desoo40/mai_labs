using NMlab1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab3
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Choose part:\n" +
                    "1 - 3.1\n" +
                    "2 - 3.2\n" +
                    "3 - 3.3\n" +
                    "4 - 3.4\n" +
                    "5 - 3.5\n");

                var ans = Console.ReadLine();

                if (ans == "1")
                {
                    Console.WriteLine("\nLagrange method:");
                    Lagrange.Start("311.txt");

                    Console.WriteLine("\nNewton method:");
                    Newton.Start("312.txt");
                }

                if (ans == "2")
                {
                    Console.WriteLine("\nCubic spline:");
                    CubicSpline.Start("32.txt");
                }

                if (ans == "3")
                {
                    Console.WriteLine("\nTEst:");

                    Matrix matr = new Matrix();
                    matr.ReadFromFile("test.txt");

                    ThomasAlgorythm.TA(matr);
                }

            }
        }
    }
}
