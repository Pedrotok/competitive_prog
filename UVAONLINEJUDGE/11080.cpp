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

vector<int> G[201];
int part[201];
int c1,c2;
bool deu_ruim;

void dfs(int a,int c){
	part[a] = c;
	if(c == 1){c1++; c=2;}
	else{c2++; c=1;}
	for(int x : G[a]){
		if(!part[x]) dfs(x,c);
		else if(part[x] != c)
			deu_ruim = 1;
	}
}

int main() {
	int n,m,i,a,b,t;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n,&m);
		for(i = 0; i < m; i++){
			scanf("%d%d", &a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}

		memset(part,0,sizeof(part));

		int ans = 0;
		deu_ruim = 0;
		for(i = 0; i < n && !deu_ruim; i++){
			if(!part[i]){
				c1 = c2 = 0;
				dfs(i,1);
				if(!c1) ans += c2;
				else if(!c2) ans += c1;
				else ans += min(c1,c2);
			}
		}
		
		printf("%d\n",(deu_ruim?-1:ans));
		for(i = 0; i < n; i++)
			G[i].clear();
	}

	return 0;
}
