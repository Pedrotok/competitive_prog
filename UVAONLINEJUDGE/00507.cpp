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

int v[20001];

int main() {
	//ios_base::sync_with_stdio(0);

	int n,i,t,ini,msum,cnt,tc=1;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n-1; i++)
			scanf("%d", &v[i]);
		int sum,auxi, ed;
		sum = ini = auxi = 0;
		msum = -1;
		for(i = 0; i < n-1; i++){
			sum+=v[i];
			if(sum > msum || (sum == msum && i+1-auxi > ed-ini)){
				msum = sum;
				ini = auxi;
				ed = i+1;
			}
			if(sum < 0){
				sum = 0;
				auxi = i+1;
			}
		}
		if(msum < 0)
			printf("Route %d has no nice parts\n", tc++);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", tc++, ini+1, ed+1);
	}

	return 0;
}

