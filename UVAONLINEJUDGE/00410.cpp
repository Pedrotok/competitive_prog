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

int v[10];

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,m,n,tc = 1;
	double am, imb;
	
	while(scanf("%d%d", &n, &m)==2){
		am = imb = 0;
		memset(v,0,sizeof(v));
		for(i = 0; i < m; i++){
			scanf("%d", &v[i]);
			am+=v[i];
		}
		sort(v, v+2*n);
		am/=n;
		printf("Set #%d\n", tc++);
		int s = 0;
		for(i = 0, j = 2*n-1; i < n; i++,j--){
			printf(" %d:", s++);
			if(v[i] != 0) printf(" %d", v[i]);
			if(v[j] != 0) printf(" %d", v[j]);
			printf("\n");
			imb += fabs(am-v[i]-v[j]);
		}
		printf("IMBALANCE = %.5lf\n", imb);
		printf("\n");
	}

	return 0;
}

