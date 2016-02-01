using System;

namespace Radians_to_Degrees
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Radians to Degrees Converter:");
            Console.Write("radians = ");
            var radians = double.Parse(Console.ReadLine());
            var degrees = (180.0 * radians) / Math.PI;

            Console.WriteLine("degrees = {0}", Math.Round(degrees));
        }
    }
}
