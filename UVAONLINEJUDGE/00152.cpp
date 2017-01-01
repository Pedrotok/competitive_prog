#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double EPS = 1e-7;

pair<int,pair<int,int>> tree[5005];

double dist(int i, int j){
	double x = tree[i].ff - tree[j].ff;
	double y = tree[i].ss.ff - tree[j].ss.ff;
	double z = tree[i].ss.ss - tree[j].ss.ss;
	return sqrt(x*x+y*y+z*z);
}

int main(){
	int i,j,x,y,z;

	int n = 0;
	while(scanf("%d%d%d", &x,&y,&z),x+y+z){
		tree[n].ff = x; tree[n].ss.ff = y; tree[n].ss.ss = z; n++; 
	}

	int ans[10] = {0,0,0,0,0,0,0,0,0,0};
	for(i = 0; i < n; i++){
		double d = 1e50;
		for(j = 0; j < n; j++){
			if(j == i) continue;
			double aux = dist(i,j);
			d = min(d,aux);
		}
		int ind = (int)d+EPS;
		if(d+EPS < 10.0) ans[ind]++;
	}

	for(i = 0; i < 10; i++)
		printf("%4d", ans[i]);
	printf("\n");

	return 0;
}