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

vector<pair<int,int> > G[2][10005];
int dist[2][10005];

int dijkstra(int s, int t, int n, int p, int flag){
	priority_queue<pair<int,pair<int,int> > > Q;
	for(int i = 1; i <= n; i++)
		dist[flag][i] = 1e9;
	dist[flag][s] = 0;
	Q.push(mp(0,mp(s,0))); //dist, vert, max_edge
	bool ret = 0;
	while(!Q.empty()){
		int d = -Q.top().ff;
		int vert = Q.top().ss.ff;
		int max_edge = Q.top().ss.ss; Q.pop();
		if(dist[flag][vert] < d) continue;
		if(vert == t)
			ret = 1;
		for(pair<int,int> &x : G[flag][vert]){
			if((ll)dist[flag][vert]+x.ss > p) continue;
			if(dist[flag][x.ff] > d+x.ss){
				dist[flag][x.ff] = dist[flag][vert]+x.ss;
				int aux = max(max_edge,x.ss);
				Q.push(mp(-dist[flag][x.ff], mp(x.ff,aux)));
			}
		}
	}
	return ret;
}

int main() {
	int i,n,m,j,a,b,c,s,p,t,test;

	scanf("%d", &test);
	while(test--){
		scanf("%d%d%d%d%d", &n,&m,&s,&t,&p);
		for(i = 0; i < m; i++){
			scanf("%d%d%d", &a,&b,&c);
			G[0][a].push_back(mp(b,c));
			G[1][b].push_back(mp(a,c));
		}

		if(dijkstra(s,t,n,p,0)){
			dijkstra(t,s,n,p,1);
			int ans = 0;
			for(i = 1; i <= n; i++){
				for(pair<int,int> &x : G[0][i]){
					ll sum = dist[0][i]+x.ss+dist[1][x.ff];
					if(sum <= p)
						ans = max(x.ss,ans);
				}
			}
			printf("%d\n", ans);
		}
		else printf("-1\n");
		for(i = 1; i <= n; i++) G[0][i].clear(), G[1][i].clear();
	}

	return 0;
}
