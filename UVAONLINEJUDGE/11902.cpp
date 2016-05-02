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

bool dom[101][101], vis[101];
vector<int> G[101];
int n;

void dfs(int a, int b){
	vis[a] = 1;
	for(int i : G[a]){
		if(i != b && !vis[i])
			dfs(i,b);
	}
}

int main() {
	int i,j,t,tc=1,a;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++) G[i].clear();
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%d", &a);
				if(a) G[i].push_back(j);
			}
		}
		memset(dom,0,sizeof(dom));
		memset(vis,0,sizeof(vis));
		dfs(0,-1);
		for(i = 0; i < n; i++)
			dom[0][i] = vis[i];

		for(i = 1; i < n; i++){
			memset(vis,0,sizeof(vis));
			dfs(0,i);
			for(j = 0; j < n; j++){
				if(dom[0][j] && !vis[j])
					dom[i][j] = 1;
			}
		}
		string s = "+-";
		for(i = 1; i < n; i++){
			s += "--";
		}
		s += '+';
		printf("Case %d:\n", tc++);
		for(i = 0; i < n; i++){
			printf("%s\n", s.c_str());
			printf("|");
			for(j = 0; j < n; j++){
				printf("%c|", (dom[i][j]?'Y':'N'));
			}
			printf("\n");
		}
		printf("%s\n", s.c_str());
	}
	return 0;
}
