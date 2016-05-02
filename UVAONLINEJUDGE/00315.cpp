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

using namespace std;

typedef long long ll;

vector<int> G[105];
int c, num[105], low[105];
bool art[105];
int root, children;

void dfs(int v, int p){
	num[v] = low[v] = c++;
	for(int x : G[v]){
		if(x == p) continue;
		if(!num[x]){
			if(v == root) children++;
			dfs(x,v);
			if(low[x] >= num[v]){
				art[v]=1;
			}
			low[v] = min(low[v], low[x]);
		}
		else low[v] = min(low[v], num[x]);
	}
}

int main() {
	int n,m,i,a,b,t;
	string s;

	while(scanf("%d\n",&n),n){

		while(1){
			getline(cin,s);
			stringstream x(s);
			b = 0;
			while(x >> a){
				if(!b) b = a;
				else{
					G[a].push_back(b);
					G[b].push_back(a);
				}
			}
			if(!a) break;
		}
		
		c = 1;
		memset(num,0,sizeof(num));
		memset(low,0,sizeof(low));
		memset(art,0,sizeof(art));
		for(i = 1; i <= n; i++){
			if(!num[i]){
				root = i; children = 0;
				dfs(i,i);
				art[i] = (children > 1);
			}
		}
		
		int ans = 0;
		for(i = 1; i <= n; i++){
			ans += art[i];
			G[i].clear();
		}
		cout << ans << "\n";
	}

	return 0;
}
