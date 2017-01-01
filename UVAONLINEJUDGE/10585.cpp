#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-9;

pair<double,double> point[100005];
bool used[10005];

bool equals(double a, double b){
	return fabs(a-b) < EPS;
}

int main(){
	int i,j,n,t;
	scanf("%d", &t);	
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%lf%lf", &point[i].ff, &point[i].ss);
		if(n == 1){
			printf("yes\n");
			continue;
		}
		double x = 0, y = 0;
		for(i = 0; i < n; i++){
			x += point[i].ff;
			y += point[i].ss;
		}

		x/=(double)n;
		y/=(double)n;
		bool flag = 1;
		for(i = 0; i < n; i++){
			bool achei = 0;
			pair<double,double> aux = mp(2*x - point[i].ff, 2*y-point[i].ss);
			for(j = 0; j < n; j++){
				if(equals(aux.ff, point[j].ff) && equals(aux.ss, point[j].ss)){
					achei = 1;
					break;
				}
			}
			if(!achei){
				printf("no\n");
				flag = 0;
				break;
			}
		}
		if(flag) printf("yes\n");
	}

	return 0;
}
