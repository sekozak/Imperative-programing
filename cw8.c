#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int my_compare(const void *a, const void *b) {
    int _a = *(int *) a;
    int _b = *(int *) b;
    if (_a < _b) return -1;
    else if (_a == _b) return 0;
    else return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *A = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i){
        scanf("%d", &A[i]);
    }

    qsort(A, n, sizeof(int), my_compare);

    int odp = 0;
    for (int i = 0; i < n;) {
        int ile = 0, j = i;
        while (j != n && A[j] == A[i]) {
            j ++;
            ile ++;
        }
        if (i != 0 && A[i - 1] >= A[i] - m) {
            odp += ile;
        } else if (j != n && A[j] <= A[j - 1] + m) {
            odp += ile;
        }
        i = j;
    }
    printf("%d", odp);
}



//-------------------------------------------
//int compare(const void *a, const void *b) {
//    if (*(int *)a < *(int *)b)
//        return -1;
//    if (*(int *)a > *(int *)b)
//        return 1;
//    return 0;
//}
//
//int main() {
//    int n, m, odp = 0, a, b, q;
//    scanf("%d %d", &n, &m);
//    int t[n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &t[i]);
//    }
//
//    qsort(t, n, sizeof(int), compare);
//
//    for (int i = 0; i < n; i++) {
//        if (q == 1 && t[i] == t[i - 1]) {
//            odp++;
//        } else if (i == 0 || t[i] != t[i - 1]) {
//            a = i;
//            b = i;
//            q = 0;
//            while (t[i] == t[a] && a > 0)
//                a--;
//            if (abs(t[i] - t[a]) <= m && t[i] != t[a]) {
//                odp++;
//                q = 1;
//                continue;
//            }
//            while (t[i] == t[b] && b < n-1)
//                b++;
//            if (abs(t[i] - t[b]) <= m && t[i] != t[b]) {
//                q = 1;
//                odp++;
//            }
//        }
//    }
//    printf("%d", odp);
//
//    return 0;
//}