const int N = 100000, A = 256;

vector<int> build_sa(string s) {
	int n = (int)s.size() + 1;
	vector<int> cnt(n + A, 0), p(n), pn(n), cn(n), c(n);

	for(int i = 0; i < n; i++)
		cnt[s[i]]++;

	for(int i = 1; i < A; i++)
		cnt[i] += cnt[i-1];

	for(int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;

	c[p[0]] = 0;
	int classes = 1;

	for(int i = 1; i < n; i++) {
		if(s[p[i]] != s[p[i-1]]) 
			classes++;
		c[p[i]] = classes-1;
	}

	for(int h = 0; (1<<h) < n; h++) {
		fill(cnt.begin(), cnt.begin() + classes, 0);

		for(int i = 0; i < n; i++) {
			pn[i] = p[i] - (1<<h);
			if(pn[i] < 0) pn[i] += n;
			cnt[c[pn[i]]]++;
		}

		for(int i = 1; i < classes; i++)
			cnt[i] += cnt[i-1];

		for(int i = n-1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];

		cn[p[0]] = 0;
		classes = 1;

		for (int i = 1; i < n; i++) {
			pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
			if (cur != prev)
				++classes;
			cn[p[i]] = classes - 1;
		}

		if(classes == n) break;
		c.swap(cn);
	}

	p.erase(p.begin());
	return p;
}

vector<int> build_lcp(string const s, vector<int> const& p) {
	int n = (int)s.size();
	vector<int> rank(n, 0);
	for (int i = 0; i < n; i++)
		rank[p[i]] = i;

	int k = 0;
	vector<int> lcp(n-1, 0);
	for (int i = 0; i < n; i++) {
		if (rank[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = p[rank[i] + 1];
		while (i + k < n && j + k < n && s[i+k] == s[j+k])
			k++;
		lcp[rank[i]] = k;
		if (k)
			k--;
	}
	return lcp;
}