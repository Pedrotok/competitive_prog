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

const double EulerConst = exp(1.0);
int p,q,r,s,t,u;

double equation(double x){
	return p*pow(EulerConst,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
	//ios_base::sync_with_stdio(0);

	int i,j;
	int ans;

	while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u)==6){
		double hi = 1.0;
		double lo = 0.0;
		double mid,res;
		for(i = 0; i < 50; i++){
			mid = (hi+lo)/2;
			res = equation(mid);
			if(fabs(res - 0) <  0.000001) break;
			if(res > 0) hi = mid;
			else lo = mid;
		}
		if(fabs(res-0) < 0.000001){
			printf("%.04lf\n", mid);
			continue;
		}
		hi = 1.0; lo = 0.0;
		for(i = 0; i < 50; i++){
			mid = (hi+lo)/2;
			res = equation(mid);
			if(fabs(res - 0) <  0.000001) break;
			if(res > 0) lo = mid;
			else hi = mid;
		}
		if(fabs(res-0) < 0.000001) printf("%.04lf\n", mid);
		else printf("No solution\n");
	}

	return 0;
}

