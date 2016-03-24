namespace Volleyball
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            const int WeeksPerYearSuitableForVolleyball = 48;
            var yearType = Console.ReadLine().ToLower();
            var holidaysThatAreNotWeekends = int.Parse(Console.ReadLine()); // p
            var weekendsAtHomeTown = int.Parse(Console.ReadLine()); // h

            var result = ((WeeksPerYearSuitableForVolleyball - weekendsAtHomeTown) * (3.0 / 4.0)) +
                weekendsAtHomeTown +
                (holidaysThatAreNotWeekends * (2.0 / 3.0));

            if (yearType == "leap")
            {
                result *= 1.15;
            }

            Console.WriteLine(Math.Truncate(result));
        }
    }
}
