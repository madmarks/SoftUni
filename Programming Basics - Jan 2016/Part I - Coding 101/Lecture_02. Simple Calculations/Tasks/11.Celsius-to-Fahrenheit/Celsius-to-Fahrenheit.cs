namespace Celsius_to_Fahrenheit
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine("Celsius to Fahrenheit converter:");
            Console.Write("Celsius temperature = ");
            var celsius = double.Parse(Console.ReadLine());
            var fahrenheit = (1.8 * celsius) + 32.0;

            Console.WriteLine("Fahrenheit temperature = {0}", Math.Round(fahrenheit, 2));
        }
    }
}
