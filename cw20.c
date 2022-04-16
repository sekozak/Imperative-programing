#include <stdio.h>
#include <malloc.h>

int main(){
    int n,k,i,j,q,wynik=0,sumap1,sumap2,sumaw,sumak,dl;
    scanf("%d %d",&n,&k);
    int **t;

    t = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { t[i] = malloc(n * sizeof(int)); }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%d", &t[i][j]);
        }
    }


    for (i=0;i<n;i++){
        dl=0,q=0,j=0;
        sumap1=0,sumap2=0,sumaw=0,sumak=0;
        while(q<n){
            sumaw+=t[i][j];
            sumak+=t[j][i];
            sumap1+=t[j%n][(i+j)%n];
            sumap2+=t[n-1-(j%n)][(i+j)%n];
            j++;
            if(j==n){j=0; }

            if(dl==k){
                dl--;

                sumaw-=t[i][q];
                sumak-=t[q][i];
                sumap1-=t[q%n][(i+q)%n];
                sumap2-=t[n-1-(q%n)][(i+q)%n];

                q++;
            }

            dl++;
            if(dl==k){
                if(sumaw>wynik){wynik=sumaw; }
                if(sumak>wynik){wynik=sumak; }
                if(sumap1>wynik){wynik=sumap1; }
                if(sumap2>wynik){wynik=sumap2; }
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