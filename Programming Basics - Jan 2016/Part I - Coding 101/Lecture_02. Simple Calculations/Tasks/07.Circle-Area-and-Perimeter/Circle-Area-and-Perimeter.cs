namespace Circle_Area_and_Perimeter
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            Console.Write("Circle radius r = ");
            var radius = double.Parse(Console.ReadLine());
            var perimeter = 2 * Math.PI * radius;
            var circleArea = Math.PI * radius * radius;
            Console.WriteLine("Area = {0}", circleArea);
            Console.WriteLine("Perimeter = {0}", perimeter);
        }
    }
}
