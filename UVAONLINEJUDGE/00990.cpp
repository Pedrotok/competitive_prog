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

pair<int,int> v[35];
int DP[35][1001];
bool sol[35][1001];
int w;

void reconstruct(int n, int t, int cnt){
	if(n == 0){
		printf("%d\n", cnt);
		return ;
	}
	if(sol[n][t]){
		reconstruct(n-1, t-3*w*v[n].ff, cnt+1);
		printf("%d %d\n", v[n].ff, v[n].ss);
		return ;
	}
	reconstruct(n-1,t,cnt);
}

int main() {
	int i,j;
	int n,m,t;
	int nfirst = false;
	
	while(scanf("%d %d", &t, &w)==2){
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			scanf("%d%d", &v[i].ff, &v[i].ss);
		memset(sol,0,sizeof(sol));
		for(i = 1; i <= t; i++) DP[0][t] = 0;
		for(i = 1; i <= n; i++){
			for(j = 0; j <= t; j++){
				DP[i][j] = DP[i-1][j];
				if(j >= 3*w*v[i].ff){
					if(DP[i-1][j] <= DP[i-1][j-3*w*v[i].ff]+v[i].ss){
						DP[i][j] = DP[i-1][j-3*w*v[i].ff]+v[i].ss;
						sol[i][j] = 1;
					}
				}
			}
		}
		if(nfirst) printf("\n");
		else nfirst = true;
		printf("%d\n", DP[n][t]);
		reconstruct(n,t,0);
	}
	
	return 0;
}

