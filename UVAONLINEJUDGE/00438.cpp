#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = 3.141592653589793;
const double EPS = 1e-7;

pair<double,double> p[3];

double det(pair<double,double> A, pair<double,double> B, pair<double,double> C){
	return A.ff*B.ss + A.ss*C.ff + B.ff*C.ss - (C.ff*B.ss + C.ss*A.ff + B.ff*A.ss);
}

double dist(pair<double,double> A, pair<double,double> B){
	double aux = A.ff-B.ff, aux2 = A.ss-B.ss;
	return sqrt(aux*aux + aux2*aux2);
}

int main(){
	while(scanf("%lf%lf", &p[0].ff, &p[0].ss) == 2){
		for(int i = 1; i < 3; i++)
			scanf("%lf%lf", &p[i].ff, &p[i].ss);

		double raio = 1;
		for(int i = 0; i < 3; i++)
			raio *= dist(p[i], p[(i+1)%3]);
	
		double area = fabs(det(p[0], p[1], p[2]))/2;

		raio /= (4*area);
	
		printf("%.2lf\n", 2*PI*raio);
	}

	return 0;
}