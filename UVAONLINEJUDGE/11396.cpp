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

vector<int> G[303];
char part[303];

int main() {
	int n,m,i,a,b,t;

	while(scanf("%d",&n),n){
		while(scanf("%d%d", &a,&b),a){
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		bool deu_ruim = 0;
		memset(part,-1,sizeof(part));
		queue<int> Q;
		Q.push(1<<1);
		part[1] = 0;

		while(!Q.empty() && !deu_ruim){
			a = Q.front()>>1;
			int state = Q.front()&1;
			Q.pop();
			state = 1-state;
			for(int x : G[a]){
				if(part[x] == -1){
					part[x] = state;
					Q.push((x<<1)|state);
				}
				else if(part[x] != state){
					deu_ruim = 1;
					break;
				}
			}
		}

		printf("%s\n", (deu_ruim?"NO":"YES"));
		for(i = 1; i <= n; i++) G[i].clear();
	}

	return 0;
}
