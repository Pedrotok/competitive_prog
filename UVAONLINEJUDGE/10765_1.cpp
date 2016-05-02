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

vector<int> G[10005];
vector<pair<int,int>> ans;
bool vis[10005],art[10005];
int c,children,root,num[10005],low[10005];

void dfs(int v){
	vis[v] = 1;
	for(int x : G[v]){
		if(vis[x]) continue;
		dfs(x);
	}
}

void dfs2(int v, int p){
	num[v] = low[v] = c++;
	for(int x : G[v]){
		if(!num[x]){
			dfs2(x,v);
			if(root == v) children++;
			if(low[x] >= num[v])
				art[v] = 1;
			low[v] = min(low[x], low[v]);
		}
		else if(x != p)
			low[v] = min(low[v], num[x]);
	}
}

int main() {
	int n,i,a,b,j,m;

	while(scanf("%d%d", &n,&m),n){
		while(scanf("%d%d", &a,&b), a != -1){
			G[a].push_back(b);
			G[b].push_back(a);
		}

		ans.clear();

		memset(num,0,sizeof(num));
		memset(low,0,sizeof(low));
		memset(art,0,sizeof(art));
		c = 1;
		for(i = 0; i < n; i++){
			if(!num[i]){
				root = i; children = 0;
				dfs2(i,i);
				art[root] = children > 1;
			}
		}

		for(i = 0; i < n; i++){
			if(!art[i]){
				ans.push_back(make_pair(-1,i));
				continue;
			}
			int d = 0;
			memset(vis,0,sizeof(vis));
			vis[i] = 1;
			for(j = 0; j < n; j++){
				if(!vis[j]){
					dfs(j);
					d++;
				}
			}
			ans.push_back(make_pair(-d,i));
		}

		sort(ans.begin(), ans.end());
		for(i = 0; i < m; i++){
			printf("%d %d\n", ans[i].ss, -ans[i].ff);
		}
		printf("\n");


		for(i = 0; i < n; i++) G[i].clear();
	}

	return 0;
}
