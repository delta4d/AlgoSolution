#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100086;
const double INF = 98765432123456.99;
const double eps = 1e-8;

struct point {
	double x, y;
	point(double _x=0, double _y=0) {}
} p[MAXN];

int n;
vector <point> tt;

inline bool cmpx(const point &a, const point &b) {
	return a.x < b.x;
}

inline bool cmpy(const point &a, const point &b) {
	return a.y < b.y;
}

inline double dis(const point &a, const point &b) {
//	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double gao(int left, int right) {
	int i, j, k;
	int mid(left + ((right - left) >> 1));
	double ret(INF);
	
	if (right - left <= 2) {
		for (i=left; i<=right; ++i) for (j=i+1; j<=right; ++j) {
			ret = min(ret, dis(p[i], p[j]));
		}
		return ret;
	}
	ret = min(gao(left, mid), gao(mid+1, right));
	tt.clear();
	for (i=left; i<=right; ++i) if (p[mid].x - ret <= p[i].x && p[i].x <= p[mid].x + ret) {
		tt.push_back(p[i]);
	}
	sort(tt.begin(), tt.end(), cmpy);
	for (i=0; i<tt.size(); ++i) {
		for (j=i+1; j<tt.size(); ++j) {
			if (tt[j].y - tt[i].y >= ret) break;
			ret = min(ret, dis(tt[i], tt[j]));
		}
	}
	return ret;
}

int main() {
//	freopen("d:\\in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		for (int i=0; i<n; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
		sort(p, p+n, cmpx);
		printf("%.2lf\n", sqrt(gao(0, n-1)) / 2.0);
	}
	return 0;
}