#include <stdio.h>
#include <malloc.h>

int main()
{
    int i,wynik,rozne=0,wszystkie,n,m,x,y;
    scanf("%d %d",&n,&m);
    int *p;

    p = malloc((n+1) * sizeof(int));

    for (i=0;i<=n;i++){ p[i]=0; }
    for (i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        p[x]+=1;
        p[y]+=1;
    }

    for (i=1;i<=n;i++){ rozne+=(p[i]*(n-p[i]-1))/2; }

    wszystkie=n*(n-1)*(n-2)/6;
    wynik=wszystkie-rozne;
    printf("%d",wynik);

    free(p);

    return 0;
}