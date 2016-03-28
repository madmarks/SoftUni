using System;
using System.Linq;

public class CondenseArrayToNumber
{
    private static void Main()
    {
        int[] nums = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        while (nums.Length > 1)
        {
            int[] condensedArr = new int[nums.Length - 1];

            for (int i = 0; i < condensedArr.Length; i++)
            {
                condensedArr[i] = nums[i] + nums[i + 1];
            }

            nums = condensedArr;
        }

        Console.WriteLine(nums[0]);
    }
}