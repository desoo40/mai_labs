using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace some_olymp
{
    class Program
    {
        Stack<char> scopes = new Stack<char>();

        static void Main(string[] args)
        {
            var line = Console.ReadLine();
            var MaxUnder = FindMaxUnder(line);

        }

        private static object FindMaxUnder(string line)
        {
            var ans = "";
            int maxLenght = 0;
            int currLenght = 0;

            for (var i = 0; i < line.Length; ++i)
            {
                if (line[i] == ')' && currLenght == 0)
                {
                    
                }
            }

            return ans;
        }
    }
}
