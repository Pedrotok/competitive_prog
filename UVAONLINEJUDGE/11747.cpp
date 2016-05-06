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
#define mp make_pair

using namespace std;

typedef long long ll;

pair<int,int> v[1005];
int p[1005], rk[1005];

int find(int a){
	if(p[a] != a)
		return p[a] = find(p[a]);
	return a;
}

void merge(int a,int b){
	int x = p[a];
	int y = p[b];
	if(rk[x] > rk[y])
		p[y] = x;
	else{
		p[x] = y;
		if(rk[x] == rk[y])
			rk[y]++;
	}
}

int main() {
	int n,i,j,m,a,b,c,sum;

	while(scanf("%d%d", &n, &m), n){
		for(i = 0; i < n; i++){
			p[i] = i;
			rk[i] = 0;
		}
		priority_queue<pair<int,pair<int,int>>> Q;
		for(i = 0; i < m; i++){
			scanf("%d%d%d", &a,&b,&c);
			Q.push(mp(-c,mp(a,b)));
		}
		
		vector<int> ans;

		while(!Q.empty()){
			int dist = -Q.top().ff;
			pair<int,int> vert = Q.top().ss;
			Q.pop();
			if(find(vert.ff) != find(vert.ss)){
				merge(vert.ff,vert.ss);
			}
			else
				ans.push_back(dist);
		}

		if(!ans.size()){
			printf("forest\n");
			continue;
		}
		sort(ans.begin(), ans.end());
		printf("%d", ans[0]);
		for(i = 1; i < ans.size(); i++)
			printf(" %d", ans[i]);
		printf("\n");
	}

	return 0;
}
