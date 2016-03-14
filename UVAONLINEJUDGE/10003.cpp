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

int v[51],DP[55][55],n;

int f(int left, int right){
	if(left+1 == right) return 0;
	if(DP[left][right] != -1) return DP[left][right];
	int x = 1e9;
	for(int i = left+1; i < right; i++)
		x = min(x,f(left,i) + f(i,right));
	x += v[right] - v[left];
	return DP[left][right] = x;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,msum,k,l,sum,x;

	while(scanf("%d", &x),x){
		scanf("%d", &n);
		for(i = 1; i <= n; i++) scanf("%d", &v[i]);
		v[n+1] = x;
		v[0] = 0;
		memset(DP,-1,sizeof(DP));
		int ans = f(0,n+1);
		printf("The minimum cutting is %d.\n", ans);
	}

	return 0;
}

