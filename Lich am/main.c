#include <stdio.h>
#include <stdlib.h>
int main()
{
    int d, m, y;
    scanf("%d %d %d", &d, &m, &y);
    if (y < 1)
    {
        printf("%d/%d/%d: khong hop le\n", d, m, y);
        return 0;
    }
    if (m < 1 || m > 12)
    {
        printf("%d/%d/%d: khong hop le\n", d, m, y);
        return 0;
    }
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d < 1 || d > 31)
        {
            printf("%d/%d/%d: khong hop le\n", d, m, y);
            return 0;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (d < 1 || d > 30)
        {
            printf("%d/%d/%d: khong hop le\n", d, m, y);
            return 0;
        }
        break;
    case 2:
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        {
            if (d < 1 || d > 29)
            {
                printf("%d/%d/%d: khong hop le\n", d, m, y);
                return 0;
            }
        }
        else
        {
            if (d < 1 || d > 28)
            {
                printf("%d/%d/%d: khong hop le\n", d, m, y);
                return 0;
            }
        }
        break;
    default:
        printf("%d/%d/%d: khong hop le\n", d, m, y);
        return 0;
    }

    printf("%d/%d/%d: hop le\n", d, m, y);
    return 0;
}
