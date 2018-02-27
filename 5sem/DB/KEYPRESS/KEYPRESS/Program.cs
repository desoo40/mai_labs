using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;


namespace KEYPRESS
{
    class Program
    {
        // Get a handle to an application window.
        [DllImport("USER32.DLL", CharSet = CharSet.Unicode)]
        public static extern IntPtr FindWindow(string lpClassName,
            string lpWindowName);

        // Activate an application window.
        [DllImport("USER32.DLL")]
        public static extern bool SetForegroundWindow(IntPtr hWnd);

        static void Main(string[] args)
        {
            Console.WriteLine("Press any key to start...");

            RunPressing();
        }

        private static void RunPressing()
        {
            // Get a handle to the Calculator application. The window class
            // and window name were obtained using the Spy++ tool.
            IntPtr calculatorHandle = FindWindow("vfp99400000", "Microsoft Visual FoxPro");

            // Verify that Calculator is a running process.
            if (calculatorHandle == IntPtr.Zero)
            {
                Console.WriteLine("Calculator is not running.");
                return;
            }

            // Make Calculator the foreground application and send it 
            // a set of calculations.
            SetForegroundWindow(calculatorHandle);
            //Thread.Sleep(500);
            //SendKeys.Send("{RIGHT}");

            Thread.Sleep(3000);


            string[] lines = File.ReadAllLines("txt.txt");
            var lin = lines.ToList();

            SendStrings(lin);
        }

        private void SendStrings(List<string> lin)
        {
            //SendKeys.SendWait("^(y)");
            Thread.Sleep(50);
            foreach (var l in lin)
            {
                var kek = l.Split(',').ToList();

                foreach (var k in kek)
                {
                    Thread.Sleep(50);

                    SendKeys.Send(k);
                    Thread.Sleep(50);
                    //File.AppendAllText("kek.txt", k + ' ');
                    SendKeys.SendWait("{ENTER}");


                }
                //File.AppendAllText("kek.txt", "\n");
                Thread.Sleep(2000);

                SendKeys.SendWait("^(y)");
                Thread.Sleep(50);

            }

        }
    }
}

