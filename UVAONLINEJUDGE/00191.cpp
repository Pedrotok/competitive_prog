#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double EPS = 1e-6;

struct Segment{
	ll px,py,qx,qy;
	Segment(ll a, ll b, ll c, ll d){
		px = a; py = b; qx = c; qy = d;
	}
	Segment(){}
	ll det(ll ax, ll ay, ll bx, ll by, ll x, ll y){
		 return (ax * by + ay * x + bx * y) - (x * by + y * ax + bx * ay);
	}
	bool contains(ll x, ll y){
		if(px == qx)
			return y >= min(py,qy) && y <= max(py,qy);
		return x >= min(px,qx) && x <= max(px,qx);
	}
	bool intersect(ll x1, ll y1, ll x2, ll y2){
		ll d1 = det(px,py,qx,qy,x1,y1);
		ll d2 = det(px,py,qx,qy,x2,y2);

		if(d1 == 0 && contains(x1,y1)) return true;
		if(d2 == 0 && contains(x2,y2)) return true;
		
		ll d3 = det(x1,y1,x2,y2,px,py);
		ll d4 = det(x1,y1,x2,y2,qx,qy);

		if(d3 == 0 && contains(x1,y1)) return true;
		if(d4 == 0 && contains(x2,y2)) return true;

		return (d1*d2 < 0) && (d3*d4 < 0);
	}
};

ll x[4], y[4];

int main(){
	int i,j,t;
	ll Px,Py,Qx,Qy,a,b,c,d;

	scanf("%d", &t);	
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&Px,&Py,&Qx,&Qy,&a,&b,&c,&d);
		x[0] = x[3] = min(a,c);
		x[1] = x[2] = max(a,c);
		y[0] = y[1] = max(b,d); 
		y[2] = y[3] = min(b,d); 
		Segment seg(Px,Py,Qx,Qy);

		bool flag = 0;
		for(i = 0; i < 4; i++){
			j = (i == 3)?0:i+1;
			if(seg.intersect(x[i],y[i],x[j],y[j])) flag = 1;
		}
		if(seg.px >= x[0] && seg.px <= x[2] && seg.py >= y[2] && seg.py<= y[0])
			flag = 1;
		if(seg.qx >= x[0] && seg.qx <= x[2] && seg.qy >= y[2] && seg.qy<= y[0])
			flag = 1;
		printf("%c\n", (flag?'T':'F'));

	}

	return 0;
}
