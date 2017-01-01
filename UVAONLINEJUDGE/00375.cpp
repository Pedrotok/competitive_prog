#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double EPS = 1e-6, PI = acos(-1);

int main(){
	int t;
	double B,H,b,h;

	scanf("%d", &t);

	while(t--){
		scanf("%lf%lf", &B,&H);
		
		b = B; h = H;
		double ans = 0;
		while(1){
			double lado = sqrt(b*b/4 + h*h);
			double raio = b*h/(2*lado + b);
			if(raio < EPS) break;
			ans += 2*PI*raio;
			
			h -= 2*raio;
			b = B*h/H;
		}
		printf("%13.6lf\n", ans);
		if(t) printf("\n");
	}

	return 0;
}