#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double EPS = 1e-7;

double row[8] = {0,sqrt(2)/2,1,sqrt(2)/2,0,-sqrt(2)/2,-1,-sqrt(2)/2};
double col[8] = {1,sqrt(2)/2,0,-sqrt(2)/2,-1,-sqrt(2)/2,0,sqrt(2)/2}; 

inline double dist(double x, double y){
	return sqrt(x*x+y*y);
}

int main(){
	int i,j,tc=1;
	double x,y;
	char s[1000];
	map<string,int> tab;
	tab["E"] = 0;
	tab["NE"] = 1;
	tab["N"] = 2;
	tab["NW"] = 3;
	tab["W"] = 4;
	tab["SW"] = 5;
	tab["S"] = 6;
	tab["SE"] = 7;
	while(scanf("%s\n",s) == 1){
		x = y = 0.0;
		if(s[0] == 'E') break;
		i = 0;
		do{
			char aux[50];
			j = 0;
			while(s[i] <= '9') aux[j++] = s[i++];
			aux[j] = '\0';
			int num = atoi(aux);
			j = 0;
			while(s[i] != ',' &&  s[i] != '.') aux[j++] = s[i++];
			aux[j] = '\0';
			x += (num*col[tab[aux]]);
			y += (num*row[tab[aux]]);
		}while(s[i++] == ',');

		printf("Map #%d\n", tc++);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n\n",dist(x,y));
	}

	return 0;
}