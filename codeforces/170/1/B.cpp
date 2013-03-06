#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 256;
const int R = 50000000 + 86;
const int STEP = 32;
const double PI = acos(-1.0);
const double RATE = 0.888;

int x[MAXN], y[MAXN];

int main() {
	int i, j, k;
	int m, n;
	double delta;

	scanf("%d%d", &n, &m);

	if (m == 3 && n >= 5) {
		puts("-1");
		return 0;
	}

	delta = 2 * PI / m;

	for (i=0; i<m; ++i) {
		x[i] = (int)floor(R * cos(delta*i));
		y[i] = (int)floor(R * sin(delta*i));
	}
	for (i=0; i<m; ++i) {
		int xx = (int)floor(x[i] * RATE), yy = (int)floor(y[i] * RATE);	
		double momo = delta / STEP;
		x[i+m] = xx * cos(momo) - yy * sin(momo);
		y[i+m] = yy * cos(momo) + xx * sin(momo);
	}
	for (i=0; i<n; ++i) printf("%d %d\n", x[i], y[i]);

	return 0;
}

// 3222273	 Mar 1, 2013 8:09:09 AM	delta_4d	 277B - Set of Points	 GNU C++	Accepted	15 ms	0 KB
