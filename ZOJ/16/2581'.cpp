#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double INF = 9999999999999.9;
const int MAXN = 100;

int n;
double f[MAXN][MAXN];
double x[MAXN], y[MAXN];

inline double dis(const int i, const int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

void gao() {
	int i, j, k;
	double res(INF);
	for (i=0; i<n; ++i) fill(f[i], f[i]+n, INF);
	f[1][0] = dis(1, 0);
	for (i=0; i<n; ++i) {
		for (j=0; j<i; ++j) {
			f[i+1][i] = min(f[i+1][i], f[i][j]+dis(j, i+1));
   			f[i+1][j] = min(f[i+1][j], f[i][j]+dis(i, i+1));
		}
	}
	for (i=0; i<n-1; ++i) res = min(res, f[n-1][i]+dis(i, n-1));
 	printf("%.2lf\n", res);
}

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%lf %lf", x+i, y+i);
		gao();
	}
	return 0;
}