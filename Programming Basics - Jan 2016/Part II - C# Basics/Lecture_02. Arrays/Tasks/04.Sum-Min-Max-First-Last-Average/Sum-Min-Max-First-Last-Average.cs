using System;
using System.Linq;

/*
 * Sum, Min, Max, First, Last, Average
 *
 * Write a program to read n integers and print their sum, 
 * min, max, first, last and average values
 */
public class SumMinMaxFirstLastAverage
{
    private static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());

        int[] nums = new int[n];

        for (int i = 0; i < n; i++)
        {
            nums[i] = int.Parse(Console.ReadLine());
        }

        Console.WriteLine("Sum = {0}", nums.Sum());
        Console.WriteLine("Min = {0}", nums.Min());
        Console.WriteLine("Max = {0}", nums.Max());
        Console.WriteLine("First = {0}", nums.First());
        Console.WriteLine("Last = {0}", nums.Last());
        Console.WriteLine("Average = {0}", nums.Average());
    }
}