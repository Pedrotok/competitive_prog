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

int fw[51][51];

int main() {
	int n,i,j,m,a,b,tc=1;
	char s1[30], s2[30];

	while(scanf("%d%d", &n,&m),n+m){
		map<string,int> tab;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				fw[i][j] = 1e9;
		int cont = 0;
		while(m--){
			scanf(" %s %s", s1,s2);
			if(tab.find(s1) == tab.end())
				tab[s1] = cont++;
			if(tab.find(s2) == tab.end())
				tab[s2] = cont++;
			a = tab[s1];
			b = tab[s2];
			fw[a][b] = fw[b][a] = 1;
		}
		for(int k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					fw[i][j] = min(fw[i][j],fw[i][k]+fw[k][j]);

		int ans = 0;
		bool disc = false;
		for(i = 0; i < n && !disc; i++){
			for(j = 0; j < n; j++){
				if(i == j) continue;
				if(fw[i][j] == 1e9){disc = 1;break;}
				ans = max(ans,fw[i][j]);
			}
		}
		if(disc){
			printf("Network %d: DISCONNECTED\n\n", tc++);
			continue;
		}
		printf("Network %d: %d\n\n", tc++,ans);
	}

	return 0;
}
