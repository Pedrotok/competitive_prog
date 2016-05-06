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

double dpoint(pair<int,int> a, pair<int,int> b){
	double aux1 = b.ff-a.ff;
	double aux2 = b.ss-a.ss;
	return sqrt(aux1*aux1 + aux2*aux2);
}

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
	int n,i,j,s,t;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &s,&n);
		for(i = 0; i < n; i++){
			scanf("%d%d", &v[i].ff,&v[i].ss);
			p[i] = i; rk[i] = 0;
		}
		
		priority_queue<pair<double,pair<int,int>>> Q;
		for(i = 0; i < n; i++){
			for(j = i+1; j < n; j++){
				double aux = dpoint(v[i],v[j]);
				Q.push(mp(-aux,mp(i,j)));
			}
		}
		int v = 0;
		double ans = 0;

		while(v < n-s){
			double dist = -Q.top().ff;
			pair<int,int> vert = Q.top().ss;
			Q.pop();
			if(find(vert.ff) != find(vert.ss)){
				v++;
				merge(vert.ff,vert.ss);
				ans = max(ans,dist);
			}
		}

		printf("%.2lf\n", ans);
	}

	return 0;
}
