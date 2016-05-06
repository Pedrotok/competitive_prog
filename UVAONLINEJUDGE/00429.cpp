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

string v[205];
vector<int> G[205];

int diff(int a, int b){
	int x = 0;
	if(v[a].size() != v[b].size()) return 0;
	for(int i = 0; v[a][i] && v[b][i]; i++)
		if(v[a][i] != v[b][i]) x++;
	return x;
}

int bfs(int s, int t){
	bool vis[205];
	memset(vis,0,sizeof(vis));
	queue<pair<int,int> > Q;
	Q.push(mp(s,0));
	vis[s] = 1;
	while(!Q.empty()){
		int x = Q.front().ff;
		int dist = Q.front().ss; Q.pop();
		if(x == t) return dist;
		for(int a : G[x])
			if(!vis[a]){
				vis[a] = 1;
				Q.push(mp(a,dist+1));
			}
	}
}

int main() {
	int n,i,j,m,t,a,b;
	string s,s1,s2;

	cin >> t;
	getline(cin,s);
	while(t--){
		n = 0;
		while(cin >> v[n], v[n][0] != '*')
			n++;

		sort(v,v+n);
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(i == j) continue;
				if(diff(i,j) == 1){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}

		getline(cin,s);
		while(getline(cin, s), !s.empty()){
			stringstream x(s);
			x >> s1 >> s2;
			int p1 = lower_bound(v, v+n,s1)-v;
			int p2 = lower_bound(v, v+n,s2)-v;
			int ans = bfs(p1,p2);
			cout << s1 << " " << s2 << " " << ans << "\n";
		}
		for(i = 0; i < n; i++) G[i].clear();
		if(t) cout << "\n";
	}

	return 0;
}
