using System;

public class MasterNumbers
{
    private static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());

        for (int num = 1; num <= n; num++)
        {
            if (IsMasterNumber(num))
            {
                Console.WriteLine(num);
            }
        }
    }

    private static bool IsMasterNumber(int num)
    {
        bool isSymmetric = IsPalindrome(num);

        bool sumOfDigitsIsDivisibleBy7 = SumOfDigits(num) % 7 == 0;

        bool holdsEvenDigit = HoldsEvenDigit(num);

        return isSymmetric && sumOfDigitsIsDivisibleBy7 && holdsEvenDigit;
    }

    private static bool IsPalindrome(int num)
    {
        string numString = string.Empty + num;

        for (int i = 0; i < numString.Length / 2; i++)
        {
            if (numString[i] != numString[numString.Length - 1 - i])
            {
                return false;
            }
        }

        return true;
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

    private static bool HoldsEvenDigit(int num)
    {
        if (num == 0)
        {
            return true;
        }

        while (num != 0)
        {
            int lastDigit = num % 10;

            if (lastDigit % 2 == 0)
            {
                return true;
            }

            num /= 10;
        }

        return false;
    }
}