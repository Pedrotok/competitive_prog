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

vector<pair<int,int>> G[20005];

ll dijkstra(int s, int t, int n){
	priority_queue<pair<int,int>> Q;
	int dist[20005];
	
	for(int i = 0; i < n; i++)
		dist[i] = 1e9;
	dist[s] = 0;
	Q.push(mp(0,s));
	while(!Q.empty()){
		int d = Q.top().ff;
		int v = Q.top().ss;
		Q.pop();
		if(dist[v] < d) continue;
		if(v == t) return -d;
		for(pair<int,int>& x : G[v]){
			if(dist[x.ff] > dist[v]+x.ss){
				dist[x.ff] = dist[v]+x.ss;
				Q.push(mp(-dist[x.ff],x.ff));
			}
		}
	}
	return -1;
}

int main() {
	int i,n,m,j,t,a,b,c,tc=1,s,tg;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &s, &tg);
		for(i = 0; i < m; i++){
			scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(mp(b,c));
			G[b].push_back(mp(a,c));
		}
		
		int ans = dijkstra(s,tg,n);
		if(ans == -1) printf("Case #%d: unreachable\n", tc++);
		else printf("Case #%d: %d\n", tc++,ans);
		for(i = 0; i < n; i++)
			G[i].clear();
	}

	return 0;
}
