#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double PER = acos(-1.0) / 180.0;
const double R = 6378.0;
const int MAXN = 100;
const int MAXL = 32;

struct loc {
	char name[MAXL];
	double a;
	double b;
	
	bool input() {
		scanf("%s", name);
		if (name[0] == '#') return false;
		scanf("%lf %lf", &a, &b);
		a *= PER, b *= PER;
		return true;
	}
	bool me(char tn[]) {
		return !strcmp(name, tn);
	}
	void mid(const loc end, loc &r) {
		r.a = (a + end.a) / 2.0;
		r.b = (b + end.b) / 2.0;
	}
	int dis(const loc end) {
		double x1, y1, z1;
		double x2, y2, z2;
		double alpha, d;
		printf("%lf %lf\n", a, b);
		printf("%lf %lf\n", end.a, end.b);
		x1 = R * cos(a);
		y1 = x1 * sin(b), x1 = x1 * cos(b), z1 = R * sin(a);
		x2 = R * cos(end.a);
		y2 = x2 * sin(end.b), x2 = x2 * cos(end.b), z2 = R * sin(end.a);
		printf("%lf %lf %lf\n", x1, y1, z1);
		printf("%lf %lf %lf\n", x2, y2, z2);
		d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
		alpha = 1.0 - d / (2.0 * R * R);
		alpha = acos(alpha);
		return int(alpha * R);
	}
} f[MAXN];

inline int find_name(char name[], const int n) {
	int i;
	for (i=0; i<n; ++i) if (f[i].me(name)) return i;
	return i;
}

int main() {
	int i, j, k;
	int n;
	int src, dst, mid;
	char s[MAXL], t[MAXL], m[MAXL];
	loc a;
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out.txt", "w", stdout);
	i = 0;
	while (f[i++].input());
	n = i - 1;
	//printf("%d\n", n);
	scanf("%s", s);
	while (s[0] != '#') {
		scanf("%s %s", t, m);
		src = find_name(s, n);
		dst = find_name(t, n);
		mid = find_name(m, n);
		if (mid == n || src == n || dst == n) {
			printf("%s is ? km off %s/%s equidistance.\n", m, s, t);
		} else {
			f[src].mid(f[dst], a);
			printf("%s is %d km off %s/%s equidistance.\n", m, f[mid].dis(a), s, t);
		}
		scanf("%s", s);
	}
	return 0;
}