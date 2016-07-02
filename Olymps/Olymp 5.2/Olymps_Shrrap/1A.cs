using System;

namespace Olymps_Shrrap
{
    class Program
    {
        static void Main()
        {
			int sum = 0;
			foreach (var a in (Console.ReadLine()).Split(' '))
			{
				sum += int.Parse(a);
			}

            Console.WriteLine(sum);
        }
    }
}
