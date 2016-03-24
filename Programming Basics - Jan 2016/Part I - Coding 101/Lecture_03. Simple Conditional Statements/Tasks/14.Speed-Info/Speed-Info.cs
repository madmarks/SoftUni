namespace Speed_Info
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var speed = double.Parse(Console.ReadLine());

            if (speed <= 10.0)
            {
                Console.WriteLine("slow");
            }
            else if (speed <= 50.0)
            {
                Console.WriteLine("average");
            }
            else if (speed <= 150.0)
            {
                Console.WriteLine("fast");
            }
            else if (speed <= 1000.0)
            {
                Console.WriteLine("ultra fast");
            }
            else
            {
                Console.WriteLine("extremely fast");
            }
        }
    }
}