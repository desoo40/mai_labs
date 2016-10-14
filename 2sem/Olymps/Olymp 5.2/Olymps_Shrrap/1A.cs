using System;
using System.Linq;

namespace Olymps_Shrrap
{
    class Program
    {
        public static void Main()
        {
            var a = Console.ReadLine();
            short s = 0;
            for (int i = 0; i < a.Length; ++i)
            {
                if(a[i] == ' ') continue;
                s += (short) a[i];
            }

            Console.WriteLine(s);
            //Console.WriteLine(Console.ReadLine().Split(' ').Sum(s=>int.Parse(s)));
            //Console.WriteLine(Console.ReadLine().Split(' ').Sum(int.Parse));
        }
    }
}
