namespace Concatenate_Data
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var firstName = Console.ReadLine();
            var lastName = Console.ReadLine();
            var age = Console.ReadLine();
            var town = Console.ReadLine();

            Console.WriteLine(
                "You are {0} {1}, a {2}-years old person from {3}.", 
                firstName, 
                lastName, 
                age, 
                town);
        }
    }
}
