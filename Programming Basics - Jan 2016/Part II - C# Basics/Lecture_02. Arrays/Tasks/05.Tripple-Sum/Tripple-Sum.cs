using System;
using System.Linq;

/*
 * Triple Sum (a + b == c)
 *
 * Write a program to read an array of integers and find all triples of elements a, b and c, 
 * such that a + b == c (a stays left from b)
 */
public class TrippleSum
{
    private static void Main(string[] args)
    {
        char[] charSeparators = new char[] { ',', '.', '!', '?', ';', ':', ' ' };

        string[] stringSeparators = { ",", ".", "!", "?", ";", ":", " " };

        var nums = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        var count = 0;

        for (int i = 0; i < nums.Length - 1; i++)
        {
            for (int j = i + 1; j < nums.Length; j++)
            {
                var a = nums[i];
                var b = nums[j];
                var c = nums[i] + nums[j];

                if (nums.Contains(c))
                {
                    Console.WriteLine($"{a} + {b} == {c}");

                    count++;
                }
            }
        }

        if (count == 0)
        {
            Console.WriteLine("No");
        }
    }
}