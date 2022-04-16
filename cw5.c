#include <stdio.h>
#include <math.h>
#include <string.h>
int liczba(long long int x, int y){
    int q;
    char a[9]="", b[9]="", c[8]="";
    char znaki[16][100] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    if (x==0) strcat(a,"0");
    while(x>0){
        q=x%y;
        x=x/y;
        strcat(b,znaki[q]);
        strcat(b,a);
        memcpy(a,b,8);
        memcpy(b,c,8);
    }
    printf("%s",a);
}

int sys(long long int x, int y, int m){
    long int i=0, q, suma=0;
    if (x==0) return 0;
    while(x>0){
        q=x%y;
        x=x/y;
        i+=1;
        suma+=pow(q,m);
    }
    return suma;
}

int main()
{
    int m, b, max, min, q=0;
    scanf("%d %d",&m,&b);
    max=pow(b,m);
    min=pow(b,m-1);
    for(int i=min; i<max; i++){
        if (sys(i,b,m)==i){
            q=1;
            liczba(i,b);
            printf(" ");
        }
    }
    if (q==0) printf("NO");
    return 0;
}