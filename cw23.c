#include <stdio.h>

int main(){
    int n,i,ilosc;
    scanf("%d",&n);

    long long wynik=0,j;
    for (i=1;i<=n/2;i+=2) {
        j=i*2,ilosc=0;
        while(j<=n){
            ilosc++;
            j*=2;
        }
        wynik+=ilosc*i;
    }


    j=n;
    if(n%2==1){wynik+=((1+j)/2)*((j/2)+1); }
    else{
        j--;
        wynik+=((1+j)/2)*((j/2)+1);
    }

    printf("%lld", wynik);

    return 0;
}
//10000000000000
//577403702195153628
