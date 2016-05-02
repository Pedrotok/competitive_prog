#include<bits/stdc++.h>

using namespace std;

char G[103][103];
int n,m,mat[103][103], components[103];
int dr[8] = {1,1,0,-1,-1,-1,0,1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};

int fill (int i, int j){
	mat[i][j] = 1;
	int tam = 0;
	for(int k = 0; k < 8; k++){
		int x = i+dr[k];
		int y = j+dc[k];
		if(x < 0 || x >= n || y < 0 || y >= m || G[x][y]!='W' || mat[x][y]!=0) continue;
		tam+= fill(i+dr[k], j+dc[k]); 
	}
	return tam+1;
}

int main() {
	int i,j,t,a,b,tc;
	char c;
	string s,token;

	n = m = 0;
	scanf("%d\n", &tc);
	for(t = 0; t < tc; t++){
		if(t != 0) cout << "\n";
		i = 0;
		j = 0;
		n = m = 0;
		bool flag = false;
		while(getline(cin,s)){
			if(s == "" || (s[0] != 'L' && s[0] != 'R' && s[0] < '0' && s[0] > '9')) break;
			if(s[0] == 'L' || s[0] == 'W'){
				for(j = 0; j < s.size(); j++)
					G[i][j] = s[j];
				i++;
			}
			else{	
				if(!flag){
					flag = true;
					n = i;
					m = j;
				}
				a = stoi(strtok((char*)s.c_str(), " \t\n"));
				b = stoi(strtok(NULL, " \t\n"));
				memset(mat,0,sizeof(mat));
				int tam = fill(a-1,b-1);
				
				cout << tam << "\n";
			}
		}
	}
	return 0;
}
