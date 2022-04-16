#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, t[100], t2[10000], t1[100][100], q, y, wiersz=0, ix=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) {
            scanf("%d",&t1[i][j]);
        }
    }

    for (int i=0; i<n; i++) t[i]=0;

    while (y){
        q=10000000;
        y=0;
        for (int i=0; i<n; i++){
            if (t[i]<n) {
                y=1;
                if (t1[i][t[i]] <= q) {
                    q = t1[i][t[i]];
                    wiersz = i;
                }
            }
        }
        if (y){
            if (ix>0) {
                if (t2[ix - 1] >= q) t[wiersz] += 1;
                else{
                    t2[ix] = q;
                    t[wiersz] += 1;
                    ix++;
                }
            }
            else{
                t2[ix] = q;
                t[wiersz] += 1;
                ix++;
            }
        }
    }

    for(int i=0; i<ix; i++) printf("%d ",t2[i]);

    return 0;
}