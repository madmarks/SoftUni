using System;

public class PrimeNumbers
{
    /* 
     * Sieve of Eratosthenes
     *
     * Write a program to find all prime numbers in range [0…n]
     */
    private static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        bool[] primes = new bool[n + 1];

        // primes[0] = false; and primes[1] = false, because 0 and 1 are not primes
        for (int i = 2; i <= n; i++)
        {
            primes[i] = true;
        }

        // mark as "false" multiples of i
        for (int i = 2; i <= n; i++)
        {
            if (primes[i])
            {
                FillNotPrimes(primes, i);
            }
        }

        // print prime numbers
        for (int i = 2; i <= n; i++)
        {
            if (primes[i])
            {
                Console.Write(i + " ");
            }
        }

        Console.WriteLine();
    }

    private static void FillNotPrimes(bool[] primes, int step)
    {
        for (int i = 2 * step; i < primes.Length; i += step)
        {
            primes[i] = false;
        }
    }
}