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

bool fw[201][201];
string v[201];

int main() {
	int n,i,j,m,a,b,tc=1;
	char s1[10], s2[10];

	while(scanf("%d", &n),n){
		map<string,int> tab;
		memset(fw,0,sizeof(fw));
		int cont = 1;
		for(i = 0; i < n; i++){
			scanf("%d", &m);
			a = -1;
			for(j = 0; j < m; j++){
				scanf(" %s",s1);
				if(tab.find(s1) == tab.end())
					v[cont] = s1,tab[s1] = cont++;
				b = tab[s1];
				if(a != -1)
					fw[a][b] = 1;
				a = b;
			}
		}
		scanf("%d", &m);
		for(j = 0; j < m; j++){
			scanf(" %s %s",s1,s2);
			a = tab[s1];
			b = tab[s2];
			fw[a][b] = 1;
		}
		for(int k = 1; k < cont; k++)
			for(i = 1; i < cont; i++)
				for(j = 1; j < cont; j++)
					fw[i][j] |= (fw[i][k] & fw[k][j]);

		set<pair<int,int>> S;
		for(i = 1; i < cont; i++){
			for(j = 1; j < cont; j++){
				if(i == j) continue;
				if(!fw[i][j] && !fw[j][i]) {
					if(j > i) S.insert(mp(i,j));
					else S.insert(mp(j,i));
				}
			}
		}
		if(S.empty()){
			printf("Case %d, no concurrent events.\n",tc++);
			continue;
		}
		printf("Case %d, %d concurrent events:\n",tc++,(int)S.size());
		cont = 1;
		for(pair<int,int> x : S){
			printf("(%s,%s) ", v[x.ff].c_str(),v[x.ss].c_str());
			if(!cont--) break;
		}
		printf("\n");
		
	}

	return 0;
}
