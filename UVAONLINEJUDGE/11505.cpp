#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-6;

char cm[1005][5];
int v[1005];

int main(){
	int i,j,n,t;
	scanf("%d", &t);	
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf(" %s %d", cm[i], &v[i]);
		double x = 0, y = 0, dg = 0;
		for(i = 0; i < n; i++){
			switch(cm[i][0]){
				case 'f':
					x += v[i]*cos(dg);
					y += v[i]*sin(dg);
					break;
				case 'l':
					dg+=(2*PI*v[i])/360;
					break;
				case 'b':
					x -= v[i]*cos(dg);
					y -= v[i]*sin(dg);
					break;
				default:
					dg-=(2*PI*v[i])/360;
			}
		}
		printf("%d\n", (int)round(sqrt(x*x+y*y)));
	}

	return 0;
}