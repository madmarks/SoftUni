namespace Number_0__100_to_Text
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var num = int.Parse(Console.ReadLine());
            var result = string.Empty;

            if (num == 100)
            {
                result = "one hundred";
            }
            else if ((19 < num && num < 100) || (0 < num && num < 10))
            {
                int num_div_10 = num / 10;
                int num_mod_10 = num % 10;

                if (num_div_10 == 9)
                {
                    result = "ninety";
                }
                else if (num_div_10 == 8)
                {
                    result = "eighty";
                }
                else if (num_div_10 == 7)
                {
                    result = "seventy";
                }
                else if (num_div_10 == 6)
                {
                    result = "sixty";
                }
                else if (num_div_10 == 5)
                {
                    result = "fifty";
                }
                else if (num_div_10 == 4)
                {
                    result = "forty";
                }
                else if (num_div_10 == 3)
                {
                    result = "thirty";
                }
                else if (num_div_10 == 2)
                {
                    result = "twenty";
                }

                if (num_mod_10 > 0)
                {
                    if (19 < num && num < 100)
                    {
                        result += " ";
                    }

                    if (num_mod_10 == 1)
                    {
                        result += "one";
                    }
                    else if (num_mod_10 == 2)
                    {
                        result += "two";
                    }
                    else if (num_mod_10 == 3)
                    {
                        result += "three";
                    }
                    else if (num_mod_10 == 4)
                    {
                        result += "four";
                    }
                    else if (num_mod_10 == 5)
                    {
                        result += "five";
                    }
                    else if (num_mod_10 == 6)
                    {
                        result += "six";
                    }
                    else if (num_mod_10 == 7)
                    {
                        result += "seven";
                    }
                    else if (num_mod_10 == 8)
                    {
                        result += "eight";
                    }
                    else if (num_mod_10 == 9)
                    {
                        result += "nine";
                    }
                }
            }
            else if (num == 19)
            {
                result = "nineteen";
            }
            else if (num == 18)
            {
                result = "eighteen";
            }
            else if (num == 17)
            {
                result = "seventeen";
            }
            else if (num == 16)
            {
                result = "sixteen";
            }
            else if (num == 15)
            {
                result = "fifteen";
            }
            else if (num == 14)
            {
                result = "fourteen";
            }
            else if (num == 13)
            {
                result = "thirteen";
            }
            else if (num == 12)
            {
                result = "twelve";
            }
            else if (num == 11)
            {
                result = "eleven";
            }
            else if (num == 10)
            {
                result = "ten";
            }
            else if (num == 0)
            {
                result = "zero";
            }
            else
            {
                result = "invalid number";
            }

            Console.WriteLine(result);
        }
    }
}