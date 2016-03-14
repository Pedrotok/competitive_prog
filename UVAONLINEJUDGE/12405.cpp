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

	int i,j,m,n,t,d,r,tc=1;
	char s[110];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s", s);
		int ans = 0;
		i = 0;
		while(i < n){
			if(s[i] == '#'){i++; continue;}
			ans++;
			i+=3;
		}
		printf("Case %d: %d\n",tc++,ans);
	}

	return 0;
}

