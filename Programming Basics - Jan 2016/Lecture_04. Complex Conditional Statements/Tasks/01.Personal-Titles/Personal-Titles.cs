namespace Personal_Titles
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var age = double.Parse(Console.ReadLine());
            var gender = Console.ReadLine().Trim().ToLower();
            var title = string.Empty;

            if (gender == "m")
            {
                if (age < 16)
                {
                    title = "Master";
                }
                else
                {
                    title = "Mr.";
                }
            }
            else
            {
                if (age < 16)
                {
                    title = "Miss";
                }
                else
                {
                    title = "Ms.";
                }
            }

            Console.WriteLine(title);
        }
    }
}
