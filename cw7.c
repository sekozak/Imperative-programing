#include <stdio.h>

int main()
{
    int n,m,suma=0,id,max;
    scanf("%d %d",&n,&m);
    int t[n];
    for (int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    for (int i=0;i<m;i++){
        max=0;
        for (int j=0;j<n;j++){
            if (t[j]>max){
                max=t[j];
                id=j;
            }
        }
        t[id]/=2;
    }
    for (int i=0;i<n;i++){
        suma+=t[i];
    }

    printf("%d",suma);

    return 0;
}
