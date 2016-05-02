#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <iomanip>
#include <bitset>
#define M_PI 3.14159265358979323846
#define ff first
#define ss second

using namespace std;

typedef long long ll;

vector<int> G[2005];
bool vis[2005];
int dfs_num[2005], dfs_low[2005];
int cont,scc;
stack<int> S;

void dfs(int a){
	dfs_num[a] = dfs_low[a] = cont++;
	vis[a] = 1;
	S.push(a);
	for(int x : G[a]){
		if(!dfs_num[x])
			dfs(x);
		if(vis[x])
			dfs_low[a] = min(dfs_low[a], dfs_low[x]);
	}
	if(dfs_low[a] == dfs_num[a]){
		scc++;
		while(1){
			int v = S.top(); S.pop(); vis[v] = 0;
			if(a == v) break;
		}
	}
}

int main() {
	int i,n,m,t,j,ans,k,a,b,c;

	while(scanf("%d%d", &n, &m), n){
		for(i = 0; i < m; i++){
			scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(b);
			if(c == 2) G[b].push_back(a);
		}
		memset(vis,0,sizeof(vis));
		memset(dfs_low,0,sizeof(dfs_low));
		memset(dfs_num,0,sizeof(dfs_num));
		cont = scc = 0;
		for(i = 1; i <= n; i++)
			if(!dfs_num[i]) dfs(i);

		printf("%d\n", scc==1?1:0);
		for(i = 1; i <= n; i++)
			G[i].clear();
	}

	return 0;
}
