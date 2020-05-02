const int A = 26;

struct SuffixAutomaton{
	vector<int> link, len, fin;
	vector<vector<int>> nxt;
	vector<ll> cnt, occ;
	int last, sz;
 
	SuffixAutomaton(string s) {
		int n = (int)s.size()*2;
		link = vector<int>(n + 5, 0);
		len = vector<int>(n + 5, 0);
		fin = vector<int>(n + 5, 0);
		cnt = vector<ll>(n + 5, 0);
		occ = vector<ll>(n + 5, 0);
		nxt = vector<vector<int>>(n+5, vector<int>(A, 0));
		last = 0;
		link[0] = -1;
		sz = 1;
		build_sa(s);
	}

	void countOcurrences() {
		vector<int> aux;
		for(int i = 1; i < sz; i++)
			aux.emplace_back(i);
		
		sort(aux.begin(), aux.end(), [](const int& a, const int&b) {
			return len[a] < len[b];
		});

		for(auto& i: aux)
			occ[link[i]] += occ[i];
	}

	void countSubstrings() {
		for(int i = 1; i < sz; i++)
			cnt[i] = len[i] - len[link[i]];
	}
 
	void build_sa(string& s) {
		for(int i = 0; s[i]; i++) {
			int cur = sz++;
			len[cur] = len[last] + 1;
 
			int p = last;
			while(p != -1 and !nxt[p][s[i]-'a']) {
				nxt[p][s[i]-'a'] = cur;
				p = link[p];
			}
 
			if(p != -1) {
				int q = nxt[p][s[i]-'a'];
				if(len[q] == len[p] + 1) {
					link[cur] = q;
				}
				else {
					int clone = sz++;
					len[clone] = len[p] + 1;
					for(int j = 0; j < A; j++)
						nxt[clone][j] = nxt[q][j];
					link[clone] = link[q];
					link[q] = link[cur] = clone;
					
					while(p != -1 and nxt[p][s[i]-'a'] == q) {
						nxt[p][s[i]-'a'] = clone;
						p = link[p];
					}
				}
			}
			else link[cur] = 0;
 
			last = cur;
		}
 
		while(last != -1) {
			fin[last] = true;
			last = link[last];
		}
	}
};