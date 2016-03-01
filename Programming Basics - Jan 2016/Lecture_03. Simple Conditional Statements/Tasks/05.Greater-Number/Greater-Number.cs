namespace Greater_Number
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            // Console.WriteLine("Enter two integers: ");
            var num1 = int.Parse(Console.ReadLine());
            var num2 = int.Parse(Console.ReadLine());

            // Console.Write("Greater number: ");
            if (num1 > num2)
            {
                Console.WriteLine(num1);
            }
            else
            {
                Console.WriteLine(num2);
            }
        }
    }
}