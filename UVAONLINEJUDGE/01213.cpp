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

ll DP[1125][15];
vector<int> prime;

void sieve(){
	bool is_prime[1125];
	memset(is_prime,1,sizeof(is_prime));
	is_prime[0] = is_prime[1] = 0;
	for(int p = 2; p*p <= 1120; p++){
		if(is_prime[p]){
			for(int i = p*2; i <= 1120; i+=p)
				is_prime[i] = false;
		}
	}
	prime.push_back(2);
	for(int p = 2; p <= 1120; p++)
		if(is_prime[p]) prime.push_back(p);
}

void construct(){
	DP[0][0] = 1;
	for(int i = 1; i < prime.size(); i++){
		for(int j = 1120; j >= 0; j--){
			for(int k = 1; k <= 14; k++){
				if(j >= prime[i]){
					DP[j][k] += DP[j-prime[i]][k-1];
				}
			}
		}
	}
}

int main() {
	int i,j;
	int n,m,t,k,l;
	
	sieve();
	memset(DP,0,sizeof(DP));
	construct();
	while(scanf("%d %d", &n, &k) && (n != 0 || k != 0)){
		printf("%lld\n", DP[n][k]);
	}
	
	return 0;
}

