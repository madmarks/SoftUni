using System;
using System.Collections.Generic;
using System.Linq;

/*
 * Largest Frame in Matrix
 *
 * Find the largest rectangular frame of same number in matrix of integers. 
 * If several equal sized largest frames exist, print all of them, sorted alphabetically.
 */
public class LargestFrameInMatrix
{
    private static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

        int rows = int.Parse(input[0]);
        int cols = int.Parse(input[1]);

        int[,] matrix = new int[rows, cols];

        for (int row = 0; row < rows; row++)
        {
            int[] items = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();

            for (int col = 0; col < cols; col++)
            {
                matrix[row, col] = items[col];
            }
        }

        int[,] rectangularFramesMap = new int[rows + 1, cols + 1];

        FillRectangularFramesMap(matrix, rectangularFramesMap);

        int largestRectangularFrameSize = GetLargestRectangularFrameSize(rectangularFramesMap);

        List<string> largestRectangularFrames =
            GetListOfLargestRectangularFrames(rectangularFramesMap, largestRectangularFrameSize);

        largestRectangularFrames.Sort();

        Console.WriteLine(string.Join(", ", largestRectangularFrames));
    }

    private static void FillRectangularFramesMap(int[,] matrix, int[,] rectangularFramesMap)
    {
        List<int> uniqueNumbers = GetListOfUniqueIntegerNumbers(matrix);

        int rows = rectangularFramesMap.GetLength(0);
        int cols = rectangularFramesMap.GetLength(1);

        foreach (var num in uniqueNumbers)
        {
            for (int rectangleRows = 1; rectangleRows < rows; rectangleRows++)
            {
                for (int rectangleCols = 1; rectangleCols < cols; rectangleCols++)
                {
                    rectangularFramesMap[rectangleRows, rectangleCols] +=
                        GetNumberOfValidRectangularFrames(num, matrix, rectangleRows, rectangleCols);
                }
            }
        }
    }

    private static int GetNumberOfValidRectangularFrames(int num, int[,] matrix, int rectangleRows, int rectangleCols)
    {
        int count = 0;

        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        for (int row = 0; row <= rows - rectangleRows; row++)
        {
            for (int col = 0; col <= cols - rectangleCols; col++)
            {
                if (IsValidRectangularFrame(num, matrix, row, col, rectangleRows, rectangleCols))
                {
                    count++;
                }
            }
        }

        return count;
    }

    private static bool IsValidRectangularFrame(int num, int[,] matrix, int row, int col, int rectangleRows, int rectangleCols)
    {
        int upperRow = row;
        int bottomRow = upperRow + rectangleRows - 1;

        int leftCol = col;
        int rightCol = leftCol + rectangleCols - 1;

        for (int i = leftCol; i <= rightCol; i++)
        {
            if (matrix[upperRow, i] != num || matrix[bottomRow, i] != num)
            {
                return false;
            }
        }

        for (int i = upperRow; i <= bottomRow; i++)
        {
            if (matrix[i, leftCol] != num || matrix[i, rightCol] != num)
            {
                return false;
            }
        }

        return true;
    }

    private static List<int> GetListOfUniqueIntegerNumbers(int[,] matrix)
    {
        List<int> uniqueNumbers = new List<int>();

        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (!uniqueNumbers.Contains(matrix[row, col]))
                {
                    uniqueNumbers.Add(matrix[row, col]);
                }
            }
        }

        return uniqueNumbers;
    }

    private static int GetLargestRectangularFrameSize(int[,] rectangularFramesMap)
    {
        int maxSize = 0;

        int rows = rectangularFramesMap.GetLength(0);
        int cols = rectangularFramesMap.GetLength(1);

        for (int row = 1; row < rows; row++)
        {
            for (int col = 1; col < cols; col++)
            {
                if (rectangularFramesMap[row, col] > 0 && (row * col) > maxSize)
                {
                    maxSize = row * col;
                }
            }
        }

        return maxSize;
    }

    private static List<string> GetListOfLargestRectangularFrames(int[,] rectangularFramesMap, int largestSize)
    {
        List<string> result = new List<string>();

        int rows = rectangularFramesMap.GetLength(0);
        int cols = rectangularFramesMap.GetLength(1);

        for (int row = 1; row < rows; row++)
        {
            for (int col = 1; col < cols; col++)
            {
                if (rectangularFramesMap[row, col] > 0 && (row * col) == largestSize)
                {
                    for (int count = 0; count < rectangularFramesMap[row, col]; count++)
                    {
                        result.Add(row + "x" + col);
                    }
                }
            }
        }

        return result;
    }
}