using System;
using System.Linq;

/*
 * Extract Middle 1, 2 or 3 Elements
 *
 * Write a method to extract the middle 1, 2 or 3 elements from array of n integers
 *   - if n = 1: extract 1 element
 *   - if n is even: extract 2 elements
 *   - if n is odd: extract 3 elements
 */
public class MiddleElements
{
    private static void Main(string[] args)
    {
        int[] nums = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        Console.WriteLine("{{ {0} }}", string.Join(", ", ExtractMiddleElements(nums)));

        // int n = nums.Length;
           
        // if (n == 1)
        // {
        //     Console.WriteLine("{{ {0} }}", nums[0]);
        // }
        // else if (n % 2 == 0)
        // {
        //     Console.WriteLine("{{ {0}, {1} }}", nums[(n / 2) - 1], nums[n / 2]);
        // }
        // else
        // {
        //     Console.WriteLine("{{ {0}, {1}, {2} }}", nums[(n / 2) - 1], nums[n / 2], nums[(n / 2) + 1]);
        // }
    }

    private static int[] ExtractMiddleElements(int[] arr)
    {
        int n = arr.Length;

        if (n == 1)
        {
            return arr;
        }
        else
        {
            int start = (n / 2) - 1;

            int[] extractedArr;

            if (n % 2 == 0)
            {
                extractedArr = new int[2];
                Array.Copy(arr, start, extractedArr, 0, 2);
            }
            else
            {
                extractedArr = new int[3];
                Array.Copy(arr, start, extractedArr, 0, 3);
            }

            return extractedArr;
        }
    }
}