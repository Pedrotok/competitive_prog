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
	
int x,y,ans,s,n,m;
char mat[101][101], d, inst[50005], v[200];

void dfs(int i){
	if(mat[x][y] == '*'){ans++; mat[x][y] = '.';}
	if(i == s) return ;
	char c = inst[i];
	if(c == 'D') d = (d+1)%4;
	else if(c == 'E') d-1==-1?d=3:d--;
	else{
		if(d == 0){if(mat[x-1][y] != '#' && x > 0) x--;}
		else if(d == 1){if(mat[x][y+1] != '#' && y < m-1) y++;}
		else if(d == 2){if(mat[x+1][y] != '#' && x < n-1) x++;}
		else{if(mat[x][y-1] != '#' && y > 0) y--;}
	}
	dfs(i+1);
}

int main() {
	int i,j;

	v['N'] = 0;
	v['L'] = 1;
	v['S'] = 2;
	v['O'] = 3;
	while(scanf("%d%d%d\n", &n, &m, &s), n+m+s!=0){
		x = -1;
		for(i = 0; i < n; i++){
			scanf(" %s", mat[i]);
			if(x == -1){
				for(j = 0; j < m; j++){
					if(mat[i][j] == 'N' || mat[i][j] == 'S' || mat[i][j] == 'L' || mat[i][j] == 'O')
						x = i, y = j, d = v[mat[i][j]];
				}
			}
		}
		scanf(" %s", inst);
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}

	return 0;
}
