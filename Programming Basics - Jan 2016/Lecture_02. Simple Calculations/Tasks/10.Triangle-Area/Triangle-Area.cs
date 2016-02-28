namespace Triangle_Area
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var side = double.Parse(Console.ReadLine());
            var height = double.Parse(Console.ReadLine());

            var area = side * height / 2;
            Console.WriteLine("Triangle area = {0}", Math.Round(area, 2));
        }
    }
}
