using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace case513
{
    class Program
    {
        static void Main(string[] args)
        {
            var b = new Basket();

            Console.Write(typeof(string).Assembly.ImageRuntimeVersion);
            try
            {
                b.AddProduct("", -1);
                b.AddProduct("Stick", 45);
                b.AddProduct("Helmet", 1);
                b.AddProduct("Gloves", 2);
                b.GetProducts();
                b.RemoveProduct("Gloves");
                b.GetProducts();

            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
            

        }
    }
}
