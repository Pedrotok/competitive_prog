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

int v[10] = {0,1,5,10,25,50};
ll DP[30001];

int main() {
	int i,j,n;
	while(scanf("%d",&n)==1){
		memset(DP,0,sizeof(DP));
		DP[0] = 1;
		for(j = 0; j <= n; j++) DP[j] = 1;
		for(i = 2; i <= 5; i++){
			for(j = v[i]; j <= n; j++){
				if(j >= v[i])
					DP[j] += DP[j-v[i]];
			}
		}
		if(DP[n] == 1) printf("There is only 1 way to produce %d cents change.\n", n);
		else printf("There are %lld ways to produce %d cents change.\n", DP[n], n);
	}
	return 0;
}

