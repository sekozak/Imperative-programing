#include <stdio.h>
#include <malloc.h>

int main()
{
    int n,i,j,x,y,a,b,wynik=0,z1,z2;
    scanf("%d",&n);
    int **t;

    t = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) { t[i] = malloc(n * sizeof(int)); }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%d", &t[i][j]);
        }
    }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if(t[i][j]==0){
                x=1;y=1;z1=1;z2=1;
                while(z1 || z2) {
                    if (z1 && i+x<n) {
                        for (a = 0; a < y; a++) {
                            if(t[i+x][j+a]==1){
                                z1=0;
                                break;
                            }
                        }
                        if(z1==1) x++;
                    }
                    else{z1=0;}
                    if (z2 && j+y<n) {
                        for (b = 0; b < x; b++) {
                            if(t[i+b][j+y]==1) {
                                z2 = 0;
                                break;
                            }
                        }
                        if(z2==1) y++;
                    }
                    else{z2=0;}
                }
                if(x*y>wynik) wynik=x*y;
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