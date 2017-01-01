#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
int vec[10][100];

int main(){
	int i,n,m,j;
	char s[100], ans[100];

	scanf("%d", &n);
	while(n--){
		int line = 0, col;
		for(i = 0; i < 10; i++){
			scanf("%s", s);
			if(i == 0 || i == 9) continue;
			m = strlen(s);
			col = 0;
			for(j = 0; j < m; j++){
				if(j == 0 || j == m-1) continue;
				vec[line][col++] = (s[j] == '\\');
			}
			line++;
		}
		for(i = 0; i < col; i++)
			ans[i] = 0;
		int aux = 0;
		for(i = line-1; i >= 0; i--, aux++){
			for(j = 0; j < col; j++)
				ans[j] += (vec[i][j]<<i);
		}
		ans[col] = '\0';
		printf("%s\n", ans);
	}

	return 0;
}