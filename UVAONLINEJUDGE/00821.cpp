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

int fw[105][105];

int main() {
	int n,i,k,m,j,a,b,tc=1;
	while(scanf("%d%d", &a, &b),a+b!=0){
		for(i = 1; i <= 100; i++)
			for(j = 1; j <= 100; j++)
				fw[i][j] = 1e9;
		set<int> S;
		S.insert(a); S.insert(b);
		fw[a][b] = 1;
		while(scanf("%d%d", &a,&b),a+b != 0){
			S.insert(a); S.insert(b);
			fw[a][b] = 1;
		}
		for(int k : S)
			for(int i : S)
				for(int j : S)
					fw[i][j] = min(fw[i][j],fw[i][k]+fw[k][j]);
		int sum = 0;
		for(int i : S)
			for(int j : S){
				if(i==j) continue;
				sum += fw[i][j];
			}
		int tot = S.size()*(S.size()-1);
		printf("Case %d: average length between pages = %.3lf clicks\n", tc++, (double)sum/tot);
	}

	return 0;
}
