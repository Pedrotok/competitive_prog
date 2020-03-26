class MergeSortTree {
	int sz;
	vector<vector<int>> st;

	const int neutral = 0;

	inline int f(int a, int b) {
		return a+b;
	}

	void build(int L, int R, int p) {
		if(L == R) {
			st[p] = {v[L]};
			return ;
		}
		int M = (L+R)/2;
		build(L,M,2*p);
		build(M+1,R,2*p+1);
		st[p] = vector<int>(st[2*p].size() + st[2*p+1].size());
		merge(st[2*p].begin(), st[2*p].end(), st[2*p+1].begin(), st[2*p+1].end(), st[p].begin());
	}

	void update(int L, int R, int i, int val, int p) {
		if(R < i or L > i) return ;
		if(L == R) {
			st[p] = {v[L]};
			return ;
		}

		int M = (L+R)/2;

		update(L,M,i,val,2*p);
		update(M+1,R,i,val,2*p+1);

		merge(st[2*p].begin(), st[2*p].end(), st[2*p+1].begin(), st[2*p+1].end(), st[p].begin());
	}

	int query(int L, int R, int i, int j, int val, int p) {
		if(R < i or L > j) return neutral;
		if(L >= i && R <= j) {
			int lo = (int)(lower_bound(st[p].begin(), st[p].end(), val) - st[p].begin());
			int hi = (int)(upper_bound(st[p].begin(), st[p].end(), val) - st[p].begin());
			return hi-lo + (lo == val);
		}

		int M = (L+R)/2;

		int l = query(L,M,i,j,val,2*p);
		int r = query(M+1,R,i,j,val,2*p+1);

		return f(l, r);
	}

	public:
		MergeSortTree(int _sz) : sz(_sz) {
			st = vector<vector<int>>(4*sz+5);
		}

		void build() { build(0, sz-1, 1); }

		void update(int i, int val) { return update(0, sz-1, i, val, 1); }
		
		int query(int i, int j, int val) { return query(0, sz-1, i, j, val, 1); }
};