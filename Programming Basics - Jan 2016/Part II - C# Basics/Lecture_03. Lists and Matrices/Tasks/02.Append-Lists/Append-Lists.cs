using System;
using System.Collections.Generic;
using System.Linq;

public class AppendLists
{
    /*
     * Append Lists
     *
     * Write a program to append several lists of numbers
     *   - Lists are separated by |
     *   - Values are separated by spaces (one or several)
     *   - Order the lists from last to first, and their values from left to right
     */
    private static void Main(string[] args)
    {
        var separators = "|".ToArray();

        List<string> lists = Console.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries).ToList();

        List<int> result = new List<int>();

        for (int i = lists.Count - 1; i >= 0; i--)
        {
            var numbers = lists[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse);

            result.AddRange(numbers);
        }

        Console.WriteLine(string.Join(" ", result));
    }
}