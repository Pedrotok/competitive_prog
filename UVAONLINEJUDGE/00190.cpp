#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
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
	pair<double,double> O;

	while(scanf("%lf%lf", &p[0].ff, &p[0].ss) == 2){
		for(int i = 1; i < 3; i++)
			scanf("%lf%lf", &p[i].ff, &p[i].ss);

		double raio = 1;
		for(int i = 0; i < 3; i++)
			raio *= dist(p[i], p[(i+1)%3]);
		double area = fabs(det(p[0], p[1], p[2]))/2;

		double a2 = p[0].ff*p[0].ff + p[0].ss*p[0].ss;
		double b2 = p[1].ff*p[1].ff + p[1].ss*p[1].ss;
		double c2 = p[2].ff*p[2].ff + p[2].ss*p[2].ss;

		double D = det(p[0], p[1], p[2]);
		O.ff = det(mp(a2,p[0].ss), mp(b2,p[1].ss), mp(c2,p[2].ss))/(2*D);
		O.ss = det(mp(p[0].ff,a2), mp(p[1].ff,b2), mp(p[2].ff,c2))/(2*D);

		raio /= (4*area);
		char s1 = O.ff + EPS < 0 ? '+' : '-';
		char s2 = O.ss + EPS < 0 ? '+' : '-';

		O.ff = fabs(O.ff);
		O.ss = fabs(O.ss);

		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", s1, O.ff, s2, O.ss, raio);
		raio = O.ff*O.ff + O.ss*O.ss - raio*raio;
		char s3 = raio + EPS < 0 ? '-' : '+';
		raio = fabs(raio);
		printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n", s1, 2*O.ff, s2, 2*O.ss, s3, raio);
	}

	return 0;
}