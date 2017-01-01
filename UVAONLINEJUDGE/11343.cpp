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

struct Segment{
	pair<int,int> P,Q;

	Segment(int a, int b, int c, int d){
		P = mp(a,b); Q = mp(c,d);
	}

	Segment(){}

	bool contains(pair<int,int> point){
		if(P.ff == Q.ff)
			return min(P.ss, Q.ss) <= point.ss && point.ss <= max(P.ss, Q.ss);
		return min(P.ff, Q.ff) <= point.ff && point.ff <= max(P.ff, Q.ff);
	}

	int D(pair<int,int> a, pair<int,int> b, pair<int,int> c){
		return (a.ff * b.ss + a.ss * c.ff + b.ff * c.ss) - (c.ff * b.ss + c.ss * a.ff + b.ff * a.ss);
	}

	bool intersect(Segment s){
		int det1 = D(P,Q,s.P);
		int det2 = D(P,Q,s.Q);

		if(!det1 && this->contains(s.P)) return true;
		if(!det2 && this->contains(s.Q)) return true;

		int det3 = D(s.P, s.Q, P);
		int det4 = D(s.P, s.Q, Q);

		if(!det3 && s.contains(P)) return true;
		if(!det4 && s.contains(Q)) return true;

		return ((ll)det1*det2 < 0) && ((ll)det3*det4 < 0);
	}
};

Segment v[105];

int main(){
	int i,j,t,n,a,b,c,d;

	scanf("%d",&t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d%d%d%d", &a,&b,&c,&d);
			v[i] = Segment(a,b,c,d);
		}
		int ans = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(i == j) continue;
				if(v[i].intersect(v[j])) break;
			}
			if(j == n) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}