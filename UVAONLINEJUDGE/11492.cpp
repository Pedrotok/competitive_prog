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

struct edge{
	char c;
	int v;
	int tam;
	edge(int a, char b, int t){
		v = a; c = b; tam = t;
	}
	edge(){}

	bool operator<(const edge &r) const{
		return tam > r.tam;
	}
};

map<string,int> tab;
vector<edge> G[4005];

int dijkstra(int n){
	priority_queue<edge> Q;
	int d[4005][26];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 26; j++)
			d[i][j] = 1e9;
	for(edge &x : G[0]){
		if(d[x.v][x.c] > x.tam){
			d[x.v][x.c] = x.tam;
			Q.push(x);
		}
	}
	while(!Q.empty()){
		int vert = Q.top().v;
		char let = Q.top().c;
		int dist = Q.top().tam; Q.pop();
		if(d[vert][let] < dist) continue;
		if(vert == 1) return dist;
		for(edge &x : G[vert]){
			if(x.c == let) continue;
			if(d[x.v][x.c] > d[vert][let]+x.tam){
				d[x.v][x.c] = d[vert][let]+x.tam;
				Q.push(edge(x.v,x.c,d[x.v][x.c]));
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	int i,n,m,j,a,b,t;
	string s1,s2,s3,source,target;

	while(cin >> n,n){
		tab.clear();
		cin >> source >> target;
		tab[source] = 0;
		tab[target] = 1;

		int cont = 2;
		for(i = 0; i < n; i++){
			cin >> s1 >> s2 >> s3;
			if(tab.find(s1) == tab.end())
				tab[s1] = cont++;
			if(tab.find(s2) == tab.end())
				tab[s2] = cont++;
			a = tab[s1];
			b = tab[s2];
			t = s3.size();
			G[a].push_back(edge(b,s3[0]-'a',t));
			G[b].push_back(edge(a,s3[0]-'a',t));
		}

		int ans = dijkstra(cont);
		if(ans) cout << ans << "\n";
		else cout << "impossivel\n";
		for(i = 0; i < cont; i++) G[i].clear();
	}

	return 0;
}
