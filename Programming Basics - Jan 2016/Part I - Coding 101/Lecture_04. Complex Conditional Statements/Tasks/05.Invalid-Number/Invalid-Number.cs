namespace Invalid_Number
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var number = int.Parse(Console.ReadLine());

            var isInRange = (100 <= number) && (number <= 200);
            var isZero = number == 0;
            var isValidNumber = isInRange || isZero;

            if (!isValidNumber)
            {
                Console.WriteLine("invalid");
            }
        }
    }
}
