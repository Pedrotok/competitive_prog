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

vector<int> G[10005];
vector<pair<int,int>> ans;
int c,children,root,num[10005],low[10005],art[10005];

void dfs2(int v, int p){
	num[v] = low[v] = c++;
	for(int x : G[v]){
		if(!num[x]){
			dfs2(x,v);
			if(root == v) children++;
			if(low[x] >= num[v])
				art[v]++;
			low[v] = min(low[x], low[v]);
		}
		else if(x != p)
			low[v] = min(low[v], num[x]);
	}
	if(root == v) return ;
	ans.push_back(make_pair(-art[v],v));
}

int main() {
	int n,i,a,b,j,m;

	while(scanf("%d%d", &n,&m),n){
		while(scanf("%d%d", &a,&b), a != -1){
			G[a].push_back(b);
			G[b].push_back(a);
		}

		ans.clear();
		for(i = 0; i < n; i++){
			num[i] = low[i] = 0;
			art[i] = 1;
		}
		c = 1;
		root = 0; children = 0;
		dfs2(0,0);
		art[root] = children;
		ans.push_back(make_pair(-art[0],0));

		sort(ans.begin(), ans.end());
		for(i = 0; i < m; i++){
			printf("%d %d\n", ans[i].ss, -ans[i].ff);
		}
		printf("\n");


		for(i = 0; i < n; i++) G[i].clear();
	}

	return 0;
}
