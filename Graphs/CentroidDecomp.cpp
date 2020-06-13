const int N = 1e5;

vector<int> G[N+5];
int subtree[N+5], treesize;
bool vis[N+5];
int dist[N+5], ans[N+5];
int k, n;

int dfs(int v, int p){
	subtree[v] = 1;
	for(int x : G[v])
		if(x != p && !vis[x]) subtree[v] += dfs(x,v);
	return subtree[v];
}

int centroid(int v, int p){
	for(int x : G[v]){
		if(x == p || vis[x]) continue;
		if(subtree[x]*2 > treesize) return centroid(x,v);
	}
	return v;
}

void procurar_ans(int v, int p, int d_atual, vector<int>& mydist){
	if(d_atual > k) return ;

	int cur = min(treesize, k - d_atual);
	ans[v] += dist[cur];
	cur = min<int>(cur, mydist.size()-1);
	ans[v] -= mydist[cur];

	for(int x : G[v]){
		if(!vis[x] && x != p)
			procurar_ans(x,v,d_atual+1,mydist);
	}
}

void atualiza_distancia(int v, int p, int d_atual, vector<int>& mydist){
	if(d_atual > k) return ;
	dist[d_atual]++;
	mydist[d_atual]++;

	for(int x : G[v]){
		if(!vis[x] && x != p)
			atualiza_distancia(x,v,d_atual+1,mydist);
	}
}

void decomp(int v, int p){
	treesize = dfs(v,v);
	int cent = centroid(v,v);
	vis[cent] = 1;

	for(int i = 0; i <= min(treesize, k); i++)
		dist[i] = 0;
	dist[0] = 1;

	vector<vector<int>> aux;
	for(int x : G[cent]){
		if(!vis[x]) {
			vector<int> mydist = vector<int>(min(subtree[x], k) + 5, 0);
			atualiza_distancia(x,cent,1,mydist);
			for(int i = 1; i < mydist.size(); i++)
				mydist[i] += mydist[i-1];
			aux.push_back(mydist);
		}
	}
	for(int i = 1; i <= min(treesize, k); i++)
		dist[i] += dist[i-1];

	ans[cent] += dist[min(treesize,k)]-1;

	int cnt = 0;
	for(int x : G[cent]){
		if(!vis[x])
			procurar_ans(x,cent,1,aux[cnt++]);
	}

	for(int x : G[cent]){
		if(!vis[x])
			decomp(x, cent);
	}
}