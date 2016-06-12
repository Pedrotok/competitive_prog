#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

#define ff first
#define ss second

using namespace std;

typedef long long ll;

int n,k,m;
ll DP[55][55][55];

ll f(int i, int b, int w){
    if(w > m) return 0;
    if(b > k) return 0;
    if(i == 1){
        return b==k?1:0;
    }
    if(DP[i][b][w] != -1) return DP[i][b][w];
    ll ret = f(i-1, b+1, 1) + f(i-1, b, w+1);
    return DP[i][b][w] = ret;
}

int main(){
    int i,j,t;

    while(scanf("%d%d%d", &n, &k, &m) == 3){
        memset(DP,-1,sizeof(DP));
        printf("%lld\n", f(n,1,1));
    }

	return 0;
}
