namespace Time_plus_15_Minutes
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var hour = int.Parse(Console.ReadLine());
            var minutes = int.Parse(Console.ReadLine());

            var totalMinutes = (hour * 60) + minutes;

            // add 15 minutes
            totalMinutes += 15;

            // 24 * 60 = 1440 minutes in twenty-four-hour period
            totalMinutes = totalMinutes % 1440;

            hour = totalMinutes / 60;
            minutes = totalMinutes % 60;

            Console.WriteLine("{0}:{1:D2}", hour, minutes);
        }
    }
}