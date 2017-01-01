#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

int main(){
	int v[3];

	while(scanf("%d%d%d", &v[0],&v[1],&v[2]), v[0]+v[1]+v[2]){
		sort(v,v+3);

		if(v[0]*v[0] + v[1]*v[1] == v[2]*v[2]) printf("right\n");
		else printf("wrong\n");
	}

	return 0;
}