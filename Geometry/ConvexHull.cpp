template<typename T>
T D(pair<T,T> P, pair<T,T> Q, pair<T,T> R) {
	return P.ff*Q.ss + P.ss*R.ff + Q.ff*R.ss - (Q.ss*R.ff + P.ff*R.ss + P.ss*Q.ff);
}

template<typename T>
vector<pair<T,T>> convex_hull(vector<pair<T,T>> S) {
	vector<pair<T,T>> L, U;

	for(auto& p : S) {
		while(L.size() >= 2 && D(L[L.size()-2], L[L.size()-1], p) < 0)
			L.pop_back();
		L.push_back(p);
	}

	for(auto& p : S) {
		while(U.size() >= 2 && D(U[U.size()-2], U[U.size()-1], p) > 0)
			U.pop_back();
		U.push_back(p);
	}

	L.pop_back();
	reverse(L.begin(), L.end());
	L.pop_back();
	U.insert(U.end(), L.begin(), L.end());

	return U;
}
