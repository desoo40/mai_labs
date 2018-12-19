using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using NMlab1;

namespace Sampling
{
    class Program
    {
        static void Main(string[] args)
        {
            var m = new Matrix();

            m.ReadFromFile("input.txt");

            m.Print("Matrix");

            JacobiMethod.JM(m, 0.001);
        }
    }
}
