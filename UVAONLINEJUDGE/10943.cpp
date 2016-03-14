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

int DP[101][101];

int f(int n, int k){
	if(k == 1) return 1;
	if(DP[n][k] != -1) return DP[n][k];
	ll ret = 0;
	for(int i = 0; i <= n; i++)
		ret = (ret+f(i,k-1))%1000000;
	return DP[n][k] = (int)ret;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int n,i,j,msum,k,l,sum;

	while(scanf("%d%d", &n, &k) && n != 0 || k != 0){
		memset(DP,-1,sizeof(DP));
		int ans = f(n,k);
		printf("%d\n", ans);
	}

	return 0;
}

