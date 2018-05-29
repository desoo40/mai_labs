using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Net;
using ExpertBot.Bot;

namespace ExpertBot
{
    class Program
    {
        /// <summary>
        /// Флаг для создания базы и табличек, что бы из кода.
        /// Можно так же аргумент в свойствах проекта прописывать, но неудобно
        /// </summary>

        static void Main(string[] args)
        {
            //to ignore untrusted SSL certificates, linux and mono love it ;)
            ServicePointManager.ServerCertificateValidationCallback = Network.SSL.Validator;

            Stopwatch sw = new Stopwatch();


            Console.CancelKeyPress += Console_CancelKeyPress;


            Console.WriteLine("Starting Bot...");
            try
            {
                ExpertBot.Start();
            }
            catch (Exception e)
            {
                Console.WriteLine("Unknown AviaBot exception: " + e.Message);
                Console.WriteLine("Bot will be terminated.");
            }
        }

        private static void Console_CancelKeyPress(object sender, ConsoleCancelEventArgs e)
        {
            Console.WriteLine("It's the end! Bye.");
            ExpertBot.End = false;
            if (!ExpertBot.End) e.Cancel = true;
        }
    }
}


