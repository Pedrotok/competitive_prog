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

char mat[205][205];
string val[200];
int comp_b,comp_w,h,w,cb[205][205],comp[201];
bool vis[205][205];
char letter[10];
int atual;

int row[4] = {-1,0,1,0};
int col[4] = {0,1,0,-1};

void dfs(int x, int y){
	vis[x][y] = 1;
	cb[x][y] = comp_b;
	for(int i = 0; i < 4; i++){
		int aux_x = x+row[i], aux_y = y+col[i];
		if(aux_x < 0 || aux_x >= h || aux_y < 0 || aux_y >= w)
			continue;
		if(mat[aux_x][aux_y] == '1' && !vis[aux_x][aux_y])
			dfs(aux_x,aux_y);
	}
}

void dfs2(int x, int y){
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int aux_x = x+row[i], aux_y = y+col[i];
		if(aux_x < 0 || aux_x >= h || aux_y < 0 || aux_y >= w)
			continue;
		if(mat[aux_x][aux_y] == '0'){
			if(!vis[aux_x][aux_y]) dfs2(aux_x,aux_y);
		}
		else atual = cb[aux_x][aux_y]; 
	}
}

void init(){
	val['0'] = "0000";
	val['1'] = "0001";
	val['2'] = "0010";
	val['3'] = "0011";
	val['4'] = "0100";
	val['5'] = "0101";
	val['6'] = "0110";
	val['7'] = "0111";
	val['8'] = "1000";
	val['9'] = "1001";
	val['a'] = "1010";
	val['b'] = "1011";
	val['c'] = "1100";
	val['d'] = "1101";
	val['e'] = "1110";
	val['f'] = "1111";

	letter[1] = 'A';
	letter[3] = 'J';
	letter[5] = 'D';
	letter[4] = 'S';
	letter[0] = 'W';
	letter[2] = 'K';
}	

int main() {
	int i,j,tc=1,k;
	char c;

	init();

	while(scanf("%d%d",&h, &w), h+w != 0){
		memset(mat,0,sizeof(mat));
		for(j = 0; j <= 4*w+1; j++)
			mat[0][j] = '0';
		for(i = 1; i <= h; i++){
			mat[i][0] = '0';
			for(j = 1,k = 1; j <= w; j++){
				scanf(" %c", &c);
				for(int l = 0; l < 4; l++)
					mat[i][k++] = val[c][l];
			}
			mat[i][k] = '0';
		}
		for(j = 0; j <= 4*w+1; j++)
			mat[h+1][j] = '0';
		w = w*4 + 2;
		h+=2;

		memset(vis,0,sizeof(vis));
		dfs2(0,0);
		comp_b = 0;
		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				if(mat[i][j] == '1' && !vis[i][j]){
					dfs(i,j);
					comp_b++;
				}
			}
		}
		memset(comp,0,sizeof(comp));
		
		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				if(mat[i][j] == '0' && !vis[i][j]){
					dfs2(i,j);
					comp[atual]++;
				}
			}
		}
		vector<char> S;
		for(i = 0; i < comp_b; i++){
			S.push_back(letter[comp[i]]);
		}
		sort(S.begin(), S.end());

		printf("Case %d: ", tc++);
		for(char k : S)
			printf("%c", k);
		printf("\n");
	}

	return 0;
}
