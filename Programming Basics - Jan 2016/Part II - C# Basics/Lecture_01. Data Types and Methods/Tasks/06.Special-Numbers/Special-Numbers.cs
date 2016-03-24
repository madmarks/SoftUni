using System;

public class SpecialNumbers
{
    private static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());

        for (int num = 1; num <= n; num++)
        {
            int sumOfDigits = SumOfDigits(num);

            bool special = sumOfDigits == 5 || sumOfDigits == 7 || sumOfDigits == 11;

            Console.WriteLine("{0} -> {1}", num, special);
        }
    }

    private static int SumOfDigits(int num)
    {
        int sum = 0;

        while (num != 0)
        {
            sum += num % 10;

            num /= 10;
        }

        return sum;
    }
}