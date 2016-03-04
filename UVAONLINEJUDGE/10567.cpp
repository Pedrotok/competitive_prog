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

vector<vector<int>> lp;

int bsearch(vector<int> v, int val){
	int lo = 0, hi = v.size()-1;
	int mid;
	while(lo < hi){
		mid = (hi+lo)/2;
		if(v[mid] <= val) lo = mid+1;
		else hi = mid;
	}
	if(v[lo] <= val) return -1;
	return v[lo];
}

int main() {
	ios_base::sync_with_stdio(0);

	int i,j,len,n,ini,fim;
	string s;
	while(cin >> s){
		lp.resize(128);
		len = s.size();
		for(i = 0; i < len; i++)
			lp[s[i]-'a'].push_back(i);
		cin >> n;
		for(i = 0; i < n; i++){
			cin >> s;
			len = s.size();
			int ind = -1;
			for(j = 0; j < len; j++){
				int x = bsearch(lp[s[j]-'a'], ind);
				if(x == -1) break;
				ind = x;
				if(j == 0) ini = ind;
			}
			if(j == len) cout << "Matched " << ini << " " << ind << "\n";
			else cout << "Not matched"<<"\n";
		}

	}

	return 0;
}

