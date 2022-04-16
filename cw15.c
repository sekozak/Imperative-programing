#include <stdio.h>
#include <malloc.h>

int main()
{

    int n,k,i,j,wyniki=0,suma,w[10000],r,l;
    scanf("%d %d",&n,&k);
    int **t;

    t = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { t[i] = malloc(n * sizeof(int)); }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%d", &t[i][j]);
        }
    }

    for (i=1;i<n-1;i++){
        for (j=1;j<n-1;j++){
            r=1;
            while(r){
                suma=0;
                if(i-r>=0 && i+r<n && j-r>=0 && j+r<n){
                    for(l=0;l<2*r+1;l++){
                        suma+=t[i-r+l][j-r];
                        suma+=t[i-r+l][j+r];
                        suma+=t[i-r][j-r+l];
                        suma+=t[i+r][j-r+l];
                    }
                    suma-=t[i-r][j-r];
                    suma-=t[i-r][j+r];
                    suma-=t[i+r][j-r];
                    suma-=t[i+r][j+r];

                    if(suma==k){
                        w[wyniki*2]=i;
                        w[wyniki*2+1]=j;
                        wyniki++;
                        r=-1;
                    }
                    r++;
                }
                else {
                    r=0;
                }
            }
        }
    }

    printf("%d\n",wyniki);
    for(i=0;i<wyniki;i++){
        printf("%d %d\n",w[i*2],w[i*2+1]);
    }

    for (i = 0; i < n; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}