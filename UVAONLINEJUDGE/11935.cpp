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

pair<int, char> v[60];
int gas[60],tot;

bool can(double comb,int cons){
	int pastD = 0;
	int leak = 0;
	double aux = comb;
	for(int j = 0; j < tot; j++){
		aux -= (double)cons*((double)v[j].ff-pastD)/100.0 + (v[j].ff-pastD)*leak;
		if(aux < 0.0) return false;
		if(v[j].ss == 'L') leak++;
		else if(v[j].ss == 'F') cons = gas[j];
		else if(v[j].ss == 'S') aux = comb;
		else if(v[j].ss == 'M') leak = 0;
		else break;
		pastD = v[j].ff;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);

	int i,t,a,b,n,cons;
	double ans;
	string s;
	while(cin >> n >> s >> s >> cons,cons){
		i = 0;
		while(cin >> n >> s){
			v[i] = make_pair(n,s[0]);
			i++;
			if(s[0] == 'F') cin >> s >> gas[i-1];
			else if(s[1] == 'a') {cin >> s; v[i-1].ss = 'S';}
			else if(s[0] == 'G') break;
		}
		tot = i;
		double low = 0.0, high = 10000.0, mid;
		for(i = 0; i < 50; i++){
			mid = (high+low)/2.0;
			if(can(mid,cons)){ans = mid; high = mid;}
			else low = mid;
		}
		cout << setprecision(3) << fixed << ans << "\n";
	}

	return 0;
}

