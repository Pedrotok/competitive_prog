#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

pair<double,double> p[3];
const double EPS = 1e-9;

double area(pair<double,double> P, pair<double,double> Q, pair<double,double> R){
	return fabs(P.ff*Q.ss + R.ff*P.ss + Q.ff*R.ss - (R.ff*Q.ss + P.ff*R.ss + Q.ff*P.ss))/2;
}

bool equals(double a, double b){
	return fabs(a-b) < EPS;
}

int main(){

	while(1){
		for(int i = 0; i < 3; i++){
			scanf("%lf %lf", &p[i].ff, &p[i].ss);
		}
		bool sai = 1;
		int minx = 1e9,miny = 1e9,maxx = 0,maxy = 0;
		for(int i = 0; i < 3; i++){
			if(p[i].ff + p[i].ss != 0) sai = 0;
			minx = min((int)ceil(p[i].ff),minx);
			miny = min((int)ceil(p[i].ss),miny);
			maxx = max((int)p[i].ff,maxx);
			maxy = max((int)p[i].ss,maxy);
		}
		if(sai) break;

		int ans = 0;
		double A = area(p[0],p[1],p[2]);
		if(minx == 0) minx++;
		if(miny == 0) miny++;
		if(maxx == 100) maxx--;
		if(maxy == 100) maxy--;
		for(int i = minx; i <= maxx; i++){
			for(int j = miny; j <= maxy; j++){
				pair<double,double> aux = {i,j};
				if(equals(A, area(p[0],p[1],aux) + area(p[0],aux,p[2]) + area(aux,p[1],p[2])))
					ans++;
			}
		}
		printf("%4d\n", ans);
	}
	
	return 0;
}