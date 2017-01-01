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
	char s[15], ans[10005];
	int line = 0;

	scanf(" %[^\n]s", s);
	while(scanf(" %[^\n]s", s), s[0] != '_'){
		char ch = 0;
		int ind = 7;
		for(i = 1; i < 10; i++){
			if(s[i] == '.') continue;
			if(s[i] == 'o')
				ch |= (1<<(ind));
			ind--;
		}
		ans[line++] = ch;
	}
	ans[line] = '\0';
	printf("%s", ans);

	return 0;
}