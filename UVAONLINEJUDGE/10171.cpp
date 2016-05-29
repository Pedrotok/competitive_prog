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

int fw_y[105][105], fw_o[105][105];

int main() {
	int n,i,j,a,b,en;
	char age,dir,c1,c2,s,t;
	while(scanf("%d", &n),n){
		for(i = 0; i < 26; i++)
			for(j = 0; j < 26; j++)
				fw_y[i][j] = fw_o[i][j] = 1e9;
		for(i = 0; i < n; i++){
			scanf(" %c %c %c %c %d", &age, &dir, &c1, &c2, &en);
			a = c1-'A';
			b = c2-'A';
			if(age == 'Y') fw_y[a][b] = en;
			else fw_o[a][b] = en;
			if(dir == 'B'){
				if(age == 'Y') fw_y[b][a] = en;
				else fw_o[b][a] = en;
			}
		}
		for(i = 0; i < 26; i++) fw_y[i][i] = fw_o[i][i] = 0;
		scanf(" %c %c", &s, &t);
		for(int k = 0; k < 26; k++){
			for(i = 0; i < 26; i++){
				for(j = 0; j < 26; j++){
					fw_y[i][j] = min(fw_y[i][j], fw_y[i][k]+fw_y[k][j]);
					fw_o[i][j] = min(fw_o[i][j], fw_o[i][k]+fw_o[k][j]);
				}
			}
		}
		int ans = 1e9;
		a = s-'A'; b=t-'A';
		set<int> place;
		for(j = 0; j < 26; j++){
			int aux = fw_y[a][j]+fw_o[b][j];
			if(ans >= aux){
				if(ans == aux) place.insert(j);
				else{
					place.clear();
					place.insert(j);
					ans = aux;
				}
			}
		}
		if(ans == 1e9) printf("You will never meet.\n");
		else{
			printf("%d", ans);
			for(int x : place) printf(" %c", x+'A');
			printf("\n");
		}
	}

	return 0;
}
