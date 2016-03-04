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

pair<int,int> st, fim, piece[15];
int n,m;
bitset<20> used;

int match(pair<int,int> a, int ind){
	if(a.ff == piece[ind].ff || a.ss == piece[ind].ff)
		return 1;
	if(a.ff == piece[ind].ss || a.ss == piece[ind].ss)
		return 2;
	return 0;
}

bool backtrack(int i, pair<int,int> p){
	if(i == n){
		if(p.ff==fim.ff || p.ff==fim.ss || p.ss==fim.ff || p.ss==fim.ss)
			return true;
		return false;
	}
	for(int j = 0; j < m; j++){
		if(used[j]) continue;
		int aux = match(p,j);
		pair<int,int> p2;
		if(aux){
			p2 = piece[j];
			if(aux == 1) p2.ff = -1;
			else p2.ss = -1;
			used[j] = 1;
			if(backtrack(i+1, p2)) return true;
			used[j] = 0;
		}
	}
	return false;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,tc=1;
	bool nfirst = false;

	while(scanf("%d", &n),n){
		scanf("%d", &m);
		scanf("%d%d", &st.ff, &st.ss);
		scanf("%d%d", &fim.ff, &fim.ss);
		for(i = 0; i < m; i++)
			scanf("%d%d", &piece[i].ff, &piece[i].ss);
		used.reset();
		st.ff = -2;
		fim.ss = -2;
		if(backtrack(0, st))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

