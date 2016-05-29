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

int bus[205];
vector<int> G[205];
int dist[205];

int main() {
	int n,i,m,j,a,b,q,tc=1;
	while(scanf("%d", &n) == 1){
		for(i = 1; i <= n; i++)
			scanf("%d", &bus[i]);
		scanf("%d", &m);
		while(m--){
			scanf("%d%d", &a,&b);
			G[a].push_back(b);
		}
		scanf("%d", &q);

		for(i = 1; i <= n; i++){
			dist[i] = 1e9;
		}
		dist[1] = 0;
		
		bool changed = 1;
		for(i = 0; i < n-1 && changed; i++){
			changed = 0;
			for(j = 1; j <= n; j++){
				if(dist[j] == 1e9) continue;
				for(int v : G[j]){
					int aux = bus[v]-bus[j];
					aux = aux*aux*aux;
					if(dist[j]+aux < dist[v]){
						dist[v] = dist[j]+aux;
						changed = 1;
					}
				}
			}
		}
		for(j = 1; j <= n && changed; j++){
			if(dist[j] == 1e9) continue;
			for(int v : G[j]){
				int aux = bus[v]-bus[j];
				aux=aux*aux*aux;
				if(dist[j]+aux < dist[v])
					dist[v] = -1e9;
			}
		}
		printf("Set #%d\n", tc++);
		while(q--){
			scanf("%d", &a);
			if(dist[a] < 3 || dist[a] == 1e9) printf("?\n");
			else printf("%d\n", dist[a]);
		}

		for(i = 1; i <= n; i++) G[i].clear();
	}

	return 0;
}
