#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

#define mp make_pair
#define ff first
#define ss second

using namespace std;

int x[11], y[11], DP[11][1<<11], q;

int dist(int i, int j){
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}

int tsp(int pos, int mask){
    if(mask == (1<<(q+1))-1) return dist(0, pos);
    if(DP[pos][mask] != -1) return DP[pos][mask];
    int ret = 1e9;
    for(int i = 1; i <= q; i++){
        if(!(mask & (1<<i))){
            ret = min(ret, tsp(i,mask | (1<<i)) + dist(pos,i));
        }
    }
    return DP[pos][mask] = ret;
}

int main(){
    int t,n,i,m;

    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d", &n,&m,&x[0],&y[0],&q);
        for(i = 1; i <= q; i++)
            scanf("%d%d", &x[i], &y[i]);
        memset(DP,-1,sizeof(DP));
        printf("The shortest path has length %d\n", tsp(0,1));
    }


	return 0;
}
