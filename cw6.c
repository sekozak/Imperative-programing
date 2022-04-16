#include<stdio.h>

int rek(int x, int t[], int i){
    if (x==0) return 1;
    if (i>=0){
        return rek(x-t[i],t,i-1) || rek(x+t[i],t,i-1) || rek(x,t,i-1);
    }
    else{
        return 0;
    }

}

int main()
{
    int n,w;
    scanf("%d %d",&n,&w);
    int t[n];
    for(int i=0; i<n; i+=1){
        scanf("%d",&t[i]);
    }

    if (rek(w,t,n-1)==1){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}