#include <stdio.h>
#include <malloc.h>

int main(){
    int n,m,k,wynik=0,a=0,b=0,q;
    scanf("%d %d %d",&n,&m,&k);
    int *t1, **t;
    char c[n];
    t1=malloc(m * sizeof(int *));
    t = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) { t[i] = malloc(2 * sizeof(int)); }


    for (int i = 0; i < m; i++){
        for (int j = 0; j < 2; j++){scanf("%d",&t[i][j]); }
    }

    scanf("%s",c);
    q=1;
    for(int i=n-1;i>=0;i--){
        if (c[i]=='1'){
            a+=q;
        }
        q*=2;
    }
    scanf("%s",c);
    q=1;
    for(int i=n-1;i>=0;i--){
        if (c[i]=='1'){
            b+=q;
        }
        q*=2;
    }


    int x,y;
    for(int i=a;i<=b;i++){
        for (int h = 0; h < m; h++){t1[h]=-1; }
        while(t1[k-1]==-1){
            for(int j=0;j<m;j++){
                x=-1;y=-1;
                if(t1[j]==-1){
                    if(t[j][0]<0){
                        q=n-(t[j][0]*(-1));
                        if(i & (1<<q)){
                            x=1;
                        }
                        else{x=0; }
                    }
                    else{
                        if(t1[t[j][0]-1]!=-1){x=t1[t[j][0]-1]; }
                    }

                    if(t[j][1]<0){
                        q=n-(t[j][1]*(-1));
                        if(i & (1<<q)){
                            y=1;
                        }
                        else{y=0; }
                    }
                    else{
                        if(t1[t[j][1]-1]!=-1){y=t1[t[j][1]-1]; }
                    }
                    if( (x+y)==1 ){t1[j]=1; }
                    if(x==y && x!=-1){t1[j]=0; }
                }
            }
        }
        if(t1[k-1]==1){wynik++; }
    }

    printf("%d",wynik);
    free(t1);
    for (int i = 0; i < m; i++){free(t[i]); }

    return 0;
}

//5 6 5
//-1 -2
//1 3
//1 -2
//2 -3
//4 6
//-4 -5
//00111
//01110