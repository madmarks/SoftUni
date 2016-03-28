using System;
using System.Linq;

/*
 * Rounding Numbers
 *
 * Read an array of real numbers (space separated values), 
 * round them in "away from 0" style and print the output
 */
public class RoundingNumbers
{
    private static void Main(string[] args)
    {
        double[] numbers = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(double.Parse).ToArray();

        for (int i = 0; i < numbers.Length; i++)
        {
            Console.WriteLine("{0} => {1}", numbers[i], Math.Round(numbers[i], MidpointRounding.AwayFromZero));
        }
    }
}