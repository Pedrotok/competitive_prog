const int N = 1e5;

int lp[N+5];

void preprocess() {
	for(int i = 2; i <= N; i++) {
		if(lp[i]) continue;
		for(int j = i; j <= N; j += i)
			lp[j] = i;
	}
}

int totient(int n) {
	int ans = n;

	while(n > 1) {
		int prime = lp[n];
		while(n > 1 && n%prime == 0)
			n /= prime;
		ans -= ans/prime;
	}
	if(n > 1) ans -= ans/n;
	return ans;
}