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
#define mp make_pair

using namespace std;

typedef long long ll;

vector<int> G[100005];
vector<int> S;
bool vis[100005],derruba[100005];
int num[100005], low[100005],comp[100005];
int c, cp;

void dfs2(int u){
	vis[u] = 1;
	for(int x : G[u]){
		if(comp[x] != comp[u])
			derruba[comp[x]] = 1;
		if(!vis[x])
			dfs2(x);
	}
}

void dfs(int u){
	num[u] = low[u] = c++;
	vis[u] = 1;
	S.push_back(u);
	for(int x : G[u]){
		if(!num[x])
			dfs(x);
		if(vis[x])
			low[u] = min(low[u], low[x]);
	}
	if(low[u] == num[u]){
		while(1){
			int a = S.back(); S.pop_back();
			vis[a] = 0;
			comp[a] = cp;
			if(a == u) break;
		}
		derruba[cp] = 0;
		cp++;
	}
}

int main() {
	int n,i,m,a,b,t;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(i = 0; i < m; i++){
			scanf("%d%d", &a,&b);
			G[a].push_back(b);
		}
		for(i = 1; i <= n; i++)
			num[i] = low[i] = vis[i] = comp[i] = 0;
		c = cp = 1;
		for(i = 1; i <= n; i++){
			if(!num[i])
				dfs(i);
		}
		
		for(i = 1; i <= n; i++)
			vis[i] = 0;
		for(i = 1; i <= n; i++){
			if(!vis[i])
				dfs2(i);
		}
		int ans = 0;
		for(i = 1; i < cp; i++)
			if(!derruba[i]) ans++;
		for(i = 1; i <= n; i++) G[i].clear();

		S.clear();
		printf("%d\n",ans);
	}

	return 0;
}
