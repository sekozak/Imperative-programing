#include <stdio.h>

long long f(long long x){
    long long suma=0;
    while(x>0){
        suma+=x;
        x/=10;
    }
    return suma;
}

int main(){
    long long n,i,x;
    scanf("%lld",&n);

    x=n*0.9;

    int bool=1;
    for (i=x-100;i<=x+100;i++){
        if(f(i)==n){
            printf("%lld",i);
            bool=0;
            break;
        }
    }
    if(bool){ printf("%d",-1); }

    return 0;
}