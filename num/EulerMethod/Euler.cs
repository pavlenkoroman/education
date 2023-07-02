using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EulerMethod
{
    internal static class Euler
    {
        private const double H = 0.001; // Шаг
        private const double XStart = 0;
        private const double XEnd = 1;
        private const double Y0 = 0.4;
        private const double Z0 = 0.4;
        public static List<double[]> EulerDefault()
        {
            var xStart = XStart;
            var xEnd = XEnd;
            double yn = Y0;
            double zn = Z0;

            var result = new List<double[]>();

            double x = xStart;
            while (x < xEnd)
            {
                // Считаем значение производных функций для текущих x, y, z
                var dy1 = F1(x, yn, zn);
                var dy2 = F2(x, zn);

                // Используем формулу Эйлера для вычисления новых значений функций
                yn += H * dy1;
                zn += H * dy2;

                x += H;

                // Выводим результаты
                Console.WriteLine($"Текущие значения: x = {x}, y = {yn}, z = {zn}");

                result.Add(new double[] { x, yn, zn });
            }

            return result;
        }

        public static List<double[]> ModifiedEuler()
        {
            var result = new List<double[]>();
            double x = XStart;
            double y = Y0;
            double z = Z0;

            int n = (int)((1 - x) / H);

            double[] xData = new double[n + 1];
            double[] yData = new double[n + 1];
            double[] zData = new double[n + 1];

            xData[0] = x;
            yData[0] = y;
            zData[0] = z;

            while(x < XEnd)
            {
                double yPrime = F1(x, y, z);
                double zPrime = F2(x, z);

                double xMid = x + H / 2;
                double yMid = y + H / 2 * yPrime;
                double zMid = z + H / 2 * zPrime;

                double yPrimeMid = Math.Sqrt(xMid * xMid + 2 * yMid * yMid) + zMid;
                double zPrimeMid = Math.Cos(2 * zMid) + xMid;

                double xNew = x + H;
                double yNew = y + H * yPrimeMid;
                double zNew = z + H * zPrimeMid;

                result.Add(new double[] { xNew, yNew, zNew });

                x += H;
            }

            return result;
        }

        private static double F1(double x, double y, double z)
        {
            return Math.Sqrt(Math.Pow(x, 2) + 2 * Math.Pow(y, 2)) + z;
        }

        private static double F2(double x, double z)
        {
            return Math.Cos(2 * z) + x;
        }
    }
}
