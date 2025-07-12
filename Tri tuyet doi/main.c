#include <stdio.h>
int main()
{
    double x;
    printf("Nhap vao mot so thuc: x = ");
    scanf("%lf", &x);
    if (x < 0)
    {
        x = -x;
    }
    printf("|x| = %.3lf\n", x);
    return 0;
}
