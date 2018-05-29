using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading;
using Telegram.Bot;
using Telegram.Bot.Types.Enums;
using System.Drawing;
using System.Drawing.Imaging;
using Telegram.Bot.Types.ReplyMarkups;
using Telegram.Bot.Types;
using ExpertBot.Bot;
using System.Diagnostics;
using Aviators.Bot;

namespace ExpertBot
{
    public static class ExpertBot
    {
        private static TelegramBotClient Bot;
        private static string Username;
        static string dirPath = Path.GetFullPath("swipl\\bin");
        static string inputPath = Path.GetFullPath("input.txt");
        static string outputPath = Path.GetFullPath("output.txt");



        public static readonly List<Chat> Chats = new List<Chat>();

        public static bool End = true;
        public static void Start()
        {
            Bot = new TelegramBotClient("531014031:AAFCVo98Vmb6B2aeHHewkxBPdT3WEerVaDI");

            var me = Bot.GetMeAsync().Result;
            Console.WriteLine("Hello my name is " + me.FirstName);
            Console.WriteLine("Username is " + me.Username);
            Console.WriteLine("Press ctrl+c to kill me.");

            Bot.OnMessage += Bot_OnMessage;
            Bot.OnCallbackQuery += Bot_OnCallbackQuery;
            ExpertBot.Username = me.Username;

            Console.WriteLine("StartReceiving..."); 
            Bot.StartReceiving();

            while (End)
            {
                //if (Program.LoadIncome)
                //    Parse.ProcessFiles();

                //Nothing to do, just sleep 1 sec
                //ctrl+c break cycle
                Thread.Sleep(10000);
            }

            Console.WriteLine("StopReceiving...");
            Bot.StopReceiving();
        }

        private static async void Bot_OnMessage(object sender, Telegram.Bot.Args.MessageEventArgs e)
        {
            var cid = e.Message.Chat.Id;

            if (e.Message.Text == "/start")
            {
                await Bot.SendTextMessageAsync(cid, "Привет!\n" +
                    "Смотрю, ты решил коньки подобрать! Молодец, что обратился ко мне, я разбираюсь в них лучше всех!");

                string firstQuery = MakeQuery("VERTEX ROOT");
                WriteQueryToFile(firstQuery);

                CmdProc();
                var resp = new Response(outputPath);
                var keyboard = ButtonGen(resp.Result);

                var text = QuetionFinder.Find(resp.Title);

                await Bot.SendTextMessageAsync(cid, text, replyMarkup: keyboard);

            }
            
            else
                await Bot.SendTextMessageAsync(cid, "Такой команды я не знаю((");

            return; 
        }
        private async static void Bot_OnCallbackQuery(object sender, Telegram.Bot.Args.CallbackQueryEventArgs e)
        {
            var cid = e.CallbackQuery.Message.Chat.Id;
            var ans = e.CallbackQuery.Data;

            Console.WriteLine("Incoming callback from: " + e.CallbackQuery.From);

            int msgid = Convert.ToInt32(e.CallbackQuery.InlineMessageId);

            var query = MakeQuery(ans);
            WriteQueryToFile(query);
            CmdProc();
            var resp = new Response(outputPath);

            if (resp.Title == "false")
            {
                await Bot.SendTextMessageAsync(cid, "Конечка");
                return;
            }

            if (resp.Title.Contains("ANSWER"))
            {
                var res = resp.Result[0];
                //TODO for few variants



                await Bot.SendTextMessageAsync(cid, "Кажется, я подобрал!\n" +
                    "Вот, что тебе подойдет ;)\n\n" + res +
                    "\n\n Еще разок? /start");

                return;
            }

            var keyboard = ButtonGen(resp.Result);
            var text = QuetionFinder.Find(resp.Title);

            await Bot.SendTextMessageAsync(cid, text, replyMarkup: keyboard);
        }

        private static void WriteQueryToFile(string firstQuery)
        {
            if (System.IO.File.Exists(inputPath))
                System.IO.File.Delete(inputPath);

            System.IO.File.WriteAllText(inputPath, firstQuery);
        }

        private static string MakeQuery(string a)
        {
            return $"get_next('{a}', Title, Res).";
        }

        private static void CmdProc()
        {
            //if (System.IO.File.Exists(outputPath))
            //    System.IO.File.Delete(outputPath);

            //System.IO.File.Create(outputPath);

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
            procCommand.WaitForExit(10000);
        }

        public static InlineKeyboardMarkup ButtonGen(List<string> str)
        {
            var massiv = new List<InlineKeyboardButton[]>();

            foreach (var s in str)
                massiv.Add(new[] { new InlineKeyboardButton(s, s) });

            var keyboard = new InlineKeyboardMarkup(massiv.ToArray());
            return keyboard;
        }

       

    }
}
