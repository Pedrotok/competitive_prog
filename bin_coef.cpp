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
#define ff first
#define ss second

using namespace std;

typedef long long ll;

ll binomialCoeff(ll n, ll k){
	ll res = 1;
 
	if ( k > n - k )
		k = n - k;
		 
	for (ll i = 0; i < k; ++i){
		res *= (n - i);
		res /= (i + 1);
	}
		 
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int i, y, j,m,k;

	ll n;
	cin >> n;
	cout << binomialCoeff(n,5) + binomialCoeff(n,6) + binomialCoeff(n,7) << "\n";
	return 0;
}
