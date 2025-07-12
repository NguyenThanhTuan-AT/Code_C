#include <stdio.h>
int main()
{
    double a, b, x;
    printf("Nhap gia tri cua a= ");
    scanf("%lf", &a);
    printf("Nhap gia tri cua b= ");
    scanf("%lf", &b);
    if (a != 0)
    {
        x = -b / a;
        printf("%.5lf\n", x);
    }
    else
    {
        if (b == 0)
        {
            printf("Moi x la nghiem\n");
        }
        else
        {
            printf("Vo nghiem\n");
        }
    }

    return 0;
}
