#include <stdio.h>
#include <malloc.h>

void lewo(int t[], int p){
    t[p]--;
    t[p-1]++;
    t[p-2]++;
}

void prawo(int t[], int p){
    t[p]--;
    t[p+1]--;
    t[p+2]++;
}

void unbox(int t[], int p){
    lewo(t,p);
    prawo(t,p-1);
    prawo(t,p);
}

int main() {
    int n, x, q, y = 1, pole, l;
    scanf("%d", &n);
    int **t, *t1;

    t = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) { t[i] = malloc(2 * sizeof(int)); }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) { scanf("%d", &t[i][j]); }
    }

    x = (t[n - 1][0] - t[0][0] + 80);
    t1 = malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++) t1[i] = 0;

    for (int i = 0; i < n; i++) t1[t[i][0] + 40] = t[i][1];

    while (y == 1) {
        y = 0;
        for (int i = 0; i < x; i++) {
            q = t1[i] / 3;
            if (q > 0) y = 1;
            for (int j = 0; j < q; j++) unbox(t1, i);
        }
    }

    for (int i = 0; i < x; i++) {
        if (t1[i] != 0) pole = i;
    }

    y = 1;
    while (y == 1) {
        for (int j = 0; j < x; j++) {
            if (t1[j] != 0) {
                l = j;
                break;
            }
        }
        if (t1[pole] > 0 && t1[pole + 1] > 0) {
            prawo(t1, pole);
            pole += 2;
        } else if (t1[pole] == 2 && t1[pole - 1] > 0) {
            pole--;
        } else if (t1[pole] == 2 && t1[pole + 1] == 0) {
            lewo(t1, pole);
            prawo(t1, pole - 1);
            pole++;
        } else if (t1[pole] == 3) {
            unbox(t1, pole);
            pole += 2;
        } else if (l == pole) {
            y = 0;
        } else {
            pole--;
            while (t1[pole] == 0) pole--;
        }
    }


    for (int i = 0; i < x; i++) {
        if(t1[i]!=0) printf("%d ", i-40);
    }

    for (int i = 0; i < n; i++){free(t[i]); }

    return 0;
}