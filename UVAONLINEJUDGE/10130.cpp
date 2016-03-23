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

pair<int,int> v[1001];
int DP[1001][31];
int mw[101];

int main() {
	int i,j,n,g,t,k;
	ll ans;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			scanf("%d%d", &v[i].ff, &v[i].ss);
		scanf("%d", &g);
		ans = 0;
		for(i = 0; i < g; i++)
			scanf("%d", &mw[i]);
		for(k = 0; k < g; k++){
			for(i = 0; i <= n; i++)
				DP[i][0] = 0;
			for(i = 1; i <= n; i++){
				for(j = 0; j <= mw[k]; j++){
					DP[i][j] = DP[i-1][j];
					if(j >= v[i].ss)
						DP[i][j] = max(DP[i][j],DP[i-1][j-v[i].ss]+v[i].ff);
				}
			}
			ans += DP[n][mw[k]];
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}

