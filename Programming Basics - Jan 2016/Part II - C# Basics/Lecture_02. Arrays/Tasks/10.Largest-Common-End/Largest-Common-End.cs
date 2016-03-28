using System;
using System.Linq;

/*
 * Largest Common End
 *
 * Read two arrays of words and find the length of the largest common end (left or right)
 */
public class LargestCommonEnd
{
    private static void Main(string[] args)
    {
        string[] words1 = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToArray();
        string[] words2 = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToArray();

        Console.WriteLine("{0}", LargestCommonEndLength(words1, words2));
    }

    private static int LargestCommonEndLength(string[] words1, string[] words2)
    {
        int startLen = 0;
        int endLen = 0;

        for (int i = 0; i < Math.Min(words1.Length, words2.Length); i++)
        {
            if (words1[i] == words2[i])
            {
                startLen++;
            }
            else
            {
                break;
            }
        }

        for (int i = 0; i < Math.Min(words1.Length, words2.Length); i++)
        {
            if (words1[words1.Length - 1 - i] == words2[words2.Length - 1 - i])
            {
                endLen++;
            }
            else
            {
                break;
            }
        }

        return Math.Max(startLen, endLen);
    }
}