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

bool G[101][101];
int d[101];

int main() {
	string s,s2;
	int n,i,m,tc=1;
	
	while(cin >> n){
		map<string,int> tab;
		vector<string> v = vector<string>(n);
		for(i = 0; i < n; i++){
			cin >> s;
			v[i] = s;
			tab[s] = i;
		}
		cin >> m;
		memset(d,0,sizeof(d));
		memset(G,0,sizeof(G));
		while(m--){
			cin >> s >> s2;
			int a = tab[s], b = tab[s2];
			if(!G[a][b]){
				d[b]++;
				G[a][b] = 1;
			}
		}

		priority_queue<int,vector<int>, greater<int> > Q;
		for(i = 0; i < n; i++){
			if(!d[i]) Q.push(i);
		}
		vector<int> ans;
		while(!Q.empty()){
			int a = Q.top(); Q.pop();
			ans.push_back(a);
			for(int x = 0; x < n; x++){
				if(!G[a][x]) continue;
				d[x]--;
				if(!d[x]) Q.push(x);
			}
		}
		cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";
		for(int x : ans)
			cout << " " << v[x];
		cout << ".\n\n";
	}

	return 0;
}
