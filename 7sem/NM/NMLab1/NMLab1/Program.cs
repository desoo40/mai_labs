using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NMLab1
{
    class Program
    {
        double f (double x, double t)
        {
            return (x + 3) / (t + 2);
        }

        double f1(double t)
        {
            return 9 - t / 4;
        }

        double f2(double t)
        {
            return 45 - t * t / 2 + 0.1 * t;
        }

        double f3(double x)
        {
            return 2 + 11 * Math.Sin(1.57079633 * x);
        }

        static void Main(string[] args)
        {
            var alp1 = 5;
            var alp2 = 6;
            var alp3 = 0.5;
            

        }
    }
}
