using System;

public class FilledSquare
{
    private static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());

        PrintHeaderRow(2 * n);

        for (int i = 1; i < n - 1; i++)
        {
            PrintMiddleRow(n);
        }

        PrintHeaderRow(2 * n);
    }

    private static void PrintHeaderRow(int count)
    {
        Console.WriteLine(new string('-', count));
    }

    private static void PrintMiddleRow(int n)
    {
        string row = "-";

        for (int i = 1; i < n; i++)
        {
            row += @"\/";
        }

        row += "-";

        Console.WriteLine(row);
    }
}