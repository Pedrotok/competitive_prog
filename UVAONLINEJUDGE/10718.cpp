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

	int i,j;
	unsigned int n,x,l,r;

	while(scanf("%u%u%u", &n, &l, &r) == 3){
		unsigned int m = 0;
		for(i = 31; i >= 0; i--){
			if( m<l && (l&(1<<i))) m |= 1<<i;
			if( !((1<<i)&n) && (m|(1<<i)) <= r) m |= (1<<i);
		}
		printf("%u\n", m);
	}

	return 0;
}

