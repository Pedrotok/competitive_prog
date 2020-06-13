class Segtree {
	int szx, szy;
	vector<int> st;
 
	const int neutral = 0;
 
	inline int f(int a, int b, int c, int d) {
		return a+b+c+d;
	}
 
	void update(int L, int R, int D, int U, int i, int j, int val, int p) {
		if(L > R or D > U) return;
		if(R < i or L > i or U < j or D > j) return;
		if(L == R && U == D) {
			st[p] += val;
			return ;
		}
 
		int M1 = (L+R)/2;
		int M2 = (U+D)/2;
 
		update(L,M1,D,M2,i,j,val,4*p+1);
		update(L,M1,M2+1,U,i,j,val,4*p+2);
		update(M1+1,R,D,M2,i,j,val,4*p+3);
		update(M1+1,R,M2+1,U,i,j,val,4*p+4);
 
		st[p] = f(st[4*p+1], st[4*p+2], st[4*p+3], st[4*p+4]);
	}
 
	int query(int L, int R, int D, int U, int l, int r, int d, int u, int p) {
		if(R < l or L > r or U < d or D > u or L > R or D > U) return neutral;
		if(L >= l && R <= r && D >= d && U <= u) return st[p];
 
		int M1 = (L+R)/2;
		int M2 = (U+D)/2;
 
		return f(query(L,M1,D,M2,l,r,d,u,4*p+1),
		query(L,M1,M2+1,U,l,r,d,u,4*p+2),
		query(M1+1,R,D,M2,l,r,d,u,4*p+3),
		query(M1+1,R,M2+1,U,l,r,d,u,4*p+4));
	}
 
 
	public:
		Segtree(int _szx, int _szy) : szx(_szx), szy(_szy) {
			st = vector<int>(szx*szy*16 + 5, 0);
		}
 
		void update(int i, int j, int val) {update(0, szx, 0, szy, i, j, val, 1);}
 
		int query(int i, int j, int k, int l) {return query(0, szx, 0, szy, i, j, k, l, 1);}
};