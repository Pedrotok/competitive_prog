#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

int main(){
	int n;
	double l;

	while(scanf("%lf", &l) == 1){
		double h = sin(PI/3)*l;
		double setor = l*l*PI/3 - 2*(l/4 * h);
		double algo = l*l*(1 - PI/4);

		double area3 = 2*algo + setor - l*l;
		double area2 = algo - 2*area3;
		double area1 = l*l - 4*area2 - 4*area3;
		printf("%.3lf %.3lf %.3lf\n", area1, 4*area2, 4*area3);
	}

	return 0;
}
