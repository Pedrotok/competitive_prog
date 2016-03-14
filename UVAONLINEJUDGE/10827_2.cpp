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

int v[150][150];

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,k,n,a,b,c,t,l,m,msum,sum;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(v,0,sizeof(v));
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++){
				scanf("%d", &v[i][j]);
				v[i+n][j] = v[i+n][j+n] = v[i][j+n] = v[i][j];
			}
		m = n;
		n*=2;
		msum = -1e9;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++){
				if(j > 0) v[i][j]+=v[i][j-1];
			}
		for(i = 0; i < n; i++)
			for(j = i; j < n; j++){
				if(j - i >= m) break;
				sum = 0;
				int aux = 1e9, aux2 = 0, tot = 0;
				for(k = 0; k < m; k++){
					if(i > 0){ 
						c=v[k][j] - v[k][i-1]; sum+=c; tot+=c;
						if(k > 0 && k < m-1) aux2+=c;
					}
					else{
						c = v[k][j]; sum+=c; tot+=c;
						if(k > 0 && k < m-1) aux2+=c;
					}
					msum = max(sum,msum);
					if(k > 0 && k < m-1)
						aux = min(aux2,aux);
					if(sum < 0) sum = 0;
					if(aux2 > 0) aux2 = 0;
				}
				msum = max(msum, tot-aux);
			}
		printf("%d\n", msum);
	}

	return 0;
}

