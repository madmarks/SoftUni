namespace Rectangle_Area
{
    using System;

    class Program
    {
        static void Main(string[] args)
        {
            var a = decimal.Parse(Console.ReadLine());
            var b = decimal.Parse(Console.ReadLine());

            Console.WriteLine((a * b).ToString());
        }
    }
}