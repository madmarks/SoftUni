namespace Metric_Converter
{
    using System;

    public class Program
    {
        private static void Main(string[] args)
        {
            /* 1 meter(m) 1000 millimeters(mm)
             * 1 meter(m) 100 centimeters(cm)
             * 1 meter(m) 0.000621371192 miles(mi)
             * 1 meter(m) 39.3700787 inches(in)
             * 1 meter(m) 0.001 kilometers(km)
             * 1 meter(m) 3.2808399 feet(ft)
             * 1 meter(m) 1.0936133 yards(yd)
             */

            var distance = double.Parse(Console.ReadLine());
            var srcMetric = Console.ReadLine().ToLowerInvariant();
            var destMetric = Console.ReadLine().ToLowerInvariant();

            var distanceInMeters = 0.0;
            bool isSourceMetricSupported = true;

            if (srcMetric == "m")
            {
                distanceInMeters = distance;
            }
            else if (srcMetric == "mm")
            {
                distanceInMeters = distance / 1000;
            }
            else if (srcMetric == "cm")
            {
                distanceInMeters = distance / 100;
            }
            else if (srcMetric == "mi")
            {
                distanceInMeters = distance / 0.000621371192;
            }
            else if (srcMetric == "in")
            {
                distanceInMeters = distance / 39.3700787;
            }
            else if (srcMetric == "km")
            {
                distanceInMeters = distance / 0.001;
            }
            else if (srcMetric == "ft")
            {
                distanceInMeters = distance / 3.2808399;
            }
            else if (srcMetric == "yd")
            {
                distanceInMeters = distance / 1.0936133;
            }
            else
            {
                isSourceMetricSupported = false;
            }

            var result = 0.0;
            bool isDestinationMetricSupported = true;

            if (destMetric == "m")
            {
                result = distanceInMeters;
            }
            else if (destMetric == "mm")
            {
                result = distanceInMeters * 1000;
            }
            else if (destMetric == "cm")
            {
                result = distanceInMeters * 100;
            }
            else if (destMetric == "mi")
            {
                result = distanceInMeters * 0.000621371192;
            }
            else if (destMetric == "in")
            {
                result = distanceInMeters * 39.3700787;
            }
            else if (destMetric == "km")
            {
                result = distanceInMeters * 0.001;
            }
            else if (destMetric == "ft")
            {
                result = distanceInMeters * 3.2808399;
            }
            else if (destMetric == "yd")
            {
                result = distanceInMeters * 1.0936133;
            }
            else
            {
                isDestinationMetricSupported = false;
            }

            /* Judge изисква единствено: Console.WriteLine("{0} {1}", result, destMetric);
             *
             * иначе прави невалидни някои от тестовете при долната проверка, но така както работи в момента, 
             * позволява въвеждане на невалидни метрики за вход и/или за изход
             */

            if (!isSourceMetricSupported)
            {
                Console.WriteLine("Unsupported source metric!");
            }
            else if (!isDestinationMetricSupported)
            {
                Console.WriteLine("Unsupported destination metric!");
            }
            else
            {
                Console.WriteLine("{0} {1}", result, destMetric);
            }
        }
    }
}
