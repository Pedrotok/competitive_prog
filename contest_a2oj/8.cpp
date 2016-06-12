#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

vector<vector<pair<int,int>>> G;

int bfs(int n, int s, int t, int p){
    int ans = -1;
    vector<int> d(n+1,1e9), z(n+1,-1);    
    queue<pair<int,pair<int,int> > > Q;
    d[s] = 0;
    z[s] = 0;
    Q.push(mp(s,(mp(0,0))));
    while(!Q.empty()){
        int v = Q.front().ff;
        int dist = Q.front().ss.ff;
        int w = Q.front().ss.ss; Q.pop();
        
//         printf("(%d,%d,%d)\n", v, dist, w);
        
        if(v == t) ans = max(ans, w);
        for(pair<int,int> &x : G[v]){
//          printf("(%d,%d) %d\n", x.ff, x.ss, z[x.ff]);
            if(dist+x.ss > p) continue;
            if (max(w,x.ss) <= z[x.ff] && dist+x.ss >= d[x.ff]) continue;
            if (max(w,x.ss) > z[x.ff]) z[x.ff] = max(w,x.ss);
            Q.push(mp(x.ff,mp(dist+x.ss, max(w,x.ss))));
            if(dist+x.ss < d[x.ff]){
                d[x.ff] = dist+x.ss;
            }
        }
    }
    return ans;
}

int main(){
    int n,m,tc,t,s,p,a,b,c;
    
    scanf("%d", &tc);
    
    while(tc--){
        scanf("%d%d%d%d%d", &n,&m,&s,&t,&p);
        
        G.assign(n+1, vector<pair<int,int>>());
        while(m--){
            scanf("%d%d%d", &a,&b,&c);
            G[a].push_back(mp(b,c));
        }
        
        int ans = bfs(n,s,t,p);
        printf("%d\n", ans);
    }
    
 
    return 0;
}