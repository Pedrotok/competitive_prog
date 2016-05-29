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

double cur[25][25][25];
int p[25][25][25];

void show_print(int s, int i, int j){
	if(s == 0){
		printf("%d %d ", i+1,j+1);
		return;
	}
	show_print(s-1,i,p[s][i][j]);
	printf("%d ", j+1);
}

int main() {
	int n,i,j,steps;

	while(scanf("%d", &n) == 1){
		memset(cur,0,sizeof(cur));
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(i == j){cur[0][i][i] = 1.0; continue;}
				scanf("%lf", &cur[0][i][j]);
				p[0][i][j] = i;
			}
		}
		for(steps = 1; steps < n; steps++)
		for(int k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++){
					double aux = cur[steps-1][i][k]*cur[0][k][j];
					if(cur[steps][i][j] < aux){
						cur[steps][i][j] = aux;
						p[steps][i][j] = k;
					}
				}
		j = -1;
		for(steps = 1; steps < n && j==-1; steps++)
			for(i = 0; i < n; i++){
				if(cur[steps][i][i] > 1.01){
					j = i;
					break;
				}
			}
		
		if(j==-1){printf("no arbitrage sequence exists\n");continue;}
		show_print(steps-2,j,p[steps-1][j][j]);
		printf("%d\n",j+1);
	}

	return 0;
}
