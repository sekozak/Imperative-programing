#include <stdio.h>

int fibb(int n){
    int a = 0;
    int b = 1;
    int answ = 0;
    while(b <=n ){
        if(a*b == n){
            answ = 1;
        }
        b += a;
        a = b - a;
    }
    return answ;
}

int main()
{
    int n;
    scanf("%d", &n);
    int answ;
    answ = fibb(n);
    if(answ == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}