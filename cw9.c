#include <stdio.h>
#include <math.h>

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

int jedno(int x){
    int y=0;
    if (x==1 || x==4) return x;
    else{
        while (x>0){
            y+=pow(x%10,2);
            x/=10;
        }
        jedno(y);
    }
}

int main()
{
    int l,u,k,odp=0,q;
    scanf("%d %d %d",&l,&u,&k);

    for (l;l<=u;l++){
        if (czy_pierwsza(l)==1){
            if(jedno(l)==1){
                k--;
                if (k==0) printf("%d",l);
            }
        }
    }
    if (k>0) printf("%d",-1);

    return 0;
}
