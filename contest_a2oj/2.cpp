#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

vector<int> G[100005];
int low[100005], num[100005], root, children;
int c;
pair<int,int> cnt[1000005];

int marc[1000005];
void dfs2(int v){
    marc[v] = 1;
    for(int x : G[v]){
        if(!marc[x]){
            dfs2(x);
        }
    }
}

void dfs(int v, int p){
    num[v] = low[v] = c++;
    for(int x : G[v]){
        if(!num[x]){
            dfs(x,v);
            if(low[x] >= num[v]) cnt[v].ff++;
            low[v] = min(low[v], low[x]);
        }
        else if(x != p) low[v] = min(low[v], num[x]);
    }
}

int main(){
    int n,m,a,b;
    
    while(scanf("%d%d", &n,&m),n+m){
        while(scanf("%d%d", &a,&b), a != -1){
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(num,0,sizeof(num));
        memset(low,0,sizeof(low));
        for(int i = 0; i < n; i++)
            cnt[i].ss = -i, cnt[i].ff = 0;
        c = 1;
        dfs(0,0);
        
        
        memset(marc,0,sizeof(marc));
        cnt[0].ff=0;
        marc[0] = 1;
        for (int i = 1; i < n; i++) {
            if (!marc[i]) {
                dfs2(i);
                cnt[0].ff++;
            }
        }
        cnt[0].ff--;
        
        sort(cnt, cnt+n);
        
        for(int i = n-1; m; m--, i--)
            printf("%d %d\n", -cnt[i].ss, cnt[i].ff+1);
        printf("\n");
        for(int i = 0; i < n; i++) G[i].clear();
    }
    
    return 0;
}