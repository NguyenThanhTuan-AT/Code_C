#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    double S=1.0;
    scanf("%d", &n);
    for(int i=2; i<=n; i++)
    {
        S+=1.0/i;
    }
    printf("%lf", S);
    return 0;
}
long long factorial(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    double eps;
    int x;
    scanf("%d %lf", &x, &eps);
    double E = 1.0, term;
    int i = 1;

    do
    {
        double giaithua = factorial(i);
        term = pow(x, i) / giaithua;
        E += term;
        i++;
    }
    while (fabs(term) > eps);
    printf("%lf\n", E);

    return 0;
}

}/*
int giaithua(int n)
{
    if(n==1) return 1;
    else return n*giaithua(n-1);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", giaithua(n));
}
#include <stdio.h>
#include <ctype.h>
#define MAX_CHAR 256
void count_char_frequency(const char *str) {
    int freq[MAX_CHAR] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c>='A' && c<='Z') c +=('a'-'A');
        freq[(int)c]++;
    }
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", (char)i, freq[i]);
        }
    }
}

int main() {
    char input[1001];
    fgets(input, sizeof(input), stdin);
    count_char_frequency(input);

    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void foo()
{
    int *px = (int*)malloc(sizeof(int));
    *px = 0x11223344;
    printf("Address = %p\n", px);
}
int main()
{
    unsigned int addr;
    foo();
    printf("Enter the address: ");
    scanf("%x", &addr);
    int *p = (int*)addr;
    printf("The number is: %x\n",*p);
    return 0;
}
int main()
{
    int*p, len, i;
    scanf("%d",&len);
    p=(int*)malloc(len*sizeof(int));
    memset(p, 0, len*sizeof(int));
    free(p);
    return 0;
}
#include <stdio.h>
#include <math.h>
int Sphenic(int n)
{
    int res=0;
    for(int i=2; i*i<=n; i++)
    {
        int cnt = 0;
        while(n%i==0)
        {
            ++cnt;
            n/=i;
        }
        if(cnt>=2) return 0;
        if(cnt=1) ++res;
    }
    if(n!=1) ++res;
    return res==3;
}
int count2(int n)
{
    int res=0;
    for(int i=5; i<=n; i*=5)
        res += n/i;
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", Sphenic(n));
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int degree;
    double *coeffs;
} Polynomial;
void inputPolynomial(Polynomial *p)
{
    scanf("%d", &p->degree);
    p->coeffs = (double *)malloc((p->degree+1)* sizeof(double));
    if(p->coeffs == NULL) exit(1);
    for(int i=0; i<= p->degree; i++)
        scanf("%lf", &p->coeffs[i]);
}
void printPolynomial(Polynomial p)
{
    for(int i=0; i<=p.degree; i++)
        printf("%.5lf ", p.coeffs[i]);
    printf("\n");
}
double evaluate(Polynomial p, double x)
{
    double result = p.coeffs[p.degree] ;
    for(int i=p.degree-1; i>=0; i--)
    {
    result = result * x + p.coeffs[i];
    }
    return result;
}
Polynomial add(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    result.degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;
    result.coeffs = (double *)calloc((result.degree+1), sizeof(double));
    if(result.coeffs == NULL) exit(1);
    for(int i=0; i<=result.degree; i++)
    {
        if(i<=p1.degree) result.coeffs[i] += p1.coeffs[i];
        if(i<=p2.degree) result.coeffs[i] += p2.coeffs[i];
    }
    return result;
}
Polynomial subtract(Polynomial p1, Polynomial p2)
{
    Polynomial result;
    result.degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;
    result.coeffs = (double *)calloc((result.degree+1), sizeof(double));
     if(result.coeffs == NULL) exit(1);
     for(int i=0; i<=result.degree; i++)
    {
        if(i<=p1.degree) result.coeffs[i] += p1.coeffs[i];
        if(i<=p2.degree) result.coeffs[i] -= p2.coeffs[i];
    }
    return result;
}
void freePolynomial(Polynomial *p)
{
    free(p->coeffs);
    p->coeffs = NULL;
}
int main()
{
    freopen("D:\\Code\\input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        Polynomial p1, p2;
        double x;
        inputPolynomial(&p1);
        inputPolynomial(&p2);
        scanf("%lf", &x);
        Polynomial sum = add(p1, p2);
        Polynomial diff = subtract(p1, p2);
        printf("p1(x) = %.5lf\n", evaluate(p1, x));
        printf("p2(x) = %.5lf\n", evaluate(p2, x));
        printf("p1+p2 = ");
        printPolynomial(sum);
        printf("p1-p2 = ");
        printPolynomial(diff);
        printf("\n");
        freePolynomial(&p1);
        freePolynomial(&p2);
        freePolynomial(&sum);
        freePolynomial(&diff);
    }
    return 0;
}
*/

