#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

int main(){
	int t,i,j,k;
	char s[100];


	scanf("%d", &t);
	while(t--){
		scanf(" %s",s);
		
		int tam = strlen(s);
		int ans = 1;
		while(ans < tam){
			char aux[100];
			for(i = 0; i < ans; i++)
				aux[i] = s[i];
			aux[i] = '\0';
			for(i = ans; i < tam; i+=ans){
				for(j = 0, k = i; j < ans; j++, k++){
					if(aux[j] != s[k]) break;
				}
				if(j != ans) break;
			}
			if(i == tam)
				break;

			ans++;
		}
		printf("%d\n", ans);
		if(t) printf("\n");
	}

	return 0;
}