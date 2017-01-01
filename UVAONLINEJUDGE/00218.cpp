#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

pair<double,double> p[1000005];

double dist(pair<double,double> a, pair<double,double> b){
	double aux = a.ff-b.ff, aux2 = a.ss-b.ss;
	return sqrt(aux*aux + aux2*aux2);
}

double D(pair<double,double> a, pair<double,double> b, pair<double,double> c){
	return a.ff*b.ss + a.ss*c.ff + b.ff*c.ss - c.ff*b.ss - c.ss*a.ff - b.ff*a.ss;
}

vector<pair<double,double> > convex_hull(int n){
	vector<pair<double,double>> L,U;

	for(int i = 0; i < n; i++){
		while(L.size() >= 2 && D(L[L.size()-2], L[L.size()-1], p[i]) < 0)
			L.pop_back();
		L.push_back(p[i]);
	}

	for(int i = n-1; i >= 0; i--){
		while(U.size() >= 2 && D(U[U.size()-2], U[U.size()-1], p[i]) < 0)
			U.pop_back();
		U.push_back(p[i]);
	}

	L.pop_back();

	L.insert(L.end(), U.begin(), U.end());

	return L; 
}

int main(){
	int n, tc = 1;

	while(scanf("%d", &n),n){

		for(int i = 0; i < n; i++){
			scanf("%lf%lf", &p[i].ff, &p[i].ss);
		}

		sort(p, p+n);

		vector<pair<double,double>> points = convex_hull(n);

		double ans = 0;
		
		for(int i = 0; i < points.size()-1; i++){
			ans += dist(points[i], points[i+1]);
		}

		if(tc > 1) printf("\n");
		printf("Region #%d:\n", tc++);
		printf("(%.1lf,%.1lf)",points[points.size()-1].ff, points[points.size()-1].ss);

		for(int i = points.size()-2; i >= 0; i--)
			printf("-(%.1lf,%.1lf)",points[i].ff, points[i].ss);

		printf("\nPerimeter length = %.2lf\n", ans);
	}

	return 0;
}

