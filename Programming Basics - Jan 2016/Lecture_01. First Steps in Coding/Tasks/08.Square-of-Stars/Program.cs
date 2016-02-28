namespace Square_of_Stars
{
    using System;

    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());

            if (n >= 2)
            {
                for (int i = 1; i <= n; i++)
                {
                    if(i == 1 || i == n)
                    {
                        Console.WriteLine(new String('*', n));
                    }
                    else
                    {
                        Console.WriteLine("*".PadRight((n - 1), ' ').PadRight(n, '*'));
                    }                    
                }
            }
            else
            {
                Console.WriteLine("Error");
            }
        }
    }
}
