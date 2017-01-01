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
	double a, b, c;
	Reta(pair<double,double> P, pair<double,double> Q){
		a = P.ss-Q.ss;
		b = Q.ff-P.ff;
		c = P.ff*Q.ss - Q.ff*P.ss;

		double k = (equals(a,0)?b:a);
		a /= k; b /= k; c /= k;
	}
	bool is_parallel(Reta q){
		return (equals(a,q.a) && equals(b,q.b) && !equals(c,q.c));
	}
	bool is_equal(Reta q){
		return (equals(a,q.a) && equals(b,q.b) && equals(c,q.c));
	}
	pair<double,double> intersect(Reta q){
		auto det = a * q.b - b * q.a;
 
        // Concorrentes
        auto x = (-c * q.b + q.c * b) / det;
        auto y = (-q.c * a + c * q.a) / det;

        return mp(x,y);
	}
};

int main(){
	int i,j,t;
	pair<double,double> P,Q;

	printf("INTERSECTING LINES OUTPUT\n");
	scanf("%d", &t);	
	while(t--){
		scanf("%lf%lf%lf%lf",&P.ff,&P.ss,&Q.ff,&Q.ss);
		Reta r(P,Q);
		scanf("%lf%lf%lf%lf",&P.ff,&P.ss,&Q.ff,&Q.ss);
		Reta s(P,Q);
		if(r.is_parallel(s)) printf("NONE\n");
		else if(r.is_equal(s)) printf("LINE\n");
		else{
			pair<double,double> aux = r.intersect(s);
			printf("POINT %.2lf %.2lf\n", aux.ff, aux.ss);
		}
	}
	
	printf("END OF OUTPUT\n");

	return 0;
}