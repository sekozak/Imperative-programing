#include <stdio.h>
#include <math.h>

int first(int x){
    for(int i=2;i<=pow(x,0.5);i++){
        if(x%i==0){return 0; }
    }
    return 1;
}

int main(){
    char x[51],wynik[51],tmp[51],q;
    scanf("%s",x);
    int i,n=0,z,j,k,l;

    i=0;q='z';
    while(x[i]!=0){
        if(x[i]<q){q=x[i]; }
        i++;
        n++;
    }

    for(k=0;k<n;k++){wynik[k] = x[k]; }

    for(i=0;i<n;i++){
        if(x[i]==q){
            for(j=2;j<n;j++){
                if(first(j)==1){
                    for(k=0;k<n;k++){
                        tmp[k]=x[(i+(j*k))%n];
                    }
                    z=0;
                    for(k=0;k<n;k++){
                        if(tmp[k]<wynik[k]){z=1; }
                        if(tmp[k]>wynik[k]){break; }
                    }
                    if (z==1){
                        for(l=0;l<n;l++){
                            wynik[l]=tmp[l];
                        }
                    }
                }
            }
        }
    }

    for(j=0;j<n;j++) {
        printf("%c", wynik[j]);
    }

    return 0;
}
