#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, c, d, root1, root2, imaginary, real;
    printf("enter a, b, c of quadratic equation\n");
    scanf("%f %f %f", &a, &b, &c);
    d = b * b - 4 * a * c;

    if (d == 0)
    {
        printf("roots are equal\n");
        root1 = root2 = -b / (2 * a);
        printf("roots are %f and %f\n", root1, root2);
    }
    else if (d > 0)
    {
        printf("roots are real and different\n");
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("roots are %f and %f\n", root1, root2);
    }
    else
    {
        printf("roots are imaginary\n");
        imaginary = -b / (2 * a);
        real = sqrt(-d) / (2 * a);
        printf("roots are %f+%fi and %f-%fi\n", real, imaginary, real, imaginary);
    }

    return 0;
}