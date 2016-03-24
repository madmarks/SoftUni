namespace Trade_Comissions
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var town = Console.ReadLine().Trim().ToLower();
            var quantity = double.Parse(Console.ReadLine());

            var commission = -1.0;

            if (town == "sofia")
            {
                if (0.0 <= quantity && quantity <= 500.0)
                {
                    commission = 5.0;
                }
                else if (500.0 < quantity && quantity <= 1000.0)
                {
                    commission = 7.0;
                }
                else if (1000.0 < quantity && quantity <= 10000.0)
                {
                    commission = 8.0;
                }
                else if (10000.0 < quantity)
                {
                    commission = 12.0;
                }
            }
            else if (town == "varna")
            {
                if (0.0 <= quantity && quantity <= 500.0)
                {
                    commission = 4.5;
                }
                else if (500.0 < quantity && quantity <= 1000.0)
                {
                    commission = 7.5;
                }
                else if (1000.0 < quantity && quantity <= 10000.0)
                {
                    commission = 10.0;
                }
                else if (10000.0 < quantity)
                {
                    commission = 13.0;
                }
            }
            else if (town == "plovdiv")
            {
                if (0.0 <= quantity && quantity <= 500.0)
                {
                    commission = 5.5;
                }
                else if (500.0 < quantity && quantity <= 1000.0)
                {
                    commission = 8.0;
                }
                else if (1000.0 < quantity && quantity <= 10000.0)
                {
                    commission = 12.0;
                }
                else if (10000.0 < quantity)
                {
                    commission = 14.5;
                }
            }

            if (commission == -1.0)
            {
                Console.WriteLine("error");
            }
            else
            {
                Console.WriteLine("{0:f2}", (quantity * commission) / 100.0);
            }
        }
    }
}
