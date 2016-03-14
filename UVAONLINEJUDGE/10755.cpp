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

ll cube[21][21][21];
ll sumA[21][21][21];

int main() {
	ios_base::sync_with_stdio(0);

	int i,j,k,n,a,b,c,t,l,m;
	ll msum, sum, subRect;

	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		for(i = 0; i < a; i++)
			for(j = 0; j < b; j++)
				for(k = 0; k < c; k++)
					cin >> cube[i][j][k];
		msum = -1e14;
		for(i = 0; i < a; i++)
			for(j = 0; j < b; j++)
				for(k = 0; k < c; k++){
					sumA[i][j][k] = cube[i][j][k];
					if(k > 0) sumA[i][j][k]+=sumA[i][j][k-1];
					if(j > 0) sumA[i][j][k]+=sumA[i][j-1][k];
					if(k > 0 && j > 0) sumA[i][j][k]-=sumA[i][j-1][k-1];
				}
		
		for(j = 0; j < b; j++)
			for(k = 0; k < c; k++)
				for(l = j; l < b; l++)
					for(m = k; m < c; m++){
						sum = 0;
						for(i = 0; i < a; i++){
							subRect = sumA[i][l][m];
							if(j > 0) subRect -= sumA[i][j-1][m];
							if(k > 0) subRect -= sumA[i][l][k-1];
							if(j > 0 && k > 0) subRect += sumA[i][j-1][k-1];
							sum+=subRect;
							msum = max(sum,msum);
							if(sum < 0) sum = 0;
						}
					}
		for(j = 0; j < b; j++)
			for(i = 0; i < a; i++)
				for(k = 0; k < c; k++){
					sumA[i][j][k] = cube[i][j][k];
					if(k > 0) sumA[i][j][k]+=sumA[i][j][k-1];
					if(i > 0) sumA[i][j][k]+=sumA[i-1][j][k];
					if(k > 0 && i > 0) sumA[i][j][k]-=sumA[i-1][j][k-1];
				}
		
		for(i = 0; i < a; i++)
			for(k = 0; k < c; k++)
				for(l = i; l < a; l++)
					for(m = k; m < c; m++){
						sum = 0;
						for(j = 0; j < b; j++){
							subRect = sumA[l][j][m];
							if(i > 0) subRect -= sumA[i-1][j][m];
							if(k > 0) subRect -= sumA[l][j][k-1];
							if(i > 0 && k > 0) subRect += sumA[i-1][j][k-1];
							sum+=subRect;
							msum = max(sum,msum);
							if(sum < 0) sum = 0;
						}
					}
		cout << msum << "\n";
		if(t > 0) cout << "\n";

	}

	return 0;
}

