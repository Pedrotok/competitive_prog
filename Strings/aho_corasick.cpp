const int N = 2000, A = 256;
int trie[N+5][A], term[N+5], fail[N+5], ptr;

void build_aho() {
	queue<int> Q;
	Q.push(0);

	while(!Q.empty()) {
		int v = Q.front(); Q.pop();

		for(int i = 0; i < A; i++) {
			if(trie[v][i]) {
				int x = trie[v][i];
				if(v) {
					fail[x] = trie[fail[v]][i];

					term[x] |= term[fail[x]];
				}
				Q.push(x);
			}
			else if(v) trie[v][i] = trie[fail[v]][i];
		}
	}
}

void insert(string s) {
	int v = 0;
	for(int j = 0; s[j]; j++) {
		if(!trie[v][s[j]]) trie[v][s[j]] = ptr++;
		v = trie[v][s[j]];
	}
	term[v] = 1;
}