#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

int st[400005];
map<int,int> tab;
int v[100005], pre[100005], nxt[100005];

void build(int L, int R, int p){
	if(L == R){
		st[p] = v[R];
		return ;
	}

	int M = (L+R)/2;
	
	build(L,M,2*p);
	build(M+1,R,2*p+1);

	st[p] = tab[st[2*p]] > tab[st[2*p+1]] ? st[2*p] : st[2*p+1];
}

int query(int L, int R, int i, int j, int p){
	if(L > j || R < i) return -1;

	if(L >= i && R <= j){
		return st[p];
	}

	int M = (L+R)/2;
	int x = query(L,M,i,j,2*p);
	int y = query(M+1,R,i,j,2*p+1);

	if(x == -1) return y;
	if(y == -1) return x;

	return tab[x] > tab[y] ? x : y;
}

int main(){
	int n,m,l,r;

	while(scanf("%d", &n), n){
		scanf("%d", &m);

		tab.clear();

		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			tab[v[i]]++;
		}

		build(1,n,1);

		int ant = 0; pre[1] = 0;
		for(int i = 2; i <= n; i++){
			if(v[i] == v[i-1]) pre[i] = ant;
			else{
				pre[i] = i-1;
				ant = i-1;
			}
		}

		ant = n+1; nxt[n] = n+1;
		for(int i = n-1; i; i--){
			if(v[i] == v[i+1]) nxt[i] = ant;
			else{
				nxt[i] = i+1;
				ant = i+1;
			}
		}


		while(m--){
			scanf("%d%d", &l, &r);

			int best = max(min(r+1,nxt[l]) - l, r - max(pre[r],l-1));

			l = nxt[l]; r = pre[r];

			if(l > r){
				printf("%d\n", best);
				continue;
			}

			int val2 = query(1,n,l,r,1);

			printf("%d\n", (tab[val2] > best?tab[val2]:best));
 		}
	}	

	return 0;
}
