using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EulerMethod
{
    internal static class E
    {
        public static void Solve(
        Func<double, double, double[]> function1,
        Func<double, double, double[]> function2,
        double a,   // Начало
        double b,   // Конец
        double y0,  // Начальный y0 для первого уравнения
        double y1,  // Начальный y1 для второго уравнения
        double h)
        {
            var dy0 = new double[2];
            var dy1 = new double[2];

            for (var i = a; i < b; i += h)
            {
                dy0 = SolveFunctionAugment(function1, i, y0);
                dy1 = SolveFunctionAugment(function2, i, y1);
                Console.Write($"{dy0} {dy1}");
                Console.WriteLine();
            }
        }

        private static double[] SolveFunctionAugment(
            Func<double, double, double[]> function,
            double x,
            double y)
        {
            return function(x, y);
        }
    }
}
