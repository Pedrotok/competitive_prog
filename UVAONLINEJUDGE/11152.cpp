#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

int main(){
	double a,b,c;

	while(scanf("%lf%lf%lf", &a,&b,&c) == 3){
		double S = (a+b+c)/2;
		double area_tri = sqrt(S*(S-a)*(S-b)*(S-c));

		double r1 = 2*area_tri/(2*S);
		double r2 = (a*b*c)/(4*area_tri);

		double area1 = PI*r1*r1;
		double area2 = area_tri - area1;
		double area3 = PI*r2*r2 - area_tri;

		printf("%.4lf %.4lf %.4lf\n", area3, area2, area1);
	}

	return 0;
}