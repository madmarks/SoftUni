using System;
using System.Linq;

/*
 * Sum Arrays
 *
 * Write a program that reads two arrays of integers and sums them.
 * When elements are less, duplicate the smaller array a few times.
 */
public class SumArrays
{
    private static void Main(string[] args)
    {
        int[] nums1 = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        int[] nums2 = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        int length = Math.Max(nums1.Length, nums2.Length);

        int[] sum = new int[length];

        for (int i = 0; i < length; i++)
        {
            sum[i] = nums1[i % nums1.Length] + nums2[i % nums2.Length];
        }

        Console.WriteLine(string.Join(" ", sum));
    }
}