using System;

/*
 * Matrix of Palindromes
 *
 * Write a program to generate the following matrix of palindromes of 
 * 3 letters with r rows and c columns:
 *
 * 4 6
 *
 * aaa aba aca ada aea afa
 * bbb bcb bdb beb bfb bgb
 * ccc cdc cec cfc cgc chc
 * ddd ded dfd dgd dhd did
 */
public class MatrixOfPalindromes
{
    private static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

        int rows = int.Parse(input[0]);
        int cols = int.Parse(input[1]);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                Console.Write((char)('a' + row) + ((char)('a' + row + col)).ToString() + (char)('a' + row) + " ");
            }

            Console.WriteLine();
        }
    }
}