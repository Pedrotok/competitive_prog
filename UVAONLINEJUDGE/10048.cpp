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

int p[105], rk[105];
vector<pair<int,int>> G[105];
bool vis[105];
int ans;

int find(int a){
	if(p[a] != a)
		return p[a] = find(p[a]);
	return a;
}

void merge(int a,int b){
	int x = p[a];
	int y = p[b];
	if(rk[x] > rk[y])
		p[y] = x;
	else{
		p[x] = y;
		if(rk[x] == rk[y])
			rk[y]++;
	}
}

bool dfs(int a, int b){
	vis[a] = 1;
	if(a == b) return true;
	for(pair<int,int>& x : G[a]){
		if(!vis[x.ff]){
			if(dfs(x.ff,b)){ans = max(ans,x.ss); return 1;}
		}
	}
	return false;
}

int main() {
	int n,i,j,m,a,b,c,q,tc=1;

	while(scanf("%d%d%d", &n, &m,&q), n+m+q){
		if(tc > 1) printf("\n");
		for(i = 1; i <= n; i++){
			p[i] = i;
			rk[i] = 0;
		}
		priority_queue<pair<int,pair<int,int>>> Q;
		for(i = 0; i < m; i++){
			scanf("%d%d%d", &a,&b,&c);
			Q.push(mp(-c,mp(a,b)));
		}
		
		int v = 0;
		int aux = 0;

		while(v < n-1 && !Q.empty()){
			int dist = -Q.top().ff;
			pair<int,int> vert = Q.top().ss;
			Q.pop();
			if(find(vert.ff) != find(vert.ss)){
				merge(vert.ff,vert.ss);
				G[vert.ff].push_back(mp(vert.ss,dist));
				G[vert.ss].push_back(mp(vert.ff,dist));
				v++;
			}
		}

		printf("Case #%d\n", tc++);
		for(i = 0; i < q; i++){
			scanf("%d%d", &a,&b);
			ans = 0;
			for(j = 1; j <= n; j++) vis[j] = 0;
			if(dfs(a,b))
				printf("%d\n", ans);
			else
				printf("no path\n");
		}
		for(i = 1; i <= n; i++)
			G[i].clear();

	}

	return 0;
}
