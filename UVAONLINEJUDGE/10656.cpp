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

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,n,x;

	while(scanf("%d", &n),n){
		bool nfirst = false;
		for(i = 0; i < n; i++){
			scanf("%d", &x);
			if(x == 0) continue;
			if(nfirst) printf(" ");
			printf("%d", x);
			nfirst = true;
		}
		if(!nfirst) printf("0");
		printf("\n");
	}

	return 0;
}

