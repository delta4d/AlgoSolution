#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 100;
const double PI = acos(-1.0);
const double R = 40000.0 / (2.0 * PI);
const double eps = 1e-8;

struct point {
	double x;
	double y;
	double z;
	
	void input() {
		scanf("%lf %lf %lf", &x, &y, &z);
	}
	double dis(const point &a) {
		return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) * (z - a.z));
	}
	double opt() {
		return sqrt(x * x + y * y + z * z - R * R);
	}
	bool reach(const point &a) {
		return dis(a) < opt() + eps;
	}
} s[MAXN], t[MAXN];
bool visit[MAXN];

int main() {
	int i, j, k;
	int m, n;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	while (m != 0 || n != 0) {
		//printf("%d %d\n", m, n);
		for (i=0; i<m; ++i) s[i].input();
		for (i=0; i<n; ++i) t[i].input();
		memset(visit, false, sizeof(visit));
		for (k=i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				if (visit[j]) continue;
				if (s[i].reach(t[j])) k += (visit[j] = true);
			}
		}
		printf("%d\n", k);
		scanf("%d %d", &m, &n);
	}
	return 0;
}