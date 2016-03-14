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

int v[101][101];

int main() {
	//ios_base::sync_with_stdio(0);

	int n,i,j,msum,k,l,sum;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%d", &v[i][j]);
				if(i > 0) v[i][j]+=v[i-1][j];
				if(j > 0) v[i][j]+=v[i][j-1];
				if(i > 0 && j > 0) v[i][j] -= v[i-1][j-1];
			}
		}
		msum = -1e9;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				for(k = i; k < n; k++){
					for(l = j; l < n; l++){
						sum = v[k][l];
						if(i > 0) sum-=v[i-1][l];
						if(j > 0) sum-=v[k][j-1];
						if(i > 0 && j > 0) sum+=v[i-1][j-1];
						msum = max(sum,msum);
					}
				}
			}
		}
		printf("%d\n",msum);
	}

	return 0;
}

