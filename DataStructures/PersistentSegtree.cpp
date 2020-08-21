const int N = 100000;
int v[N+5];
int st[20*N+5], lft[20*N+5], rgt[20*N+5];

class PersistentSegTree {
	int sz, NODES;
	vector<int> root;
 
	const int neutral = 0;

	int newleaf(int val) {
		int p = ++NODES;
		st[p] = val;
		lft[p] = rgt[p] = 0;
		return p;
	}

	int newparent(int l, int r) {
		int p = ++NODES;
		st[p] = 0;
		lft[p] = l;
		rgt[p] = r;
		if(l) st[p] = st[l];
		if(r) st[p] += st[r];
		return p;
	}
 
	inline int f(int a, int b) {
		return a+b;
	}

	int build(int L, int R) {
		if(L == R) return newleaf(v[L]);
		int M = (L+R)/2;
 		return newparent(build(L,M), build(M+1,R));
	}	

	int update(int node, int L, int R, int i, int val) {
		if(L == R) return newleaf(val);
		int M = (L+R)/2;
 
 		if(i <= M) return newparent(update(lft[node],L,M,i,val), rgt[node]);
 		else return newparent(lft[node], update(rgt[node],M+1,R,i,val));
	}
 
	int query(int node, int L, int R, int i, int j) {
		if(R < i or L > j) return neutral;
		if(L >= i && R <= j) return st[node];
 
		int M = (L+R)/2;
 
		int l = query(lft[node], L,M,i,j);
		int r = query(rgt[node], M+1,R,i,j);
 
		return f(l, r);
	}
 
	public:
		PersistentSegTree(int _sz) : sz(_sz) {
			NODES = 0;
		}

		void build() { root.push_back(build(0,sz-1)); }
 
		void update(int i, int val) {root.push_back(update(root.back(), 0, sz-1, i, val));}
 
		int query(int version, int i, int j) {return query(root[version], 0, sz-1, i, j);}
};