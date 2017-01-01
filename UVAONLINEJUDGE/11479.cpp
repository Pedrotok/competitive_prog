#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

int main(){
	unsigned int v[3];
	int t;
	char type[20];

	scanf("%d", &t);

	for(int i = 1; i <= t; i++){
		scanf("%d%d%d", &v[0],&v[1],&v[2]);

		sort(v,v+3);
		if(!(v[0] + v[1] > v[2] && v[0] + v[2] > v[1] && v[1] + v[2] > v[0])) strcpy(type,"Invalid");
		else if(v[0] == v[1] && v[1] == v[2]) strcpy(type, "Equilateral");
		else if(v[0] == v[1] || v[1] == v[2]) strcpy(type, "Isosceles");
		else strcpy(type, "Scalene");

		printf("Case %d: %s\n", i, type);
	}

	return 0;
}