using System;

/*
 * Rotate a Matrix
 *
 * Write a program to read a matrix of words (space separated) and 
 * rotate it on the right
 */
public class RotateMatrix
{
    private static void Main(string[] args)
    {
        int rows = int.Parse(Console.ReadLine());
        int cols = int.Parse(Console.ReadLine());

        string[,] matrix = new string[rows, cols];

        for (int row = 0; row < rows; row++)
        {
            string[] cells = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            for (int col = 0; col < cols; col++)
            {
                matrix[row, col] = cells[col];
            }
        }

        for (int row = 0; row < cols; row++)
        {
            for (int col = rows - 1; col >= 0; col--)
            {
                Console.Write(matrix[col, row] + " ");
            }

            Console.WriteLine();
        }
    }
}