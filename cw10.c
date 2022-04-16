#include <stdio.h>

int main()
{
    int n, len=1, q, k, T[1000],i ,j;
    T[0]=1;
    scanf("%d",&n);
    for (i=2; i<=n; i++){
        k=0;
        for (j=0; j<len; j++){
            q=(T[j]*i+k)/10;
            T[j]=(T[j]*i+k)%10;
            k=q;
        }
        if(k>0){
            while(k>0){
                T[len]=k%10;
                k/=10;
                len++;
            }
        }
    }
    for(i=1; i<=len; i++) printf("%d",T[len-i]);

    return 0;
}
