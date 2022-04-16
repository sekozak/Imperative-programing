#include <stdio.h>
#include <malloc.h>
#include <math.h>

int spr(int *t, int n){
    int q=0;
    for (int j=0;j<n;j++){
        if (t[j]==1 && t[j]==q){ return 0; }
        q=t[j];
    }
    return 1;
}

void add(int *t, int n){
    int q=0;
    t[n-1]+=1;
    for (int j=n-1;j>=0;j--){
        t[j]+=q;
        q=0;
        if(t[j]>1){
            t[j]=0;
            q=1;
        }
    }
}

int main(){
    int n,k,i,j,liczba=0,q=0;
    scanf("%d %d",&n,&k);
    int *t;

    t = malloc(n * sizeof(int *));

    for (i=0;i<n;i++){t[i]=0; }


    for (i=0;i<pow(2,n);i++){
        if(spr(t,n)){liczba++; }
        if(liczba==k){
            for (j=0;j<n;j++){
                printf("%d",t[j]);
            }
            q=1;
            break;
        }

        add(t,n);

    }

    if(q==0){printf("%d",-1); }

    free(t);

    return 0;
}