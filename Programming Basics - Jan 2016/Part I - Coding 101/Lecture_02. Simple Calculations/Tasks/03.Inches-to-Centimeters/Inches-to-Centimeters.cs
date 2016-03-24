namespace Inches_to_Centimeters
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            // centimeters = 2.54 * inches
            Console.WriteLine("Inches to Centimeters Converter:");
            Console.Write("inches = ");
            var inches = double.Parse(Console.ReadLine());
            var centimeters = 2.54 * inches;
            Console.WriteLine("centimeters = " + centimeters);
        }
    }
}
