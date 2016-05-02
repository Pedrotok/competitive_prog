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

int G[50005];
char vis[50005];

int dfs(int a){
	vis[a] = 2;
	int x = G[a];
	int tam = 0;

	if(!x) return 1;
	if(vis[x] != 2){
		tam = dfs(x);
	}
	vis[a] = 1;
	return tam+1;
}

int main() {
	int i,j,t,n,tc=1,a,b;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 1; i <= n; i++) G[i] = 0;
		for(i = 1; i <= n; i++){
			scanf("%d%d", &a, &b);
			G[a] = b;
		}
		memset(vis,0,sizeof(vis));
		int ans = 0, aux = 0;
		int tam;
		for(i = 1; i <= n; i++){
			if(!vis[i]){
				tam = dfs(i);
				if(tam > aux)
					ans = i, aux = tam;
			}
		}

		printf("Case %d: %d\n", tc++, ans);
	}

	return 0;
}
