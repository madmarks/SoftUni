namespace Sum_Seconds
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var num1 = int.Parse(Console.ReadLine());
            var num2 = int.Parse(Console.ReadLine());
            var num3 = int.Parse(Console.ReadLine());

            var sum = num1 + num2 + num3;
            var minutes = sum / 60;
            var seconds = sum % 60;

            // Console.Write("Total time: ");
            Console.WriteLine("{0}:{1:D2}", minutes, seconds);
        }
    }
}