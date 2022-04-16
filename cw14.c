#include <stdio.h>

int main()
{
    int n,x,y,a,b,li,i,j;
    scanf("%d",&n);
    int t[100][100];

    x=n+1; y=n; a=0; b=-1; li=1;

    while (x!=0) {
        x -= 1;
        y -= 1;
        for (i = 0; i < x; i++) {
            b += 1;
            t[a][b] = li;
            li += 1;
        }
        for (i = 0; i < y; i++) {
            a += 1;
            t[a][b] = li;
            li += 1;
        }
        if (x == 0) break;
        x -= 1;
        y -= 1;

        for(i = 0; i < x; i++) {
            b -= 1;
            t[a][b] = li;
            li += 1;
        }
        for(i = 0; i < y; i++) {
            a -= 1;
            t[a][b] = li;
            li += 1;
        }
    }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}