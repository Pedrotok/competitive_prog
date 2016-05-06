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

vector<int> G[2505];
bool vis[2505];

int main() {
	int n,i,j,m,t,a,b;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &j);
		while(j--){
			scanf("%d", &a);
			G[i].push_back(a);
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &a);
		for(i = 0; i < n; i++) vis[i] = 0;
		int day = 0, p = -1, ans1 = 0, ans2 = 0;
		queue<pair<int,int>> Q;
		Q.push(mp(a,0));
		vis[a] = 1;
		while(!Q.empty()){
			a = Q.front().ff;
			int d = Q.front().ss; Q.pop();
			if(day == d) p++;
			else day = d, p=1;
			if(p > ans2){
				ans1 = day;
				ans2 = p;
			}
			for(int x : G[a]){
				if(!vis[x]){
					vis[x] = 1;
					Q.push(mp(x,d+1));
				}
			}
		}
		if(ans1) printf("%d %d\n", ans2, ans1);
		else printf("%d\n", ans1);
	}

	return 0;
}
