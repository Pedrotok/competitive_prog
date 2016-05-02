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

char v[25];
int v2[200];
bool G[25][25];
char vis[25];
set<string> ans;
int n;

void backtrack(int a, string s, int tam){
	for(int i = 0; i < n; i++){
		if(vis[i] && G[a][i]) return ;
	}
	if(tam == n){
		ans.insert(s);
		return ;
	}
	for(int i = 0; i < n; i++){
		if(G[i][a] || vis[i]) continue;
		vis[i] = 1;
		backtrack(i, s+" "+v[i], tam+1);
		vis[i] = 0;
	}
	return ;
}

int main() {
	int t,i,j,tc=0;
	string line,s;

	cin >> t;
	getline(cin,line);
	while(t--){
		if(tc++) cout << "\n";
		getline(cin,line);
		getline(cin,line);
		stringstream x(line);
		
		n = 0;
		while(x >> s){
			v2[s[0]] = n;
			v[n++] = s[0];
		}
		memset(G,0,sizeof(G));

		getline(cin,line);
		stringstream y(line);
		while(y >> s){
			G[v2[s[0]]][v2[s[2]]] = 1;
		}
		
		ans.clear();
		memset(vis,0,sizeof(vis));
		s.clear();
		for(j = 0; j < n; j++){
			vis[j] = 1;
			s = v[j];
			backtrack(j,s,1);
			vis[j] = 0;
		}
		if(!ans.size()) cout << "NO\n";
		else{
			for(string x : ans){
				cout << x << "\n";
			}
		}
	}

	return 0;
}
