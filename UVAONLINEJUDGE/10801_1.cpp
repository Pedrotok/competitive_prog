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

int T[6];
vector<int> G[6];

int dijkstra(int t, int n){
	priority_queue<pair<int,pair<int,int>>> Q;
	int dist[105][5];
	int i,j;	
	for(i = 0; i < 100; i++)
		for(j = 0; j < n; j++)
			dist[i][j] = 1e9;
	for(j = 0; j < n; j++){
		if(G[j][0] == 0){
			dist[0][j] = 0;
			Q.push(mp(0,mp(j,0)));
		}
	}
	while(!Q.empty()){
		int d = Q.top().ff;
		pair<int,int> v = Q.top().ss;
		Q.pop();
		int floor = G[v.ff][v.ss];
		int elev = v.ff;
		if(dist[floor][elev] < d) continue;
		if(floor == t) return -d;
		for(i = 0; i < G[elev].size(); i++){
			int aux = G[elev][i];
			int tempo = (abs(floor-aux))*T[elev];
			if(dist[aux][elev] > dist[floor][elev]+tempo){
				dist[aux][elev] = dist[floor][elev]+tempo;
				Q.push(mp(-dist[aux][elev],mp(elev,i)));
			}
		}
		for(i = 0; i < n; i++){
			if(i == elev) continue;
			int aux = lower_bound(G[i].begin(), G[i].end(), floor)-G[i].begin();
			if(aux < G[i].size() && G[i][aux] == floor){
				if(dist[floor][i] > dist[floor][elev]+60){
					dist[floor][i] = dist[floor][elev]+60;
					Q.push(mp(-dist[floor][i],mp(i,aux)));
				}
			}
		}
	}
	return -1;
}

int main() {
	int i,n,m,j,t,a,b,c,k;
	string s;

	while(!cin.eof(), cin >> n >> k){
		for(i = 0; i < n; i++)
			cin >> T[i];
		getline(cin,s);
		for(i = 0; i < n; i++){
			getline(cin, s);
			stringstream x(s);
			while(x >> a)
				G[i].push_back(a);
		}
		
		int ans = dijkstra(k,n);
		if(ans == -1) printf("IMPOSSIBLE\n");	
		else printf("%d\n", ans);
		for(i = 0; i < n; i++)
			G[i].clear();
	}

	return 0;
}
