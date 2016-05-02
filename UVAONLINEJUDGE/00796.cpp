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

vector<int> num,low;
vector<vector<int>> G;
vector<pair<int,int>> ans;
int c;

void dfs(int v, int p){
	num[v] = low[v] = c++;
	for(int x : G[v]){
		if(!num[x]){
			dfs(x,v);
			if(low[x] > num[v]){
				int a = v, b = x;
				if(b < a) swap(a,b);
				ans.push_back(make_pair(a,b));
			}
			low[v] = min(low[v], low[x]);
		}
		else if(x != p)
			low[v] = min(low[v], num[x]);
	}
}

int main() {
	int n,i,a,b,j,k;

	while(scanf("%d", &n) == 1){
		G.resize(n);
		low.resize(n);
		num.resize(n);
		for(i = 0; i < n; i++){
			low[i] = num[i] = 0;
			G[i].clear();
		}
		for(i = 0; i < n; i++){
			scanf("%d (%d)", &a, &k);
			for(j = 0; j < k; j++){
				scanf("%d", &b);
				G[a].push_back(b);
			}
		}

		ans.clear();
		c = 1;
		for(i = 0; i < n; i++){
			if(!num[i])
				dfs(i,i);
		}
		
		printf("%d critical links\n", (int)ans.size());

		sort(ans.begin(), ans.end());
		for(pair<int,int>& x : ans)
			printf("%d - %d\n", x.ff, x.ss);
		printf("\n");
	}

	return 0;
}
