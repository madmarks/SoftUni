namespace Area_of_Figures
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var figure = Console.ReadLine();

            if (figure == "square")
            {
                var side = double.Parse(Console.ReadLine());

                Console.WriteLine("{0}", Math.Round(side * side, 3));
            }
            else if (figure == "rectangle")
            {
                var sideA = double.Parse(Console.ReadLine());
                var sideB = double.Parse(Console.ReadLine());

                Console.WriteLine("{0}", Math.Round(sideA * sideB, 3));
            }
            else if (figure == "circle")
            {
                var radius = double.Parse(Console.ReadLine());

                Console.WriteLine("{0}", Math.Round(Math.PI * radius * radius, 3));
            }
            else if (figure == "triangle")
            {
                var side = double.Parse(Console.ReadLine());
                var height = double.Parse(Console.ReadLine());

                Console.WriteLine("{0}", Math.Round(side * height / 2, 3));
            }
        }
    }
}