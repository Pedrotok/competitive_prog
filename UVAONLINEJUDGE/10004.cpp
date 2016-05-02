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

int v[51], color[201];
vector<int> G[201];
bool flag;

bool dfs(int a, int c){
	color[a] = c;
	c = 1-c;
	for(int x : G[a]){
		if(color[x] == -1)
			dfs(x,c);
		else if(color[x] != c)
			flag = false;
	}
}

int main() {
	int n,i,t,j,c,m,a,b;

	while(scanf("%d", &n),n){
		scanf("%d", &m);
		for(i = 0; i < m; i++){
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		memset(color,-1,sizeof(color));
		flag = true;
		for(i = 0; i < n && flag; i++){
			if(color[i] == -1){
				dfs(i,0);
			}
		}
		if(flag)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
		for(i = 0; i < n; i++)
			G[i].clear();
	}

	return 0;
}
