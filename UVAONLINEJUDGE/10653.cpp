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

bool vis[1001][1001];
int row[4] = {0,1,0,-1};
int col[4] = {1,0,-1,0};

int main() {
	int n,i,m,t,a,b,r,c;
	pair<int,int> source,target;

	while(scanf("%d%d", &n, &m),n+m){
		memset(vis,0,sizeof(vis));
		scanf("%d", &r);
		for(i = 0; i < r; i++){
			scanf("%d%d", &a,&b);
			while(b--){
				scanf("%d", &c);
				vis[a][c] = 1;
			}
		}
		scanf("%d%d", &source.ff, &source.ss);
		scanf("%d%d", &target.ff, &target.ss);
		queue<pair<pair<int,int>,int>> Q;
		Q.push(mp(source,0));
		vis[source.ff][source.ss] = 1;
		int ans;
		while(!Q.empty()){
			pair<int,int> aux = Q.front().ff;
			int d = Q.front().ss; Q.pop();
			if(aux == target){ans = d;break;}
			for(i = 0; i < 4; i++){
				int x = aux.ff+row[i];
				int y = aux.ss+col[i];
				if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y])
					continue;
				vis[x][y] = 1;
				Q.push(mp(mp(x,y),d+1));
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
