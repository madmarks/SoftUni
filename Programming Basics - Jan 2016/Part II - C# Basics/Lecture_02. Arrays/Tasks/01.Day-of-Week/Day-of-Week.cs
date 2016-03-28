using System;

public class DayOfWeek
{
    /*
     * Day of Week
     *
     * Enter a day number [1…7] and print the day name (in English) or "Invalid day!"
     */
    private static void Main(string[] args)
    {
        string[] daysOfWeek =
        {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
        };

        var n = int.Parse(Console.ReadLine());

        if (1 <= n && n <= 7)
        {
            Console.WriteLine(daysOfWeek[n - 1]);
        }
        else
        {
            Console.WriteLine("Invalid day!");
        }
    }
}