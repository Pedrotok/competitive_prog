#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

double det(pair<double,double> A, pair<double,double> B, pair<double,double> C){
	return A.ff*B.ss + A.ss*C.ff + B.ff*C.ss - (C.ff*B.ss + C.ss*A.ff + B.ff*A.ss);
}

double dist(pair<double,double> A, pair<double,double> B){
	double aux = A.ff-B.ff, aux2 = A.ss-B.ss;
	return sqrt(aux*aux + aux2*aux2);
}

int main(){
	char s[5];
	int r;
	int dg;

	while(scanf("%d %d %s", &r, &dg, s) == 3){
		double ang;
		if(s[0] == 'm'){
			dg %= 2160;
			dg = min(dg,2160-dg);
			ang = dg/60.0*2*PI/360; 
		}
		else{
			dg %= 360;
			dg = min(dg,360-dg);
			ang = dg*2*PI/360;
		}
		r += 6440;



		double arc = r*ang;
		double chord = 2*sin(ang/2)*r;
		printf("%.6lf %.6lf\n", arc, chord);
	}

	return 0;
}