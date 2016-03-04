#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <iomanip>
#include <bitset>
#define M_PI 3.14159265358979323846
#define ff first
#define ss second

using namespace std;

typedef long long ll;

string seq[15];
string mat[10];
int n;
bitset<8> burned;

void init(){
	mat[0] = "YYYYYYN";
	mat[1] = "NYYNNNN";
	mat[2] = "YYNYYNY";
	mat[3] = "YYYYNNY";
	mat[4] = "NYYNNYY";
	mat[5] = "YNYYNYY";
	mat[6] = "YNYYYYY";
	mat[7] = "YYYNNNN";
	mat[8] = "YYYYYYY";
	mat[9] = "YYYYNYY";
}

bool backtrack(int i, int num){
	if(i == n){
		return true;
	}
	if(num==-1) return false;
	for(int j = 0; j < 7; j++)
		if(seq[i][j] == 'Y' && burned[j]) return false;
	string s = seq[i];
	bitset<8> aux = burned;
	bool flag = true;
	for(int j = 0; j < 7; j++){
		if(s[j] == 'Y' && mat[num][j] == 'N'){
			flag = false;
			break;
		}
		if(s[j] == 'N' && mat[num][j] == 'Y')
			burned[j] = 1;
	}
	if(flag)
		if(backtrack(i+1, num-1)) return true;
	burned = aux;
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);

	int i,t,a,b;
	init();
	while(cin >> n,n){
		for(i = 0; i < n; i++)
			cin >> seq[i];
		string s = seq[0];
		bool match = false;
		for(int k = 0; k < 10; k++){
			burned.reset();
			bool flag = true;
			for(int j = 0; j < 7; j++){
				if(s[j] == 'Y' && mat[k][j] == 'N'){
					flag = false;
					break;
				}
				if(s[j] == 'N' && mat[k][j] == 'Y')
					burned[j] = 1;
			}
			if(flag){
				if(backtrack(1, k-1)){
					match = true;
					break;
				}
			}
		}
		if(match) 
			cout << "MATCH\n";
		else
			cout << "MISMATCH\n";
		
	}

	return 0;
}

