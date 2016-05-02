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

vector<int> G[101];
bool vis[101];
stack<int> S;

void dfs(int a){
	vis[a] = 1;
	for(int x : G[a])
		if(!vis[x]) dfs(x);
	S.push(a);
}

int main() {
	int n,m,i,a,b;

	while(scanf("%d%d", &n,&m),n){
		for(i = 0; i < m; i++){
			scanf("%d%d", &a,&b);
			G[a].push_back(b);
		}

		memset(vis,0,sizeof(vis));
		for(i = 1; i <= n; i++){
			if(!vis[i]) dfs(i);
		}
		a = S.top(); S.pop();
		printf("%d", a);
		while(!S.empty()){
			a = S.top(); S.pop();
			printf(" %d", a);
		}
		printf("\n");
	}

	return 0;
}
