const int N = 100000, LG = 18;
vector<int> G[N+5];
int anc[N+5][LG+2], lvl[N+5];

void dfs(int v, int p, int l) {
	lvl[v] = l;

	for(int u : G[v])
		if(u != p) {
			anc[u][0] = v;
			dfs(u, v, l+1);
		}
}

int LCA(int u, int v) {
	if(lvl[u] > lvl[v]) swap(u, v);

	for(int i = LG; i >= 0; i--)
		if(lvl[v] - (1<<i) >= lvl[u])
			v = anc[v][i];

	if(u == v) return u;

	for(int i = LG; i >= 0; i--)
		if(anc[u][i] != anc[v][i]) {
			v = anc[v][i];
			u = anc[u][i];
		}

	return anc[u][0];
}

void preprocess(int n) {
	dfs(1, 1, 0);

	for(j = 1; j <= LG; j++)
		for(i = 1; i <= n; i++)
			anc[i][j] = anc[ anc[i][j-1] ][j-1];
}