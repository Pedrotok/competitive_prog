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

pair<int,int> v[105];
int DP[105][10205],n,m,money;

int f(int i, int mon){
	if(mon > money) return -1e9;
	if(i == n){	
		if(!(mon > 2000 || mon <= m)) return -1e9;
		return 0;
	}
	if(DP[i][mon] != -1) return DP[i][mon];
	int ret = 0;
	ret = max(f(i+1, mon), f(i+1,mon+v[i].ff)+v[i].ss);
	return DP[i][mon] = ret;
}

int main() {
	int i,j;
	bool flag;
	while(scanf("%d%d",&m,&n) == 2){
		money = m;
		if(m > 1800) money += 200;
		for(i = 0; i < n; i++){
			scanf("%d%d", &v[i].ff, &v[i].ss);
		}
		memset(DP,-1,sizeof(DP));
		int ans = f(0,0);
		printf("%d\n", ans);
	}
	return 0;
}

