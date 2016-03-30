using System;
using System.Linq;

/*
 * Max Sequence of Equal Elements
 *
 * Read a list of integers and find the longest sequence of equal elements. 
 * If several such exist, print the leftmost.
 */
public class MaxSequenceOfEqualElements
{
    private static void Main(string[] args)
    {
        int[] nums = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        int startIndexOfTheLongestSequence = 0;
        int countOfElementsInTheLongestSequence = 1;

        int pos = 0;

        while (pos < nums.Length)
        {
            int number = nums[pos];
            int count = 1;

            while (pos + count < nums.Length && nums[pos + count] == number)
            {
                count++;
            }

            if (count > countOfElementsInTheLongestSequence)
            {
                startIndexOfTheLongestSequence = pos;
                countOfElementsInTheLongestSequence = count;
            }

            pos += count;
        }

        for (int i = 0; i < countOfElementsInTheLongestSequence; i++)
        {
            Console.Write("{0} ", nums[startIndexOfTheLongestSequence]);
        }

        Console.WriteLine();
    }
}