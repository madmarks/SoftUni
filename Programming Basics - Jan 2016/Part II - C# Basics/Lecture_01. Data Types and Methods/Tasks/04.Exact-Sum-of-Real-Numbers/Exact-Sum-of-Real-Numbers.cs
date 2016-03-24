using System;

public class ExactSumOfRealNumbers
{
    private static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        decimal sum = 0.0m;

        for (int i = 0; i < n; i++)
        {
            sum += decimal.Parse(Console.ReadLine());
        }

        // decimals can have at most 29 significant digits
        Console.WriteLine(sum.ToString("0.#############################"));
    }
}