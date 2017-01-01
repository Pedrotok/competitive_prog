#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-11;

bool equals(double a, double b){
	return fabs(a-b) < EPS;
}

struct Reta{
	double a,b,c;
	bool degenerated;
	Reta(int a1, int b1, int c1){
		a = a1; b = b1; c = -c1;
		if(!a && !b){
			degenerated = 1;
		}
		else{
			double k = a1?a:b;
			a/=k; b/=k; c/=k;
			degenerated = 0;
		}
	}

	bool is_parallel(Reta q){
		if(degenerated || q.degenerated) return true;
		return equals(a,q.a) && equals(b,q.b);
	}

	pair<double,double> intersect(Reta q){
		double det = a*q.b - b*q.a;

		double x = (-c*q.b + b*q.c)/(double)det;
		double y = (-q.c*a + c*q.a)/(double)det;
		if(equals(x,0)) x = 0;
		if(equals(y,0)) y = 0;
		return mp(x,y);
	}
};

int main(){
	int a,b,c,a2,b2,c2;
	while(scanf("%d%d%d%d%d%d", &a,&b,&c,&a2,&b2,&c2),a+b+c+a2+b2+c2){
		Reta r(a,b,c), s(a2,b2,c2);
		if(r.is_parallel(s)){
			printf("No fixed point exists.\n");
			continue;
		}
		pair<double,double> point = r.intersect(s);
		printf("The fixed point is at %.2lf %.2lf.\n", point.ff, point.ss);
	}

	return 0;
}