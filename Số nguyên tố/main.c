#include <stdio.h>
#include <math.h>
int prime[1000001];
void sieve()
{
    for(int i=0; i<=1000000; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i=2; i<=1000; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j<=100000; j+=i)
                prime[j]=0;
        }
    }
    /*for(int i=0; i<=n; i++)
    {
        if(prime[i]) printf("%d ", i);
    }*/
}
int main()
{
    sieve();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(prime[n]) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

/*#include <stdio.h>
#include <math.h>
int max(int a, int b)
{
    if(a>b) return a;
    return b;
}
void sang(int l, int r)
{
    int prime[r-l+1];
    for(int i=0; i<=r-l; i++)
        prime[i]=1;
    for(int i=2; i<=sqrt(r); i++)
    {
        for(int j=max(i*i, (l+i-1)/i*i); j<=r; j+=i)
            prime[j-l]=0;
    }
    for(int i=max(l,2); i<=r; i++)
        if(prime[i-l]) printf("%d ", i);
}
int main()
{
    int l, r;
    scanf("%d %d", &l, &r);
    sang(l, r);
    return 0;
}
*/
#include<stdio.h>
#include<math.h>
int nt(int n)
{
    for(int i=2; i<= sqrt(r); i++)
    {
        if(n%i==0) return 0;
    }
    return n>1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(nt(n)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
