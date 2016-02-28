namespace _1000_Days_After_Birth
{
    using System;
    using System.Globalization;

    public class Program
    {
        private static void Main(string[] args)
        {
            CultureInfo provider = CultureInfo.InvariantCulture;

            // Console.Write("Enter birthday: ");
            // var birthDate = DateTime.ParseExact("25-02-1995", "dd-MM-yyyy", provider);
            var birthDate = DateTime.ParseExact(Console.ReadLine(), "dd-MM-yyyy", provider);            
            
            //// Console.WriteLine("Start date: {0}", birthDate.ToString("dd-MM-yyyy"));

            var days = 1000;

            // Console.WriteLine("After one thousand days: ");
            // Console.Write("After {0} days: ", days.ToString());
            Console.WriteLine("{0}", birthDate.AddDays(days - 1).ToString("dd-MM-yyyy"));
        }
    }
}
