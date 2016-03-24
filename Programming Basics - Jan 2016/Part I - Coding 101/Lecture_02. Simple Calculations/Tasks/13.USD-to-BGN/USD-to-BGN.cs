namespace USD_to_BGN
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine("USD to BGN Converter:");
            Console.Write("Input (USD): ");
            var bgn = double.Parse(Console.ReadLine());
            var usd = 1.79549 * bgn;

            Console.WriteLine("Output: {0} BGN", Math.Round(usd, 2));
        }
    }
}
