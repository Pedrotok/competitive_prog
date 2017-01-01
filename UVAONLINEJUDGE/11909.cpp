#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

int main(){
	int l,w,h,dg;

	while(scanf("%d%d%d%d", &l, &w, &h, &dg) == 4){
		double vol_caixa = (double)w*h*l;
		double ang = PI*dg*2/360;
		double height = tan(ang)*l;
		if(height <= h){
			printf("%.3lf mL\n", vol_caixa -(double)l*height*w/2);
		}
		else{
			dg = 180 - dg + 90;
			ang = PI*dg*2/360;

			height = tan(ang)*h;
			printf("%.3lf mL\n", (double)height*h*w/2);
		}

	}

	return 0;
}