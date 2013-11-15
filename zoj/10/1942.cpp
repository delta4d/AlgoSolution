#include <cmath>
#include <cstdio>
#include <memory>
#include <cstring>
#include <algorithm>
using namespace std;

const double INF = 98765432123456.0;
const int MAXN = 201;
struct point {
	double x;
	double y;
} f[MAXN];
bool visit[MAXN];
double d[MAXN];

inline double dis(const int a, const int b) {
	return sqrt((f[a].x - f[b].x)*(f[a].x - f[b].x)+(f[a].y - f[b].y)*(f[a].y - f[b].y));
}

double gao(const int n) {
	int i, j , k;
	int index;
	int mint;
	double t;
	memset(visit, false, sizeof(visit));
	fill(d, d+n, INF);
	d[0] = 0;
	for (k=0; k<n; ++k) {
		mint = INF;
		for (i=0; i<n; ++i) {
			if (!visit[i] && d[i] < mint) {
				mint = d[i];
				index = i;
			}
		}
		visit[index] = true;
		for (i=0; i<n; ++i) {
			if (!visit[i]) {
				t = dis(index, i);
				if (t >= d[index]) {
					d[i] = min(d[i], t);
				} else {
					d[i] = min(d[i], d[index]);
				}
			}
		}
	}
	return d[1];
}

int main() {
	int i, j, k;
	int n, cn(0);
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", &f[i].x, &f[i].y);
		}
		printf("Scenario #%d\n", ++cn);
		printf("Frog Distance = %.3lf\n\n", gao(n));
		scanf("%d", &n);
	}
	return 0;
}