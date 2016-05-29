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

vector<pair<int,int>> G[1005];
int dist[1005];

int main() {
	int n,i,m,j,a,b,c,t;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&m);
		while(m--){
			scanf("%d%d%d", &a,&b,&c);
			G[a].push_back(mp(b,c));
		}

		for(i = 0; i < n; i++)
			dist[i] = 1e9;
		dist[0] = 0;
		
		for(i = 0; i < n-1; i++){
			for(j = 0; j < n; j++){
				for(pair<int,int> &v : G[j]){
					dist[v.ff] = min(dist[v.ff], dist[j]+v.ss);
				}
			}
		}
		bool cycle = 0;
		for(j = 0; j < n && !cycle; j++){
			for(pair<int,int> &v : G[j]){
				if(dist[j] + v.ss < dist[v.ff]){
					cycle = 1;
					break;
				}
			}
		}
		for(i = 0; i < n; i++) G[i].clear();
		if(cycle) printf("possible\n");
		else printf("not possible\n");
	}

	return 0;
}
