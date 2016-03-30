using System;
using System.Linq;

/*
 * 2 x 2 Squares in Matrix
 *
 * Find the count of 2 x 2 squares of equal chars in matrix of chars
 *   - The matrix size (rows and columns) is given at the first row
 *   - Matrix characters come at the next rows lines (space separated)
 */
public class _2x2_SquaresInMatrix
{
    private static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

        int rows = int.Parse(input[0]);
        int cols = int.Parse(input[1]);

        char[,] matrix = new char[rows, cols];

        for (int row = 0; row < rows; row++)
        {
            char[] items = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(char.Parse).ToArray();

            for (int col = 0; col < cols; col++)
            {
                matrix[row, col] = items[col];
            }
        }

        int count = 0;

        for (int row = 0; row < rows - 1; row++)
        {
            for (int col = 0; col < cols - 1; col++)
            {
                if (
                    matrix[row, col] == matrix[row, col + 1] &&
                    matrix[row, col] == matrix[row + 1, col] &&
                    matrix[row, col] == matrix[row + 1, col + 1])
                {
                    count++;
                }
            }
        }

        Console.WriteLine(count);
    }
}