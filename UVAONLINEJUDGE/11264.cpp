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

int v[1001];

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,m,n,t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);
		
		if(n == 1){ printf("1\n"); continue; }
		int ans = 2, sum = v[0];

		for(i = 1; i < n-1; i++){
			if(sum+v[i] >= v[i+1]) continue;
			sum += v[i];
			ans++;
		}
		printf("%d\n",ans);
	}

	return 0;
}

