#include <stdio.h>
#include <malloc.h>

int main()
{
    int n=201,N,i,j,wynik=0,x1,x2,y1,y2,q;
    scanf("%d",&N);
    int **t;
    int p[40000];

    t = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { t[i] = malloc(n * sizeof(int)); }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            t[i][j]=1;
        }
    }
    for (i=0;i<N*4;i++){
        scanf("%d", &p[i]);
    }

    for (int l=0;l<N*4;l+=4){
        x1=p[l]+100;
        y1=p[l+1]+100;
        x2=p[l+2]+100;
        y2=p[l+3]+100;
        if(x1>x2){
            q=x1;
            x1=x2;
            x2=q;
            q=y1;
            y1=y2;
            y2=q;
        }
        if(y1>y2){
            q=y1;
            y1=y2;
            y2=q;
        }
        for (i=x1;i<x2;i++){
            for (j=y1;j<y2;j++){
                t[i][j]*=-1;
            }
        }
    }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (t[i][j]==-1){
                wynik+=1;
            }
        }
    }

    printf("%d",wynik);

    for (i = 0; i < n; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}