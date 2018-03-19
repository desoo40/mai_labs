using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMlab1
{
    class Program
    {
        
        static void Main(string[] args)
        {
            while (1 == 1)
            { 
            Console.WriteLine("Choose part:\n" +
                "1 - 1.1\n" +
                "2 - 1.2\n" +
                "3 - 1.3\n" +
                "4 - 1.4\n" +
                "5 - 1.5\n");

            var ans = Console.ReadLine();
            var matr = new Matrix();

            if (ans == "1")
            {
                matr.ReadFromFile("11.txt");
                Console.WriteLine("Решаем систему LU - методом:");

                matr.PrintLikeSystem();

                var sys = new LESystem(matr);
                var LU = new LUDecomposition(sys);

                LU.LU_Algorithm();

                Console.WriteLine("L Matrix:");
                LU.L.Print();

                Console.WriteLine("U Matrix:");
                LU.U.Print();

                Console.WriteLine("Right side:");
                sys.PrintRight();

                Console.WriteLine();

                sys.PrintSolution();
                LU.FindDeter();
                LU.FindInvertMtx();

            }

            if (ans == "2")
            {
                matr.ReadFromFile("12.txt");
                Console.WriteLine("Решаем систему методом прогонки:");
            
                matr.PrintLikeSystem();
                var TA = new ThomasAlgorythm(matr);
            }

            if (ans == "3")
            {
                matr.ReadFromFile("13.txt");
                Console.WriteLine("Решаем систему методом простых итераций:");

                matr.PrintLikeSystem();

                var eps = 0.01;
                Console.WriteLine("Введите точность:");
                var s = Console.ReadLine();
                s = s.Replace('.', ',');
                try
                {
                    eps = Convert.ToDouble(s);
                }
                catch(Exception e)
                {
                        
                }
                var SIM = new SimpleIterationMethod(matr, eps);

                Console.WriteLine("Решаем систему методом Зейделя:");

                matr.PrintLikeSystem();

                var Seidel = new SeidelMethod(matr, eps);
                

            }

                if (ans == "9")
                {
                    var test1 = new Matrix();
                    //var test2 = new Matrix();

                    test1.ReadFromFile("test1.txt");
                    //test2.ReadFromFile("test2.txt");

                    //var test3 = test1 * test2;

                    //if (test3 != null)
                    //    test3.Print();

                    var l = new List<double>()
                {
                    1, 2, 3
                };

                    var kek = test1 * l;

                    foreach (var el in kek)
                    {
                        Console.WriteLine(el);
                    }
                }
            }


        }

        

       
    }
}
