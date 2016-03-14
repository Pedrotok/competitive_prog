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

pair<double,double> v[10005];

int main() {
	ios_base::sync_with_stdio(0);

	int i,j,m,n;
	double w,l,a,b;
	
	while(cin >> n >> l >> w){
		w/=2;
		w*=w;
		for(i = 0; i < n; i++){
			cin >> a >> b;
			if(b*b-w < 0){v[i].ff = v[i].ss = l+1; continue;}
			double aux = sqrt(b*b-w);
			v[i].ff = -aux+a;
			v[i].ss = aux+a;
		}
		sort(v,v+n);
		double pos = 0;
		int ans = 0;
		i = 0;
		while(pos < l){
			double aux = -1;
			for(; i < n; i++){
				if(v[i].ff > pos) break;
				aux = max(aux,v[i].ss);
			}
			if(aux < 0) break;
			ans++;
			pos += (aux-pos);
		}
		if(pos < l) cout << "-1\n";
		else cout << ans << "\n";

	}

	return 0;
}

