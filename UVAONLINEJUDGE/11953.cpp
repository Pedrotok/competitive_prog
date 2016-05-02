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

char mapa[105][105];
bool vis[105][105];
int n,qt_x;
int row[4] = {0,1,0,-1};
int col[4] = {1,0,-1,0};

void dfs(int i, int j){
	vis[i][j] = 1;
	if(mapa[i][j] == 'x') qt_x++;
	for(int k = 0; k < 4; k++){
		int x = i+row[k]; int y = j+col[k];
		if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y] || mapa[x][y] == '.')
			continue;
		dfs(x,y);
	}
}

int main() {
	int t,i,j,tc=1;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%s",mapa[i]);
		memset(vis,0,sizeof(vis));
		int ans = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(!vis[i][j] && mapa[i][j] != '.'){
					qt_x = 0;
					dfs(i,j);
					if(qt_x) ans++;
				}
			}
		}
		printf("Case %d: %d\n",tc++,ans);
	}

	return 0;
}
