#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <stack>
#include <algorithm>
#include <math.h>
#define abs(a) if(a < 0) a = -1*a;
#define M_PI           3.14159265358979323846

using namespace std;

double px,py,dmin = 10000000,dmax = 0;
pair<double,double> point[100000];

double dist(pair<double,double> a, pair<double,double> b){
	double aux1 = a.first-b.first;
	double aux2 = a.second-b.second;
	return sqrt(aux1*aux1 + aux2*aux2);
}

double Dot(pair<double,double> a, pair<double,double> b){
	return (a.first*b.first + a.second*b.second);
}

double dist_line(pair<double,double> a, pair<double,double> b){
	pair<double, double> v1,v2,v3;

	if(a.first == b.first && a.second == b.second)
		return dist(make_pair(px,py), a);
	v1 = {px-a.first, py-a.second};
	v2 = {px-b.first, py-b.second};
	v3 = {b.first-a.first, b.second-a.second};

	if(Dot(v1,v3) < 0)
		return dist(make_pair(px,py), a);
	if(Dot(v2,v3) > 0)
		return dist(make_pair(px,py), b);
	return (fabs(v1.first*v2.second - v1.second*v2.first)/dist(a,b));
}

int main() {
	string s;
	int n;

	cin >> n >> px >> py;
	
	for(int i = 0; i < n; i++)
		cin >> point[i].first >> point[i].second;
	
	for(int i = 0; i < n; i++){
		double aux = dist(make_pair(px,py), point[i]);
		dmax = max(dmax, aux);
		dmin = min(dmin, aux);
	}

	for(int i = 0; i < n; i++){
		double aux;
		if(i == n-1)
			aux = dist_line(point[i], point[0]);
		else
			aux = dist_line(point[i], point[i+1]);
		dmin = min(dmin,aux);
		dmax = max(dmax,aux);
	}

	printf("%.10lf\n", (double)M_PI*(dmax*dmax -dmin*dmin));

	return 0;
}
