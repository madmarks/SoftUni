using System;

/*
 * Matrix of Letters
 *
 * Build a matrix of capital Latin letters of size rows x cols
 */
public class MatrixOfLetters
{
    private static void Main(string[] args)
    {
        int rows = int.Parse(Console.ReadLine());
        int cols = int.Parse(Console.ReadLine());

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols - 1; col++)
            {
                Console.Write((char)((int)'A' + (((row * cols) + col) % 26)) + " ");
            }

            Console.WriteLine((char)((int)'A' + (((row * cols) + cols - 1) % 26)));
        }
    }
}