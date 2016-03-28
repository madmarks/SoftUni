using System;
using System.Linq;

/*
 * Fold and Sum
 *
 * Read an array of 4*k integers, fold it like shown below, and print the sum of 
 * the upper and lower rows (2*k integers):
 *
 */
public class FoldAndSum
{
    private static void Main(string[] args)
    {
        int[] nums = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        Console.WriteLine(string.Join(" ", FoldAndSumArray(nums)));
    }

    private static int[] FoldAndSumArray(int[] nums)
    {
        int[] sum = new int[nums.Length / 2];

        for (int i = 0; i < sum.Length / 2; i++)
        {
            sum[i] = nums[(nums.Length / 4) + i] + nums[(nums.Length / 4) - 1 - i];

            sum[(sum.Length / 2) + i] = nums[(nums.Length / 2) + i] + nums[nums.Length - 1 - i];
        }

        return sum;
    }
}