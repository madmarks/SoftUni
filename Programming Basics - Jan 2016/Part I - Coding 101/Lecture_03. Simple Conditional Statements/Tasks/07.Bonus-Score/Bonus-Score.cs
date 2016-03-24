namespace Bonus_Score
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            Console.Write("Enter score: ");
            var score = int.Parse(Console.ReadLine());
            var bonus = 0.0;

            if (score <= 100)
            {
                bonus += 5;
            }
            else if (score <= 1000)
            {
                bonus += 0.2 * score;
            }
            else
            {
                bonus += 0.1 * score;
            }

            if (score % 2 == 0)
            {
                bonus += 1;
            }
            else if (score % 10 == 5)
            {
                bonus += 2;
            }

            Console.WriteLine("Bonus score: {0}", bonus);
            Console.WriteLine("Total score: {0}", score + bonus);
        }
    }
}