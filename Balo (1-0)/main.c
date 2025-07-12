#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if(a<b) return b;
    else return a;
}
int main()
{
    int n, S;
    printf("Nhap sl do vat va trong luong balo:\n");
    scanf("%d %d", &n, &S);
    int w[n+1], v[n+1];
    int dp[n+1][S+1];
    printf("Nhap trong luong cua vat:\n");
    for(int i = 1; i<=n; i++) scanf("%d", &w[i]);
    printf("Nhap gia tri cua vat:\n");
    for(int i =1; i<=n; i++) scanf("%d", &v[i]);

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<= S; j++)
        {
            if( i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i-1][j];
                if(j>=w[i])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<= S; j++)
        {
            printf("%2d  ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
