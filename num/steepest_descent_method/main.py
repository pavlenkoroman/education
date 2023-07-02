import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def function(x, y):
    return x ** 2 + 3 * y ** 2 - 5 * x * y + x + 2 * y


def partial_derivative_x(x, y):
    return 2 * x - 5 * y + 1


def partial_derivative_y(x, y):
    return 6 * y - 5 * x + 2


def gradient_descent(x_initial, y_initial, epsilon, learning_rate):
    x = x_initial
    y = y_initial
    x_history = [x]
    y_history = [y]

    for _ in range(1000):  # Максимальное количество итераций
        x_new = x - learning_rate * partial_derivative_x(x, y)
        y_new = y - learning_rate * partial_derivative_y(x, y)

        if abs(x_new - x) < epsilon and abs(y_new - y) < epsilon:
            break

        x = x_new
        y = y_new
        x_history.append(x)
        y_history.append(y)

    return x_history, y_history


# Задаем начальные значения
x_initial = 1
y_initial = 0
epsilon = 0.01
learning_rate = 0.1

# Выполняем метод наискорейшего спуска
x_history, y_history = gradient_descent(x_initial, y_initial, epsilon, learning_rate)

# Создаем сетку точек для построения графика
x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
X, Y = np.meshgrid(x, y)
Z = function(X, Y)

# Построение графика функции
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='viridis')

# Построение графика пути спуска
ax.plot(x_history, y_history, function(np.array(x_history), np.array(y_history)), color='red', marker='o')

# Настройка меток и заголовка
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Метод наискорейшего спуска')

# Отображение графика
plt.show()
