#include <stdio.h>
#include <stdlib.h>
int main()
{
    //freopen("D:\\Code\\input.txt","r", stdin);
    double a, b, c, d, e, f;
    double D, Dx, Dy, x, y;
    scanf("%lf %lf %lf", &a, &b, &e);
    scanf("%lf %lf %lf", &c, &d, &f);
    D = a * d - b * c;
    Dx = e * d - b * f;
    Dy = a * f - e * c;
    if (D != 0)
    {
        x = Dx / D;
        y = Dy / D;
        printf("He phuong trinh co nghiem duy nhat\n");
        printf("x = %.5lf\n", x);
        printf("y = %.5lf\n", y);
    }
    else
    {
        if (Dx == 0 && Dy == 0)
        {
            printf("He phuong trinh co vo so nghiem\n");
        }
        else
        {
            printf("He phuong trinh vo nghiem\n");
        }
    }

    return 0;
}
