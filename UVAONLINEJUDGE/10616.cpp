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

int v[205],d[10],m[10],tar;
ll DP[205][11][21];

ll f(int i, int j, int s){
	if(DP[i][j][s] != -1)
		return DP[i][j][s];
	if(s == 0)
		return DP[i][j][s] = 0;
	if(j == 0){
		if(s == tar) return DP[i][j][s] = 1;
		return DP[i][j][s] = 0;
	}
	if(i == 0)
		return DP[i][j][s] = 0;
	
	ll ret = 0;
	int s2;
	if(s >= v[i]){
		s2 = (s-v[i])%tar;
		if(!s2) s2 = tar;
	}
	else{
		s2 = tar-(v[i]-s)%tar;
	}
	ret = f(i-1, j, s) + f(i-1,j-1, s2);
	return DP[i][j][s] = ret;
}

int main() {
	int i, t, j,k,n,q,tc=1;

	while(scanf("%d%d",&n,&q) && q != 0 && n != 0){
		for(i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		for(i = 0; i < q; i++)
			scanf("%d%d", &d[i], &m[i]);
		printf("SET %d:\n", tc++);
		int query = 1;
		for(i = 0; i < q; i++){
			memset(DP, -1, sizeof(DP));
			tar = d[i];
			ll ans = f(n,m[i], d[i]);
			printf("QUERY %d: %lld\n", query++,ans);
		}
	}
	return 0;
}

