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

int dist1[101], dist2[101];
vector<int> G[101];

void bfs(int v){
	dist1[v] = 0;
	queue<int> Q;
	Q.push(v);
	while(!Q.empty()){
		int a = Q.front(); Q.pop();
		for(int x : G[a])
			if(dist1[x] == -1){
				dist1[x] = dist1[a]+1;
				Q.push(x);
			}
	}
}

void bfs2(int v){
	dist2[v] = 0;
	queue<int> Q;
	Q.push(v);
	while(!Q.empty()){
		int a = Q.front(); Q.pop();
		for(int x : G[a])
			if(dist2[x] == -1){
				dist2[x] = dist2[a]+1;
				Q.push(x);
			}
	}
}

int main() {
	int n,i,j,a,b,m,tc=1,t,src,tg;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n,&m);
		while(m--){
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		scanf("%d%d", &src, &tg);
		memset(dist1,-1,sizeof(dist1));
		memset(dist2,-1,sizeof(dist2));
		bfs(src);
		bfs2(tg);
		int ans = 0;
		for(j = 0; j < n; j++)
			ans = max(ans,dist1[j]+dist2[j]);
		printf("Case %d: %d\n", tc++, ans);	
		for(i = 0; i < n; i++) G[i].clear();
	}

	return 0;
}
