template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

const int MOD = 1e9 + 7;
template <class T>
struct MB {
	MB(int v = 0) : val(v < 0 ? v + MOD : v) {}
	int val;

	void operator += (MB<T> o) { *this = *this + o; }
	void operator -= (MB<T> o) { *this = *this - o; }
	void operator *= (MB<T> o) { *this = *this * o; }
	MB<T> operator * (MB<T> o) { return (int)((long long) val * o.val % MOD); }
	MB<T> operator / (MB<T> o) { return *this * fexp(o, MOD - 2); }
	MB<T> operator + (MB<T> o) { return val + o.val >= MOD ? val + o.val - MOD : val + o.val; }
	MB<T> operator - (MB<T> o) { return val - o.val < 0 ? val - o.val + MOD : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const MB<T> &p) { return os << p.val; }
	friend std::istream& operator >> (std::istream &is, MB<T> &p) { return is >> p.val; }
};
