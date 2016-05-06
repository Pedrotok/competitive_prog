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
#define mp make_pair

using namespace std;

typedef long long ll;

pair<int,int> va[400005], vb[400005];
int row[4] = {1,0,-1,0};
int col[4] = {0,-1,0,1};
bool vis[2005][2005], dest[2005][2005];

int main() {
	int n,i,j,m,t,a,b;

	while(scanf("%d", &a),a){
		for(i = 0; i < a; i++)
			scanf("%d%d", &va[i].ff, &va[i].ss);
		scanf("%d", &b);
		memset(vis,0,sizeof(vis));
		memset(dest,0,sizeof(dest));
		for(i = 0; i < b; i++){
			scanf("%d%d", &vb[i].ff, &vb[i].ss);
			dest[vb[i].ff][vb[i].ss] = 1;
		}
		queue<pair<pair<int,int>,int> > Q;
		for(i = 0; i < a; i++){
			Q.push(mp(va[i],0));
			vis[va[i].ff][va[i].ss] = 1;
		}
		int ans;
		while(!Q.empty()){
			pair<int,int> aux = Q.front().ff;
			int dist = Q.front().ss;
			Q.pop();
			if(dest[aux.ff][aux.ss]){
				ans = dist;
				break;
			}
			for(i = 0; i < 4; i++){
				int x = aux.ff+row[i];
				int y = aux.ss+col[i];
				if(x < 0 || x > 2000 || y < 0 || y > 2000 || vis[x][y]) continue;
				vis[x][y]=1;
				Q.push(mp(mp(x,y),dist+1));
			}

		}
		printf("%d\n", ans);
	}

	return 0;
}
