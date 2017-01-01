#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

double hole[105];

int main(){
	int n,m;
	double a,b,c;

	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
		scanf("%lf", &hole[i]);

	scanf("%d", &m);

	for(int i = 0; i < m; i++){
		scanf("%lf%lf%lf", &a,&b,&c);
		
		double S = (a+b+c)/2.0;
		double area = sqrt(S*(S-a)*(S-b)*(S-c));
		double diameter = a*b*c/(2.0*area);

		double ang1 = acos(((b*b - a*a - c*c)/(-2*a*c)));
		double ang2 = acos(((c*c - a*a - b*b)/(-2*a*b)));
		double ang3 = acos(((a*a - b*b - c*c)/(-2*b*c)));

		bool is_obtuse = 0;
		if(ang1 > PI/2 || ang2 > PI/2 || ang3 > PI/2) is_obtuse = 1;

		if(is_obtuse) diameter = max(a,max(b,c));
		vector<int> ans;
		
		for(int j = 0; j < n; j++){
			if(hole[j] + EPS >= diameter) ans.push_back(j+1);
		}

		if(ans.empty()){
			printf("Peg %c will not fit into any holes\n", i+'A');
		}
		else{
			printf("Peg %c will fit into hole(s): %d", i+'A', ans[0]);
			for(int j = 1; j < ans.size(); j++)
				printf(" %d", ans[j]);
			printf("\n");
		}
	}


	return 0;
}