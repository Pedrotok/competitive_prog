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

pair<int,int> v[105];
int p[105], rk[105];
bool flag[10005];

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
	int n,i,j,m,t,a,b,c;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n,&m);
		for(i = 1; i <= n; i++){
			rk[i] = 0;
			p[i] = i;
		}
		vector<pair<int,pair<int,int>>> Q;
		for(i = 0; i < m; i++){
			scanf("%d%d%d", &a,&b,&c);
			flag[i] = 0;
			Q.push_back(mp(c,mp(a,b)));
		}
		sort(Q.begin(), Q.end());
		int v = 0;
		int ans1 = 0, ans2 = 1e9;

		vector<int> aresta;
		i = 0;
		while(v < n-1){
			int dist = Q[i].ff;
			pair<int,int> vert = Q[i].ss;
			if(find(vert.ff) != find(vert.ss)){
				v++;
				merge(vert.ff,vert.ss);
				ans1+= dist;
				aresta.push_back(i);
			}
			i++;
		}

		for(int x : aresta){
			flag[x] = 1;
			for(i = 1; i <= n; i++){
				rk[i] = 0;
				p[i] = i;
			}
			i = v = 0;
			int aux = 0;
			while(v < n-1 && i < m){
				if(flag[i]) {i++;continue;}
				int dist = Q[i].ff;
				pair<int,int> vert = Q[i].ss;
				if(find(vert.ff) != find(vert.ss)){
					v++;
					merge(vert.ff,vert.ss);
					aux += dist;
				}
				i++;
			}
			if(v == n-1)
				ans2 = min(ans2,aux);
			flag[x] = 0;
		}

		printf("%d %d\n", ans1, ans2);
	}

	return 0;
}
