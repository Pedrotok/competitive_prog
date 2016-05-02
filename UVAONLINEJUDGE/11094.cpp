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

char mapa[25][25],land;
int vis[25][25];
int comp[2500],n,m;
int row[4] = {0,1,0,-1};
int col[4] = {1,0,-1,0};

int dfs(int i, int j,int c){
	vis[i][j] = c;
	int tam = 0;
	for(int k = 0; k < 4; k++){
		int x = i+row[k]; int y = j+col[k];
		(y<0)?y=m-1 : y = y%m;
		if(x < 0 || x >= n || vis[x][y] || mapa[x][y] != land)
			continue;
		tam += dfs(x,y,c);
	}
	return tam+1;
}

int main() {
	int x,y,i,j,start;

	while(scanf("%d%d", &n, &m)==2){
		for(i = 0; i < n; i++)
			scanf("%s",mapa[i]);
		scanf("%d%d", &x, &y);
		land = mapa[x][y];
		int c = 1;
		memset(vis,0,sizeof(vis));
		memset(comp,0,sizeof(comp));
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(!vis[i][j] && mapa[i][j] == land){
					int tam = dfs(i,j,c);
					comp[c++] = tam;
				}
			}
		}
		start = vis[x][y];
		int ans = 0;
		for(i = 1; i < c; i++){
			if(i == start) continue;
			ans = max(ans,comp[i]);
		}
		printf("%d\n",ans);
	}

	return 0;
}
