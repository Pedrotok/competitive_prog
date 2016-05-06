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

struct node{
	int x,y,dir,dist;
	node(int a,int b, int c, int d){
		x = a; y = b; dir = c; dist = d;
	}
	node(){}
};

bool vis[55][55][4], thing[55][55];
int row[4][3];
int col[4][3];
map<string, int> tab;

void init(){
	int i;
	tab["north"] = 0;tab["east"] = 1;tab["south"] = 2;tab["west"] =3;
	for(i = 0; i < 3; i++){row[0][i] = -i-1; col[0][i] = 0;}
	for(i = 0; i < 3; i++){row[2][i] = i+1; col[2][i] = 0;}
	for(i = 0; i < 3; i++){row[1][i] = 0; col[1][i] = i+1;}
	for(i = 0; i < 3; i++){row[3][i] = 0; col[3][i] = -i-1;}
}

int main() {
	int i,n,m,j,a,b,c;
	pair<int,int> sc,tg;
	char dir[10];
	init();

	while(scanf("%d%d", &n, &m),n+m){
		memset(thing,0,sizeof(thing));
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				scanf("%d", &a);
				if(a)
					thing[i][j]=thing[i+1][j]=thing[i][j+1]=thing[i+1][j+1] = 1;
			}
		}
		scanf("%d%d%d%d%s", &sc.ff,&sc.ss,&tg.ff,&tg.ss,dir);

		memset(vis,0,sizeof(vis));
		vis[sc.ff][sc.ss][tab[dir]] = 1;
		queue<node> Q;
		Q.push(node(sc.ff,sc.ss,tab[dir],0));
		int ans = -1;

		while(!Q.empty()){
			node aux = Q.front();
			Q.pop();
			if(aux.x == tg.ff && aux.y == tg.ss){
				ans = aux.dist;
				break;
			}
			aux.dist++;
			for(i = 0; i < 3; i++){
				a = aux.x+row[aux.dir][i];
				b = aux.y+col[aux.dir][i];
				if(a <= 0 || a >= n || b <= 0 || b >= m || vis[a][b][aux.dir]) continue;
				if(thing[a][b]) break;
				vis[a][b][aux.dir] = 1;
				Q.push(node(a,b,aux.dir,aux.dist));
			}
			a = (aux.dir+1)%4;
			if(!vis[aux.x][aux.y][a]){
				vis[aux.x][aux.y][a] = 1;
				Q.push(node(aux.x,aux.y,a,aux.dist));
			}
			a = aux.dir-1<0?3:aux.dir-1;
			if(!vis[aux.x][aux.y][a]){
				vis[aux.x][aux.y][a] = 1;
				Q.push(node(aux.x,aux.y,a,aux.dist));
			}
		}
		printf("%d\n", ans);

	}

	return 0;
}
