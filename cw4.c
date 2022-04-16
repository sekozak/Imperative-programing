#include<stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int t[x];
    for(int i=0; i<x; i+=1){
        scanf("%d",&t[i]);
    }

    int i=0, j=x-1, suml=0, sumr=0, s=0, suma;
    while (i<j){
        suml+=t[i];
        sumr+=t[j];
        i+=1;
        j-=1;
    }
    if(x%2==1) suml+=t[i];
    suma=suml+sumr;
    for(int i=0; i<x; i+=1){
        if((suma-t[i])==s*2) printf("%d",i);
        s+=t[i];
    }

    return 0;
}
