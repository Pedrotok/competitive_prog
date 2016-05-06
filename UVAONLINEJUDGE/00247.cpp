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

set<int> G[30];
string v[30];
stack<int> S;
bool vis[30];
int num[30], low[30];
int c;

void dfs(int u){
	num[u] = low[u] = c++;
	vis[u] = 1;
	S.push(u);
	for(int x : G[u]){
		if(!num[x])
			dfs(x);
		if(vis[x])
			low[u] = min(low[u], low[x]);
	}
	if(low[u] == num[u]){
		int a = S.top(); S.pop();
		cout << v[a]; vis[a] = 0;
		while(u != a){
			a = S.top(); S.pop();
			vis[a] = 0;
			cout << ", " << v[a];
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int n,i,m,d,tc=1;
	string s1,s2;

	while(cin >> n >> m,n){
		if(tc > 1) cout << "\n";
		map<string, int> tab;
		d = 0;
		for(i = 0; i < m; i++){
			cin >> s1 >> s2;
			if(tab.find(s1) == tab.end()){
				tab[s1] = d;
				v[d++] = s1;
			}
			if(tab.find(s2) == tab.end()){
				tab[s2] = d;
				v[d++] = s2;
			}
			G[tab[s1]].insert(tab[s2]);
		}
		memset(num,0,sizeof(num));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));
		cout << "Calling circles for data set " << tc++ <<":\n";
		c = 1;
		for(i = 0; i < n; i++){
			if(!num[i])
				dfs(i);
		}
		for(i = 0; i < n; i++) G[i].clear();
		stack<int> empty;
		swap(empty,S);

	}

	return 0;
}
