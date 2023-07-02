class Program
    {
        static void Main(string[] args)
        {
            // Шаг разбиения сетки
            var h = 0.01;

            // Создание списка узлов сетки
            var nodes = new List<double>();
            for (var x = 0.9; x <= 1.5; x += h)
            {
                nodes.Add(x);
            }

            var nodesCount = nodes.Count;

            // Создание матрицы системы уравнений
            var matrix = new double[nodesCount, nodesCount];
            var rightHandSide = new double[nodesCount];

            // Заполнение матрицы системы уравнений
            for (var i = 1; i < nodesCount - 1; i++)
            {
                var x = nodes[i];
                matrix[i, i - 1] = 1 / Math.Pow(h, 2) - 1 / (2 * h * 3);
                matrix[i, i] = -2 / Math.Pow(h, 2) + 2;
                matrix[i, i + 1] = 1 / Math.Pow(h, 2) + 1 / (2 * h * 3);
                rightHandSide[i] = Math.Pow(x, 2);
            }

            // Учет граничных условий
            var x0 = nodes[0];
            var xN = nodes[nodesCount - 1];

            matrix[0, 0] = 1;
            matrix[nodesCount - 1, nodesCount - 1] = 1;

            rightHandSide[0] = 0.9;
            rightHandSide[nodesCount - 1] = 2;

            matrix[0, 1] = 2;
            matrix[nodesCount - 1, nodesCount - 2] = -1 / (2 * h * 3);

            // Решение системы уравнений
            var solution = SolveSystem(matrix, rightHandSide);

            // Вывод результата в консоль
            for (var i = 0; i < nodesCount; i++)
            {
                Console.WriteLine("x = {0}, y = {1}", nodes[i], solution[i]);
            }

            Console.ReadLine();
        }

        // Метод решения системы уравнений методом прогонки
        private static double[] SolveSystem(double[,] matrix, double[] rightHandSide)
        {
            var N = rightHandSide.Length;

            // Прямой ход метода прогонки
            var alpha = new double[N];
            var beta = new double[N];
            alpha[1] = -matrix[0, 1] / matrix[0, 0];
            beta[1] = rightHandSide[0] / matrix[0, 0];

            for (var i = 1; i < N - 1; i++)
            {
                var denom = matrix[i, i] + matrix[i, i - 1] * alpha[i];
                alpha[i + 1] = -matrix[i, i + 1] / denom;
                beta[i + 1] = (rightHandSide[i] - matrix[i, i - 1] * beta[i]) / denom;
            }

            // Обратный ход метода прогонки
            var solution = new double[N];
            solution[N - 1] = (rightHandSide[N - 1] - matrix[N - 1, N - 2] * beta[N - 1]) /
                (matrix[N - 1, N - 1] + matrix[N - 1, N - 2] * alpha[N - 1]);

            for (var i = N - 2; i >= 0; i--)
            {
                solution[i] = alpha[i + 1] * solution[i + 1] + beta[i + 1];
            }

            return solution;
        }
    }