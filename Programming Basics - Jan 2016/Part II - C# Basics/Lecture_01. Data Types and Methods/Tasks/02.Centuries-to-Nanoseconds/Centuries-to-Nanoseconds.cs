using System;

public class CenturiesToNanoseconds
{
    private static void Main(string[] args)
    {
        ulong centuries = ulong.Parse(Console.ReadLine());

        ulong years = centuries * 100;
        ulong days = (ulong)(years * 365.2422m);
        ulong hours = days * 24;
        ulong minutes = hours * 60;
        ulong seconds = minutes * 60;
        decimal milliseconds = seconds * 1000m;
        decimal microseconds = milliseconds * 1000m;
        decimal nanoseconds = microseconds * 1000m;

        Console.WriteLine($"{centuries} centuries = {years} years = {days} days = {hours:f0} hours = {minutes:f0} minutes {seconds} seconds {milliseconds} milliseconds {microseconds} microseconds {nanoseconds} nanoseconds");
    }
}