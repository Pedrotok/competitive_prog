class Bit2d {
	vector<vector<int>> bit;
	int szx, szy;

	int get(int x, int y) {
		int sum = 0;
		for(; x; x -= x&(-x))
			for(int ny = y; ny; ny -= ny&(-ny))
				sum += bit[x][ny];

		return sum;
	}

public:
	Bit2d(int _szx, int _szy) : szx(_szx), szy(_szy){
		bit = vector<vector<int>>(szx+5, vector<int>(szy+5, 0));
	}

	void update(int x, int y, int val) {
		for(; x <= szx; x += x&(-x))
			for(int ny = y; ny <= szy; ny += ny&(-ny))
				bit[x][ny] += val;
	}

	int query(int x1, int y1, int x2, int y2) {
		return get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
	}
};