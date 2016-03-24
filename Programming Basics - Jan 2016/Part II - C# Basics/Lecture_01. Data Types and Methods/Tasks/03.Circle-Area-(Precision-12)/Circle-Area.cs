using System;

public class CircleArea
{
    private static void Main(string[] args)
    {
        double radius = double.Parse(Console.ReadLine());

        double circleArea = Math.PI * radius * radius;

        Console.WriteLine("{0:F12}", circleArea);
    }
}