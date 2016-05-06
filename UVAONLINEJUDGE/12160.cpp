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

int v[12];
bool vis[10000];

int main() {
	int i,n,m,j,l,u,r,tc=1;

	while(scanf("%d%d%d", &l, &u, &r),l+u+r){
		for(i = 0; i < r; i++)
			scanf("%d", &v[i]);

		memset(vis,0,sizeof(vis));
		vis[l] = 1;
		queue<pair<int,int>> Q;
		Q.push(mp(l,0));

		int ans = -1;
		while(!Q.empty()){
			n = Q.front().ff;
			int d = Q.front().ss; Q.pop();
			if(n == u){
				ans = d;
				break;
			}
			d++;
			for(i = 0; i < r; i++){
				int aux = (v[i]+n)%10000;
				if(vis[aux]) continue;
				vis[aux] = 1;
				Q.push(mp(aux,d));
			}
		}

		if(ans == -1) printf("Case %d: Permanently Locked\n", tc++);
		else printf("Case %d: %d\n", tc++,ans);

	}

	return 0;
}
