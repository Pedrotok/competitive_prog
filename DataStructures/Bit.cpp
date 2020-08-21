template<typename T>
struct Bit {
	vector<T> ft;
	int sz;

	Bit(){}
	Bit(int n) : sz(n) {
		ft = vector<T>(sz+5, 0);
	}

	T get(int i) {
		T sum = 0;
		for(;i; i -= i&(-i))
			sum += ft[i];
		return sum;
	}

	T get(int l, int r) {
		if(l > r) return 0;
		return get(r) - get(l-1);
	}

	int getPos(T sum) {
		int pos = 0;
		for(int i = 20; i >= 0; i--) {
			int nPos = pos + (1<<i);
			if(nPos > sz) continue;
			if(ft[nPos] < sum) {
				sum -= ft[nPos];
				pos |= 1<<i;
			}
		}

		return pos+1;
	}

	void update(int i, T val) {
		for(;i <= sz; i += i&(-i))
			ft[i] += val;
	}
};