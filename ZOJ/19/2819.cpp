#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
const double INF = 999999999999.9;
const int MAXN = 500;

struct point {
	double x, y, z;
	point(double _x=0, double _y=0, double _z=0):x(_x), y(_y), z(_z) {}
	inline bool input() { return 3 == scanf("%lf %lf %lf", &x, &y, &z); }
	inline void mark() { x = INF; }
	inline bool is_marked() { return x > 1000; }
	inline double normal() { return x*x+y*y+z*z; }
} f[MAXN];

inline double dotmult(point &a, point &b) {
	double t =  a.x * b.x + a.y * b.y + a.z * b.z;
	return t < 0 ? -INF : t * t;
}

struct telescope {
	point sight;
	double angle;
	double cangle;
	inline bool input() {
		if (!sight.input()) return false;
		if (1 != scanf("%lf", &angle)) return false;
		cangle = cos(angle), cangle *= cangle;
		return true;
	}
	inline bool in(point &a) {
		double t = dotmult(sight, a) / (sight.normal() * a.normal());
		return t > cangle + eps;
	}
};

int main() {
	int i, j, k;
	int m, n;
	int cnt;
	telescope x;
	//freopen("f:\\in.txt", "r", stdin);	
	while (scanf("%d", &n), n) {
		for (i=0; i<n; ++i) f[i].input();
		scanf("%d", &m);
		cnt = 0;
		for (i=0; i<m; ++i) {
			x.input();
			for (k=0; k<n; ++k) {
				if (!f[k].is_marked() && x.in(f[k])) {
					++cnt;
					f[k].mark();
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}