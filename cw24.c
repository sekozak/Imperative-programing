#include <stdio.h>

int main(){
    char x[50];
    scanf("%s",x);

    int i=0, q=0, l, ix=0;
    while(x[i]!=0) {
        q=0;
        while (x[i] > 0) {
            if (x[i] > q) {
                q = x[i];
                l = 0;
            }
            if (x[i] == q) {
                l++;
                ix = i;
            }
            i++;
        }

        for (i = 0; i < l; i++) {
            printf("%c", q);
        }

        i=ix+1;
    }
    return 0;
}