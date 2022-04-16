#include <stdio.h>
#include <malloc.h>

int main()
{
    int n,k,l,i,j,suma,wynik=0,x,y;
    scanf("%d %d %d",&n,&k,&l);
    int **t, **p;

    t = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { t[i] = malloc(n * sizeof(int)); }

    p = malloc(k * sizeof(int *));
    for (i = 0; i < k; i++) { p[i] = malloc(l * sizeof(int)); }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%d", &t[i][j]);
        }
    }

    for (i=0;i<k;i++){
        for (j=0;j<l;j++){
            scanf("%d", &p[i][j]);
        }
    }


    for(i=0;i<n-k;i++){
        for(j=0;j<n-l;j++){
            suma=0;
            for(x=0;x<k;x++){
                for(y=0;y<l;y++){
                    if (p[x][y]==1){
                        suma+=t[i+x][j+y];
                    }
                }
            }
            if(suma>wynik){ wynik=suma; }
        }
    }

    printf("%d",wynik);



    for (i = 0; i < n; i++) {
        free(t[i]);
    }
    free(t);

    for (i = 0; i < k; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}