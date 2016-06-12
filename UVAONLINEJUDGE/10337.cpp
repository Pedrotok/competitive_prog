#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

#define ff first
#define ss second

using namespace std;

int mat[10][1005],n,DP[10][1005];

int f(int alt, int col){
    if(col == n) return (alt==0?0:1e9);
    if(DP[alt][col] != -1) return DP[alt][col];
    int ret = f(alt,col+1)+30-mat[alt][col];
    if(alt+1 < 10) ret = min(ret,f(alt+1,col+1)+60-mat[alt][col]);
    if(alt-1 >= 0) ret = min(ret,f(alt-1,col+1)+20-mat[alt][col]);
    return DP[alt][col] = ret;
}

int main(){
    int i,j,t;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        n/=100;
        for(i = 9; i >= 0; i--){
            for(j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        }
        memset(DP,-1,sizeof(DP));
        printf("%d\n\n", f(0,0));
    }

	return 0;
}
