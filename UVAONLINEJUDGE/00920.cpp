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

struct Reta{
	double a,b,c;
	Reta(pair<double,double> P, pair<double,double> Q){
		a = P.ss-Q.ss;
		b = Q.ff-P.ff;
		c = P.ff*Q.ss-Q.ff*P.ss;
	}
	pair<double,double> find_point(double y){
		return mp((-c-b*y)/a,y);
	}
};

pair<double,double> v[105];

double dist(pair<double,double> i, pair<double,double> j){
	double aux = i.ff-j.ff, aux2 = i.ss-j.ss;
	return sqrt(aux*aux + aux2*aux2);
}

int main(){
	int i,j,t,n;
	pair<double,double> P,Q;

	scanf("%d", &t);	
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%lf%lf", &v[i].ff, &v[i].ss);
		sort(v,v+n);
		double ans = dist(v[n-1],v[n-2]);
		double pico = v[n-2].ss;
		for(i = n-3; i >= 0; i--){
			if(v[i].ss <= pico) continue;
			Reta r(v[i],v[i+1]);
			pair<double,double> point = r.find_point((double)pico);
			ans += dist(point,v[i]);
			pico = v[i].ss;
		}
		printf("%.2lf\n", ans);
	}

	return 0;
}