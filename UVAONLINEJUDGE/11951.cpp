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

ll v[150][150];

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,money,k,tc=1,t,n,m,l;
	ll sum,msum;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &money);
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++){
				scanf("%lld", &v[i][j]);
				if(j > 0) v[i][j]+=v[i][j-1];
			}

		int a,b,a2,aux;
		a = a2 = b = 0;
		msum = 0;
		for(i = 0; i < m; i++)
			for(j = i; j < m; j++){
				sum = 0;
				l = 0;
				for(k = 0; k < n; k++){
					if(i > 0) sum += v[k][j] - v[k][i-1];
					else sum += v[k][j];
					if(sum <= money){
						int area = (k+1-l)*(j-i+1);
						if(area > (a2-a)*b || (area == (a2-a)*b && sum < msum)){
							b = j-i+1;
							a2 = k+1;
							a = l;
							msum = sum;
						}
					}
					else{k = l++; sum = 0;}
				}
			}
		printf("Case #%d: %d %lld\n", tc++, (a2-a)*b, msum);
	}

	return 0;
}

