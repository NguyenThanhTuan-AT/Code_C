#include <stdio.h>
#include <stdlib.h>
int X[9], a[9], b[17], c[15], t=1;
int ketqua(int X[])
{
    printf("\n Lan %2d : ", t);
    for(int j = 1; j<=8; j++)
    {
        printf("%d ", X[j]);
    }
    t++;
}

void try(int j)
{
    for(int i = 1; i<= 8; i++)
    {
        if(a[i] && b[i+j] && c[i-j+7])
        {
            X[j] = i;
            a[i] = b[i+j] = c[i-j+7] = 0;
            if(j<8) try(j+1);
            else ketqua(X);
            a[i] = b[i+j] = c[i-j + 7] = 1;

        }
    }
}
int main()
{
    for(int i =1; i<= 8; i++) a[i] = 1;
    for(int i = 2 ; i<= 16; i++) b[i] = 1;
    for(int i = 0; i<= 14; i++) c[i] = 1;
    try(1);
    return 0;
}
