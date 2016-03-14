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

int v[21][21],n,M;
int DP[201][21];

int f(int money, int g){
	if(money < 0) return 1e9;
	if(g == n) return money;
	if(DP[money][g] != -1) return DP[money][g];
	int ans = 1e9;
	for(int i = 1; i <= v[g][0]; i++)
		ans = min(ans, f(money-v[g][i], g+1));
	return DP[money][g] = ans;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,t;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &M, &n);

		for(i = 0; i < n; i++){
			scanf("%d", &v[i][0]);
			for(j = 1; j <= v[i][0]; j++)
				scanf("%d", &v[i][j]);
		}
		memset(DP,-1,sizeof(DP));
		int ans = f(M, 0);
		if(M-ans < 0) printf("no solution\n");
		else printf("%d\n", M-ans);
	}


	return 0;
}

