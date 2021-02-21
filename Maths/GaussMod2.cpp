const int B = 30;
 
struct Gauss2 {
	int basis[B], sz;
 
	Gauss2() {
		sz = 0;
		for(int i = 0; i < B; i++)
			basis[i] = 0;
	}
 
	bool can(int mask) {
		for(int i = B-1; i >= 0; i--) {
			if ((mask & (1 << i)) == 0) continue;
			if(!basis[i]) return false;
			mask ^= basis[i];
		}
		return true;
	}
 
	void insert(int mask) {
		for (int i = B-1; i >= 0; i--) {
			if ((mask & (1 << i)) == 0) continue;
 
			if (!basis[i]) {
				basis[i] = mask;
				sz++;
				return;
			}
 
			mask ^= basis[i];
		}
	}
};