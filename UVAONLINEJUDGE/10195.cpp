#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double EPS = 1e-6, PI = acos(-1);

int main(){
	double A,B,C;

	while(scanf("%lf%lf%lf", &A,&B,&C) == 3){
		double p = A+B+C;
		double s = p/2.0;
		double area = sqrt(s*(s-A)*(s-B)*(s-C));
		double ans = p == 0 ? 0 : 2*area/p;
		printf("The radius of the round table is: %.3lf\n", ans);
	}

	return 0;
}