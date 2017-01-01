#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
char s[1000005];

int main(){
	int i,n;

	while(scanf("%d %s", &n, s) == 2){
		string aux;
		map<string,int> tab;
		for(i = 0; s[i] && i < n; i++)
			aux += s[i];
		tab[aux] = 1;
		for(i = n; s[i]; i++){
			aux.erase(aux.begin());
			aux+=s[i];
			tab[aux]++;
		}
		int m = 0;
		string ans;
		for(auto it = tab.begin(); it != tab.end(); it++){
			if(m < it->ss){
				ans = it->ff;
				m = it->ss;
			}
		}
		printf("%s\n", ans.c_str());
	}
	

	return 0;
}