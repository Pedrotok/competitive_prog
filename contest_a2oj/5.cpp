#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

vector<pair<ll,ll>> G[20005];

ll dijkstra(ll s, ll t, ll n){
    ll d[20005];
    for(ll i = 0; i < n; i++) d[i] = 1e18;
    priority_queue<pair<ll,ll>> Q;
    
    d[s] = 0;
    Q.push(mp(0,s));
    while(!Q.empty()){
        ll dist = -Q.top().ff;
        ll v = Q.top().ss; Q.pop();
        if(d[v] < dist) continue;
        if(v == t) return dist;
        for(pair<ll,ll> &x : G[v]){
            if(d[x.ff] > x.ss + d[v]){
                d[x.ff] = x.ss + d[v];
                Q.push(mp(-d[x.ff], x.ff));
            }
        }
    }
    return -1;
}

int main(){
    ll tc,n,m,s,t,a,b,c;
    
    scanf("%lld", &tc);
    for(ll i = 1; i <= tc; i++){
        scanf("%lld%lld%lld%lld", &n,&m,&s,&t);
        while(m--){
            scanf("%lld%lld%lld", &a,&b,&c);
            G[a].push_back(mp(b,c));
            G[b].push_back(mp(a,c));
        }
        ll ans = dijkstra(s,t,n);
        if(ans == -1) printf("Case #%lld: unreachable\n", i);
        else printf("Case #%lld: %lld\n", i,ans);
        
        for(ll j = 0; j < n; j++) G[j].clear();
    }
    
 
    return 0;
}