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
#include <stack>
#include <sstream>
#include <iomanip>
#include <bitset>
#define M_PI 3.14159265358979323846
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

int fw[105][105];

int main() {
	int n,i,j,a,b,m,tc=1,t,src,tg;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n,&m);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				fw[i][j] = 1e9;
		while(m--){
			scanf("%d%d", &a, &b);
			fw[a][b] = fw[b][a] = 1;
		}
		scanf("%d%d", &src, &tg);
		for(i = 0; i < n; i++) fw[i][i] = 0;
		for(int k = 0; k < n; k++){
			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
				}
			}
		}
		int ans = 0;
		for(j = 0; j < n; j++)
			ans = max(ans,fw[src][j]+fw[j][tg]);
		printf("Case %d: %d\n", tc++, ans);	
	}

	return 0;
}
