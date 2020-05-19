const int N = 100000;
int vis[N+5], comp[N+5];
vector<int> G[N+5], GT[N+5];
vector<int> order;

void dfs1(int v) {
	vis[v] = true;
	for(int u : G[v])
		if(!vis[u])
			dfs1(u);
	order.push_back(v);
}

void dfs2(int v, int c) {
	comp[v] = c;
	for(int u : GT[v])
		if(!comp[u])
			dfs2(u, c);
}

void kosaraju(int n) {
	for(int i = 1; i <= n; i++)
		vis[i] = false;

	for(int i = 1; i <= n; i++)
		if(!vis[i])
			dfs1(i);

	int c = 1;
	for(int i = (int)order.size()-1; i >= 0; i--) {
		int v = order[i];
		if(!comp[v])
			dfs2(v, c++);
	}
}