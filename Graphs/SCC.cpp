const int N = 100000;
int vis[N+5], low[N+5], num[N+5], t, comp;
stack<int> S;
vector<int> G[N+5];

void dfs(int v) {
	vis[v] = 1;
	num[v] = low[v] = t++;
	S.push(v);

	for(int u : G[v]) {
		if(!num[u]) dfs(u);
		if(vis[u]) low[v] = min(low[v], low[u]);
	}

	if(num[v] == low[v]) {
		while(true) {
			int u = S.top(); S.pop();
			vis[u] = 0;
			if(v == u) break;
		}
		comp++;
	}
}