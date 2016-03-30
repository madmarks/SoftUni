using System;
using System.Collections.Generic;
using System.Linq;

public class RemoveNegativesAndReverse
{
    /*
     * Remove Negatives and Reverse
     *
     * Read a list of integers, remove all negative numbers from it and print the list in reversed order
     */
    private static void Main(string[] args)
    {
        var separators = " ".ToArray();

        List<int> nums = Console.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).Where(e => e >= 0).Reverse().ToList();

        if (nums.Count > 0)
        {
            Console.WriteLine(string.Join(" ", nums));
        }
        else
        {
            Console.WriteLine("empty");
        }
    }
}