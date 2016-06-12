#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

#define mp make_pair
#define ff first
#define ss second

using namespace std;

typedef long long ll;

pair<int,ll> sv[14];
ll dist[55][55];
ll DP[13][1<<13];
int q;

ll tsp(int pos, int mask){
    if(mask == (1<<(q+1))-1) return -dist[0][sv[pos].ff];
    if(DP[pos][mask] != -1e18) return DP[pos][mask];
    ll ret = -dist[0][sv[pos].ff];
    for(int i = 1; i <= q; i++){
        if(!(mask & (1<<i))){
            ret = max(ret, tsp(i,mask | (1<<i)) - dist[sv[pos].ff][sv[i].ff] + sv[i].ss);
        }
    }
    return DP[pos][mask] = ret;
}

void floyd(int n){
    int i,j,k;
    for(k = 0; k <= n; k++){
        for(i = 0; i <= n; i++){
            for(j = 0; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    int t,n,i,m,a,b;
    ll dlr, cnt;

    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n,&m);
        for(i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++)
                dist[i][j] = 1e18;
            dist[i][i] = 0;
        }
        while(m--){
            scanf("%d %d %lld.%lld", &a,&b,&dlr,&cnt);
            dist[a][b] = dist[b][a] = min(dist[a][b],dlr*100+cnt);
        }
        memset(sv,0,sizeof(sv));
        sv[0] = mp(0,0);
        scanf("%d", &q);
        for(i = 1; i <= q; i++){
            scanf("%d %lld.%lld", &sv[i].ff, &dlr, &cnt);
            sv[i].ss = dlr*100 + cnt;
        }
        floyd(n);
        for(i = 0; i <= q; i++)
            for(int j = 0; j < 1<<(q+1); j++)
                DP[i][j] = -1e18;
        ll ans = tsp(0,1);
        if(ans > 0) printf("Daniel can save $%.2lf\n", (double)ans/100);
        else printf("Don't leave the house\n");
    }

	return 0;
}
