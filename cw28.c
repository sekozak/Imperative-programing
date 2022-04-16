#include <stdio.h>
#include <malloc.h>

void dziel(int t[],int i){
    if(t[0]==0){t[0]=1; }
    else{t[0]=0; }
    for(int j=1; j<=i; j++ ){
        if(t[j]%2==0) t[j]/=2;
        else{
            t[j]/=2;
            if(j+1<=i) t[j+1]+=10;
        }
    }
}

int main() {
    int i,q;
    int *t,*tt,*bankomat1,*bankomat2;
    char n[100];
    scanf("%s",n);

    i=0;
    while(n[i]!='\0') i++;

    t = calloc(i+1, sizeof(int *));
    tt = calloc(i+1, sizeof(int *));
    bankomat1 = calloc(100, sizeof(int *));
    bankomat2 = calloc(100, sizeof(int *));

    tt[0]=1;
    for(int j=0; j<=i; j++ ) {
        if (n[j]=='0'){t[j+1]=0;tt[j+1]=0;}
        else if (n[j]=='1'){t[j+1]=1;tt[j+1]=1;}
        else if(n[j]=='2'){t[j+1]=2;tt[j+1]=2;}
        else if(n[j]=='3'){ t[j+1]=3;tt[j+1]=3;}
        else if(n[j]=='4'){ t[j+1]=4;tt[j+1]=4;}
        else if(n[j]=='5'){ t[j+1]=5;tt[j+1]=5;}
        else if(n[j]=='6'){ t[j+1]=6;tt[j+1]=6;}
        else if(n[j]=='7'){ t[j+1]=7;tt[j+1]=7;}
        else if(n[j]=='8'){ t[j+1]=8;tt[j+1]=8;}
        else if(n[j]=='9'){ t[j+1]=9;tt[j+1]=9;}
    }


    for(int j=1; j<=100; j++ ){
        bankomat1[j-1]=t[i]%2;
        if(t[0]==0){t[i]-=bankomat1[j-1]; }
        else t[i]+=bankomat1[j-1];
        dziel(t,i);
    }
    for(int j=1; j<=100; j++ ){
        bankomat2[j-1]=tt[i]%2;
        if(tt[0]==0){tt[i]-=bankomat2[j-1]; }
        else tt[i]+=bankomat2[j-1];
        dziel(tt,i);
    }


    if(t[i]==0) {
        for (int j = 0; j <= 100; j++) {
            if (bankomat1[j] != 0) q = j;
        }
        for (int j = 0; j <= q; j++) {
            if (bankomat1[j] == 1)printf("%d ", j);
        }
    } else printf("NO");
    printf("\n");
    if(tt[i]==0) {
        for (int j = 0; j <= 100; j++) {
            if (bankomat2[j] != 0) q = j;
        }
        for (int j = 0; j <= q; j++) {
            if (bankomat2[j] == 1)printf("%d ", j);
        }
    } else printf("NO");

    free(tt);
    free(t);

    return 0;
}