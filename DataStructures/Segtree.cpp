template<typename T>
class Segtree {
	int sz;
	vector<T> st;
	vector<T> lazy;
 
	const T neutral = 0;
 
	inline T f(T a, T b) {
		return a+b;
	}
 
	void propagate(bool isLeaf, int p) {
		st[p] += lazy[p];
 
		if(!isLeaf) {
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
		}
 
		lazy[p] = 0;
	}
 
	void update(int L, int R, int i, int j, T val, int p) {
		propagate(L == R, p);
 
		if(R < i or L > j) return;
		if(L >= i && R <= j) {
			lazy[p] = val;
			propagate(L == R, p);
			return ;
		}
 
		int M = (L+R)/2;
 
		update(L,M,i,j,val,2*p);
		update(M+1,R,i,j,val,2*p+1);
 
		st[p] = f(st[2*p], st[2*p+1]);
	}
 
	T query(int L, int R, int i, int j, int p) {
		propagate(L == R, p);
 
		if(R < i or L > j) return neutral;
		if(L >= i && R <= j) return st[p];
 
		int M = (L+R)/2;
 
		int l = query(L,M,i,j,2*p);
		int r = query(M+1,R,i,j,2*p+1);
 
		return f(l, r);
	}
 
 
	public:
		Segtree(int _sz) : sz(_sz) {
			st = vector<T>(4*sz+5, T(0));
			lazy = vector<T>(4*sz+5, T(0));
		}
 
		void update(int i, int j, T val) {update(0, sz-1, i, j, val, 1);}
 
		T query(int i, int j) {return query(0, sz-1, i, j, 1);}
};