#include <stdio.h>
#include <math.h>

int main(){
    int n,m,wynik=0;
    long int k;
    scanf("%d %d",&n,&m);

    k=pow(2,n);
    for(int i=1;i<k;i++){
        if(i%m!=0){
            for(int j=0;j<n;j++){
                if(i & (1<<j)) {
                    i-=1 << j;
                    if (i%m==0) {
                        if (i != 0) {
                            wynik++;
                            i+=1<<j;
                            break;
                        }
                    }
                    i+=1<<j;
                }
                else{
                    i+=1<<j;
                    if (i%m==0) {
                        if (i != 0) {
                            wynik++;
                            i-=1<<j;
                            break;
                        }
                    }
                    i-=1<<j;
                }
            }
        }
    }

    printf("%d",wynik);

    return 0;
}