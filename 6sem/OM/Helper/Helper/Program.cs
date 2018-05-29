using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Helper
{
    class Program
    {
        static void Main(string[] args)
        {
            while (1 == 1)
            {
                var x1 = Convert.ToDouble(Console.ReadLine());
                var x2 = Convert.ToDouble(Console.ReadLine());

                var fx = 3 * x1 * x1 + 2 * x2 * x2 + 90 * x1 + 120 * x2 + 11 * 15 * 15;
                var gr1 = 6 * x1 + 90;
                var gr2 = 4 * x2 + 120;
                var norm = Math.Sqrt(gr1 * gr1 + gr2 * gr2);

                Console.WriteLine("gr1 " + gr1);
                Console.WriteLine("gr2 " + gr2);
                Console.WriteLine("norm " + norm);
                Console.WriteLine("fx " + fx);
            }
        }
    }
}
