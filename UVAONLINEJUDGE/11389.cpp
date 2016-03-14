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

vector<int> ev, mo;

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,m,n,t,d,r;
	while(scanf("%d%d%d", &n,&d,&r) && (n!=0 || d != 0 || r!=0)){
		ev.resize(n);
		mo.resize(n);
		for(i = 0; i < n; i++)
			scanf("%d", &mo[i]);
		for(i = 0; i < n; i++)
			scanf("%d", &ev[i]);
		sort(mo.begin(), mo.end());
		sort(ev.begin(), ev.end());
		int ans = 0;
		for(i = 0, j = n-1; i < n; i++,j--){
			if(mo[i]+ev[j] <= d) continue;
			ans += (mo[i]+ev[j]-d)*r;
		}
		printf("%d\n",ans);
	}

	return 0;
}

