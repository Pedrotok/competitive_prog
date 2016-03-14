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

int v[100005];

bool f(int k, int n){
	for(int i = 1; i <= n; i++){
		int x = v[i]-v[i-1];
		if(x > k) return false;
		if(x == k) k--;
	}
	return true;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,t,n,tc=1,hi,lo,r,mid;
	int ans;
	
	scanf("%d", &t);
	while(t--){
		hi = 0;
		v[0] = 0;
		scanf("%d", &n);
		for(i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			hi = max(hi,v[i]);	
		}
		lo = 0;
		while(lo <= hi){
			mid = (hi+lo)/2;
			if(f(mid,n)) hi = mid-1;
			else lo = mid+1;
		}
		printf("Case %d: %d\n", tc++, lo);
	}

	return 0;
}

