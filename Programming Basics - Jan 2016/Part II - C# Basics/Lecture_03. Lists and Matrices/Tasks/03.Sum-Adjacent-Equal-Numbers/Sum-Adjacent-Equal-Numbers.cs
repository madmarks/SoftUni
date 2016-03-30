using System;
using System.Collections.Generic;
using System.Linq;

public class SumAdjacentEqualNumbers
{
    /*
     * Sum Adjacent Equal Numbers
     *
     * Write a program to sum all adjacent equal numbers in a list of decimal numbers, 
     * starting from left to right
     *
     *  - After two numbers are summed, the obtained result could be equal to some of its 
     *    neighbors and should be summed as well
     */
    private static void Main(string[] args)
    {
        List<decimal> numbers = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(decimal.Parse).ToList();

        int pos = 0;
        while (pos < numbers.Count - 1)
        {
            if (numbers[pos] == numbers[pos + 1])
            {
                numbers[pos] = numbers[pos] + numbers[pos + 1];
                numbers.RemoveAt(pos + 1);

                if (pos > 0)
                {
                    pos--;
                }
            }
            else
            {
                pos++;
            }
        }

        Console.WriteLine(string.Join(" ", numbers));
    }
}