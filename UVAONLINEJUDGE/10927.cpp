#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-9;

struct Point{
	int x,y,z;
	pair<int,int> norma;
	bool operator<(const Point &r) const{
		if(norma != r.norma)
			return norma < r.norma;
		if(x != r.x)
			return abs(x) < abs(r.x);
		return abs(y) < abs(r.y);
	}
};

Point v[100005];

bool equals(double a, double b){
	return fabs(a-b) < EPS;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	int i,j,n,tc = 1;
	while(scanf("%d", &n),n){
		map<pair<int,int>, vector<Point>> tab;
		for(i = 0; i < n; i++){
			scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].z);
			int g = 1;
			if(!v[i].x) g = abs(v[i].y);
			else if(!v[i].y) g = abs(v[i].x);
			else g = gcd(abs(v[i].x), abs(v[i].y));
			v[i].norma = mp(v[i].x/g, v[i].y/g);
		}
		
		sort(v, v+n);

		vector<pair<int,int> > ans;
		int height = v[0].z;
		for(i = 1; i < n; i++){
			if(v[i].norma == v[i-1].norma){
				if(v[i].z <= height)
					ans.push_back(mp(v[i].x,v[i].y));
				else
					height = v[i].z;
			}
			else{
				height = v[i].z;
			}
		}
		printf("Data set %d:\n", tc++);
		if(ans.empty()){
			printf("All the lights are visible.\n");
			continue;
		}
		sort(ans.begin(), ans.end());
		printf("Some lights are not visible:\n");
		for(i = 0; i < ans.size(); i++){
			printf("x = %d, y = %d", ans[i].ff, ans[i].ss);
			if(i+1 == ans.size()) printf(".\n");
			else printf(";\n");
		}
	}

	return 0;
}