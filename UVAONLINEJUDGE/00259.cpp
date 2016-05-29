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

// App -> 0,25; PCs -> 26,35; s -> 36; t -> 37

vector<int> G[50];
int res[50][50];
int p[50];
int f;
char pc[10];

void fill_pc(){
	int i,j;
	for(i = 26; i <= 35; i++)
		for(j = 0; j <= 25; j++)
			if(res[i][j] == 1){ pc[i-26] = j+'A'; break; }
}

void augment(int v, int min_val){
	if(36 == v) {f = min_val; return ;}
	if(p[v] == -1) return ;
	augment(p[v], min(min_val,res[p[v]][v]));
	res[p[v]][v] -= f;
	res[v][p[v]] += f;
}

bool calc_flow(int people){
	for(int i = 0; i < 10; i++) pc[i] = '_';
	bool vis[50];
	int mf = 0;
	while(1){
		memset(vis,0,sizeof(vis));
		memset(p,-1,sizeof(p));
		queue<int> Q;
		Q.push(36);
		p[36]=36;
		vis[36] = 1;
		while(!Q.empty()){
			int v = Q.front(); Q.pop();
			if(v == 37) break;
			for(int x : G[v]){
				if(!vis[x] && res[v][x] > 0){
					p[x] = v;
					vis[x] = 1;
					Q.push(x);
				}
			}
		}
		f = 0;
		augment(37,1e9);
		if(f == 0) break;
		mf += f;
	}
	return mf == people;
}

int main() {
	int i,n,m,sum;
	string s;

	while(getline(cin,s)){
		memset(res,0,sizeof(res));
		for(i = 26; i <= 35; i++){
			G[i].push_back(37);
			res[i][37] = 1;
			G[37].push_back(i);
		}
		sum = 0;
		do{
			int app = s[0]-'A';
			int b = s[1]-'0';

			G[36].push_back(app);
			res[36][app] = b;
			G[app].push_back(36);
			sum += b;
			for(i = 3; s[i] != ';'; i++){
				b = s[i]-'0'+26;
				G[app].push_back(b);
				res[app][b] = 1e9;
				G[b].push_back(app);
			}
		}while(getline(cin,s),s[0] >= 'A' && s[0] <= 'Z');


		bool ans = calc_flow(sum);
		if(ans){
			fill_pc();
			for(i = 0; i < 10; i++)
				cout << pc[i];
			cout << "\n";
		}
		else cout << "!\n";

		for(i = 0; i < 38; i++) G[i].clear();
	}

	return 0;
}
