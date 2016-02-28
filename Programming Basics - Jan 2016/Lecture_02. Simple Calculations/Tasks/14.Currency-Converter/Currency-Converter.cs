namespace Currency_Converter
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            const decimal USD_RATE = 1.79549M;
            const decimal EUR_RATE = 1.95583M;
            const decimal GBP_RATE = 2.53405M;

            Console.WriteLine("Currency Converter:");
            var value = decimal.Parse(Console.ReadLine());
            var srcCurrency = Console.ReadLine().ToUpper();
            var destCurrency = Console.ReadLine().ToUpper();

            decimal bgnValue = value;
            switch (srcCurrency)
            {
                case "BGN":
                    break;
                case "USD":
                    bgnValue = value * USD_RATE;
                    break;
                case "EUR":
                    bgnValue = value * EUR_RATE;
                    break;
                case "GBP":
                    bgnValue = value * GBP_RATE;
                    break;
            }

            decimal destValue = bgnValue;
            switch (destCurrency)
            {
                case "BGN":
                    break;
                case "USD":
                    destValue = bgnValue / USD_RATE;
                    break;
                case "EUR":
                    destValue = bgnValue / EUR_RATE;
                    break;
                case "GBP":
                    destValue = bgnValue / GBP_RATE;
                    break;
            }

            Console.WriteLine("{0} {1}", Math.Round(destValue, 2), destCurrency);
        }
    }
}
