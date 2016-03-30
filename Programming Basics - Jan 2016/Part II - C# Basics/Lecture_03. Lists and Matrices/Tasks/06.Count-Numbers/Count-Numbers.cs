using System;
using System.Collections.Generic;
using System.Linq;

public class CountNumbers
{
    /*
     * Count-Numbers
     *
     * Read a list of integers in range [0…1000] and print them in ascending 
     * order along with their number of occurrences
     */
    private static void Main(string[] args)
    {
        List<int> numbers = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToList();

        numbers.Sort();

        int pos = 0;

        while (pos < numbers.Count)
        {
            int num = numbers[pos];
            int count = 1;

            while (pos + count < numbers.Count && numbers[pos + count] == num)
            {
                count++;
            }

            Console.WriteLine("{0} -> {1}", num, count);

            pos += count;
        }
    }
}