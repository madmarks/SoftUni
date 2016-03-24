using System;

public class CenturiesToMinutes
{
    private static void Main(string[] args)
    {
        int centuries = int.Parse(Console.ReadLine());

        int years = centuries * 100;
        int days = (int)(years * 365.2422m);
        decimal hours = days * 24;
        decimal minutes = hours * 60;

        Console.WriteLine($"{centuries} centuries = {years} years = {days} days = {hours:f0} hours = {minutes:f0} minutes");
    }
}