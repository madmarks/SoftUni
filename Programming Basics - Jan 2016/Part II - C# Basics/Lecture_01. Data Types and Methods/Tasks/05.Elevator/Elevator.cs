﻿using System;

public class Elevator
{
    private static void Main(string[] args)
    {
        int persons = int.Parse(Console.ReadLine());
        int capacity = int.Parse(Console.ReadLine());

        int courses = (int)Math.Ceiling((double)persons / capacity);

        Console.WriteLine(courses);
    }
}