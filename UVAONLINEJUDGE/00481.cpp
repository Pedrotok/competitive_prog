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

int v[100000];
int L[100000], P[100000], L_id[100000];

void reconstruct(int i){
	if(P[i] == -1){
		printf("%d\n", v[i]);
		return ;
	}
	reconstruct(P[i]);
	printf("%d\n", v[i]);
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,k,t,n,lis = 0;

	n = 0;
	while(scanf("%d", &v[n++])==1);
	n--;
	
	for(i = 0; i < n; i++){
		int pos = lower_bound(L, L+lis, v[i]) - L;
		L[pos] = v[i];
		L_id[pos] = i;
		P[i] = pos?L_id[pos-1]:-1;
		if(pos+1 > lis)
			lis = pos+1;
	}
	printf("%d\n-\n", lis);
	reconstruct(L_id[lis-1]);

	return 0;
}

