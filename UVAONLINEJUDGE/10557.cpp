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

int en[105];
vector<int> G[105];
int dist[105];
bool cycle[105], vis[105];

bool dfs(int v, int d, int energy){
	vis[v] = 1;
	if(v == d) return true;
	if(cycle[v]) energy = 1e8;
	for(int x : G[v]){
		if(vis[x]) continue;
		if(energy+en[x] <= 0) continue;
		if(dfs(x, d, energy+en[x])) return true;
	}
	return false;
}

int main() {
	int n,i,m,j,a,b;
	while(scanf("%d", &n),n!=-1){
		for(i = 1; i <= n; i++){
			scanf("%d", &en[i]);
			scanf("%d", &a);
			while(a--){
				scanf("%d", &b);
				G[i].push_back(b);
			}
		}
		for(i = 1; i <= n; i++)
			dist[i] = -1e9, cycle[i] = 0;
		dist[1] = 100;

		for(i = 0; i < n-1; i++){
			for(j = 1; j <= n; j++){
				if(dist[j] <= 0) continue;
				for(int v : G[j]){
					dist[v] = max(dist[v], dist[j]+en[v]);
				}
			}
		}
		for(j = 1; j <= n; j++){
			if(dist[j] <= 0) continue;
			for(int v : G[j]){
				if(dist[v] < dist[j]+en[v]){
					cycle[j] = cycle[v] = 1;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		if(dfs(1,n,100)) printf("winnable\n");
		else printf("hopeless\n");

		for(i = 1; i <= n; i++) G[i].clear();
	}

	return 0;
}
