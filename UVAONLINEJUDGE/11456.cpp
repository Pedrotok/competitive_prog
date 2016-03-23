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

int v[2001], LIS[2001], LDS[2001], LI[2001], LD[2001];

int search_smaller(int tam, int num){
	int lo,hi,mid;
	hi = tam; lo = 0;
	while(hi > lo+1){
		mid = (hi+lo)/2;
		if(LDS[mid] < num) hi=mid;
		else lo=mid;
	}
	if(LDS[lo] < num) return lo;
	return hi;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,k,t,n,l;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		l = 0;
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);
		for(i = n-1; i >= 0; i--){
			int pos = lower_bound(LIS, LIS+l, v[i])-LIS;
			LIS[pos] = v[i];
			LI[i] = pos+1;
			l = max(l,pos+1);
		}
		l = 0;
		for(i = n-1; i >= 0; i--){
			int pos = search_smaller(l,v[i]);
			LDS[pos] = v[i];
			LD[i] = pos+1;
			l = max(l,pos+1);
		}
		
		int ans = 0;
		for(i = 0; i < n; i++)
			ans = max(ans, LI[i] + LD[i] - 1);
		
		printf("%d\n", ans);
	}

	return 0;
}

