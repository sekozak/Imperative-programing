#include <math.h>
#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    int ilosc=0;
    int tab[m-n];
    while(n<=m) {
        int s = 1, p = sqrt(n);
        for (int i = 2; i <= p; i++)
            if (n % i == 0)
                s += i + n / i;

        if (n == p * p) s -= p;

        if (n == s){
            tab[ilosc]=n;
            ilosc += 1;
        }
        n += 1;
    }
    printf("%d\n",ilosc);
    for (int i = 0; i < ilosc; i++)
        printf("%d ",tab[i]);

    return 0;
}