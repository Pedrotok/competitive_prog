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

int num[20];
bitset<20> used;
bitset<40> isprime;

void init(){
	isprime.reset();
	isprime[2] = isprime[3] = isprime[5] = isprime[7] = isprime[11] = isprime[13]= isprime[17] = isprime[19] = isprime[23] = isprime[29] = isprime[31] = 1;
}

bool backtrack(int pos, int n){
	if(pos == n){
		if(!isprime[num[pos-1]+num[0]]) return false;
		printf("%d", num[0]);
		for(int j =1; j < n; j++)
			printf(" %d", num[j]);
		printf("\n");

	}
	for(int j = 2; j <= n; j++){
		if(used[j]) continue;
		if(isprime[num[pos-1]+j]){
			used[j] = 1;
			num[pos] = j;
			backtrack(pos+1, n);
			used[j] = 0;
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,n,tc=1;
	bool nfirst = false;

	init();
	while(scanf("%d", &n)!=EOF){
		if(nfirst) printf("\n");
		nfirst = true;
		printf("Case %d:\n", tc++);
		memset(num,0,sizeof(num));
		used[1] = 1;
		num[0] = 1;
		used.reset();
		backtrack(1,n);
	}

	return 0;
}

