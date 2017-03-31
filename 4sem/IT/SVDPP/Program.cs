using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace SVDPP
{
    class Program
    {
        private static int Factors = 2;        // Количество параметров
        private static double TS = 0.025;       // Скорость обучения 
        private static double L1 = 0.0005;      // Первый коэффициент регуляризации
        private static double L2 = 0.0025;      // Второй коэффициент регуляризации
        private static double EPS = 0.00001;    // Коэффициент точности погрешности
        private static double Threshold = 0.01; // Пороговый коэффициент
        private static List<double> BS_User = new List<double>(); // Вектор предсказаний пользователей
        private static List<double> BS_Item = new List<double>(); // Вектор предсказаний фильмов
        private static List<List<double>> MF_User = new List<List<double>>(); // Declaring the matrix of user's latent factors
        private static List<List<double>> MF_Item = new List<List<double>>(); // Declaring the matrix of item's latent factors
        private static List<List<double>> MatrixUI = new List<List<double>>(); // Матрица оценок фильмов пользователями
        private static List<string> Films = new List<string>(); // List of films


        private static readonly System.Random rand = new System.Random();

        static void Initialize()
        {
            for (int User = 0; User < MatrixUI.Count(); User++)
            {
                List<double> MF_UserRow = new List<double>();

                MF_UserRow.AddRange(Enumerable.Repeat(0.00, Factors));
                MF_User.Insert(User, MF_UserRow);
            }

            
            for (int Item = 0; Item < MatrixUI.ElementAt(0).Count(); Item++)
            {
                List<double> MF_ItemRow = new List<double>();

                MF_ItemRow.AddRange(Enumerable.Repeat(0.00, Factors));
                MF_Item.Insert(Item, MF_ItemRow);
            }

            MF_User[0][0] = 0.1; MF_Item[0][0] = MF_User[0][0] / 2;

            BS_User.AddRange(Enumerable.Repeat(0.00, MatrixUI.Count()));
            BS_Item.AddRange(Enumerable.Repeat(0.00, MatrixUI.ElementAt(0).Count()));
        }
        public static double GetProduct(List<double> VF_User, List<double> VF_Item)
        {
            
            double Product = 0.00; 

            for (int Index = 0; Index < Factors; Index++)
                
                Product += VF_User[Index] * VF_Item[Index];

            return Product;
        }
        public static double GetAverageRating(List<List<double>> Matrix)
        {
          
            double Sum = 0;
            int Count = 0;

            for (int User = 0; User < Matrix.Count(); User++)
                for (int Item = 0; Item < Matrix[User].Count(); Item++)
                    if (Matrix[User][Item] > 0)
                    {
                        Sum = Sum + Matrix[User][Item];
                        Count = Count + 1;
                    }

            return Sum / Count;
        }
        public static void LoadItemsFromFile(string Filename, List<List<double>> Matrix)
        {
            

            using (System.IO.FileStream fsFile = new System.IO.FileStream(Filename,
              System.IO.FileMode.Open, System.IO.FileAccess.Read, System.IO.FileShare.Read))
            {
                using (System.IO.StreamReader fsStream = new System.IO.StreamReader(
                  fsFile, System.Text.Encoding.UTF8, true, 128))
                {
                    string textBuf = "\0";
                    while ((textBuf = fsStream.ReadLine()) != null)
                    {
                        List<double> Row = new List<double>();
                        if (!String.IsNullOrEmpty(textBuf))
                        {
                            string sPattern = "\t";
                            foreach (var rating in Regex.Split(textBuf, sPattern))
                                Row.Add(double.Parse(rating));
                        }

                        Matrix.Add(Row);
                    }
                }
            }
        }
        static void Learn()
        {
            // Initializing the iterations loop counter variable
            int Iterations = 0;
            // Initializing the RMSE and RMSE_New variables to store
            // current and previous values of RMSE
            double RMSE = 0.00, RMSE_New = 1.00;
            // Computing the average rating for the entire domain of rated items
            double AvgRating = GetAverageRating(MatrixUI);
            // Iterating the process of the ratings prediction model update until
            // the value of difference between the current and previous value of RMSE
            // is greater than the value of error precision accuracy EPS (e.g. the learning
            // process has converged).
            while (Math.Abs(RMSE - RMSE_New) > EPS)
            {
                // Assign the previously obtained value of RMSE to the RMSE variable
                // Assign the variable RMSE_New equal to 0
                RMSE = RMSE_New; RMSE_New = 0;
                // Iterate through the matrix of ratings and for each existing rating compute
                // the error value and perform the stochastic gradient descent to update 
                // the main parameters of the ratings prediction model for the current user and item
                for (int User = 0; User < MatrixUI.Count(); User++)
                {
                    for (int Item = 0; Item < MatrixUI.ElementAt(0).Count(); Item++)
                        // Perform a check if the current rating in the matrix of ratings is unknown.
                        // If not, perform the following steps to adjust the values of baseline
                        // predictors and factorization vectors
                        if (MatrixUI[User].ElementAt(Item) > 0)
                        {
                            // Compute the value of estimated rating using formula (2)
                            double Rating = AvgRating + BS_User[User] +
                                BS_Item[Item] + GetProduct(MF_User[User], MF_Item[Item]);

                            // Compute the error value as the difference between the existing and estimated ratings
                            double Error = MatrixUI[User].ElementAt(Item) - Rating;

                            // Add the value of error square to the current value of RMSE
                            RMSE_New = RMSE_New + Math.Pow(Error, 2);

                            // Update the value of average rating for the entire domain of ratings
                            // by performing stochastic gradient descent using formulas (7.1-5)
                            AvgRating = AvgRating + TS * (Error - L1 * AvgRating);
                            // Update the value of baseline predictor of the current user
                            // by performing stochastic gradient descent using formulas (7.1-5)
                            BS_User[User] = BS_User[User] + TS * (Error - L1 * BS_User[User]);
                            // Update the value of baseline predictor of the current item 
                            // by performing stochastic gradient descent using formulas (7.1-5)
                            BS_Item[Item] = BS_Item[Item] + TS * (Error - L1 * BS_Item[Item]);

                            // Update each component of the factorization vector for the current user and item
                            for (int Factor = 0; Factor < Factors; Factor++)
                            {
                                // Adjust the value of the current component of the user's factorization vector 
                                // by performing stochastic gradient descent using formulas (7.1-5)
                                MF_User[User][Factor] += TS * (Error * MF_Item[Item][Factor] + L2 * MF_User[User][Factor]);
                                // Adjust the value of the current component of the item's factorization vector 
                                // by performing stochastic gradient descent using formulas (7.1-5)
                                MF_Item[Item][Factor] += TS * (Error * MF_User[User][Factor] + L2 * MF_Item[Item][Factor]);
                            }
                        }
                }

                // Compute the current value of RMSE (root means square error)
                RMSE_New = Math.Sqrt(RMSE_New / (MatrixUI.Count() * MatrixUI.ElementAt(0).Count()));

                //Console.WriteLine("Iteration: {0}\t RMSE={1}\n\n", Iterations, RMSE_New);

                // Performing a check if the difference between the values 
                // of current and previous values of RMSE exceeds the given threshold
                if (RMSE_New > RMSE - Threshold)
                {
                    // If so, reduce the values of training speed and threshold 
                    // by multiplying each value by the value of specific coefficients
                    TS *= 0.66; Threshold *= 0.5;
                }

                Iterations++; // Increment the iterations loop counter variable
                Console.SetCursorPosition(0,0);
                Console.WriteLine("Done {0} iterations of learning", Iterations);
            }
        }

        public static void Predict()
        {
            double AvgRating = GetAverageRating(MatrixUI);
            int blocks = MatrixUI.Count*MatrixUI[0].Count;
            int work = 0;
            using (StreamWriter file = File.AppendText(@"output.txt"))
            {

                for (int User = 0; User < MatrixUI.Count(); User++)
                {
                    double maxRating = 0;
                    int itemWithMax = -1;

                    for (int Item = 0; Item < MatrixUI.ElementAt(0).Count(); Item++)
                    {
                        if (MatrixUI[User].ElementAt(Item) == 0)
                        {
                            
                            MatrixUI[User][Item] = AvgRating + BS_User[User] +
                                                   BS_Item[Item] + GetProduct(MF_User[User], MF_Item[Item]);
                            double tmp = MatrixUI[User][Item];

                            if (tmp > maxRating)
                            {
                                maxRating = tmp;
                                itemWithMax = Item;
                            }
                        }
                        Console.SetCursorPosition(0,1);
                        double doneWork = (double)++work/(double)blocks;
                        string proc = "Working... " + Math.Round(doneWork*100) + " %";
                        Console.WriteLine(proc);
                    }

                    if (itemWithMax >= 0)
                    {
                        if (maxRating > 5)
                            maxRating = 5;

                        string userRate = "User " + User + " will rated " + Films[itemWithMax] +
                                        " as " +
                                       Math.Round(maxRating);

                        file.WriteLine(userRate);
                       

                    }
             }
        }

        }
        static void Main(string[] args)
        {
            
            LoadItemsFromFile(@"ratings.txt", MatrixUI);
            Films = File.ReadAllLines(@"films.txt").ToList();

            Initialize(); // Подготавливаем необходимые данные о пользователях и фильмах

            Learn();      // Машинное обучение 

            Predict();    // Предсказание рейтингов

            Console.WriteLine("Done");
            Console.ReadKey();
        }
    }
}
