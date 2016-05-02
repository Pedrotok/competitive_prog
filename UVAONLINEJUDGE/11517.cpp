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

int v[105], DP[105][20005];

int main() {
	int i,j,n,t,price;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &price, &n);
		for(i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		for(j = 0; j <= 20000; j++)
			DP[0][j] = 1e9;
		for(i = 0; i <= n; i++)
			DP[i][0] = 0;
		int ans = 20000;
		for(i = 1; i <= n; i++){
			for(j = 0; j <= ans; j++){
				DP[i][j] = DP[i-1][j];
				if(j >= v[i] && DP[i][j] > DP[i-1][j-v[i]]+1){
					DP[i][j] = DP[i-1][j-v[i]]+1;
					if(j >= price){
						ans = min(ans,j);
						break;
					}
				}
			}
		}
		printf("%d %d\n", ans, DP[n][ans]);
	}
	return 0;
}

