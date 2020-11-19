const double PI = acos(-1);
const double EPS = 1e-11;

bool equals(double a, double b){
	return fabs(a-b) < EPS;
}

template<typename T>
struct Point {
	T x, y;
	Point(){}
	Point(T a, T b) : x(a), y(b) {}

	double length() const {
		return hypot(x, y);
	}

	bool operator<(const Point& rhs) const {
		if(x == rhs.x) return y < rhs.y;
		return x < rhs.x;
	}

	bool operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	Point operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}

	Point operator+(const Point& rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}

	double distance(const Point& rhs) const {
		return hypot(rhs.x - x, rhs.y - y);
	}

	ll distance_squared(const Point& rhs) const {
		return 1LL*(rhs.x - x)*(rhs.x - x) + 1LL*(rhs.y - y)*(rhs.y - y);
	}

	double angle() const {
		return atan2(y / x);
	}

	double smallest_angle(const Point& v) {
		auto lu = length();
		auto lv = v.length();
		auto prod = dot_product(v);

		return acos(prod/(lu * lv));
	}

	double dot_product(const Point& rhs) const {
		return 1.0*x*rhs.x + 1.0*y*rhs.y;
	}

	double cross_product(const Point& rhs) const {
		return 1.0*x*rhs.y - 1.0*y*rhs.x;
	}

	void rotate(double angle) {
		double auxx = cos(angle)*x - sin(angle)*y;
		double auxy = sin(angle)*x + cos(angle)*y;

		x = auxx; y = auxy;
	}

	void normalize() {
		auto len = length();
		x /= len;
		y /= len;
	}

	void normalize_gcd() {
		auto g = gcd(x, y);
		x /= g;
		y /= g;
	}
};

template<typename T>
struct Line {
	T a, b, c;

	Line(Point<T> R, Point<T> S){
		a = R.y - S.y;
		b = S.x - R.x;
		c = R.x*S.y - S.x*R.y;
	}

	Line(pair<int,int> R, pair<int,int> S){
		a = R.ss - S.ss;
		b = S.ff - R.ff;
		c = R.ff*S.ss - S.ff*R.ss;
	}

	Line(pair<double,double> R, pair<double,double> S){
		a = R.ss - S.ss;
		b = S.ff - R.ff;
		c = R.ff*S.ss - S.ff*R.ss;
	}

	double dist(pair<int,int> t){
		return fabs(a*t.ff+b*t.ss+c)/sqrt(a*a+b*b);
	}

	Point<double> closest(const Point<T>& p) const {
		auto den = 1.*a*a + b*b;
		auto x = (1.*b*(1.*b*p.x - 1.*a*p.y) - 1.*a*c)/den;
		auto y = (1.*a*(-1.*b*p.x + 1.*a*p.y) - 1.*b*c)/den;

		return Point<double>(x, y);
	}
};

struct Segment {
	Point<double> A, B;

	Segment(const Point<double>& Av, const Point<double>& Bv) : A(Av), B(Bv) {}

	double length() const {
		return hypot(A.x - B.x, A.y - B.y);
	}

	bool contains(const Point<double>& P) const {
	if (equals(A.x, B.x))
		return min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
	else
		return min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x);
	}

	Point<double> closest(const Point<double>& P) {
		Line<double> r(A, B);

		auto Q = r.closest(P);

		if (contains(Q)) return Q;

		auto distA = P.distance(A);
		auto distB = P.distance(B);

		if (distA <= distB) return A;
		else return B;
	}

	double distancePoint(const Point<double>& P) {
		auto close = closest(P);
		return close.distance(P);
	}
};
