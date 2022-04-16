#include <stdio.h>
#include <malloc.h>

int main(){
    int n,g,wynik,*t,q,count,k=0,p=1;
    scanf("%d %d",&n,&g);
    t= malloc(n * sizeof(int *));

    for(int i=0;i<n;i++){scanf("%d",&t[i]); }

    while(g>p){
        p*=2;
        k++;
    }

    for(int j=0;j<k;j++){
        if(g & (1<<j)){}
        else{
            for(int i=0;i<n;i++) {
                q = t[i];
                if (q & (1 << j)) {t[i] = 0; }
            }
        }
    }

    wynik=n;
    for(int j=0;j<k;j++){
        count=0;
        if(g & (1<<j)){
            for(int i=0;i<n;i++) {
                q = t[i];
                if (q < p) {
                    if (q & (1 << j)){count++; }
                }
            }
            if(count<wynik){wynik=count; }
        }
    }

    if(n==wynik){wynik=0; }
    printf("%d",wynik);
    free(t);

    return 0;
}