using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1
{
    class Program
    {
        static string dirPath = Path.GetFullPath("swipl\\bin");
        static string inputPath = Path.GetFullPath("input.txt");
        static string outputPath = Path.GetFullPath("output.txt");

        static void Main(string[] args)
        {
            string firstQuery = MakeQuery("VERTEX ROOT");

            if (File.Exists(inputPath))
                File.Delete(inputPath);

            File.WriteAllText(inputPath, firstQuery);

            Console.WriteLine("Привет! \n Смотрю ты конёчки хочешь подобрать?");

            CmdProc();

            Expert();
        }

        private static void Expert()
        {
            var resp = new Response(outputPath);

            if (resp.Title == "Colour")
            {
                Console.WriteLine("Какой цвет предпочтешь?");

                var n = 1;

                foreach(string s in resp.Result)
                {
                    Console.WriteLine(s);
                }

                var answer = Console.ReadLine();

                var query = MakeQuery(answer);
                File.WriteAllText(inputPath, query);
                CmdProc();
                Expert();
            }

            if (resp.Title == "Appointment")
            {
                Console.Write("EHDDD");
            }
        }

        private static string MakeQuery(string a)
        {
            return $"get_next('{a}', Title, Res).";
        }

        private static void CmdProc()
        {
            var command = $"cd {dirPath} & swipl rules.pl < {inputPath} > {outputPath}";

            // создаем процесс cmd.exe с параметрами "ipconfig /all"
            ProcessStartInfo psiOpt = new ProcessStartInfo(@"cmd.exe", $"/C {command}");
            // скрываем окно запущенного процесса
            psiOpt.WindowStyle = ProcessWindowStyle.Hidden;
            psiOpt.RedirectStandardOutput = true;
            psiOpt.UseShellExecute = false;
            psiOpt.CreateNoWindow = true;
            // запускаем процесс
            Process procCommand = Process.Start(psiOpt);
            // закрываем процесс
            procCommand.WaitForExit(1000);
        }
    }
}
