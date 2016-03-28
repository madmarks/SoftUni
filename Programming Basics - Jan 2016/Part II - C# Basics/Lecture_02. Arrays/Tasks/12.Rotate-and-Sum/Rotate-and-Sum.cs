using System;
using System.Linq;

/*
 * Rotate and Sum
 *
 * Read an array of n integers and an integer k. 
 * Rotate the array right k times and sum the obtained arrays.
 */
public class RotateAndSum
{
    private static void Main(string[] args)
    {
        int[] nums = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        int k = int.Parse(Console.ReadLine());

        int[] sum = new int[nums.Length];

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < nums.Length; j++)
            {
                sum[j] += nums[(nums.Length - (i % nums.Length) + j) % nums.Length];
            }
        }

        Console.WriteLine(string.Join(" ", sum));
    }
}