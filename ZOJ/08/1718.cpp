#include <cmath>
#include <cstdio>
#include <memory>
using namespace std;

const double INF = 9876543210.0;
const int MAXN = 101;
double d[MAXN];
bool visit[MAXN];
struct cell {
	double x;
	double y;
	double z;
	double r;
}c[MAXN];

inline double dis(const cell &a, const cell &b) {
	double d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
	d = sqrt(d);
	if (a.r + b.r >= d) return 0.0;
	return d - a.r - b.r;
}

double mst(const int &n) {
	int i, j, k;
	int index;
	double min;
	double temp;
	double len(0.0);
	fill(d+1, d+n+1, INF);
	memset(visit, false, sizeof(visit));
	d[1] = 0;
	for (k=0; k<n; ++k) {
		min = INF;
		for (i=1; i<=n; ++i) {
			if (!visit[i] && d[i] < min) {
				min = d[i];
				index = i;
			}
		}
		visit[index] = true;
		len += d[index];
		for (i=1; i<=n; ++i) {
			if (!visit[i] && (temp = dis(c[index], c[i])) < d[i]) d[i] = temp;
		}
	}
	return len;
}

int main() {
	int n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=1; i<=n; ++i) {
			scanf("%lf %lf %lf %lf", &c[i].x, &c[i].y, &c[i].z, &c[i].r);
		}
		printf("%.3lf\n", mst(n));
		scanf("%d", &n);
	}
	return 0;
}
