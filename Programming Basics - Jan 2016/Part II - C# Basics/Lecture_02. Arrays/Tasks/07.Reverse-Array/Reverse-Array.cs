using System;
using System.Linq;

/*
 * Reverse Array
 *
 * Read an array of strings (space separated values), reverse it and print its elements
 */
public class ReverseArray
{
    private static void Main(string[] args)
    {
        string[] strings = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToArray();

        Console.WriteLine(string.Join(" ", strings.Reverse().ToArray()));
    }
}