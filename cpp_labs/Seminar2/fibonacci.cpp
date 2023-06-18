#include <math.h>

unsigned long long fibonacci(int n) {
    const double SQRT5 = sqrt(5);
    const double PHI = (SQRT5 + 1) / 2;

    return pow(PHI, n) / SQRT5 + 0.5;
}