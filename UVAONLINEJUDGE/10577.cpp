#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);

pair<double,double> p[4];

double det(pair<double,double> A, pair<double,double> B, pair<double,double> C){
	return A.ff*B.ss + A.ss*C.ff + B.ff*C.ss - (C.ff*B.ss + C.ss*A.ff + B.ff*A.ss);
}

int main(){
	int n, tc = 1;

	while(scanf("%d", &n),n){

		for(int i = 0; i < 3; i++)
			scanf("%lf%lf", &p[i].ff, &p[i].ss);

		double ang = 2*PI/n;

		double D = det(p[0], p[1], p[2])*2;

		pair<double,double> O;
		double a2 = p[0].ff*p[0].ff + p[0].ss*p[0].ss;
		double b2 = p[1].ff*p[1].ff + p[1].ss*p[1].ss;
		double c2 = p[2].ff*p[2].ff + p[2].ss*p[2].ss;

		O.ff = det(mp(a2,p[0].ss), mp(b2,p[1].ss), mp(c2,p[2].ss))/D;
		O.ss = det(mp(p[0].ff,a2), mp(p[1].ff,b2), mp(p[2].ff,c2))/D;

		pair<double,double> cur = {p[0].ff - O.ff, p[0].ss - O.ss};
		double menorX = p[0].ff, menorY = p[0].ss, maiorX = p[0].ff, maiorY = p[0].ss;

		for(int i = 0; i < n-1; i++){
			pair<double,double> aux = cur;

			cur.ff = aux.ff*cos(ang) - aux.ss*sin(ang);
			cur.ss = aux.ff*sin(ang) + aux.ss*cos(ang);

			menorX = min(menorX, cur.ff + O.ff);
			maiorX = max(maiorX, cur.ff + O.ff);
			menorY = min(menorY, cur.ss + O.ss);
			maiorY = max(maiorY, cur.ss + O.ss);
		}

		printf("Polygon %d: %.3lf\n", tc++, (maiorX-menorX)*(maiorY-menorY));
	}

	return 0;
}