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

int v[10001];

int bsearch(int n, int val){
	int lo,hi,mid;
	lo = 0; hi = n-1;
	while(lo < hi){
		mid = (hi+lo)/2;
		if(v[mid] == val) return mid;
		if(v[mid] < val) lo=mid+1;
		else hi = mid-1;
	}
	if(v[lo] == val) return lo;
	return -1;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,n,money;
	while(scanf("%d", &n)==1){
		for(i = 0; i < n; i++)
			scanf("%d", &v[i]);
		scanf("%d", &money);
		sort(v, v+n);
		int p1,p2,n1=0,n2=money;
		for(i = n-1; i >= 0; i--){
			p1 = v[i];
			p2 = money-p1;
			int x = bsearch(n,p2);
			if(x == -1) continue;
			if(x != i){
				if(abs(p2-p1) < n2-n1){
					n1=min(p1,p2);
					n2=max(p1,p2);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",n1,n2);
	}

	return 0;
}

