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

pair<int,int> v[10001], LIS[10001], LDS[10001];
int LI[10001], LD[10001];

int search_smaller(int tam, int num){
	int lo,hi,mid;
	hi = tam; lo = 0;
	while(hi > lo+1){
		mid = (hi+lo)/2;
		if(LDS[mid].ff < num) hi=mid;
		else lo=mid;
	}
	if(LDS[lo].ff < num) return lo;
	return hi;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,k,t,n,l,tc=1;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		l = 0;
		for(i = 0; i < n; i++)
			scanf("%d", &v[i].ff);
		for(i = 0; i < n; i++)
			scanf("%d", &v[i].ss);
		for(i = 0; i < n; i++){
			LI[i] = 0;
			for(j = 0; j < i; j++)
				if(v[j].ff < v[i].ff) LI[i] = max(LI[i], LI[j]);
			LI[i]+=v[i].ss;
		}
		for(i = 0; i < n; i++){
			LD[i] = 0;
			for(j = 0; j < i; j++)
				if(v[j].ff > v[i].ff) LD[i] = max(LD[i], LD[j]);
			LD[i]+=v[i].ss;
		}
		
		int lis=0,lds=0;
		for(i = 0; i < n; i++){
			lis = max(lis, LI[i]);
			lds = max(lds, LD[i]);
		}
		
		if(lis >= lds)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", tc++, lis, lds);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", tc++, lds, lis);
	}

	return 0;
}

