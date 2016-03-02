namespace Point_on_Rectangle_Border
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var x1 = double.Parse(Console.ReadLine());
            var y1 = double.Parse(Console.ReadLine());
            var x2 = double.Parse(Console.ReadLine());
            var y2 = double.Parse(Console.ReadLine());
            var x = double.Parse(Console.ReadLine());
            var y = double.Parse(Console.ReadLine());

            var onLeftSide = (x == x1) && (y1 <= y) && (y <= y2);
            var onRightSide = (x == x2) && (y1 <= y) && (y <= y2);
            var onUpperSide = (y == y1) && (x1 <= x) && (x <= x2);
            var onBottomSide = (y == y2) && (x1 <= x) && (x <= x2);

            if (onLeftSide || onRightSide || onUpperSide || onBottomSide)
            {
                Console.WriteLine("Border");
            }
            else
            {
                Console.WriteLine("Inside / Outside");
            }
        }
    }
}
