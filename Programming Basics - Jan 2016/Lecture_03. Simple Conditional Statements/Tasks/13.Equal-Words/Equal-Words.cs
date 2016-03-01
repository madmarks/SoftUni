namespace Equal_Words
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var word1 = Console.ReadLine().ToLowerInvariant();
            var word2 = Console.ReadLine().ToLowerInvariant();

            if (word1 == word2)
            {
                Console.WriteLine("yes");
            }
            else
            {
                Console.WriteLine("no");
            }
        }
    }
}