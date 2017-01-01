#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double EPS = 1e-6;

bool equals(double a, double b){
	return fabs(a-b) < EPS;
}

double dist(pair<double,double> P, pair<double,double> Q){
	double aux = P.ff-Q.ff, aux2 = P.ss-Q.ss;
	return sqrt(aux*aux+aux2*aux2);
}

struct Reta{
	double a,b,c;
	pair<double,double> R,S;
	Reta(pair<double,double> P, pair<double,double> Q){
		a = P.ss-Q.ss;
		b = Q.ff-P.ff;
		c = P.ff*Q.ss-P.ss*Q.ff;
		double k = equals(a,0)?b:a;
		a /= k; b /= k; c /= k;
		R = P; S = Q;
	}

	bool contains(pair<double,double> P){
		if(R.ff == S.ff)
			return min(R.ss,S.ss) <= P.ss && P.ss <= max(R.ss,S.ss);
		return min(R.ff,S.ff) <= P.ff && P.ff <= max(R.ff,S.ff);
	}

	pair<double,double> find_closest(pair<double,double> P){
		double den = a*a+b*b;
		double x = b*(b*P.ff-a*P.ss) - a*c;
		double y = a*(-b*P.ff+a*P.ss) - b*c;
		x/=den;
		y/=den;

		if(this->contains(mp(x,y)))
			return mp(x,y);

		double dR = dist(R,P);
		double dS = dist(S,P);
		if(dR < dS) return R;
		return S;
	}
};

pair<double,double> v[100005];

int main(){
	int i,j,t,n;
	pair<double,double> m, p;

	while(scanf("%lf%lf", &m.ff, &m.ss) == 2){
		scanf("%d", &n);
		for(i = 0; i <= n; i++)
			scanf("%lf%lf", &v[i].ff, &v[i].ss);
		double ans = 1e50;
		for(i = 0; i < n; i++){
			Reta r(v[i],v[i+1]);
			pair<double,double> closest = r.find_closest(m);
			double aux = dist(closest,m);
			if(aux < ans){
				ans = aux;
				p = closest;
			}
		}
		printf("%.4lf\n%.4lf\n",p.ff,p.ss);
	}
	return 0;
}