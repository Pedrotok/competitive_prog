class Segtree2D {
	int szx, szy;
	vector<vector<int>> st;
 
	const int neutral = 0;

	inline int f(int a, int b) {
		return max(a, b);
	}

	void update_y(int LX, int RX, int LY, int RY, int x, int y, int val, int px, int py) {
		if(RY < y or LY > y) return;
		if(LY == RY) {
			if(LX == RX) st[px][py] = val;
			else st[px][py] = f(st[2*px][py], st[2*px+1][py]);
			return ;
		}
 
		int M = (LY+RY)/2;
 
		update_y(LX,RX,LY,M,x,y,val,px,2*py);
		update_y(LX,RX,M+1,RY,x,y,val,px,2*py+1);

		st[px][py] = f(st[px][2*py], st[px][2*py+1]);
	}
 
	void update_x(int LX, int RX, int LY, int RY, int x, int y, int val, int px) {
		if(RX < x or LX > x) return;
		if(LX != RX) {
			int M = (LX+RX)/2;
 
			update_x(LX,M,LY,RY,x,y,val,2*px);
			update_x(M+1,RX,LY,RY,x,y,val,2*px+1);
		}

		update_y(LX, RX, LY, RY, x, y, val, px, 1);
	}

	int query_y(int LY, int RY, int y1, int y2, int px, int py) {
		if(RY < y1 or LY > y2) return neutral;
		if(LY >= y1 && RY <= y2) {
			return st[px][py];
		}
 
		int M = (LY+RY)/2;
 
		int l = query_y(LY,M,y1,y2,px,2*py);
		int r = query_y(M+1,RY,y1,y2,px,2*py+1);
 
		return f(l, r);
	}
 
	int query_x(int LX, int RX, int LY, int RY, int x1, int y1, int x2, int y2, int px) {
		if(RX < x1 or LX > x2) return neutral;
		if(LX >= x1 && RX <= x2) {
			return query_y(LY, RY, y1, y2, px, 1);
		}
 
		int M = (LX+RX)/2;
 
		int l = query_x(LX,M,LY,RY,x1,y1,x2,y2,2*px);
		int r = query_x(M+1,RX,LY,RY,x1,y1,x2,y2,2*px+1);
 
		return f(l, r);
	}
 
 
	public:
		Segtree2D(int _szx, int _szy) : szx(_szx), szy(_szy) {
			st = vector<vector<int>>(4*szx+5, vector<int>(4*szy+5, 0));
		}
 
		void update(int x, int y, int val) {update_x(0, szx, 0, szy, x, y, val, 1);}
 
		int query(int x1, int y1, int x2, int y2) {return query_x(0, szx, 0, szy, x1, y1, x2, y2, 1);}
};