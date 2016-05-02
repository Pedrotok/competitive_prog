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

pair<int,int> v[205];
int DP[202][23][1002];

int f(int i, int j, int mon){
	if(mon < 0) return -1e9;
	if(j == 0) return 0;
	if(i == 0) return 0;
	if(DP[i][j][mon] != -1) return DP[i][j][mon];
	int ret = max(f(i-1,j,mon),f(i-1,j-1,mon-v[i].ff) + v[i].ss);
	return DP[i][j][mon] = ret;
}

int main() {
	int i,j,n,m,x,t,a,money,tot_dish,k;
	while(scanf("%d%d%d%d",&n,&x,&t,&k) && (n != 0 || x != 0 || t != 0 || k != 0)){
		money = floor(double(x*(n+1))/1.1 + 1e-6)-(n+1)*t;
		tot_dish = 2*(n+1);
		for(i = 1; i <= k*2; i+=2){
			scanf("%d", &v[i].ff);
			int sum = 0;
			for(j = 0; j <= n; j++){
				scanf("%d", &a);
				sum+=a;
			}
			v[i].ss = sum;
			v[i+1] = v[i];
		}
		int ans = f(2*k,tot_dish,money);
		printf("%.2f\n", (double)ans/(n+1));
	}
	return 0;
}

