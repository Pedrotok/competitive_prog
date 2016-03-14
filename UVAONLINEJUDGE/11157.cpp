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

pair<char,int> v[101];
bitset<101> used;

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,t,n,d,tc=1;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &d);
		for(i = 0; i < n; i++)
			scanf(" %c-%d", &v[i].ff, &v[i].ss);
		int pos = 0;
		int ans = 0;
		used.reset();
		for(i = 0; i < n; i++){
			ans = max(ans, v[i].ss-pos);
			pos = v[i].ss;
			if(v[i].ff == 'S') used[i] = 1;
			if(i+1 < n && v[i+1].ff == 'S') i++;
		}
		ans = max(ans, d-pos);
		pos = 0;
		for(i = 0; i < n; i++){
			if(used[i]) continue;
			ans = max(ans, v[i].ss-pos);
			pos = v[i].ss;
		}
		ans = max(ans, d-pos);
		printf("Case %d: %d\n", tc++, ans);
	}

	return 0;
}

