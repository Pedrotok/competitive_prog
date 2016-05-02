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

int v[205],n;
int DP[205][10005], place[205];
int length,total;

int f(int i,int left, int right){
	if(i == n) return 0;

	if(DP[i][left] != -1) return DP[i][left];
	int ans = 0;
	if(left+v[i] <= length) ans = f(i+1, left+v[i], right)+1;
	if(right+v[i] <= length) ans = max(ans,f(i+1, left, right+v[i])+1);
	return DP[i][left] = ans;
}

bool build(int i, int left, int right){
	if(i == total) return true;
	int l,r;
	l = r = 0;
	if(left+v[i] <= length) l = f(i+1,left+v[i],right)+1;
	if(right+v[i] <= length) r = f(i+1,left,right+v[i])+1; 

	if(l > r){
		place[i] = 1;
		build(i+1, left+v[i], right);
	}
	else{
		if(r){
			place[i] = 2;
			build(i+1, left, right+v[i]);
		}
	}
}

int main() {
	int i, t, j,k;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &length);
		length*=100;
		n = 0;
		int sum = 0;
		while(scanf("%d", &i) && i && sum <= length*2){
			v[n++] = i;
			sum+=i;
		}
		while(i && scanf("%d", &i));
		memset(DP,-1,sizeof(DP));
		memset(place,0,sizeof(place));

		total = f(0,0,0);
		printf("%d\n", total);
		build(0,0,0);
		for(i = 0; i < total; i++){
			if(place[i] == 1) printf("starboard\n");
			else printf("port\n");
		}
		if(t) printf("\n");
	}
	return 0;
}

