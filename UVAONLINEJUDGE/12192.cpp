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

int mat[501][501];

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,n,m,q,left,right,a,b;

	while(scanf("%d%d", &n, &m),n){
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		}
		scanf("%d", &q);
		for(i = 0; i < q; i++){
			scanf("%d%d", &left, &right);
			int ans = 0;
			for(j = 0; j < n; j++){
				if(mat[j][0] > right) break;
				auto it = lower_bound(mat[j], mat[j]+m, left);
				a = it-mat[j];
				if(a == m) continue;
				if(*it < left) a++;
				int aux = 0;
				for(int k = j; k < n; k++,a++){
					if(mat[k][a] <= right) aux++;
					if(!(a+1 < m && mat[k][a+1] <= right))
						 break;
				}
				ans = max(ans,aux);
			}
			printf("%d\n",ans);
		}
		printf("-\n");
	}

	return 0;
}

