namespace Small_Shop
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var product = Console.ReadLine().Trim().ToLower();
            var town = Console.ReadLine().Trim().ToLower();
            var quantity = double.Parse(Console.ReadLine());
            double price = 0.0;

            if (product == "coffee")
            {
                if (town == "sofia")
                {
                    price = 0.50 * quantity;
                }
                else if (town == "plovdiv")
                {
                    price = 0.40 * quantity;
                }
                else if (town == "varna")
                {
                    price = 0.45 * quantity;
                }
            }
            else if (product == "water")
            {
                if (town == "sofia")
                {
                    price = 0.80 * quantity;
                }
                else if (town == "plovdiv")
                {
                    price = 0.70 * quantity;
                }
                else if (town == "varna")
                {
                    price = 0.70 * quantity;
                }
            }
            else if (product == "beer")
            {
                if (town == "sofia")
                {
                    price = 1.20 * quantity;
                }
                else if (town == "plovdiv")
                {
                    price = 1.15 * quantity;
                }
                else if (town == "varna")
                {
                    price = 1.10 * quantity;
                }
            }
            else if (product == "sweets")
            {
                if (town == "sofia")
                {
                    price = 1.45 * quantity;
                }
                else if (town == "plovdiv")
                {
                    price = 1.30 * quantity;
                }
                else if (town == "varna")
                {
                    price = 1.35 * quantity;
                }
            }
            else if (product == "peanuts")
            {
                if (town == "sofia")
                {
                    price = 1.60 * quantity;
                }
                else if (town == "plovdiv")
                {
                    price = 1.50 * quantity;
                }
                else if (town == "varna")
                {
                    price = 1.55 * quantity;
                }
            }

            Console.WriteLine(price);
        }
    }
}
