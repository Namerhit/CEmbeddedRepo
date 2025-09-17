#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    double z1, z2;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter y: ");
    scanf("%lf", &y);

    // z1 = cos^4(x) + sin^2(y) + (1/4) * sin^2(2x) - 1
    z1 = pow(cos(x), 4) + pow(sin(y), 2) + 0.25 * pow(sin(2 * x), 2) - 1;

    // z2 = sin(x + y) * sin(x - y)
    z2 = sin(x + y) * sin(x - y);

    printf("z1 = %lf\n", z1);
    printf("z2 = %lf\n", z2);

    return 0;
}
