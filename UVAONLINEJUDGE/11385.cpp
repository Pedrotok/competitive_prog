#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
map<int,int> tab;
int v[105];

int main(){
	int i,n,m,j,t;
	char ans[105], s[105];

	tab[1] = 1; tab[2] = 2;
	ll a = 3, b = 2;
	for(i = 3; a < ((ll)1<<31); i++){
		tab[a] = i;
		ll aux = a; a = a+b; b = aux;
	}

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		int fim = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &v[i]);
			fim = max(fim,tab[v[i]]);
		}
		scanf(" %[^\n]s", s);
		for(i = 0; i < 100; i++) ans[i] = ' ';
		for(i = 0, j = 0; s[i] && j < n; i++){
			if(s[i] < 'A' || s[i] > 'Z') continue;
			ans[tab[v[j]]-1] = s[i];
			j++;
		}
		ans[fim] = '\0';
		printf("%s\n", ans);
	}
	

	return 0;
}