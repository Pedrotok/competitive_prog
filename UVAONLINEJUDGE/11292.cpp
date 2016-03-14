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

int head[20001], knight[20001];

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j,m,n;
	
	while(scanf("%d%d", &n, &m) && (n!=0 || m!=0)){
		for(i = 0; i < n; i++)
			scanf("%d", &head[i]);
		for(i = 0; i < m; i++)
			scanf("%d", &knight[i]);
		if(m < n){printf("Loowater is doomed!\n"); continue;}

		sort(knight, knight + m);
		sort(head, head + n);
		int ans = 0;
		i = j = 0;
		while(i < n && j < m){
			while(head[i] > knight[j] && j < m) j++;
			if(j == m) break;
			ans += knight[j];
			i++;
			j++;
		}
		if(i == n) printf("%d\n", ans);
		else printf("Loowater is doomed!\n");

	}

	return 0;
}

