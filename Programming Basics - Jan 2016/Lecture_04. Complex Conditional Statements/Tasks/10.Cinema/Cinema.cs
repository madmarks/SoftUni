namespace Cinema
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var type = Console.ReadLine().ToLower();
            var rows = int.Parse(Console.ReadLine());
            var cols = int.Parse(Console.ReadLine());

            double ticketPrice = 0.0;

            if (type == "premiere")
            {
                ticketPrice = 12.0;
            }
            else if (type == "normal")
            {
                ticketPrice = 7.5;
            }
            else if (type == "discount")
            {
                ticketPrice = 5.0;
            }

            double income = ticketPrice * rows * cols;

            Console.WriteLine("{0:f2}\nleva", income);
        }
    }
}
