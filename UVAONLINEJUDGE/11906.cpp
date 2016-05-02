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
	
char mat[101][101];
bool vis[101][101];
int r,c,m,n,even,odd;
queue<pair<int,int>> Q;

int deu_certo(int x, int y){
	if(x < 0 || x >= r || y < 0 || y >= c)
		return 0;
	if(mat[x][y] == 'W') return 0;
	if(!vis[x][y]){
		vis[x][y] = 1;
		Q.push(make_pair(x, y));
	}
	return 1;
}

void bfs(){
	queue<pair<int,int>> empty;
	swap(empty,Q);
	Q.push(make_pair(0,0));
	vis[0][0] = 1;
	while(!Q.empty()){
		pair<int,int> aux = Q.front(); Q.pop();
		int cont = 0;

		cont+=deu_certo(aux.ff+m, aux.ss+n);
		if(n != 0)
			cont+=deu_certo(aux.ff+m, aux.ss-n);
		if(m != 0)
			cont+=deu_certo(aux.ff-m, aux.ss+n);
		if(n != 0 && m != 0)
			cont+=deu_certo(aux.ff-m, aux.ss-n);
		if(n != m){
			cont+=deu_certo(aux.ff+n, aux.ss+m);
			if(m != 0)
				cont+=deu_certo(aux.ff+n, aux.ss-m);
			if(n != 0)
				cont+=deu_certo(aux.ff-n, aux.ss+m);
			if(m != 0 && n != 0)
				cont+=deu_certo(aux.ff-n, aux.ss-m);
		}

		cont&1?odd++:even++;
	}
}


int main() {
	int i,j,t,w,tc=1,a,b;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &r, &c, &m, &n, &w);
		memset(mat,0,sizeof(mat));
		for(i = 0; i < w; i++){
			scanf("%d%d", &a, &b);
			mat[a][b] = 'W';
		}
		even = odd = 0;
		memset(vis,0,sizeof(vis));
		bfs();
		
		printf("Case %d: %d %d\n", tc++, even, odd);
	}

	return 0;
}
