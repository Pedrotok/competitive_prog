#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#define ff first
#define ss second
#define M_PI 3.14159265358979323846

using namespace std;

typedef long long ll;

vector<pair<double,double>> v;

double dist(pair<double,double> a, pair<double,double> b){
	double aux = a.ff-b.ff; aux*= aux;
	double aux2 = a.ss-b.ss; aux2*=aux2;
	return sqrt(aux+aux2);
}

double Dot(pair<double,double> a, pair<double,double> b){
	return a.ff*b.ff+a.ss*b.ss;
}

double cross(pair<double,double> a, pair<double,double> b){
	return a.ff*b.ss-a.ss*b.ff;
}

double dist_line(pair<double,double> p, pair<double,double> a, pair<double,double> b){
	pair<double,double> u,v,w,z;
	u = {b.ff-a.ff,b.ss-a.ss}; //AB
	v = {p.ff-a.ff,p.ss-a.ss}; //AP
	w = {p.ff-b.ff,p.ss-b.ss}; //BP
	z = {a.ff-b.ff,a.ss-b.ss}; //BA

	if(Dot(u,w) > 0)
		return dist(p,b);
	if(Dot(z,v) > 0)
		return dist(p,a);
	return fabs(cross(u,v))/dist(a,b);
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int n,i;
	double maxD = 0,minD = 1e9;
	pair<double,double> aux,p;

	cin >> n >> p.ff >> p.ss;
	for(i = 0; i < n; i++){
		cin >> aux.ff >> aux.ss;
		v.emplace_back(aux);
	}

	for(int i = 0; i < n; i++){
		double d = dist(p, v[i]);
		maxD = max(maxD, d);
		minD = min(minD, d);
	}
	for(i = 0; i < n; i++){
		double d = dist_line(p,v[i],v[(i+1)%n]);
		maxD = max(maxD,d);
		minD = min(minD,d);
	}

	cout.precision(10);
	cout << fixed << (maxD*maxD-minD*minD)*M_PI << "\n";
	return 0;
}
