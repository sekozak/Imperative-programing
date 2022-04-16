#include <stdio.h>

int main()
{
    int n, r, sum, x, y, F[100][100], W[100][100];
    scanf("%d %d",&n,&r);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d",&F[i][j]);
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            sum=0;
            for (x=i-r; x<=i+r; x++){
                for (y=j-r; y<=j+r; y++){
                    if(x>=0 && x<n){
                        if(y>=0 && y<n){
                            sum+=F[x][y];
                        }
                    }
                }
            }
            W[i][j]=sum;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ",W[i][j]);
        }
        if(i!=n-1) printf("\n");
    }

    return 0;
}