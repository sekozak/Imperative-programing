#include <math.h>
#include <stdio.h>
#include <time.h>

int czy_pierwsza(int n){
    if(n<2){
        return 0;
    }
    int m=sqrt(n);
    for(int i=2;i<=m;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int czy_malejaca(int n){
    int buff, x;
    buff = n%10;
    while(n>0){
        x = n%10;
        if(buff < x){
            return 0;
        }
        n /= 10;
        buff = x;
    }
    return 1;
}

int main()
{
    int n=10000000;
    /*scanf("%d", &n);*/
    clock_t start, stop;
    float time;
    start=clock();
    for(int i = 1;  i < n ;i++){
        if(czy_malejaca(i) == 1){
            if(czy_pierwsza(i) == 1){
                printf("%d\n", i);
            }
        }
    }
    stop=clock();
    time=(double)(stop - start)/CLOCKS_PER_SEC;
    printf("%.20f", time);
    return 0;
}