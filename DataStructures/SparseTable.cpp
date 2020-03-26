void build(int n) {
	for(int i = 0; i < n; i++)
		st[i][0] = v[i];

	for(int j = 1; j < LOGN; j++) {
		for(int i = 0; i + (1<<j) <= n; i++) {
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int l, int r) {
	int log = 31 - __builtin_clz(r-l+1);
	return min(st[l][log], st[r-(1<<log)+1][log]);
}