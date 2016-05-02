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

pair<int,int> v[41];
int DP[302][302];

int main() {
	int i,j,n,t,d,k;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &d);
		for(i = 1; i <= n; i++)
			scanf("%d%d", &v[i].ff, &v[i].ss);
		for(i = 0; i <= 300; i++)
			for(j = 0; j <= 300; j++) DP[i][j] = 1e9;
		DP[0][0] = 0;
		int d1 = d*d;
		for(i = 1; i <= n; i++){
			for(j = v[i].ff; j <= 300; j++){
				for(k = v[i].ss; k <= 300; k++){
					DP[j][k] =min(DP[j][k],DP[j-v[i].ff][k-v[i].ss]+1);
				}
			}
		}
		int ans = 1e9;
		for(i = 0; i <= d; i++){
			j = d1-i*i;
			k = sqrt(j);
			if(k*k != j) continue;
			ans = min(ans,DP[i][k]);
			ans = min(ans,DP[k][i]);
		}
		if(ans == 1e9) printf("not possible\n");
		else printf("%d\n", ans);
	}
	return 0;
}

