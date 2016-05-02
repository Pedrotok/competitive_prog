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

vector<int> G[30];
bool vis[30];

void dfs(int a){
	vis[a] = 1;
	for(int i : G[a]){
		if(!vis[i])
			dfs(i);
	}
}

int main() {
	int i,j,t,a,n,b;
	char c;
	string s;

	scanf("%d\n", &t);
	while(t--){
		scanf(" %c", &c);
		n = c-'A'+1;
		for(i = 0; i < n; i++)
			G[i].clear();
		s.clear();
		getline(cin,s);
		while(getline(cin,s) && !s.empty()){
			a = s[0]-'A';
			b = s[1]-'A';
			G[a].emplace_back(b);
			G[b].emplace_back(a);
		}
		memset(vis,0,sizeof(vis));
		int ans = 0;
		for(i = 0; i < n; i++){
			if(!vis[i]){
				dfs(i);
				ans++;
			}
		}
		printf("%d\n", ans);
		if(t) printf("\n");
	}
	return 0;
}
