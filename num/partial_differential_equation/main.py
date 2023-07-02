import numpy as np
import matplotlib.pyplot as plt

# Заданные параметры
L = 0.6  # Длина промежутка x
T = 0.1  # Конечное время t
Nx = 7  # Количество узлов по x
Nt = 11  # Количество узлов по t
dx = L / (Nx - 1)  # Шаг по x
dt = T / (Nt - 1)  # Шаг по t

# Создание сетки значений x и t
x = np.linspace(0, L, Nx)
t = np.linspace(0, T, Nt)

# Инициализация сеточной функции U
U = np.zeros((Nt, Nx))

# Установка начальных условий
f = lambda x: 2 * x * (1 - x) + 0.2
U[0, :] = f(x)

# Установка граничных условий
F = lambda t: 0.2
Y = lambda t: t + 0.68
U[:, 0] = F(t)
U[:, Nx - 1] = Y(t)

# Численное решение
for i in range(1, Nt):
    for j in range(1, Nx - 1):
        U[i, j] = U[i - 1, j] + (dt * (U[i - 1, j + 1] - 2 * U[i - 1, j] + U[i - 1, j - 1])) / (dx ** 2)

# Построение графика
X, T = np.meshgrid(x, t)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_wireframe(X, T, U, cmap='viridis')
ax.set_xlabel('x')
ax.set_ylabel('t')
ax.set_zlabel('U')
plt.show()

# Вывод численного решения
print("Численное решение:")
for i in range(Nt):
    for j in range(Nx):
        print(f"U({x[j]:.2f}, {t[i]:.2f}) = {U[i, j]:.4f}")

print("Численное решение:")
print(U)
