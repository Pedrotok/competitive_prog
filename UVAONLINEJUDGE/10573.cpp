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

inline double area(double r){return PI*r*r;}

int main(){
	int t, v[3];
	string s;

	cin >> t;
	getline(cin,s);
	while(t--){
		getline(cin,s);
		stringstream x(s);

		int i = 0;
		while(x >> v[i]) i++;

		if(i == 2){
			int raio = v[0]+v[1];
			printf("%.4lf\n", area(raio) - area(v[0]) - area(v[1]));
			continue;
		}

		double r1 = (double)v[0]/2.0;
		double r2 = r1/2.0;
		printf("%.4lf\n", area(r1) - area(r2) - area(r2));
	}

	return 0;
}