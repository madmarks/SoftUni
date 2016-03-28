using System;

/*
 * Last K Numbers Sums
 *
 * Enter two integers n and k
 * Generate and print the following sequence:
 *   - The first element is: 1
 *   - All other elements = sum of the previous k elements
 * Example: n = 9, k = 5
 *   120 = 4 + 8 + 16 + 31 + 61   (1 1 2 4 8 16 31 61 120)
 */
public class Last_K_NumbersSums
{
    private static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var k = int.Parse(Console.ReadLine());

        long[] sequence = new long[n];

        sequence[0] = 1;

        for (int current = 1; current < n; current++)
        {
            var start = Math.Max(0, current - k);
            int end = current - 1;

            long sum = 0;

            for (int i = start; i <= end; i++)
            {
                sum += sequence[i];
            }

            sequence[current] = sum;
        }

        Console.WriteLine(string.Join(" ", sequence));
    }
}