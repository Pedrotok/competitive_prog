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

vector<pair<int,int>> G[105];

int dijkstra(int s, int n, int tempo){
	priority_queue<pair<int,int>> Q;
	int dist[105];
	
	for(int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dist[s] = 0;
	Q.push(mp(0,s));
	while(!Q.empty()){
		int d = Q.top().ff;
		int v = Q.top().ss;
		Q.pop();
		if(dist[v] < d) continue;
		for(pair<int,int>& x : G[v]){
			if(dist[x.ff] > dist[v]+x.ss){
				dist[x.ff] = dist[v]+x.ss;
				Q.push(mp(-dist[x.ff],x.ff));
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(dist[i] <= tempo) ans++;
	return ans;
}

int main() {
	int i,n,m,j,t,e,a,tempo;
	pair<int,int> aux;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &e, &tempo, &m);
		for(i = 0; i < m; i++){
			scanf("%d%d%d", &aux.ff, &a, &aux.ss);
			G[a].push_back(aux);
		}
		
		int ans = dijkstra(e,n,tempo);
		printf("%d\n", ans);
		if(t) printf("\n");
		for(i = 1; i <= n; i++)
			G[i].clear();
	}

	return 0;
}
