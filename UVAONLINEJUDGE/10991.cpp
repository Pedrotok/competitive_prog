#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);

pair<double,double> p[4];

int main(){
	int t;
	double r1,r2,r3,A,B,C;

	scanf("%d", &t);
	
	while(t--){
		scanf("%lf%lf%lf", &r1, &r2, &r3);

		A = r1+r2;
		B = r2+r3;
		C = r1+r3;

		double S = (A+B+C)/2;
		double area = sqrt(S*(S-A)*(S-B)*(S-C));

		double ang1 = acos(((B*B - A*A - C*C)/(-2*A*C)));
		double ang2 = acos(((C*C - A*A - B*B)/(-2*A*B)));
		double ang3 = acos(((A*A - B*B - C*C)/(-2*B*C)));

		printf("%.15lf\n", area - r1*r1*ang1/2 - r2*r2*ang2/2 - r3*r3*ang3/2);
	}


	return 0;
}