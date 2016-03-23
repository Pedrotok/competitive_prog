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

int v[101];
int DP[101][50001];

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,n,d,m,t;
	int sum;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = 0;
		for(i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			sum += v[i];
		}

		memset(DP,0,sizeof(DP));
		int lim = sum/2;
		for(i = 0; i <= n; i++)
			DP[i][0] = 1;
		for(i = 1; i <= lim; i++)
			DP[0][i] = 0;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= lim; j++){
				if(j >= v[i])
					DP[i][j] = max(DP[i-1][j], DP[i-1][j-v[i]]);
				else
					DP[i][j] = DP[i-1][j];
			}
		}
		for(i = lim; i >= 0; i--)
			if(DP[n][i]) break;
		
		printf("%d\n", abs(sum-2*i));


	}
	return 0;
}

