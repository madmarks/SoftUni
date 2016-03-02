namespace Point_in_the_Figure
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            var h = int.Parse(Console.ReadLine());
            var x = int.Parse(Console.ReadLine());
            var y = int.Parse(Console.ReadLine());

            var rec1_BottomLeftCorner_X = 0;
            var rec1_BottomLeftCorner_Y = 0;
            var rec1_TopRightCorner_X = 3 * h;
            var rec1_TopRightCorner_Y = 1 * h;

            var rec2_BottomLeftCorner_X = 1 * h;
            var rec2_BottomLeftCorner_Y = 1 * h;
            var rec2_TopRightCorner_X = 2 * h;
            var rec2_TopRightCorner_Y = 4 * h;

            var isPointOutsideOfRec1 =
                x < rec1_BottomLeftCorner_X || rec1_TopRightCorner_X < x ||
                y < rec1_BottomLeftCorner_Y || rec1_TopRightCorner_Y < y;

            var isPointOutsideOfRec2 =
                x < rec2_BottomLeftCorner_X || rec2_TopRightCorner_X < x ||
                y < rec2_BottomLeftCorner_Y || rec2_TopRightCorner_Y < y;

            var isPointInsideOfRec1 =
                rec1_BottomLeftCorner_X < x && x < rec1_TopRightCorner_X &&
                rec1_BottomLeftCorner_Y < y && y < rec1_TopRightCorner_Y;

            var isPointInsideOfRec2 =
                rec2_BottomLeftCorner_X < x && x < rec2_TopRightCorner_X &&
                rec2_BottomLeftCorner_Y < y && y < rec2_TopRightCorner_Y;

            var isPointOnBorderBetween_rec1_and_rec2 = h < x && x < (2 * h) && y == h;

            var isPointOutsideOfFigure = isPointOutsideOfRec1 && isPointOutsideOfRec2;

            var isPointInsideOfFigure = isPointInsideOfRec1 || isPointInsideOfRec2 || isPointOnBorderBetween_rec1_and_rec2;

            if (isPointOutsideOfFigure)
            {
                Console.WriteLine("outside");
            }
            else if (isPointInsideOfFigure)
            {
                Console.WriteLine("inside");
            }
            else
            {
                Console.WriteLine("border");
            }
        }
    }
}