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
            while (true)
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
                    ThomasAlgorythm.TA(matr);
                }

                if (ans == "3")
                {
                    matr.ReadFromFile("13.txt");
                    Console.WriteLine("Решаем систему методом простых итераций:");

                    matr.PrintLikeSystem();

                    var eps = EnterEps();
                    var SIM = new SimpleIterationMethod(matr, eps);

                    Console.WriteLine("Решаем систему методом Зейделя:");

                    matr.PrintLikeSystem();

                    var Seidel = new SeidelMethod(matr, eps);


                }

                if (ans == "4")
                {
                    matr.ReadFromFile("14.txt");
                    Console.WriteLine("Ищем собственные значения и собственные векторы методом вращений:");

                    var eps = EnterEps();

                    matr.Print();
                    JacobiMethod.JM(matr, eps);
                }

                if (ans == "5")
                {
                    matr.ReadFromFile("15.txt");
                    Console.WriteLine("Ищем собственные значения и собственные векторы QR методом:");

                    var eps = EnterEps();

                    matr.Print();
                    QRAlgorythm.QR(matr, eps);
                }

                if (ans == "6")
                {
                    matr.ReadFromFile("16.txt");
                    Console.WriteLine("QR разложение матрицы:");

                    matr.Print();

                    QRAlgorythm.QR(matr);
                }

                if (ans == "9")
                {
                    List<double> v = new List<double>()
                        {5.24, 1, 4};

                    QRAlgorythm.HouseholderCalc(v).Print();
                }
                if (ans == "9")
                {
                    List<double> v = new List<double>()
                        {5.24, 1, 4};

                    QRAlgorythm.HouseholderCalc(v).Print();
                }
            }

        }



        private static double EnterEps()
        {
            var eps = 0.01;
            Console.WriteLine("Введите точность:");
            var s = Console.ReadLine();
            s = s.Replace('.', ',');
            try
            {
                eps = Convert.ToDouble(s);
            }
            catch (Exception e)
            {

            }

            return eps;
        }

    }
}