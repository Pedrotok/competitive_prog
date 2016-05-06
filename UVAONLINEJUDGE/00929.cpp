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

int mat[1000][1000];
int row[4] = {0,1,0,-1};
int col[4] = {1,0,-1,0};

int dijkstra(int tx, int ty){
	priority_queue<pair<int,pair<int,int>>> Q;
	int dist[1000][1000];
	
	for(int i = 0; i <= tx; i++)
		for(int j = 0; j <= ty; j++){
			dist[i][j] = 1e9;
		}
	dist[0][0] = mat[0][0];
	Q.push(mp(0,mp(0,0)));
	while(!Q.empty()){
		pair<int,int> aux = Q.top().ss;
		int d = Q.top().ff; Q.pop();
		if(dist[aux.ff][aux.ss] < d) continue;
		if(aux.ff == tx && aux.ss == ty) break;
		for(int i = 0; i < 4; i++){
			int x = aux.ff+row[i];
			int y = aux.ss+col[i];
			if(x < 0 || x > tx || y < 0 || y > ty) continue;
			if(dist[x][y] > dist[aux.ff][aux.ss]+mat[x][y]){
				dist[x][y] = dist[aux.ff][aux.ss]+mat[x][y];
				Q.push(mp(-dist[x][y],mp(x,y)));
			}
		}
	}
	return dist[tx][ty];
}

int main() {
	int i,n,m,j,t;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		}
		
		int ans = dijkstra(n-1,m-1);
		printf("%d\n", ans);
	}

	return 0;
}
