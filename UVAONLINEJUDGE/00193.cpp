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

int n,m,color[101],ans;
vector<int> G[101], vert;

void backtrack(int i, int black){
	if(i == n+1){
		if(black > ans){
			ans = black;
			vert.clear();
			for(int j = 1; j <= n; j++)
				if(color[j]) vert.push_back(j);
		}
		return ;
	}
	bool flag = true;
	for(int x : G[i]){
		if(color[x]){
			flag = false;
			break;
		}
	}
	if(flag){
		color[i] = 1;
		backtrack(i+1, black+1);
		color[i] = 0;
	}
	backtrack(i+1, black);
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,t,a,b;
	bool nfirst = false;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n,&m);
		for(i = 1; i <= m; i++){
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		ans = 0;
		memset(color,0,sizeof(color));
		backtrack(1,0);
		printf("%d\n", ans);
		printf("%d", vert[0]);
		for(i = 1; i < vert.size(); i++)
			printf(" %d", vert[i]);
		printf("\n");
		for(i = 1; i <= n; i++) 
			G[i].clear();
	}

	return 0;
}

