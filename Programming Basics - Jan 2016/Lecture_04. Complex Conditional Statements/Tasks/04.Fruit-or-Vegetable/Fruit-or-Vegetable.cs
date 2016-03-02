namespace Fruit_or_Vegetable
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var product = Console.ReadLine().Trim().ToLower();

            if (product == "banana" || product == "apple" || product == "kiwi" ||
                product == "cherry" || product == "lemon" || product == "grapes")
            {
                Console.WriteLine("fruit");
            }
            else if (product == "tomato" || product == "cucumber" ||
                product == "pepper" || product == "carrot")
            {
                Console.WriteLine("vegetable");
            }
            else
            {
                Console.WriteLine("unknown");
            }
        }
    }
}
