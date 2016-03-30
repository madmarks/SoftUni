using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;

/*
 * Largest Increasing Subsequence
 *
 * Read a list of integers and find the longest increasing subsequence. 
 * If several such exist, print, the leftmost. 
 *
 *                Input                | Output
 * ------------------------------------|---------------
 *                                   1 | 1
 * ------------------------------------|---------------
 *                    7 3 5 8 -1 0 6 7 | 3 5 6 7
 * ------------------------------------|---------------
 *                     1 2 5 3 5 2 4 1 | 1 2 3 5
 * ------------------------------------|---------------
 *     0 10 20 30 30 40 1 50 2 3 4 5 6 | 0 1 2 3 4 5 6
 * ------------------------------------|---------------
 * 11 12 13 3 14 4 15 5 6 7 8 7 16 9 8 | 3 4 5 6 7 8 16
 * ------------------------------------|---------------
 */
public static class LongestIncreasingSubsequence
{
    private static void Main(string[] args)
    {
        int[] nums = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

        List<int> longestIncreasingSubsequenceList = GetLongestIncreasingSubsequenceList(nums);

        Console.WriteLine(string.Join(" ", longestIncreasingSubsequenceList.ToArray()));
    }

    private static List<int> GetLongestIncreasingSubsequenceList(int[] arr)
    {
        List<int> longestIncreasingSubsequenceList = new List<int>();

        for (int i = 0; i < arr.Length; i++)
        {
            List<int> currentLongestIncreasingSubsequenceList = new List<int>();

            currentLongestIncreasingSubsequenceList.Add(arr[i]);

            int startIdxOfSubArray = i + 1;
            int lengthOfSubArray = arr.Length - startIdxOfSubArray;

            currentLongestIncreasingSubsequenceList.AddRange(GetLongestIncreasingSubsequenceList(arr[i], arr, startIdxOfSubArray, lengthOfSubArray));

            if (currentLongestIncreasingSubsequenceList.Count > longestIncreasingSubsequenceList.Count)
            {
                longestIncreasingSubsequenceList = currentLongestIncreasingSubsequenceList;
            }
        }

        return longestIncreasingSubsequenceList;
    }

    /// <summary>
    /// Finds longest increasing subsequence
    /// </summary>
    /// <param name="prevElement"></param>
    /// <param name="arr"></param>
    /// <param name="idx">Start index of sub-array</param>
    /// <param name="length">Length of sub-array</param>
    /// <returns></returns>
    private static List<int> GetLongestIncreasingSubsequenceList(int prevElement, int[] arr, int idx, int length)
    {
        List<int> longestIncreasingSubsequenceList = new List<int>();

        if (length == 1)
        {
            if (prevElement < arr[idx])
            {
                longestIncreasingSubsequenceList.Add(arr[idx]);
            }
        }
        else if (length > 1)
        {
            for (int i = idx; i < idx + length; i++)
            {
                if (prevElement < arr[i])
                {
                    List<int> currentLongestIncreasingSubsequenceList = new List<int>();

                    currentLongestIncreasingSubsequenceList.Add(arr[i]);

                    int startIdxOfSubArray = i + 1;
                    int lengthOfSubArray = arr.Length - startIdxOfSubArray;

                    currentLongestIncreasingSubsequenceList.AddRange(GetLongestIncreasingSubsequenceList(arr[i], arr, startIdxOfSubArray, lengthOfSubArray));

                    if (currentLongestIncreasingSubsequenceList.Count > longestIncreasingSubsequenceList.Count)
                    {
                        longestIncreasingSubsequenceList = currentLongestIncreasingSubsequenceList;
                    }
                }
            }
        }

        return longestIncreasingSubsequenceList;
    }

    /// <summary>
    /// Getting a sub-array from an existing array.
    /// 
    /// http://stackoverflow.com/questions/943635/getting-a-sub-array-from-an-existing-array
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="data"></param>
    /// <param name="index"></param>
    /// <param name="length"></param>
    /// <returns></returns>
    private static T[] SubArray<T>(this T[] data, int index, int length)
    {
        T[] result = new T[length];
        Array.Copy(data, index, result, 0, length);
        return result;
    }

    /// <summary>
    /// Getting a deep clone sub-array from an existing array.
    /// This does require the objects to be serializable ([Serializable] or ISerializable).
    /// 
    /// You must use deep clone when need to clone array with reference type data
    /// 
    /// http://stackoverflow.com/questions/943635/getting-a-sub-array-from-an-existing-array
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="data"></param>
    /// <param name="index"></param>
    /// <param name="length"></param>
    /// <returns></returns>
    private static T[] SubArrayDeepClone<T>(this T[] data, int index, int length)
    {
        T[] arrCopy = new T[length];
        Array.Copy(data, index, arrCopy, 0, length);
        using (MemoryStream ms = new MemoryStream())
        {
            var bf = new BinaryFormatter();
            bf.Serialize(ms, arrCopy);
            ms.Position = 0;
            return (T[])bf.Deserialize(ms);
        }
    }
}