using System;
using System.Collections.Generic;
using System.Linq;

public class SortNumbers
{
    /*
     * Sort Numbers
     *
     * Read a list of decimal numbers and sort them
     */
    private static void Main(string[] args)
    {
        List<decimal> numbers = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(decimal.Parse).ToList();

        numbers.Sort();

        Console.WriteLine(string.Join(" <= ", numbers));
    }
}