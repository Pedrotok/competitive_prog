const int MOD = 1e9+7;

struct Matrix {
	int n,m;
	vector<vector<int>> M;

	Matrix(){}

	Matrix(int _n, int _m) : n(_n), m(_m) {
		M = vector<vector<int>>(n+5, vector<int>(m+5, 0));
	}

	Matrix(int _n) : Matrix(_n, _n){}

	Matrix(vector<vector<int>> mat) : n((int)mat.size()), m((int)mat[0].size()), M(mat) {}

	static Matrix eye(int n) {
		Matrix mat = Matrix(n);
		for(int i = 0; i < n; i++)
			mat.M[i][i] = 1;
		return mat;
	}

	Matrix operator*(const Matrix& A) const {
		assert(m == A.n);
		Matrix res(n, A.m);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < A.m; j++)
				for(int k = 0; k < m; k++) {
					ll aux = ((ll)M[i][k]*A.M[k][j]) + res.M[i][j];
					if(aux >= MOD) aux %= MOD;
					res.M[i][j] = (int)aux;
				}

		return res;
	}

	static Matrix exp(Matrix A, ll b) {
		assert(A.n == A.m);
		Matrix r = eye(A.n);

		while(b) {
			if(b&1) r = r*A;
			A = A*A;
			b /= 2;
		}

		return r;
	}
};